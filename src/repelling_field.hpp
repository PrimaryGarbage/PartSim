#ifndef __REPELLING_FIELD_HPP__
#define __REPELLING_FIELD_HPP__

#include "field.hpp"

namespace prim
{
    class RepellingField : public Field
    {
    public:
        float force;

        RepellingField() = default;
        RepellingField(float force);
        virtual ~RepellingField();

        virtual void affect(Particle* particle, float deltaTime) const override;
    };
}

#endif // __REPELLING_FIELD_HPP__