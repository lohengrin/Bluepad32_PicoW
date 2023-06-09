// SPDX-License-Identifier: Apache-2.0
// Copyright 2022 Ricardo Quesada
// http://retro.moe/unijoysticle2

#include "uni_log.h"

#include <stdarg.h>

#include "sdkconfig.h"
#include "uni_config.h"

#if !(defined(CONFIG_BLUEPAD32_PLATFORM_PC_DEBUG) || defined(CONFIG_BLUEPAD32_PLATFORM_PICO))
#include <esp_log.h>
#endif  // !CONFIG_BLUEPAD32_PLATFORM_PC_DEBUG

void uni_log(const char* format, ...) {
    va_list args;

    va_start(args, format);
    uni_logv(format, args);
    va_end(args);
}

void uni_logv(const char* format, va_list args) {
#if defined(CONFIG_BLUEPAD32_PLATFORM_PC_DEBUG) || defined(CONFIG_BLUEPAD32_PLATFORM_PICO)
    vfprintf(stderr, format, args);
#else
    esp_log_writev(ESP_LOG_WARN, "bp32", format, args);
#endif  // ! UNI_PLATFORM_PC_DEBUG
}