/****************************************************************************
http://retro.moe/unijoysticle2

Copyright 2019 Ricardo Quesada

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

#ifndef UNI_HID_PARSER_DS5_H
#define UNI_HID_PARSER_DS5_H

#include <stdint.h>

#include "uni_hid_parser.h"

// For DualSense gamepads
void uni_hid_parser_ds5_setup(struct uni_hid_device_s *d);
void uni_hid_parser_ds5_init_report(struct uni_hid_device_s *d);
void uni_hid_parser_ds5_parse_input_report(struct uni_hid_device_s *d, const uint8_t *report, uint16_t len);
void uni_hid_parser_ds5_parse_feature_report(struct uni_hid_device_s *d, const uint8_t *report, uint16_t len);
void uni_hid_parser_ds5_set_player_leds(struct uni_hid_device_s *d, uint8_t value);
void uni_hid_parser_ds5_set_lightbar_color(struct uni_hid_device_s *d, uint8_t r, uint8_t g, uint8_t b);
void uni_hid_parser_ds5_set_rumble(struct uni_hid_device_s *d, uint8_t value, uint8_t duration);
void uni_hid_parser_ds5_device_dump(struct uni_hid_device_s *d);
#endif // UNI_HID_PARSER_DS5_H