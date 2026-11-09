/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software. You can redistribute this software
 * and/or modify this software under the terms of the GNU General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later
 * version.
 *
 * Betaflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define FC_TARGET_MCU     STM32H723

#define BOARD_NAME        YUME_MINI_H723
#define MANUFACTURER_ID   CUST

#define SYSTEM_HSE_MHZ    8

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACCGYRO_IIM42652
#define USE_BARO
// SPL06-001 is register-compatible with the DPS310 driver.
#define USE_BARO_DPS310
#define USE_SDCARD
#define USE_SDCARD_SPI
// External I2C compass; common_post.h enables the supported drivers.
#define USE_MAG

// Basic I/O
#define LED0_PIN             PE5
#define LED1_PIN             PE6
#define BEEPER_PIN           PE2
#define LED_STRIP_PIN        PE9
#define USB_DETECT_PIN       PE10
#define ESCSERIAL_PIN        PC7

// Motor outputs S1-S8
#define MOTOR1_PIN           PA3
#define MOTOR2_PIN           PA2
#define MOTOR3_PIN           PA1
#define MOTOR4_PIN           PA0
#define MOTOR5_PIN           PD13
#define MOTOR6_PIN           PD12
#define MOTOR7_PIN           PD14
#define MOTOR8_PIN           PD15

// Servo and camera control outputs
#define SERVO1_PIN           PC8  // SE1
// #define SERVO2_PIN        PC9  // SE2 is used for Camera Control
#define CAMERA_CONTROL_PIN   PC9  // SE2

// UART
#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10
#define UART2_TX_PIN         PD5
#define UART2_RX_PIN         PD6
#define UART3_TX_PIN         PD8
#define UART3_RX_PIN         PD9
#define UART4_TX_PIN         PD1
#define UART4_RX_PIN         PD0
#define UART5_TX_PIN         PC12
#define UART5_RX_PIN         PD2
#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7
#define UART7_TX_PIN         PE8
#define UART7_RX_PIN         PE7
#define UART8_TX_PIN         PE1
#define UART8_RX_PIN         PE0
// UART1: serial receiver; UART2: MSP DisplayPort at the default 115200 baud.
#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL
#define SERIALRX_UART           SERIAL_PORT_USART1
#define MSP_DISPLAYPORT_UART    SERIAL_PORT_USART2

// I2C1: SPL06-001 barometer, SDO pulled low (address 0x76)
#define USE_I2C_PULLUP
#define I2C1_SCL_PIN         PB6
#define I2C1_SDA_PIN         PB7
#define BARO_I2C_INSTANCE    I2CDEV_1

// I2C2: external connector
#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11
#define MAG_I2C_INSTANCE     I2CDEV_2

// ADC
#define ADC_VBAT_PIN         PC1
#define ADC_CURR_PIN         PC3
#define ADC_RSSI_PIN         PC2
#define ADC_EXTERNAL1_PIN    PC0
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC

// Gyro 1: ICM-42688-P / IIM-42652 on SPI1, facing board forward
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
#define GYRO_1_CS_PIN        PA4
#define GYRO_1_EXTI_PIN      PC4
#define GYRO_1_SPI_INSTANCE  SPI1
#define GYRO_1_ALIGN         CW0_DEG

// Gyro 2: ICM-42688-P / IIM-42652 on SPI4, facing board left
#define SPI4_SCK_PIN         PE12
#define SPI4_SDI_PIN         PE13
#define SPI4_SDO_PIN         PE14
#define GYRO_2_CS_PIN        PE11
#define GYRO_2_EXTI_PIN      PE15
#define GYRO_2_SPI_INSTANCE  SPI4
#define GYRO_2_ALIGN         CW270_DEG
#define DEFAULT_GYRO_TO_USE  GYRO_CONFIG_USE_GYRO_BOTH

// Both gyro CLKIN pins are wired to PB9. The ICM-42688-P uses this
// external clock; the IIM-42652 driver currently uses its internal clock.
#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN     PB9
#define GYRO_2_CLKIN_PIN     PB9

// SD NAND on SPI3
#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PB2
#define SDCARD_SPI_CS_PIN    PA15
#define SDCARD_SPI_INSTANCE  SPI3
#define SDCARD_DETECT_PIN    NONE
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_SDCARD

// User-switchable outputs
#define PINIO1_PIN           PC5
#define PINIO2_PIN           PB1
#define PINIO1_BOX           40
#define PINIO2_BOX           41

// CAN2 test pads. Enable the DroneCAN feature separately when required.
#define CAN2_TX_PIN          PB13
#define CAN2_RX_PIN          PB12

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PA3 , 1,  0) \
    TIMER_PIN_MAP( 1, PA2 , 1,  1) \
    TIMER_PIN_MAP( 2, PA1 , 1,  2) \
    TIMER_PIN_MAP( 3, PA0 , 1,  3) \
    TIMER_PIN_MAP( 4, PD13, 1,  4) \
    TIMER_PIN_MAP( 5, PD12, 1,  5) \
    TIMER_PIN_MAP( 6, PD14, 1,  6) \
    TIMER_PIN_MAP( 7, PD15, 1,  7) \
    TIMER_PIN_MAP( 8, PE9 , 1,  8) \
    TIMER_PIN_MAP( 9, PB9 , 1, -1) \
    TIMER_PIN_MAP(10, SERVO1_PIN, 2, -1) \
    TIMER_PIN_MAP(11, CAMERA_CONTROL_PIN, 1, -1)

#define ADC1_DMA_OPT        9
#define ADC3_DMA_OPT        10

#define DEFAULT_DSHOT_BITBANG DSHOT_BITBANG_ON

// TODO: Calibrate voltage/current meters and verify both gyro axes on
// hardware before flight. Both gyros are enabled by default.
