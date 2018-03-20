
#ifndef JEMU_IDATAGENERATOR1_H
#define JEMU_IDATAGENERATOR1_H

#include <cstdint>
class iDataGeneratorV1 {
  public:
    virtual int32_t GetNextInt32() = 0;
    virtual double GetNextDouble() = 0;
    virtual int16_t GetNextInt16() = 0;
    virtual uint8_t GetNextUInt8() = 0;
    virtual double GetCachedValue() = 0;
};
#endif //JEMU_IDATAGENERATOR1_H
