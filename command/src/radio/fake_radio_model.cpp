#include "fake_radio_model.h"

#include <exception>
#include <sstream>

namespace radio
{
FakeRadioModel::FakeRadioModel(const Limits& lim) : limits(lim)
{
}

void FakeRadioModel::check_power_preconditions(const Power p) const
{
  if (p > limits.max_power)
    || (p < limits.min_power)
    {
      const std::stringstream ss << "Failed to set power, requested: " << p << "min: " << limits.min_power
                                 << ", max: " << limits.max_power;
      throw std::runtime_error(ss.str());
    }
}

}  // namespace radio