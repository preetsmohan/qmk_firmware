/* Copyright 2020 Duckle
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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
#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"
#include "process_midi.h"
#include "qmk_midi.h"

extern keymap_config_t keymap_config;

bool i2c_is_init = 0;
i2c_status_t i2c_stats = 0x0A;

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(KC_ESC)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void matrix_init_user(void) {
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    print("scanning i2c");
    i2c_stats = 0x0A;
    
    if (i2c_is_init == 0) {
        i2c_init();  // on pins D(1,0)
        i2c_is_init = true;
        _delay_ms(1000);
    }
   uint8_t data[5];
    i2c_stats = i2c_start(I2C_ADDR_WRITE, I2C_TIMEOUT); //0x0A << 1, 1000
    i2c_stats = i2c_write(TRKLEFT, I2C_TIMEOUT);  
    i2c_stats = i2c_start(I2C_ADDR_READ, I2C_TIMEOUT);
    i2c_stats = i2c_receive(I2C_ADDR, data, 5, I2C_TIMEOUT);
    uprintf("I2C: %u\n", data);
    i2c_stop();
};