#ifndef EFFECT_INTERFACE_H
#define EFFECT_INTERFACE_H

#include "effect.h"

template <class T>
class EffectInterface : public Effect
{
public:
    virtual ~EffectInterface()
    {
        // We have to access the variable "registered",
        // otherwise it will be deleted by the compiler

        if (!registered)
            printf("Class not registered\n");
    }

    static inline bool register_effect()
    {
        auto &registry = Effect::get_registry();

        registry[T::effectIdentifier] = T::create;

        return true;
    }

    static const bool registered;

protected:
    virtual void DoNotInheritFromEffectDirectlyButFromEffectInterfaceInstead() final {}
};

template <class T>
const bool EffectInterface<T>::registered = EffectInterface<T>::register_effect();

#endif // EFFECT_INTERFACE_H
