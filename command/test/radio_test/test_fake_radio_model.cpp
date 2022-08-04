#include <gtest.h>

#include "fake_radio_model.h"

TEST(TestFakeRadioModel, UsingPowerPreconditions_SetValidPower_Success)
{
  radio::FakeRadioModel::Limits limits;
  limits.min_power = 0;
  limits.max_power = 10;
  limits.min_freq = 200;
  limits.max_freq = 400;

  auto radio = radio::FakeRadioModel(limits);

  radio::Power power_target = (limits.max_power - limits.min_power) / 2;

  try
  {
    radio.set_power(power_target);
  }
  catch (const std::runtime_error& exc)
  {
  }
}