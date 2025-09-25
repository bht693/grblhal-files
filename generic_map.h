/*
  generic_map.h - driver code for ESP32

  Part of grblHAL

  Copyright (c) 2020-2023 Terje Io

  grblHAL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grblHAL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grblHAL. If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 0
#error "Axis configuration is not supported!"
#endif

#if VFD_SPINDLE
#error "Generic map does not have support for VFD spindle."
#endif

#if KEYPAD_ENABLE == 1
#error No free pins for I2C keypad!
#endif

// Define step pulse output pins.
#define X_STEP_PIN              GPIO_NUM_12
#define Y_STEP_PIN              GPIO_NUM_14
#define Z_STEP_PIN              GPIO_NUM_27

// Define step direction output pins. NOTE: All direction pins must be on the same port.
#define X_DIRECTION_PIN         GPIO_NUM_26
#define Y_DIRECTION_PIN         GPIO_NUM_25
#define Z_DIRECTION_PIN         GPIO_NUM_33

// Define stepper driver enable/disable output pin(s).
#define STEPPERS_ENABLE_PIN     GPIO_NUM_13

// Define homing/hard limit switch input pins and limit interrupt vectors.
#define X_LIMIT_PIN             GPIO_NUM_2
#define Y_LIMIT_PIN             GPIO_NUM_4
#define Z_LIMIT_PIN             GPIO_NUM_15

#define AUXOUTPUT0_PIN          GPIO_NUM_17 // Spindle PWM
#define AUXOUTPUT1_PIN          GPIO_NUM_18 // Spindle enable
#define AUXOUTPUT2_PIN          GPIO_NUM_5  // Spindle direction
#define AUXOUTPUT3_PIN          GPIO_NUM_16 // Coolant flood
#define AUXOUTPUT4_PIN          GPIO_NUM_21 // Coolant mist

// Define driver spindle pins
#if DRIVER_SPINDLE_ENABLE & SPINDLE_PWM
#define SPINDLE_PWM_PIN         AUXOUTPUT0_PIN
#endif
#if DRIVER_SPINDLE_ENABLE & SPINDLE_DIR
#define SPINDLE_DIRECTION_PIN   AUXOUTPUT2_PIN
#endif
#if DRIVER_SPINDLE_ENABLE & SPINDLE_ENA
#define SPINDLE_ENABLE_PIN      AUXOUTPUT1_PIN
#endif

// Define flood and mist coolant enable output pins.
#if COOLANT_ENABLE & COOLANT_FLOOD
#define COOLANT_FLOOD_PIN       AUXOUTPUT3_PIN
#endif
#if COOLANT_ENABLE & COOLANT_MIST
#define COOLANT_MIST_PIN        AUXOUTPUT4_PIN
#endif

#define AUXINPUT0_PIN           GPIO_NUM_35
#define AUXINPUT1_PIN           GPIO_NUM_32
#define AUXINPUT2_PIN           GPIO_NUM_34 // Reset/EStop
#define AUXINPUT3_PIN           GPIO_NUM_36 // Feed hold
#define AUXINPUT4_PIN           GPIO_NUM_39 // Cycle start

// Define user-control controls (cycle start, reset, feed hold) input pins.
#if CONTROL_ENABLE & CONTROL_HALT
#define RESET_PIN               AUXINPUT2_PIN
#endif
#if CONTROL_ENABLE & CONTROL_FEED_HOLD
#define FEED_HOLD_PIN           AUXINPUT3_PIN
#endif
#if CONTROL_ENABLE & CONTROL_CYCLE_START
#define CYCLE_START_PIN         AUXINPUT4_PIN
#endif

#if PROBE_ENABLE
#define PROBE_PIN               AUXINPUT1_PIN
#endif

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PIN         AUXINPUT0_PIN
#endif

#if I2C_ENABLE
// Define I2C port/pins
#define I2C_PORT                I2C_NUM_1
#define I2C_SDA                 GPIO_NUM_21
#define I2C_SCL                 GPIO_NUM_22
#define I2C_CLOCK               100000
#endif

#if SDCARD_ENABLE
// Pin mapping when using SPI mode.
// With this mapping, SD card can be used both in SPI and 1-line SD mode.
// Note that a pull-up on CS line is required in SD mode.
#define PIN_NUM_MISO            GPIO_NUM_19
#define PIN_NUM_MOSI            GPIO_NUM_23
#define PIN_NUM_CLK             GPIO_NUM_18
#define PIN_NUM_CS              GPIO_NUM_5
#endif
