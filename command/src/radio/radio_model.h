#ifndef RADIO_MODEL_H_
#define RADIO_MODEL_H_

#include <cstdint>

namespace radio
{
using Power = uint32_t;
using Freq = uint32_t;
enum class State
{
  active,
  passive
};

class RadioModel
{
public:
  virtual ~RadioModel() = default;
  void set_power(const Power p);
  void set_freq(const Freq f);
  void set_state(const State& s);
  Power get_power();
  Freq get_freq();
  State get_state();

protected:
  RadioModel() = default;

private:
  // These functions are not pure virtual because a RadioModel that
  // needs no preconditions shouldnt'b be forced to check any.
  virtual void check_power_preconditions(const Power p) const;
  virtual void check_freq_preconditions(const Freq f) const;
  virtual void check_state_preconditions(const State& s) const;

  virtual void set_power_impl(const Power p) = 0;
  virtual void set_freq_impl(const Freq f) = 0;
  virtual void set_state_impl(const State& s) = 0;
  virtual Power get_power_impl() = 0;
  virtual Freq get_freq_impl() = 0;
  virtual State get_state_impl() = 0;
};
}  // namespace radio

#endif  // RADIO_MODEL_H_