// ----------------------------------------------------------------------------
// MouseReachTestController.h
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef MOUSE_REACH_TEST_CONTROLLER_H
#define MOUSE_REACH_TEST_CONTROLLER_H
#include <ArduinoJson.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <ConstantVariable.h>
#include <Functor.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>

#include "MouseReachTestController/Constants.h"


class MouseReachTestController : public ModularDeviceBase
{
public:
  virtual void setup();

  void startAssay();
  void dispense();

private:
  modular_server::Pin pins_[mouse_reach_test_controller::constants::PIN_COUNT_MAX];

  modular_server::Property properties_[mouse_reach_test_controller::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[mouse_reach_test_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[mouse_reach_test_controller::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[mouse_reach_test_controller::constants::CALLBACK_COUNT_MAX];

  // Handlers
  void setDispenseVelocityLimitHandler(size_t channel);
  void getAssayStatusHandler();
  void playPositionToneHandler();
  void buzzHandler();
  void moveToDispenseHandler(int arg);
  void moveToBuzzHandler(int arg);
  void setMoveToLoadHandler(int arg);
  void setWaitAtLoadHandler(int arg);
  void setMoveToNextDeliverPositionHandler(int arg);
  void setLeftPositionSignalHighHandler(int arg);
  void setLeftPositionSignalLowHandler(int arg);
  void setRightPositionSignalHighHandler(int arg);
  void setRightPositionSignalLowHandler(int arg);
  void startAssayHandler(modular_server::Pin * pin_ptr);
  void dispenseHandler(modular_server::Pin * pin_ptr);
  void abortHandler(modular_server::Pin * pin_ptr);

};

#endif
