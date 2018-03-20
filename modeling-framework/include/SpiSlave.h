#pragma once
#include <cstdint>
#include "SpiCommon.h"

struct SpiSlaveConfig {
    int mosi_pin_number;
    int miso_pin_number;
    int ss_pin_number;
    int sclk_pin_number;
    int supported_spi_modes;
    unsigned int max_frequency;
    BitOrder bit_order;
};

class iSpiSlaveV1 {
  public:
    /* Read:
     * Wait until ss is active.
     * Run until ss is deactivated or all bytes are received.
     * Return num bytes received. */
    virtual size_t Read(uint8_t* buffer, size_t num_bytes_to_read) = 0;

    /* Write */
    virtual size_t Write(const uint8_t* buffer, size_t num_bytes_to_write) = 0;

    /* IsSsActive */
    virtual bool IsSsActive() = 0;
};
