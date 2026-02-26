/* temperature_system.c - handles everything related to temperature control */
#include "hardware.h"
#include "uart.h"
#include "flash.h"
#include "lcd.h"

static uint16_t current_temp;
static uint16_t target_temp;
static uint8_t alarm_status;
static char lcd_buffer[32];

void process_temperature(void) {
    /* Read hardware sensors */
    current_temp = adc_read(TEMP_SENSOR_CH);
    
    /* Handle calibration */
    current_temp = apply_calibration(current_temp);
    
    /* Update display */
    sprintf(lcd_buffer, "Temp: %d C", current_temp);
    lcd_write_string(LCD_LINE_1, lcd_buffer);
    
    /* Check alarm conditions */
    if (current_temp > TEMP_ALARM_THRESHOLD) {
        alarm_status = 1;
        gpio_set(LED_RED);
        uart_send_string("ALARM: Temperature critical\r\n");
    }
    
    /* Log to flash memory */
    struct temp_log_entry entry = {
        .timestamp = get_system_time(),
        .temperature = current_temp
    };
    flash_write_log(&entry, sizeof(entry));
    
    /* Control heater */
    if (current_temp < target_temp) {
        gpio_set(HEATER_PIN);
    } else {
        gpio_clear(HEATER_PIN);
    }
}
