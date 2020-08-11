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

/* Test for general text splitting*/
void test_split_text(void)
{
	char *test_str = "my_name_is_edcast_future_skills";
	char *test_pcs[] = { "my", "name", "is", "edcast", "future", "skills", NULL};

	char **pcs;

	// Test Split
	// TODO : Compare pcs & test_pcs
}

/*  Test for non-mutablility of input  */
void test_mutability(void)
{
	char *test_str = "my_name_is_edcast_future_skills";
	char *test_str_copy = "my_name_is_edcast_future_skills";

	char **pcs;

	// Test Mutability
	// TODO : Compare test_str & test_str_copy
}

/* Test for handling successive delimitters */
void test_double_delim(void)
{
	char *test_str = "my_name_is__edcast_future___skills";
	char *test_pcs[] = { "my", "name", "is", "edcast", "future", "skills", NULL};

	char **pcs;

	// Test Consistency for multiple delimiters
	// TODO : Compare pcs & test_pcs
}

void test_delim_at_ends(void)
{
	char *test_str_a = "_my_name_is_edcast_future_skills";
	char *test_str_b = "my_name_is_edcast_future_skills_";
	char *test_pcs[] = { "my", "name", "is", "edcast", "future", "skills", NULL};

	char **pcs_a, **pcs_b;

	// Test Split A
	// TODO : Compare pcs_a & test_pcs
	
	// Test Split B
	// TODO : Compare pcs_b & test_pcs
}

/* Test for handling string consisting only of delimitters */
void test_delim_only(void)
{
	char *test_str = "__";
	char *test_pcs[] = { NULL};

	char **pcs;

	// Test Consistency for string with delimiters only
	// TODO : Compare pcs & test_pcs
}

/* Test for handling abscence of delimitters */
void test_none(void)
{
	char *test_str = "my name is edcast future skills";
	char *test_pcs[] = { "my name is edcast future skills", NULL};

	char **pcs;

	// Test Consistency for string with delimiters only
	// TODO : Compare pcs & test_pcs
}

int test_main(void)
{
	/* Initiate the Unity Test Framework */
	UNITY_BEGIN();

	/* Run Test functions */
	RUN_TEST(test_split_text);
	RUN_TEST(test_mutability);
	RUN_TEST(test_double_delim);
	RUN_TEST(test_delim_at_ends);
	RUN_TEST(test_delim_only);
	RUN_TEST(test_none);

	/* Close the Unity Test Framework */
	return UNITY_END();
}
