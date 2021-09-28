#pragma once

#include <stdlib.h>

class Test
{
  public:

    static void check(bool expr, const char *func, const char  *filename, size_t line_num);
    static void show_final_result();
    virtual void run_all_tests() = 0;

  protected:

    static int failed_num;
    static int total_num;
};