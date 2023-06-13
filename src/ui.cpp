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
        btn->setPosition(Vec2f(100.0f));
        btn->setColor(sf::Color::Blue);
        buttons.push_back(std::move(btn));
    }

    void Ui::update(float deltaTime)
    {
        for(const Unp<Button>& btn : buttons)
        {
            btn->update(deltaTime, *window);
        }
    }
    
    void Ui::render()
    {
        if(!window) return;

        for(const Unp<Button>& btn : buttons)
        {
            btn->render(*window);
        }
    }
}