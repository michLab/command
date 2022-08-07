#include "radio_model.h"

namespace radio
{
void RadioModel::set_power(const Power p)
{
  check_power_preconditions(p);
  set_power_impl(p);
}

void RadioModel::set_freq(const Freq f)
{
  check_freq_preconditions(f);
  set_freq_impl(f);
}

void RadioModel::set_state(const State& s)
{
  check_state_preconditions(s);
  set_state_impl(s);
}

Power RadioModel::get_power()
{
  return get_power_impl();
}

Freq RadioModel::get_freq()
{
  return get_freq_impl();
}

State RadioModel::get_state()
{
  return get_state_impl();
}

void RadioModel::check_power_preconditions(const Power p) const
{
  (void)p;
  return;
}

void RadioModel::check_freq_preconditions(const Freq f) const
{
  (void)f;
  return;
}

void RadioModel::check_state_preconditions(const State& s) const
{
  (void)s;
  return;
}

}  // namespace radio