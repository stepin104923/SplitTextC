#include <string.h>
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

void compare_pcs(char** expected, char** actual)
{
	int i;
	for(i = 0; expected[i] != NULL; i++) {
		TEST_ASSERT_EQUAL_STRING(expected[i], actual[i]);
	}
	TEST_ASSERT_EQUAL(expected[i], actual[i]);
}

/* Test for general text splitting*/
void test_split_text(void)
{
	char *test_str = strdup("my_name_is_edcast_future_skills");
	char *test_pcs[] = { "my", "name", "is", "edcast", "future", "skills", NULL};

	char **pcs;

	// Test Split
	pcs = split_text(test_str);
	compare_pcs(test_pcs, pcs);

	free_pieces(pcs);
}

/*  Test for non-mutablility of input  */
void test_mutability(void)
{
	char *test_str = strdup("my_name_is_edcast_future_skills");
	char *test_str_copy = "my_name_is_edcast_future_skills";

	char **pcs;

	// Test Mutability
	pcs = split_text(test_str);
	TEST_ASSERT_EQUAL_STRING(test_str, test_str_copy);

	free_pieces(pcs);
}

/* Test for handling successive delimitters */
void test_double_delim(void)
{
	char *test_str = strdup("my_name_is__edcast_future___skills");
	char *test_pcs[] = { "my", "name", "is", "edcast", "future", "skills", NULL};

	char **pcs;

	// Test Consistency for multiple delimiters
	pcs = split_text(test_str);
	compare_pcs(test_pcs, pcs);

	free_pieces(pcs);
}

void test_delim_at_ends(void)
{
	char *test_str_a = strdup("_my_name_is_edcast_future_skills");
	char *test_str_b = strdup("my_name_is_edcast_future_skills_");
	char *test_pcs[] = { "my", "name", "is", "edcast", "future", "skills", NULL};

	char **pcs_a, **pcs_b;

	// Test Split A
	pcs_a = split_text(test_str_a);
	compare_pcs(test_pcs, pcs_a);
	
	// Test Split B
	pcs_b = split_text(test_str_b);
	compare_pcs(test_pcs, pcs_b);

	free_pieces(pcs_a);
	free_pieces(pcs_b);
}

/* Test for handling string consisting only of delimitters */
void test_delim_only(void)
{
	char *test_str = strdup("__");
	char *test_pcs[] = { NULL};

	char **pcs;

	// Test Consistency for string with delimiters only
	pcs = split_text(test_str);
	compare_pcs(test_pcs, pcs);

	free_pieces(pcs);
}

/* Test for handling abscence of delimitters */
void test_none(void)
{
	char *test_str = strdup("my name is edcast future skills");
	char *test_pcs[] = { "my name is edcast future skills", NULL};

	char **pcs;

	// Test Consistency for string with delimiters only
	pcs = split_text(test_str);
	compare_pcs(test_pcs, pcs);

	free_pieces(pcs);
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
