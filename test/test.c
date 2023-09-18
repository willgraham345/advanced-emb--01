#include <unity.h>
#include "lab1.h"

int last_delay_time;
void setUp(void) {}

void tearDown(void) {}

void test_delay_ms(void)
{
    last_delay_time = delay_ms(1000);
    TEST_ASSERT_EQUAL_INT_MESSAGE(last_delay_time, 1000, "delay_ms(1000) should return 1000");
}


void testWorks()
{
    TEST_ASSERT_TRUE_MESSAGE(1 == 1,"Data bits not set as expected");
}

int main (void)
{
    UNITY_BEGIN();
    RUN_TEST(testWorks);
    UNITY_END();
    return 0;
}