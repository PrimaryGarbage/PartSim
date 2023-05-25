#include "app.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "timer.hpp"
#include "prim_exception.hpp"

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
        delete mainTexture;
        delete mainSprite;
        delete font;
    }

    int App::run()
    {
        window = new sf::RenderWindow(sf::VideoMode({initialWindowWidth, initialWindowHeight}), windowName);
        window->setVerticalSyncEnabled(true);
        window->setFramerateLimit(60);

        mainTexture = new sf::Texture();
        mainSprite = new sf::Sprite(*mainTexture);

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

        while(window->isOpen())
        {
            deltaTime = timer.peekSinceLastPeek();

            sf::Event event;
            while(window->pollEvent(event))
                handleEvent(event);

            sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                particleMaster.addParticle({sf::Vector2f(float(mousePos.x), float(mousePos.y)), sf::Vector2f(0.0f, 0.0f), ParticleType::Electron, false});
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
                particleMaster.addParticle({sf::Vector2f(float(mousePos.x), float(mousePos.y)), sf::Vector2f(0.0f, 0.0f), ParticleType::Proton, false});

            particleMaster.update(deltaTime);

            window->clear(clearColor);

            mainSprite->setTexture(*mainTexture, true);
            particleMaster.render(mainTexture);

            window->draw(*mainSprite);

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
        static sf::Text particleCountText(*font);
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