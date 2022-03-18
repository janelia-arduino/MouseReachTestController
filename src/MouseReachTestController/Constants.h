// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef MOUSE_REACH_TEST_CONTROLLER_CONSTANTS_H
#define MOUSE_REACH_TEST_CONTROLLER_CONSTANTS_H
#include <ConstantVariable.h>
#include <ModularDeviceBase.h>


namespace mouse_reach_test_controller
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{PROPERTY_COUNT_MAX=1};
enum{PARAMETER_COUNT_MAX=1};
enum{FUNCTION_COUNT_MAX=1};
enum{CALLBACK_COUNT_MAX=2};

extern ConstantString device_name;

extern ConstantString firmware_name;
extern const modular_server::FirmwareInfo firmware_info;

extern ConstantString hardware_name;
extern const modular_server::HardwareInfo hardware_info;

extern const long pwm_period_ms;
extern const long pwm_on_duration_ms;
extern const long pwm_count;

// Pins
enum{PIN_COUNT_MAX=5};

extern ConstantString signal_a_pin_name;
extern const size_t signal_a_pin_number;

extern ConstantString signal_b_pin_name;
extern const size_t signal_b_pin_number;

extern ConstantString signal_c_pin_name;
extern const size_t signal_c_pin_number;

extern ConstantString signal_d_pin_name;
extern const size_t signal_d_pin_number;

extern ConstantString power_switch_pin_name;
extern const size_t power_switch_pin_number;

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]

// Parameters

// Functions

// Callbacks
extern ConstantString start_assay_callback_name;
extern ConstantString dispense_callback_name;

// Errors
}
}
#include "TEENSY40.h"
#endif
