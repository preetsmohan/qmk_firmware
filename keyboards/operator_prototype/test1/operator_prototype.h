/* Copyright 2020 Duckle
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 fo the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "i2c_master.h"
#include <print.h>
#include "quantum.h"

#define I2C_ADDR        0x0A << 1
#define I2C_ADDR_WRITE  ( 0x0A << 1 | I2C_WRITE )
#define I2C_ADDR_READ   ( 0x0A << 1 | I2C_READ  )
#define I2C_TIMEOUT 1000


//Trackball pin defs
#define TRKLEFT 0x04 // << 1
#define TRKRIGHT 0x05 // << 1
#define TRKUP 0x06 // << 1
#define TRKDOWN 0x07 // << 1
#define TRKBTN 0x08 // << 1

uint8_t init_trackball(void);

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT(K00) \
{{K00}}

