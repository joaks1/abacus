#include <stdlib.h>
#include <check.h>
#include <signal.h>
#include "../src/probability.c"
#include "test_rng.h"

START_TEST (test_draw_gamma_or_uniform_gamma) {
    double e, shape, scale, d, sum, mn;
    int i, reps;
    gsl_rng * rng;
    rng = get_rng(0);
    reps = 100000;
    shape = 1.0;
    scale = 10.0;
    for (i = 0; i < reps; i++) {
        d = draw_gamma_or_uniform(rng, shape, scale);
        ck_assert_msg((d > 0.0), "gamma draw %lf is less than zero", d);
        sum += d;
    }
    e = 0.1;
    mn = sum / reps;
    ck_assert_msg(almost_equal(mn, 10.0, e), "mean of gamma draws "
            "is %lf, expecting 10.0", mn);
    free_rng(rng);
}
END_TEST


Suite * probability_suite(void) {
    Suite * s = suite_create("probability");

    TCase * tc_draw_gamma_or_uniform = tcase_create(
            "draw_gamma_or_uniform_test_case");
    tcase_add_test(tc_draw_gamma_or_uniform, test_draw_gamma_or_uniform_gamma);
    suite_add_tcase(s, tc_draw_gamma_or_uniform);

    return s;
}

int main(void) {
    int number_failed;
    Suite * s = probability_suite();
    SRunner * sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

