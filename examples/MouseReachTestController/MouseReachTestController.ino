#include <MouseReachTestController.h>


MouseReachTestController dev;

void setup()
{
  dev.setup();
  dev.startServer();
}

void loop()
{
  dev.update();
}
