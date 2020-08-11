#include "unity.h"
#include "split_text.h"

/* Required by the unity test framework */
void setUp()
{

}

/* Required by the unity test framework */
void tearDown()
{

}

/* Test for general text splitting and non mutablility of input */
void test_split_text(void)
{

}

/* Test for handling successive delimitters */
void test_double_delim(void)
{

}

/* Test for handling abscence of delimitters */
void test_none(void)
{

}

int test_main(void)
{
	/* Initiate the Unity Test Framework */
	UNITY_BEGIN();

	/* Run Test functions */
	RUN_TEST(test_split_text);
	RUN_TEST(test_double_delim);
	RUN_TEST(test_none);

	/* Close the Unity Test Framework */
	return UNITY_END();
}
