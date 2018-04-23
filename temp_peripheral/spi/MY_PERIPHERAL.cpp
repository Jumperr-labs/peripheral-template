#include "MY_PERIPHERAL.h"
#include <iostream>

MY_PERIPHERAL::MY_PERIPHERAL() {
    /************************************************************************************
    TODO: Modify the following parameters for according to the peripheral's spec.
    ************************************************************************************/
    SpiSlaveConfig spi_config = {
            .mosi_pin_number = GetPinNumber("si"), .miso_pin_number = GetPinNumber("so"),
            .ss_pin_number = GetPinNumber("cs"), .sclk_pin_number = GetPinNumber("sck"),
            .supported_spi_modes = SPI_MODE_CPOL0_CPHA0 | SPI_MODE_CPOL0_CPHA1 | SPI_MODE_CPOL1_CPHA0 | SPI_MODE_CPOL1_CPHA1,
            .max_frequency = 5000000, .bit_order = MSB_FIRST
    };

    spi_slave_ = CreateSpiSlave(spi_config);    
}

void MY_PERIPHERAL::Main() {
    while (true) {
        // TODO: Add device logic here
    }
}

void MY_PERIPHERAL::Stop() {
    // TODO: (optional) Add logic for stopping the peripheral here. If not needed, leave this empty.
}

