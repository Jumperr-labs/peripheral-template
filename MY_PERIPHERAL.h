#pragma once
#include "ModelingFramework.h"

class MY_PERIPHERAL : public ExternalPeripheral {
  public:
    MY_PERIPHERAL();
    void Main() override;
    void Stop() override;
  private:
    iSpiSlaveV1* spi_slave_ {};
};

extern "C" ExternalPeripheral *PeripheralFactory() {
    return new MY_PERIPHERAL();
}
