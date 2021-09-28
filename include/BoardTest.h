#pragma once

class BoardTest: public Test 
{
  public:

    void test_get_value1();
    void test_get_value2();
    void test_get_value3();

    void test_is_correct_num1();
    void test_is_correct_num2();
    void test_is_correct_num3();

    void test_move1();
    void test_move2();
    void test_move3();

    void test_can_move1();
    void test_can_move2();
    void test_can_move3();

    void test_check_row1();
    void test_check_row2();
    void test_check_row3();

    void test_check_column1();
    void test_check_column2();
    void test_check_column3();
  
    void test_check_diagonal_left1();
    void test_check_diagonal_left2();
    void test_check_diagonal_left3();

    void test_check_diagonal_right1();
    void test_check_diagonal_right2();
    void test_check_diagonal_right3();

    void test_is_win1();
    void test_is_win2();
    void test_is_win3();

    void run_all_tests();
};