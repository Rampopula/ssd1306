/*
    MIT License

    Copyright (c) 2018, Alexey Dynda

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

/**
 * @file ssd1306_hal/io.h SSD1306 HAL IO communication functions
 */

#ifndef _SSD1306_HAL_IO_H_
#define _SSD1306_HAL_IO_H_

#include "UserSettings.h"
#if defined(ARDUINO)
#include "arduino/io.h"
#elif defined(__AVR__) && !defined(ARDUINO)
#include "avr/io.h"
#elif defined(__XTENSA__) && !defined(ARDUINO)
#include "esp/io.h"
#elif defined(STM32F1) || defined(STM32F2)
#include "stm32/io.h"
#elif defined(__linux__)
#include "linux/io.h"
#elif defined(__MINGW32__)
#include "mingw/io.h"
#else
#warning "Platform is not supported. Use template to add support"
#include "template/io.h"
#endif

#ifndef LCDINT_TYPES_DEFINED
/** Macro informs if lcdint_t type is defined */
#define LCDINT_TYPES_DEFINED
/** internal int type, used by ssd1306 library. Important for uC with low SRAM */
typedef int lcdint_t;
/** internal int type, used by ssd1306 library. Important for uC with low SRAM */
typedef unsigned int lcduint_t;
#endif

/** swaps content of a and b variables of type type */
#define ssd1306_swap_data(a, b, type)  { type t = a; a = b; b = t; }

#endif


