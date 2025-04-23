/*******************************************************************************
 * @file servo_control.c
 * @brief CAN driven servo control callbacks.
 *******************************************************************************
 */

/** Includes. *****************************************************************/

#include "servo_control.h"
#include "can_pwm_node.h"
#include "stm32l4xx_hal_tim.h"

/** Public variables. *********************************************************/

volatile uint32_t tim2_pwm[4] = {0, 0, 0, 0};

/** Public functions. *********************************************************/

void servo_command_init(void) {
  HAL_TIM_PWM_Init(&SERVOS_TIM);

  HAL_TIM_DMABurst_WriteStart(&SERVOS_TIM, TIM_DMABASE_CCR1, TIM_DMA_UPDATE,
                              (uint32_t *)tim2_pwm,
                              TIM_DMABURSTLENGTH_4TRANSFERS);

  HAL_TIM_PWM_Start(&SERVOS_TIM, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&SERVOS_TIM, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&SERVOS_TIM, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&SERVOS_TIM, TIM_CHANNEL_4);
}

void can_rx_servo_command(CAN_RxHeaderTypeDef *header, uint8_t *data) {
  for (int i = 0; i < 4; ++i) {
    tim2_pwm[i] = ((uint32_t)data[i * 2]) | ((uint32_t)data[(i * 2) + 1] << 8);
  }

  // TODO: WIP LOOPBACK CAN CONFIRM:
  can_message_t command_msg = dbc_messages[1];
  const uint32_t sigs[4] = {tim2_pwm[0], tim2_pwm[1], tim2_pwm[2], tim2_pwm[3]};
  can_send_message_raw32(&hcan1, &command_msg, sigs);
}
