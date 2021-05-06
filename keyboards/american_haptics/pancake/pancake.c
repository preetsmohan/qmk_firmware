#include "pancake.h"

static uint16_t key_timer;

bool pressed = false;

uint8_t encoder_mode = ENC_MODE_MIN;
uint8_t layer_change = 0;

void matrix_init_kb(void) {
	matrix_init_user();
};

void encoder_update_kb(uint8_t index, bool clockwise) {
	switch (encoder_mode) {
		case 0: 
    		if (clockwise) {
    			if (pressed) { 
    				layer_change = 1; 
    			}
    			else {
    				tap_code(KC_VOLU);
    			} 
      	  		
   	 		} else {
   	 			if (pressed) { 
   	 				layer_change = -1; 
   	 			}
        		else {
        			tap_code(KC_VOLD);
        		} 
    		}
    		break;
    	case 1:
    		if (clockwise) {
    		 	if (pressed) { 
    		 		layer_change = 1; 
    		 	}
    		  	else {
    		  		tap_code(KC_PGDN);
    		  	} 
    		} else {
    		  if (pressed) { 
    		  	layer_change = -1; 
    		  }
    		  else {
    		  	tap_code(KC_PGUP);
    		  }
    		}
    		break;
    	default:
    		break;
	}
}

void dip_switch_update_kb(uint8_t index, bool active) { 
	// start time =
    switch (index) {
        case 0:		
        	if (active) { //pressed
				pressed = true;
				key_timer = timer_read();
			} 
			else { //released
				pressed = false;
				if (timer_elapsed(key_timer) < 100) {
					switch (encoder_mode) {
						case ENC_MODE_MIN:
							tap_code(KC_MEDIA_PLAY_PAUSE); 
							break;
						case ENC_MODE_MAX:
							tap_code(KC_BTN1); 
							break;
						default:
							break;
					}
				}
				else {
					if (layer_change == 0) {
                        if (encoder_mode == ENC_MODE_MAX) {
						  tap_code(KC_BTN3);
                        }
					}
					else {
						encoder_mode += layer_change;
                        if (encoder_mode < ENC_MODE_MIN) {
                            encoder_mode = ENC_MODE_MAX;
                        }
                        if (encoder_mode > ENC_MODE_MAX) {
                            encoder_mode = ENC_MODE_MIN;
                        }
						layer_change = 0;
					}
				}
			}

         	break;
    }
}



/*void keyboard_post_init_user(void) {
	setPinOutput(PD5);
    setPinInputHigh(PD5);
    print("hello");
}
*/