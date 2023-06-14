#include "app.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "timer.hpp"
#include "prim_exception.hpp"
#include "electric_field.hpp"
#include "repelling_field.hpp"
#include "input.hpp"

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

        Field* electricField = new ElectricField({0.0004f, 0.0000f});
        electricField->setBounds(sf::Rect<float>({200.0f, 170.0f}, {300.0f, 300.0f}));
        electricField->setColor({255u, 255u, 255u, 40u});
        particleMaster.addField(electricField);

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

            sf::Event event;
            while(window->pollEvent(event))
                handleEvent(event);

            // UPDATE //
            Input::update();

            ui.update(deltaTime);
            particleMaster.update(deltaTime);
            ////////////


            // RENDER //
            window->clear(clearColor);
            particleMaster.render(*window);
            ui.render(*window);
            ///////////

            printInfo(deltaTime);

            window->display();
        }
    }
    
    void App::handleEvent(const sf::Event& event)
    {
        switch(event.type)
        {
            case sf::Event::KeyPressed:
            case sf::Event::KeyReleased:
            case sf::Event::MouseButtonPressed:
            case sf::Event::MouseButtonReleased:
            case sf::Event::MouseMoved:
            case sf::Event::MouseWheelScrolled:
                handleInput(event);
                break;
            case sf::Event::Closed:
                window->close();
                break;
            default:
                break;
        }
    }
    
    void App::printInfo(float deltaTime)
    {
        static sf::Text particleCountText;
        particleCountText.setFont(*font);
        particleCountText.setPosition({ 20.0f, 20.0f });
        particleCountText.setCharacterSize(12u);

        particleCountText.setString("Particle count: " + std::to_string(particleMaster.getParticleCount()));

        window->draw(particleCountText);
    }

    void App::handleInput(const sf::Event& event)
    {
        switch(event.type)
        {
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Key::T:
                        particleMaster.clearTextureOnRender = !particleMaster.clearTextureOnRender;
                        break;
                    case sf::Keyboard::Key::C:
                        particleMaster.removeAllParticles();
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::KeyReleased:
                break;
            case sf::Event::MouseButtonPressed:
                // if(event.mouseButton.button == sf::Mouse::Button::Left)
                //     particleMaster.addParticle({{float(event.mouseButton.x), float(event.mouseButton.y)}, {0.0f, 0.0f}, ParticleType::Electron, false});
                // else if(event.mouseButton.button == sf::Mouse::Button::Right)
                //     particleMaster.addParticle({{float(event.mouseButton.x), float(event.mouseButton.y)}, {0.0f, 0.0f}, ParticleType::Proton, false});
                break;
            case sf::Event::MouseButtonReleased:
                break;
            case sf::Event::MouseMoved:
                break;
            case sf::Event::MouseWheelScrolled:
                break;
            default:
                break;
        }
    }
}