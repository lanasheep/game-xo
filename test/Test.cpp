#include <stdio.h>

#include "Test.h"

int Test::total_num = 0;
int Test::failed_num = 0;

void Test::check(bool expr, const char *func, const char  *filename, size_t line_num)
{
    if (expr == false)
    {
        printf("test failed: %s in %s:%ld\n", func, filename, line_num);
        failed_num++;
    }
    total_num++;
}

void Test::show_final_result()
{
    if (failed_num == 0)
    {
        printf("All test passed.\n");
    }
    else
    {
        printf("Failed %d of %d tests.\n", failed_num, total_num);
    }
}