#ifndef FAKE_RADIO_MODEL_H_
#define FAKE_RADIO_MODEL_H_

#include <memory>
#include <mutex>
#include "radio_model.h"

namespace radio
{
class FakeRadioModel : public RadioModel
{
public:
  struct Limits
  {
    Power min_power;
    Power max_power;
    Freq min_freq;
    Freq max_freq;
  };

public:
  explicit FakeRadioModel(const Limits& limits);
  ~FakeRadioModel() = default;

private:
  void check_power_preconditions(const Power p) const override;
  void check_freq_preconditions(const Freq f) const override;
  void check_state_preconditions(const State& s) const override;
  void set_power_impl(const Power p) override;
  void set_freq_impl(const Freq f) override;
  void set_state_impl(const State& s) override;
  Power get_power_impl() override;
  Freq get_freq_impl() override;
  State get_state_impl() override;

private:
  std::mutex private_data_mutex;
  const Limits limits;
};

}  // namespace radio
#endif  // FAKE_RADIO_MODEL_H_