#include <check.h>
#include <life.h>

START_TEST(isalive_cellaliveandtwoneighbors_returnstrue)
{
    ck_assert_int_eq(true, is_alive(true, 2));
}
END_TEST

TCase *tcase_rules(void)
{
    TCase *tc;

    tc = tcase_create("rules");
    tcase_add_test(tc, isalive_cellaliveandtwoneighbors_returnstrue);

    return tc;
}

Suite *suite_life(void)
{
    Suite *s;

    s = suite_create("life");
    suite_add_tcase(s, tcase_rules());

    return s;
}

int main(int argc, char **argv)
{
    Suite *s;
    SRunner *runner;
    int number_fails;

    s = suite_life();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_NORMAL);
    number_fails = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_fails;
}