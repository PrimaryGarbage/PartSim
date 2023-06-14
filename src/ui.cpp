#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "ui.hpp"
#include <iostream>

namespace prim
{
    Ui::Ui()
    {
        Unp<Button> btn = std::make_unique<Button>();
        btn->pressed_ev.subscribe("print on press", [](){ std::cout << "Pressed!" << std::endl; });
        btn->setSize({50.0f, 50.0f});
        btn->setPosition(Vec2f(50.0f, 100.0f));
        buttons.push_back(std::move(btn));
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