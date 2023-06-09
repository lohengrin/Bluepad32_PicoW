/****************************************************************************
http://retro.moe/unijoysticle2

Copyright 2021 Ricardo Quesada

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
****************************************************************************/

#ifndef UNI_PLATFORM_PICO_H
#define UNI_PLATFORM_PICO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "uni_common.h"
#include "uni_gamepad.h"
#include "uni_platform.h"

enum {
    UNI_PICO_OK = 0,
    UNI_PICO_ERROR = -1,
};

enum {
    UNI_PICO_GAMEPAD_INVALID = -1,
};

enum {
    PICO_PROPERTY_FLAG_RUMBLE = BIT(0),
    PICO_PROPERTY_FLAG_PLAYER_LEDS = BIT(1),
    PICO_PROPERTY_FLAG_PLAYER_LIGHTBAR = BIT(2),
};

typedef uni_controller_t pico_controller_data_t;
typedef uni_gamepad_t pico_gamepad_data_t;

typedef struct {
    uint8_t btaddr[6];    // BT Addr
    uint8_t type;         // Gamepad model: PS3, PS4, Switch, etc.
    uint8_t subtype;      // subtype. E.g: Wii Remote 2nd version
    uint16_t vendor_id;   // VID
    uint16_t product_id;  // PID
    uint16_t flags;       // Features like Rumble, LEDs, etc.
} pico_controller_properties_t;
typedef pico_controller_properties_t pico_gamepad_properties_t;

typedef struct {
    int8_t idx;  // Gamepad index
    pico_controller_data_t data;

    // TODO: To reduce RAM, the properties should be calculated at "request time", and
    // not store them "forever".
    pico_controller_properties_t properties;
} pico_controller_t;

struct uni_platform* uni_platform_pico_create(void);

// Deprecated: Call pico_get_controller_data() instead.
int pico_get_gamepad_data(int idx, pico_gamepad_data_t* out_data);
int pico_get_controller_data(int idx, pico_controller_data_t* out_data);
// Deprecated: Call pico_get_controller_properties () instead.
int pico_get_gamepad_properties(int idx, pico_gamepad_properties_t* out_properties);
int pico_get_controller_properties(int idx, pico_gamepad_properties_t* out_properties);
int pico_set_player_leds(int idx, uint8_t leds);
int pico_set_lightbar_color(int idx, uint8_t r, uint8_t g, uint8_t b);
int pico_set_rumble(int idx, uint8_t force, uint8_t duration);
int pico_forget_bluetooth_keys(void);

#ifdef __cplusplus
}
#endif

#endif  // UNI_PLATFORM_PICO_H
