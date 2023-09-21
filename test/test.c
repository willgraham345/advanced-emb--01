#include <stdint.h>
#include <stdio.h>
#include <unity.h>
#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>
#include "lab1.h"

#define LED_NODE DT_ALIAS(led3)
#define LED	DT_GPIO_LABEL(LED_NODE, gpios)
#define PIN	DT_GPIO_PIN(LED_NODE, gpios)
#define FLAGS	DT_GPIO_FLAGS(LED_NODE, gpios)

void setUp(void) {}

void tearDown(void) {}

void test_delay_ms(void)
{
    int last_delay_time;
    last_delay_time = delay_ms(1000);
    TEST_ASSERT_EQUAL_INT_MESSAGE(last_delay_time, 1000, "delay_ms(1000) should return 1000");
}

void testWorks()
{
    TEST_ASSERT_TRUE_MESSAGE(1 == 1,"Data bits not set as expected");
}

void test_main_thread()
{
    const struct device *dev = device_get_binding(LED);
    int *counter = 0;

    int led_is_on = main_thread_setup(dev, PIN, FLAGS);
    TEST_ASSERT_TRUE_MESSAGE(!led_is_on, "LED flag should start toggled off");

    led_is_on = main_thread_iteration(dev, PIN, led_is_on);
    TEST_ASSERT_TRUE_MESSAGE(led_is_on, "LED flag should be toggled on");
    TEST_ASSERT_TRUE_MESSAGE(gpio_pin_get(dev, PIN) , "GPIO should be toggled on");

    // led_is_on = second_thread_setup(dev, PIN, FLAGS, counter);
    // TEST_ASSERT_TRUE_MESSAGE(led_is_on, "LED flag should start toggled on");

    // led_is_on = second_thread_iteration(dev, PIN, led_is_on, counter);
    // TEST_ASSERT_TRUE_MESSAGE(led_is_on, "LED flag should be toggled off");
    // TEST_ASSERT_TRUE_MESSAGE(gpio_pin_get(dev, PIN) , "GPIO should be toggled on");
}

void test_LED(){

}

int main (void)
{
    UNITY_BEGIN();
    RUN_TEST(testWorks);
    RUN_TEST(test_main_thread);
    RUN_TEST(test_delay_ms);
    UNITY_END();
    return 0;
}