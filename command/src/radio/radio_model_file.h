#ifndef RADIO_MODEL_FILE_H_
#define RADIO_MODEL_FILE_H_

#include "i_radio_model.h"

#include <iostream>
#include <memory>

namespace radio
{
class RadioModelStream : public IRadioModel
{
  class RadioModelStreamImpl;

public:
  RadioModelStream(std::istream& input, std::ostream& output);
  ~RadioModelStream() = default;
  void set_power(Power p);
  void set_freq(Freq f);
  void set_state(State s);
  Power get_power();
  Freq get_freq();
  State get_state();

private:
  std::unique_ptr<RadioModelStreamImpl> pimpl_;
};

}  // namespace radio
#endif  // RADIO_MODEL_FILE_H_