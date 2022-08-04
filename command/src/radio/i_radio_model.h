#ifndef RADIO_MODEL_H_
#define RADIO_MODEL_H_

#include <cstdint>

namespace radio
{
using Power = uint32_t;
using Freq = uint32_t;
enum class State { active, passive };

class IRadioModel
{
public:
    virtual ~IRadioModel() = 0;
    virtual void set_power(Power p) = 0;
    virtual void set_freq(Freq f) = 0;
    virtual void set_state(State s) = 0;
    virtual Power get_power() = 0;
    virtual Freq get_freq() = 0;
    virtual State get_state() = 0;
};
}  // namespace radio

#endif  // RADIO_MODEL_H_