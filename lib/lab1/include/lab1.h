#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>


int toggle_led(const struct device *dev, gpio_pin_t pin, int led_state);
//int main_thread_setup(const struct device *dev, gpio_pin_t pin, int led_state);
int delay_ms(unsigned int delay);
int main_thread_loop(const struct device *dev, gpio_pin_t pin, int led_state);
int main_thread_setup(const struct device *dev, gpio_pin_t pin, gpio_flags_t flags);
int main_thread_iteration(const struct device *dev, gpio_pin_t pin, int led_state);
int second_thread_setup(const struct device *dev, gpio_pin_t pin, gpio_flags_t flags, int *counter);
int second_thread_iteration(const struct device *dev, gpio_pin_t pin, int led_state, int *counter);
