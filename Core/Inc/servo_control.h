/*******************************************************************************
 * @file servo_control.h
 * @brief CAN driven servo control callbacks.
 *******************************************************************************
 */

#ifndef PWM_NODE__SERVO_CONTROL_H
#define PWM_NODE__SERVO_CONTROL_H

/** Includes. *****************************************************************/

#include "can.h"
#include "stm32l4xx_hal.h"

/** STM32 port and pin configs. ***********************************************/

extern TIM_HandleTypeDef htim2;

// PWM timer channel.
#define SERVOS_TIM htim2

/** Public variables. *********************************************************/

extern volatile uint32_t tim2_pwm[4];

/** Public functions. *********************************************************/

void servo_command_init(void);

void can_rx_servo_command(CAN_RxHeaderTypeDef *header, uint8_t *data);

#endif
