#include "app.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "timer.hpp"
#include "prim_exception.hpp"
#include "electric_field.hpp"
#include "repelling_field.hpp"
#include "input.hpp"
#include "globals.hpp"

static const uint initialWindowWidth = 800;
static const uint initialWindowHeight = 800;
static const char* windowName = "PartSim";
static const sf::Color clearColor(10, 10, 10);

namespace prim
{
    App::App() : particleMaster({ initialWindowWidth, initialWindowHeight })
    {}
    
    App::~App() 
    {
        delete window;
        delete font;
    }

    int App::run()
    {

        window = new sf::RenderWindow(sf::VideoMode({initialWindowWidth, initialWindowHeight}), windowName);
        Input::initialize(window);
        window->setVerticalSyncEnabled(true);
        window->setFramerateLimit(60);

        // init globals
        Globals::app = this;
        Globals::mainWindow = window;
        Globals::particleMaster = &particleMaster;
        Globals::ui = &ui;

        font = new sf::Font();
        if(!font->loadFromFile("./res/fonts/Roboto-Regular.ttf"))
            throw PRIM_EXCEPTION("Failed to load font file.");

        mainLoop();
        return 0;
    }

    void App::mainLoop()
    {
        Timer timer;
        timer.start();

        Field* repellingField = new RepellingField(0.02f);
        repellingField->setBounds(sf::Rect<float>({150.0f, 500.0f}, {150.0f, 200.0f}));
        repellingField->setColor({255u, 255u, 0u, 40u});
        particleMaster.addField(repellingField);

        Field* repellingField2 = new RepellingField(0.02f);
        repellingField2->setBounds(sf::Rect<float>({350.0f, 500.0f}, {150.0f, 200.0f}));
        repellingField2->setColor({255u, 255u, 0u, 40u});
        particleMaster.addField(repellingField2);

        Field* repellingField3 = new RepellingField(0.02f);
        repellingField3->setBounds(sf::Rect<float>({100.0f, 700.0f}, {400.0f, 150.0f}));
        repellingField3->setColor({255u, 255u, 0u, 40u});
        particleMaster.addField(repellingField3);

        while(window->isOpen())
        {
            deltaTime = timer.peekSinceLastPeek();

            Input::clear();

            window->clear(clearColor);

            sf::Event event;
            while(window->pollEvent(event))
                Input::handleEvent(event);

            // UPDATE //
            handleInput();

            ui.update(deltaTime);
            particleMaster.update(deltaTime);
            ////////////

            // RENDER //
            particleMaster.render(*window);
            ui.render(*window);
            ///////////

            printInfo(deltaTime);

            window->display();
        }
    }
    
    void App::printInfo(float deltaTime)
    {
        static sf::Text particleCountText;
        particleCountText.setFont(*font);
        particleCountText.setPosition({ 20.0f, 20.0f });
        particleCountText.setCharacterSize(12u);
        particleCountText.setString("Particle count: " + std::to_string(particleMaster.getParticleCount()));

        static sf::Text brushText;
        brushText.setFont(*font);
        brushText.setPosition({ 20.0f, 40.0f });
        brushText.setCharacterSize(12u);
        brushText.setString("Current brush: " + std::string(Brush_str[cast(ui.getCurrentBrush(), int)]));

        window->draw(particleCountText);
        window->draw(brushText);
    }

    void App::handleInput()
    {
        if(Input::isJustPressed(sf::Keyboard::T))
            particleMaster.clearTextureOnRender = !particleMaster.clearTextureOnRender;
        if(Input::isJustPressed(sf::Keyboard::C))
            particleMaster.removeAllParticles();
    }
}