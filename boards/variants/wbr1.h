/* This file was auto-generated from wbr1.json using boardgen */

#pragma once

// clang-format off

// Pins
// ----
#define PINS_COUNT         12 // Total GPIO count
#define NUM_DIGITAL_PINS   12 // Digital inputs/outputs
#define NUM_ANALOG_INPUTS  0  // ADC inputs
#define NUM_ANALOG_OUTPUTS 12 // PWM & DAC outputs
#define PINS_GPIO_MAX      17 // Last usable GPIO number

// Wire Interfaces
// ---------------
#define PIN_WIRE0_SCL_0 2u  // PIN_A2
#define PIN_WIRE0_SCL_1 11u // PIN_A11
#define PIN_WIRE0_SCL_2 15u // PIN_A15
#define PIN_WIRE0_SDA_0 3u  // PIN_A3
#define PIN_WIRE0_SDA_1 16u // PIN_A16
#define PIN_WIRE0_SDA_2 12u // PIN_A12
#define PINS_WIRE0_SCL  (pin_size_t[]){2u, 11u, 15u}
#define PINS_WIRE0_SDA  (pin_size_t[]){3u, 16u, 12u}

// Serial ports
// ------------
#define PIN_SERIAL0_RX_0 13u // PIN_A13
#define PIN_SERIAL0_RX_1 12u // PIN_A12
#define PIN_SERIAL0_TX_0 14u // PIN_A14
#define PIN_SERIAL0_TX_1 11u // PIN_A11
#define PIN_SERIAL1_CTS  4u  // PIN_A4
#define PIN_SERIAL1_RX_0 2u  // PIN_A2
#define PIN_SERIAL1_RX_1 0u  // PIN_A0
#define PIN_SERIAL1_TX_0 3u  // PIN_A3
#define PIN_SERIAL1_TX_1 1u  // PIN_A1
#define PIN_SERIAL2_RX   15u // PIN_A15
#define PIN_SERIAL2_TX   16u // PIN_A16
#define PINS_SERIAL0_RX  (pin_size_t[]){13u, 12u}
#define PINS_SERIAL0_TX  (pin_size_t[]){14u, 11u}
#define PINS_SERIAL1_CTS (pin_size_t[]){4u}
#define PINS_SERIAL1_RX  (pin_size_t[]){2u, 0u}
#define PINS_SERIAL1_TX  (pin_size_t[]){3u, 1u}
#define PINS_SERIAL2_RX  (pin_size_t[]){15u}
#define PINS_SERIAL2_TX  (pin_size_t[]){16u}

// Pin function macros
// -------------------
#define PIN_CTS1  4u  // PIN_A4
#define PIN_MOSI0 4u  // PIN_A4
#define PIN_PA00  0u  // PIN_A0
#define PIN_PA01  1u  // PIN_A1
#define PIN_PA02  2u  // PIN_A2
#define PIN_PA03  3u  // PIN_A3
#define PIN_PA04  4u  // PIN_A4
#define PIN_PA11  11u // PIN_A11
#define PIN_PA12  12u // PIN_A12
#define PIN_PA13  13u // PIN_A13
#define PIN_PA14  14u // PIN_A14
#define PIN_PA15  15u // PIN_A15
#define PIN_PA16  16u // PIN_A16
#define PIN_PA17  17u // PIN_A17
#define PIN_PWM5  17u // PIN_A17
#define PIN_PWM7  13u // PIN_A13
#define PIN_RX2   15u // PIN_A15
#define PIN_SCL0  15u // PIN_A15
#define PIN_SDA0  12u // PIN_A12
#define PIN_TX2   16u // PIN_A16

// Port availability
// -----------------
#define HAS_SERIAL0             1
#define HAS_SERIAL1             1
#define HAS_SERIAL2             1
#define HAS_WIRE0               1
#define SERIAL_INTERFACES_COUNT 3
#define WIRE_INTERFACES_COUNT   1

// Arduino pin names
// -----------------
#define PIN_D0  14u // PIN_A14
#define PIN_D1  13u // PIN_A13
#define PIN_D2  2u  // PIN_A2
#define PIN_D3  3u  // PIN_A3
#define PIN_D4  16u // PIN_A16
#define PIN_D5  4u  // PIN_A4
#define PIN_D6  11u // PIN_A11
#define PIN_D7  15u // PIN_A15
#define PIN_D8  12u // PIN_A12
#define PIN_D9  17u // PIN_A17
#define PIN_D10 0u  // PIN_A0
#define PIN_D11 1u  // PIN_A1

// Static pin names
// ----------------
static const unsigned char D0 = PIN_D0;
static const unsigned char D1 = PIN_D1;
static const unsigned char D2 = PIN_D2;
static const unsigned char D3 = PIN_D3;
static const unsigned char D4 = PIN_D4;
static const unsigned char D5 = PIN_D5;
static const unsigned char D6 = PIN_D6;
static const unsigned char D7 = PIN_D7;
static const unsigned char D8 = PIN_D8;
static const unsigned char D9 = PIN_D9;
static const unsigned char D10 = PIN_D10;
static const unsigned char D11 = PIN_D11;
