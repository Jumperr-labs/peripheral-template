#include "MY_PERIPHERAL.h"
#include <iostream>

MY_PERIPHERAL::MY_PERIPHERAL() {
    /************************************************************************************
    TODO: Modify the following address according to the peripheral's spec.
    ************************************************************************************/
    i2c_slave_ = CreateI2cSlave();
    i2c_slave_->SetSlaveAddress(device_address_, 0x7F);
    i2c_slave_->SetMasterReadCommandCallback(std::bind(&MY_PERIPHERAL::OnMasterRead,this,std::placeholders::_1, std::placeholders::_2));
    i2c_slave_->SetMasterWriteCommandCallback(std::bind(&MY_PERIPHERAL::OnMasterWrite,this,std::placeholders::_1, std::placeholders::_2));
}

void MY_PERIPHERAL::Main() {
    while (true) {
        // TODO: Add device logic here
    }
}

void MY_PERIPHERAL::Stop() {
    // TODO: (optional) Add logic for stopping the peripheral here. If not needed, leave this empty.
}

void MY_PERIPHERAL::OnMasterRead(uint8_t device_address, iI2cSlaveBaseWriteStream& i2c_slave_write_stream) {
     // TODO: Add your logic here
     // Basic example

    // uint8_t value_to_send_to_master = 2;
    // i2c_slave_write_stream.Write(&value_to_send_to_master, 1);
}

void MY_PERIPHERAL::OnMasterWrite(uint8_t device_address, iI2cSlaveBaseReadStream& i2c_slave_read_stream) {
    // TODO: Add your logic here
    // Basic example

    // uint8_t value;
    // while (!i2c_slave_read_stream.ReceivedStop()) {
    //      number_of_byte_recevied_from_master = i2c_slave_read_stream.ReadAndSendAck(&value, 1);
    //      if (number_of_byte_recevied_from_master < 1) {
    //          return;
    //      }
    //    std::cout << "Byte read from master: " << value << std::endl;
    // }
}