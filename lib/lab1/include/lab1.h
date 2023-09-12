#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>


int toggle_led(const struct device *dev, gpio_pin_t pin, int led_state);
// int main_thread_setup(const struct device *dev, gpio_pin_t pin, int led_state);
int main_thread_loop(const struct device *dev, gpio_pin_t pin, int led_state);