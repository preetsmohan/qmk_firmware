#include "matrix.h"
#include <stdint.h>
#include <stdbool.h>
#include "wait.h"
#include "action_layer.h"
#include <print.h>
#include "debug.h"
#include "util.h"
#include QMK_KEYBOARD_H
#include "pointing_device.h"


bool i2c_initialized = 0;
i2c_status_t trackball_status = 0x0A;

__attribute__ ((weak)) matrix_row_t read_cols(uint8_t row);
__attribute__ ((weak)) void         init_cols(void);
__attribute__ ((weak)) void         unselect_rows(void);
__attribute__ ((weak)) void         select_row(uint8_t row);
__attribute__ ((weak)) void enableInterrupts(void);

__attribute__ ((weak)) void matrix_init_user(void) {}

__attribute__ ((weak)) void matrix_scan_user(void) {}

__attribute__ ((weak))
void matrix_init_kb(void) {
  matrix_init_user();
}

__attribute__ ((weak))
void matrix_scan_kb(void) {
  matrix_scan_user();
}

uint8_t init_trackball(void) {
    print("starting init");
    trackball_status = 0x0A;
    
    if (i2c_initialized == 0) {
        i2c_init();  // on pins D(1,0)
        i2c_initialized = true;
        _delay_ms(1000);
    }

    trackball_status = i2c_start(I2C_ADDR_WRITE);
    uprintf("%u string", trackball_status);
    i2c_stop();
    return trackball_status;
}
