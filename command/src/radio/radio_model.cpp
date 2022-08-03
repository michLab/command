#ifndef RADIO_MODEL_H_
#define RADIO_MODEL_H_

#include "radio_model_file.h"

#include <mutex>

namespace radio
{
class RadioModelFile::RadioModelStreamImpl
{
public:
  RadioModelStreamImpl(std::istream& input, std::ostream& output);
  ~RadioModelStreamImpl() = default;
  void set_power(Power p);
  void set_freq(Freq f);
  void set_state(State s);
  Power get_power();
  Freq get_freq();
  State get_state();

private:
  std::mutex public_function_mutex;
  std::istream in;
  std::ostream out;
};

RadioModelFile::RadioModelStreamImpl::RadioModelStreamImpl(std::istream& input, std::ostream& output)
{
  in = input;
  out = output;
}

void RadioModelFile::RadioModelStreamImpl::set_power(Power p)
{
  std::lock_guard<std::mutex> lock(public_function_mutex);
  out << "power," << p << std::endl;
}

void RadioModelFile::RadioModelStreamImpl::set_freq(Freq f)
{
  std::lock_guard<std::mutex> lock(public_function_mutex);
  out << "freq," << f << std::endl;
}

void RadioModelFile::RadioModelStreamImpl::set_state(State s)
{
  std::lock_guard<std::mutex> lock(public_function_mutex);
  out << "state," << s.value() << std::endl;
}

Power RadioModelFile::RadioModelStreamImpl::get_power()
{
  std::lock_guard<std::mutex> lock(public_function_mutex);
  Power p;
  in >> p;
  return p;
}

Freq RadioModelFile::RadioModelStreamImpl::get_freq()
{
  std::lock_guard<std::mutex> lock(public_function_mutex);
  Freq f;
  in >> f;
  return f;
}

State RadioModelFile::RadioModelStreamImpl::get_state()
{
  std::lock_guard<std::mutex> lock(public_function_mutex);
  State s;
  in >> s;
  return s;
}

RadioModelStream::RadioModelStream(std::istream& input, std::ostream& output)
  : pimpl_{ std::make_unique<RadioModelStreamImpl>(input, output) };
{
}

void RadioModelStream::set_power(Power p)
{
  pimpl_->set_power(p);
}

void RadioModelStream::set_freq(Freq f)
{
  pimpl_->set_freq(f);
}

void RadioModelStream::set_state(State s)
{
  pimpl_->set_state(s);
}

Power RadioModelStream::get_power()
{
  return pimpl_->get_power();
}

Freq RadioModelStream::get_freq()
{
  return pimpl_->get_freq();
}

State RadioModelStream::get_state()
{
  return pimpl_->get_state();
}

}  // namespace radio

#endif  // RADIO_MODEL_H_