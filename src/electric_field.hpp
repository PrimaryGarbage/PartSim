#ifndef __ELECTRIC_FIELD_HPP__
#define __ELECTRIC_FIELD_HPP__

#include "field.hpp"

namespace prim
{
    class ElectricField : public Field
    {
    public:
        ElectricField() = default;
        ElectricField(const sf::Vector2f force);
        virtual ~ElectricField();

        sf::Vector2f force;
        virtual void affect(Particle* particle, float deltaTime) const override;
    };
}

#endif // __ELECTRIC_FIELD_HPP__