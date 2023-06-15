#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "ui.hpp"
#include <iostream>

namespace prim
{
    Ui::Ui()
    {
        Unp<Button> particleBtn = std::make_unique<Button>();
        particleBtn->pressed_ev.subscribe("ChooseParticleBrush", [this](){ currentBrush = Brush::Particle;});
        particleBtn->setSize({50.0f, 50.0f});
        particleBtn->setPosition(Vec2f(50.0f, 50.0f));
        particleBtn->setColor({0u, 0u, 255u, 255u});
        buttons.push_back(std::move(particleBtn));

        Unp<Button> fieldBtn = std::make_unique<Button>();
        fieldBtn->pressed_ev.subscribe("ChooseFieldBrush", [this](){ currentBrush = Brush::Field; });
        fieldBtn->setSize({50.0f, 50.0f});
        fieldBtn->setPosition(Vec2f(110.0f, 50.0f));
        fieldBtn->setColor({100u, 100u, 100u, 255u});
        buttons.push_back(std::move(fieldBtn));

        Unp<Button> eraseBtn = std::make_unique<Button>();
        eraseBtn->pressed_ev.subscribe("ChooseEraseBrush", [this](){ currentBrush = Brush::Erase; });
        eraseBtn->setSize({50.0f, 50.0f});
        eraseBtn->setPosition(Vec2f(170.0f, 50.0f));
        eraseBtn->setColor({255u, 0u, 0u, 255u});
        buttons.push_back(std::move(eraseBtn));
    }

    void Ui::update(float deltaTime)
    {
        for(const Unp<Button>& btn : buttons)
        {
            btn->update(deltaTime);
        }
    }
    
    void Ui::render(sf::RenderWindow& window)
    {
        for(const Unp<Button>& btn : buttons)
        {
            btn->render(window);
        }
    }
}