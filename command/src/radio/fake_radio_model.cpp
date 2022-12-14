#include "fake_radio_model.h"

#include <exception>
#include <sstream>

namespace radio
{
FakeRadioModel::FakeRadioModel(const FakeRadioModel::Limits& lim) : limits(lim)
{
}

void FakeRadioModel::check_power_preconditions(const Power p) const
{
  if ((p > limits.max_power) || (p < limits.min_power))
  {
    std::stringstream ss;
    ss << "Failed to set power, requested: " << p << "min: " << limits.min_power << ", max: " << limits.max_power;
    throw std::runtime_error(ss.str());
  }
}

void FakeRadioModel::check_freq_preconditions(const Freq f) const
{
  (void)f;
}

void FakeRadioModel::check_state_preconditions(const State& s) const
{
  (void)s;
}

void FakeRadioModel::set_power_impl(const Power p)
{
  (void)p;
}

void FakeRadioModel::set_freq_impl(const Freq f)
{
  (void)f;
}

void FakeRadioModel::set_state_impl(const State& s)
{
  (void)s;
}

Power FakeRadioModel::get_power_impl()
{
  return 0;
}

Freq FakeRadioModel::get_freq_impl()
{
  return 0;
}

State FakeRadioModel::get_state_impl()
{
  return State();
}

}  // namespace radio