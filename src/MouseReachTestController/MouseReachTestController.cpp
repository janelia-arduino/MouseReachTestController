// ----------------------------------------------------------------------------
// MouseReachTestController.cpp
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#include "../MouseReachTestController.h"


using namespace mouse_reach_test_controller;

void MouseReachTestController::setup()
{
  // Parent Setup
  ModularDeviceBase::setup();

  // Reset Watchdog
  resetWatchdog();

  // Set Device ID
  modular_server_.setDeviceName(constants::device_name);

  // Add Hardware
  modular_server_.removeHardware();
  modular_server_.addHardware(constants::hardware_info,
    pins_);

  // Pins
  modular_server::Pin & signal_a_pin = modular_server_.createPin(constants::signal_a_pin_name,
    constants::signal_a_pin_number);
  signal_a_pin.setModePwmFalling();

  modular_server::Pin & signal_b_pin = modular_server_.createPin(constants::signal_b_pin_name,
    constants::signal_b_pin_number);
  signal_b_pin.setModePwmFalling();

  modular_server::Pin & signal_c_pin = modular_server_.createPin(constants::signal_c_pin_name,
    constants::signal_c_pin_number);
  signal_c_pin.setModeDigitalOutput();

  modular_server::Pin & signal_d_pin = modular_server_.createPin(constants::signal_d_pin_name,
    constants::signal_d_pin_number);
  signal_d_pin.setModeDigitalOutput();

  modular_server::Pin & power_switch_pin = modular_server_.createPin(constants::power_switch_pin_name,
    constants::power_switch_pin_number);
  power_switch_pin.setModePwmRising();

  // Add Firmware
  modular_server_.addFirmware(constants::firmware_info,
    properties_,
    parameters_,
    functions_,
    callbacks_);

  // Properties

  // Parameters

  // Functions

  // Callbacks
  modular_server::Callback & start_assay_callback = modular_server_.createCallback(constants::start_assay_callback_name);
  start_assay_callback.attachFunctor(makeFunctor((Functor1<modular_server::Pin *> *)0,*this,&MouseReachTestController::startAssayHandler));

  modular_server::Callback & dispense_callback = modular_server_.createCallback(constants::dispense_callback_name);
  dispense_callback.attachFunctor(makeFunctor((Functor1<modular_server::Pin *> *)0,*this,&MouseReachTestController::dispenseHandler));

}

void MouseReachTestController::startAssay()
{
  modular_server_.pin(constants::signal_b_pin_name).addPwm(constants::pwm_period_ms,
    constants::pwm_on_duration_ms,
    constants::pwm_count);
}

void MouseReachTestController::dispense()
{
  modular_server_.pin(constants::signal_a_pin_name).addPwm(constants::pwm_period_ms,
    constants::pwm_on_duration_ms,
    constants::pwm_count);
}

void MouseReachTestController::startAssayHandler(modular_server::Pin * pin_ptr)
{
  startAssay();
}

void MouseReachTestController::dispenseHandler(modular_server::Pin * pin_ptr)
{
  dispense();
}
