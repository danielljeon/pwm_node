# pwm_node

![arm_gcc_build](https://github.com/danielljeon/pwm_node/actions/workflows/arm_gcc_build.yaml/badge.svg)

PWM controller board designed for CAN-based control.

---

<details markdown="1">
  <summary>Table of Contents</summary>

<!-- TOC -->
* [pwm_node](#pwm_node)
  * [1 Overview](#1-overview)
    * [1.1 Bill of Materials (BOM)](#11-bill-of-materials-bom)
    * [1.2 Block Diagram](#12-block-diagram)
    * [1.3 Pin Configurations](#13-pin-configurations)
    * [1.4 Clock Configurations](#14-clock-configurations)
  * [2 TJA1051T/3 CAN Bus Transceiver](#2-tja1051t3-can-bus-transceiver)
  * [3 PWM Breakouts](#3-pwm-breakouts)
<!-- TOC -->

</details>

---

## 1 Overview

### 1.1 Bill of Materials (BOM)

| Manufacturer Part Number | Manufacturer       | Description         | Quantity | Notes |
|--------------------------|--------------------|---------------------|---------:|-------|
| STM32L432KC              | STMicroelectronics | 32-bit MCU          |        1 |       |
| TJA1051T/3               | NXP USA Inc.       | CAN Bus Transceiver |        1 |       |

### 1.2 Block Diagram

TODO.

### 1.3 Pin Configurations

<details markdown="1">
  <summary>CubeMX Pinout</summary>

![CubeMX Pinout.png](docs/CubeMX%20Pinout.png)

</details>

<details markdown="1">
  <summary>Pin & Peripherals Table</summary>

| STM32F446RE | Peripheral       | Config             | Connection                | Notes |
|-------------|------------------|--------------------|---------------------------|-------|
| PB3         | `SYS_JTDO-SWO`   |                    | TC2050 SWD Pin 6: `SWO`   |       |
| PA14        | `SYS_JTCK-SWCLK` |                    | TC2050 SWD Pin 4: `SWCLK` |       |
| PA13        | `SYS_JTMS-SWDIO` |                    | TC2050 SWD Pin 2: `SWDIO` |       |
| PA11        | `CAN1_RX`        |                    | TJA1051T/3 Pin 1: `TXD`   |       |
| PA12        | `CAN1_TX`        |                    | TJA1051T/3 Pin 4: `RXD`   |       |
| PA5         | `TIM2_CH1`       | PWM Generation CH1 | Breakout                  |       |
| PA1         | `TIM2_CH2`       | PWM Generation CH2 | Breakout                  |       |
| PA2         | `TIM2_CH3`       | PWM Generation CH3 | Breakout                  |       |
| PA3         | `TIM2_CH4`       | PWM Generation CH4 | Breakout                  |       |
| PB7         | `USART1_RX`      |                    | TBD                       |       |
| PB6         | `USART1_TX`      |                    | TBD                       |       |
| PA9         | `I2C1_SCL`       |                    | TBD                       |       |
| PA10        | `I2C1_SDA`       |                    | TBD                       |       |

</details>

### 1.4 Clock Configurations

```
8 MHz High Speed External (HSE)
↓
Phase-Locked Loop Main (PLLM)
↓
80 MHz SYSCLK
↓
80 MHz HCLK
↓
 → 80 MHz APB1 (Maxed) → 80 MHz APB1 Timer
 → 80 MHz APB2 (Maxed) → 80 MHz APB2 Timer
```

---

## 2 TJA1051T/3 CAN Bus Transceiver

Carry over from [nerve](https://github.com/danielljeon/nerve).

---

## 3 PWM Breakouts
