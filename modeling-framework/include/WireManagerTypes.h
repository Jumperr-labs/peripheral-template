#pragma once

#include <cstdint>
#include <vector>
#include <functional>

typedef enum {
    FALLING = 0,
    RISING = 1
} transition_type_t;

typedef enum {
    DIRECTION_IN,
    DIRECTION_OUT,
    UNDEFINED
} pin_direction_t;

typedef enum {
    DISABLED = 0,
    PULL_DOWN = 1,
    PULL_UP = 3
} pin_pullup_t;

/*
 * PinChangeEvent used to send event by PinManager and should
 * be changed only if GPIO tests are changing accordingly
 * */

typedef struct {
    transition_type_t type;
    uint32_t wire_number;
    uint32_t pin_number;
    double voltage;
} WireLogicLevelEvent;

typedef struct {
    uint32_t length;
    uint8_t *data;
    uint32_t wire_number;
    uint32_t pin_number;
} WireDataEvent;

typedef struct {
    bool is_level_high;
    double voltage;
    uint32_t wire_number;
} ConstWireState;


struct WireChange{
    WireChange() = default;
    WireChange(uint32_t wire_number, bool level_is_high, uint32_t pin_number) :
        wire_number_(wire_number),
        level_is_high_(level_is_high),
        pin_number_(pin_number) {}

  uint32_t wire_number_{0};
  bool level_is_high_{false};
  uint32_t pin_number_{0};
};

typedef std::vector<WireChange> pin_level_changes_t;
typedef std::vector<WireLogicLevelEvent> WireLogicLevelEventVector_t;
typedef std::function<void(WireLogicLevelEventVector_t& notifications )> pin_change_level_callback_t;

struct PinChangeLevelEventCallback {
    PinChangeLevelEventCallback(const pin_change_level_callback_t& pin_change_level_callback) :
        pin_change_level_callback_(pin_change_level_callback){}

    void operator()(WireLogicLevelEvent* arr, size_t size) {
        WireLogicLevelEventVector_t vec;
        std::copy(arr, arr + size, std::back_inserter(vec));
        pin_change_level_callback_(vec);
    }
    pin_change_level_callback_t pin_change_level_callback_;
};
