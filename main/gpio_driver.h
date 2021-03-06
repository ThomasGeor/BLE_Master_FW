/* GPIO Driver for ESP32 burglar alarm
 *
 * author : Thomas Georgiadis
 *
 */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "driver/gpio.h"

// Defintions
#define BZR_PIN                 GPIO_NUM_33
#define PSH_BTN_PIN             GPIO_NUM_34
#define MG_SNS_PIN              GPIO_NUM_35
#define ESP_INTR_FLAG_DEFAULT   0

xQueueHandle   gpio_evt_queue;

void IRAM_ATTR gpio_isr_handler(void* arg);

void gpio_init();
uint8_t get_alarm_current_state();
void activate_buzzer(uint8_t door_state);
