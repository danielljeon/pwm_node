/** Auto-generated CAN message definitions from DBC file. */

#include "can_pwm_node.h"
#include "servo_control.h"

const can_message_t dbc_messages[] = {
    {
        .name = "state",
        .message_id = 257,
        .id_mask = 0xFFFFFFFF,
        .dlc = 1,
        .rx_handler = 0,
        .tx_handler = 0,
        .signal_count = 1,
        .signals =
            {
                {
                    .name = "system_state",
                    .start_bit = 0,
                    .bit_length = 8,
                    .byte_order = CAN_LITTLE_ENDIAN,
                    .scale = 1.0f,
                    .offset = 0.0f,
                    .min_value = 0.0f,
                    .max_value = 255.0f,
                },
            },
    },
    {
        .name = "command_a",
        .message_id = 513,
        .id_mask = 0xFFFFFFFF,
        .dlc = 8,
        .rx_handler = (can_rx_handler_t)can_rx_servo_command,
        .tx_handler = 0,
        .signal_count = 4,
        .signals =
            {
                {
                    .name = "command_u16_0",
                    .start_bit = 0,
                    .bit_length = 16,
                    .byte_order = CAN_LITTLE_ENDIAN,
                    .scale = 1.0f,
                    .offset = 0.0f,
                    .min_value = 0.0f,
                    .max_value = 65535.0f,
                },
                {
                    .name = "command_u16_1",
                    .start_bit = 16,
                    .bit_length = 16,
                    .byte_order = CAN_LITTLE_ENDIAN,
                    .scale = 1.0f,
                    .offset = 0.0f,
                    .min_value = 0.0f,
                    .max_value = 65535.0f,
                },
                {
                    .name = "command_u16_2",
                    .start_bit = 32,
                    .bit_length = 16,
                    .byte_order = CAN_LITTLE_ENDIAN,
                    .scale = 1.0f,
                    .offset = 0.0f,
                    .min_value = 0.0f,
                    .max_value = 65535.0f,
                },
                {
                    .name = "command_u16_3",
                    .start_bit = 48,
                    .bit_length = 16,
                    .byte_order = CAN_LITTLE_ENDIAN,
                    .scale = 1.0f,
                    .offset = 0.0f,
                    .min_value = 0.0f,
                    .max_value = 65535.0f,
                },
            },
    },
};

const int dbc_message_count = sizeof(dbc_messages) / sizeof(dbc_messages[0]);
