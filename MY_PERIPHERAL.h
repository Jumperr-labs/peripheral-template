#pragma once
#include "ModelingFramework.h"

class MY_PERIPHERAL : public ExternalPeripheral {
  public:
    MY_PERIPHERAL();
    void Main() override;
    void Stop() override;
  private:
    /**********************************************************************************
    TODO: Uncomment the following code to enable SPI capabilities for the peripheral.
          Make sure to uncomment the coresponding code in MY_PERIPHERAL.cpp as well.
    **********************************************************************************/
    // iSpiSlaveV1* spi_slave_ {};
};

extern "C" ExternalPeripheral *PeripheralFactory() {
    return new MY_PERIPHERAL();
}
