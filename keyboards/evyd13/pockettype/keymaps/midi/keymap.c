/* Copyright 2019 Maarten Dekkers <maartenwut@gmail.com>
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _MIDI 0 //Main layer

extern keymap_config_t keymap_config;

uint16_t chord = 0;

enum {
    TD_C1_LAYER,
    MAJOR = SAFE_RANGE,
    MINOR,
    MAJ7,
    MIN7,
    MAJADD9,
    MINADD9,
    SUS2,
    SUS4
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
    switch (keycode) {
      case MI_C_1 ... MI_C_5:
          if(chord > 0) {
               if (chord == MAJOR) {
                  if (record->event.pressed) {
                      //process_midi_basic_noteon(keycode);
                      process_midi_basic_noteon(midi_compute_note(keycode) + 4);
                      process_midi_basic_noteon(midi_compute_note(keycode) + 7);
                  } else {
                      process_midi_all_notes_off();
                      process_midi_basic_noteoff(midi_compute_note(keycode) + 4);
                      process_midi_basic_noteoff(midi_compute_note(keycode) + 7);
                  }
                }
                if (chord == MINOR) { 
                    if (record->event.pressed) {
                        //process_midi_basic_noteon(keycode);
                        process_midi_basic_noteon(midi_compute_note(keycode) + 3);
                        process_midi_basic_noteon(midi_compute_note(keycode) + 7);
                    } else {
                      process_midi_basic_noteoff(midi_compute_note(keycode) + 3);
                      process_midi_basic_noteoff(midi_compute_note(keycode) + 7);
                      process_midi_all_notes_off();
                    
                    }
                  }
                if (chord == MAJ7) {
                  if (record->event.pressed) {
                      process_midi_basic_noteon(midi_compute_note(keycode) + 4);
                      process_midi_basic_noteon(midi_compute_note(keycode) + 7);
                      process_midi_basic_noteon(midi_compute_note(keycode) + 11);
                  } else {
                     process_midi_all_notes_off();
                     process_midi_basic_noteoff(midi_compute_note(keycode) + 4);
                      process_midi_basic_noteoff(midi_compute_note(keycode) + 7);
                      process_midi_basic_noteoff(midi_compute_note(keycode) + 11);

                 }
                }
                if (chord == MIN7) { 
                    if (record->event.pressed) {
                        //process_midi_basic_noteon(keycode);
                        process_midi_basic_noteon(midi_compute_note(keycode) + 3);
                        process_midi_basic_noteon(midi_compute_note(keycode) + 7);
                        process_midi_basic_noteon(midi_compute_note(keycode) + 10);
                    } else {
                     process_midi_all_notes_off();  
                     process_midi_basic_noteoff(midi_compute_note(keycode) + 3);
                        process_midi_basic_noteoff(midi_compute_note(keycode) + 7);
                        process_midi_basic_noteoff(midi_compute_note(keycode) + 10);                  
                    }
                  }
                if (chord == MAJADD9) {
                  if (record->event.pressed) {
                      process_midi_basic_noteon(midi_compute_note(keycode) + 4);
                      process_midi_basic_noteon(midi_compute_note(keycode) + 7);
                      process_midi_basic_noteon(midi_compute_note(keycode) + 14);
                  } else {
                      process_midi_all_notes_off();
                       process_midi_basic_noteoff(midi_compute_note(keycode) + 4);
                      process_midi_basic_noteoff(midi_compute_note(keycode) + 7);
                      process_midi_basic_noteoff(midi_compute_note(keycode) + 14);
                 }
                }
                if (chord == MINADD9) { 
                    if (record->event.pressed) {
                        //process_midi_basic_noteon(keycode);
                        process_midi_basic_noteon(midi_compute_note(keycode) + 3);
                        process_midi_basic_noteon(midi_compute_note(keycode) + 7);
                        process_midi_basic_noteon(midi_compute_note(keycode) + 14);
                    } else {
                      process_midi_all_notes_off();            
                      process_midi_basic_noteoff(midi_compute_note(keycode) + 3);
                        process_midi_basic_noteoff(midi_compute_note(keycode) + 7);
                        process_midi_basic_noteoff(midi_compute_note(keycode) + 14);      
                    }
                  }
                  if (chord == SUS2) { 
                    if (record->event.pressed) {
                        //process_midi_basic_noteon(keycode);
                        process_midi_basic_noteon(midi_compute_note(keycode) + 2);
                        process_midi_basic_noteon(midi_compute_note(keycode) + 7);

                    } else {
                      process_midi_all_notes_off();
                      process_midi_basic_noteoff(midi_compute_note(keycode) + 2);
                        process_midi_basic_noteoff(midi_compute_note(keycode) + 7);
                    
                    }
                  }
                  if (chord == SUS4) { 
                    if (record->event.pressed) {
                        //process_midi_basic_noteon(keycode);
                        process_midi_basic_noteon(midi_compute_note(keycode) + 5);
                        process_midi_basic_noteon(midi_compute_note(keycode) + 7);
                    } else {
                      process_midi_all_notes_off();
                      process_midi_basic_noteoff(midi_compute_note(keycode) + 5);
                       process_midi_basic_noteoff(midi_compute_note(keycode) + 7);
                  
                    }
                  }                 
               }
          if (!record->event.pressed) {
            process_midi_basic_noteoff(midi_compute_note(keycode));
          }
          break;
      case MAJOR:
          chord = MAJOR;
          if (record->event.pressed) {
              chord = MAJOR;
          } else {
              chord = 0;
              process_midi_all_notes_off();
          }
          break;
      case MINOR:
          if (record->event.pressed) {
              chord = MINOR;
          } else {
              chord = 0;
              process_midi_all_notes_off();
          }
          break;
      case MAJ7:
          if (record->event.pressed) {
              chord = MAJ7;
          } else {
              chord = 0;
              process_midi_all_notes_off();
          }
          break;
      case MIN7:
          if (record->event.pressed) {
              chord = MIN7;
          } else {
              chord = 0;
              process_midi_all_notes_off();
          }
          break;
      case MAJADD9:
          if (record->event.pressed) {
              chord = MAJADD9;
          } else {
              chord = 0;
              process_midi_all_notes_off();
          }
          break;
      case MINADD9:
          if (record->event.pressed) {
              chord = MINADD9;
          } else {
              chord = 0;
              process_midi_all_notes_off();
          }
          break;
      case SUS2:
          if (record->event.pressed) {
              chord = SUS2;
          } else {
              chord = 0;
              process_midi_all_notes_off();
          }
          break;
      case SUS4:
          if (record->event.pressed) {
              chord = SUS4;
          } else {
              chord = 0;
              process_midi_all_notes_off();
          }
          break;
      }
    return true;
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_C1_LAYER] = ACTION_TAP_DANCE_DOUBLE(MI_C_1, TO(_MIDI)),
};
  
  #if defined(MIDI_ENABLE) && defined(MIDI_ADVANCED)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_MIDI] = LAYOUT_ortho_4x12(
      TO(1), MI_TRNSD, MI_TRNSU,  MI_TRNS_0, MI_C_4, MI_D_4, MI_E_4, MI_F_4, MI_G_4, MI_A_4, MI_B_4, MI_C_5,
      MI_OCTD, MI_OCTU, MI_MODSD, MI_MODSU, MI_C_3, MI_D_3, MI_E_3, MI_F_3, MI_G_3, MI_A_3, MI_B_3, MI_C_4,
      MAJOR, MAJ7, MAJADD9, SUS2, MI_C_2, MI_D_2, MI_E_2, MI_F_2, MI_G_2, MI_A_2, MI_B_2, MI_C_3,
      MINOR, MIN7, MINADD9, SUS4, MI_C_1, MI_D_1, MI_E_1, MI_F_1, MI_G_1, MI_A_1, MI_B_1, MI_C_2),

[1] = LAYOUT_ortho_4x12(
      MI_C_4, MI_Cs_4, MI_D_4, MI_Ds_4, MI_E_4, MI_F_4, MI_Fs_4, MI_G_4, MI_Gs_4, MI_A_4, MI_As_4, TO(0),
      MI_C_3, MI_Cs_3, MI_D_3, MI_Ds_3, MI_E_3, MI_F_3, MI_Fs_3, MI_G_3, MI_Gs_3, MI_A_3, MI_As_3, MI_B_3,
      MI_C_2, MI_Cs_2, MI_D_2, MI_Ds_2, MI_E_2, MI_F_2, MI_Fs_2, MI_G_2, MI_Gs_2, MI_A_2, MI_As_2, MI_B_2,
      MI_C_1, MI_Cs_1, MI_D_1, MI_Ds_1, MI_E_1, MI_F_1, MI_Fs_1, MI_G_1, MI_Gs_1, MI_A_1, MI_As_1, MI_B_1)
  #endif
};
