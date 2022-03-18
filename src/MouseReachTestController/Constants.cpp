// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#include "Constants.h"


namespace mouse_reach_test_controller
{
namespace constants
{
CONSTANT_STRING(device_name,"mouse_reach_test_controller");

CONSTANT_STRING(firmware_name,"MouseReachTestController");
// Use semantic versioning http://semver.org/
const modular_server::FirmwareInfo firmware_info =
{
  .name_ptr=&firmware_name,
  .version_major=1,
  .version_minor=0,
  .version_patch=0,
};

CONSTANT_STRING(hardware_name,"mouse_reach_controller");

const long pwm_period_ms = 1000;
const long pwm_on_duration_ms = 200;
const long pwm_count = 1;

// Pins
CONSTANT_STRING(signal_a_pin_name,"signal_a");

CONSTANT_STRING(signal_b_pin_name,"signal_b");

CONSTANT_STRING(signal_c_pin_name,"signal_c");

CONSTANT_STRING(signal_d_pin_name,"signal_d");

CONSTANT_STRING(power_switch_pin_name,"power_switch");

// Units

// Properties

// Parameters

// Functions

// Callbacks
CONSTANT_STRING(start_assay_callback_name,"startAssay");
CONSTANT_STRING(dispense_callback_name,"dispense");

// Errors
}
}
