#ifndef EFFECT_INTERFACE_H
#define EFFECT_INTERFACE_H

#include "effect.h"

/**
 * @class EffectInterface
 * @brief A template class used as an interface 
 * for creating and registering new effects
 */
template <class T>
class EffectInterface : public Effect
{
public:
    /**
     * @brief Destructor
     * @details We must access the variable "registered"
     * to prevent the compiler from deleting it
     */
    virtual ~EffectInterface()
    {
        if (!registered)
            printf("Class not registered\n");
    }

    /**
     * @brief Adds an effect class to the effect registrar
     * @return True
     */
    static inline bool register_effect()
    {
        auto &registry = Effect::get_registry();

        registry[T::effectIdentifier] = T::create;

        return true;
    }

    /**
     * @brief Gets a value indicating whether the effect is registered or not
     */
    static const bool registered;

protected:
    /**
     * @brief Prevents inherited classes from overriding this function. It is only needed in the interface
     */
    virtual void DoNotInheritFromEffectDirectlyButFromEffectInterfaceInstead() final {}
};

/**
 * @details The "registered" variable is static, which means that it will be initialized 
 * prior to the program execution. This allows for self-registering effect classes.
 */
template <class T>
const bool EffectInterface<T>::registered = EffectInterface<T>::register_effect();

#endif // EFFECT_INTERFACE_H
