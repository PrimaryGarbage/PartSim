#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "ui.hpp"
#include <iostream>

namespace prim
{
    Ui::Ui(sf::RenderWindow* window) : window(window)
    {
        Unp<Button> btn = std::make_unique<Button>();
        btn->pressed_ev.subscribe("print on press", [](){ std::cout << "Pressed!" << std::endl; });
        btn->transform.position = Vec2f(100.0f);
        buttons.push_back(std::move(btn));
    }

    void Ui::update(float deltaTime)
    {
        for(const Unp<Button>& btn : buttons)
        {
            btn->pressed = false;
            sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
            sf::Vector2f mousePosf(mousePos.x, mousePos.y);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && btn->getRect().contains(mousePosf))
            {
                btn->pressed = true;
                btn->pressed_ev.invoke();
            }
        }
    }
    
    void Ui::render()
    {
        if(!window) return;

        for(const Unp<Button>& btn : buttons)
        {
            sf::Vector2f pos = btn->transform.position.toSfVec();
            pos.y = window->getSize().y - pos.y;
            btn->sprite->setPosition(pos);
            window->draw(*(btn->sprite));
        }
    }
}