#include "Test.h"
#include "BoardTest.h"

int main() 
{
    BoardTest autotest;
    autotest.run_all_tests();
    Test::show_final_result();

    return 0;
}