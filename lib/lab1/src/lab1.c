#include "lab1.h"


int delay_ms(unsigned int delay){
/*
/// @brief Wrapper for a delay function, sleeping for delay milliseconds
/// @param delay 
/// @return last delay
*/
    int last_delay;
    last_delay = delay;
    k_msleep(delay);
    return last_delay;
}


// int main_thread_setup(const struct device *dev, gpio_pin_t pin, int led_state){
//     return 1+3;
// }

int main_thread_loop(const struct device* dev, gpio_pin_t pin, int led_state){
    /*
/// @brief Main loop of the main thread, basically toggling an LED
/// @param dev 
/// @param pin 
/// @param led_state 
/// @return 
    */
    led_state = toggle_led(dev, pin, led_state);
    return led_state;
}

int toggle_led(const struct device *dev, gpio_pin_t pin, int led_state){
    /*
/// @brief Toggle an LED
/// @param dev
/// @param pin
/// @param led_state
/// @return
    */
    led_state = !led_state;
    gpio_pin_set(dev, pin, led_state);
    return led_state;
}

int main_thread_setup(const struct device *dev, gpio_pin_t pin, gpio_flags_t flags)
{
    gpio_pin_configure(dev, pin,  GPIO_OUTPUT_ACTIVE | flags);
    return 0;
}

int main_thread_iteration(const struct device *dev, gpio_pin_t pin, int led_state)
{
    led_state = !led_state;
    gpio_pin_set(dev, pin, (int)led_state);
    return led_state;
}

int second_thread_setup(const struct device *dev, gpio_pin_t pin, gpio_flags_t flags, int *counter)
{
    counter = 0;
	gpio_pin_configure(dev, pin, GPIO_OUTPUT_ACTIVE | flags);
    return 0;
}

int second_thread_iteration(const struct device *dev, gpio_pin_t pin, int led_state, int *counter)
{
    *counter = *counter + 1;
    led_state = !led_state;
    gpio_pin_set(dev, pin, (int)led_state);
    return led_state;
}