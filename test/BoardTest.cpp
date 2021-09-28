#include "Board.h"
#include "Test.h"
#include "BoardTest.h"

#define DO_CHECK(EXPR) check(EXPR, __FUNCTION__, __FILE__, __LINE__)

void BoardTest::test_get_value1()
{
    Board board;
    board.move(5, 5, 'O');
    DO_CHECK(board.get_value(5, 5) == ZERO);
}

void BoardTest::test_get_value2()
{
    Board board;
    board.move(0, 0, 'O');
    board.move(7, 9, 'X');
    DO_CHECK(board.get_value(7, 9) == CROSS);
}

void BoardTest::test_get_value3()
{
    Board board;
    DO_CHECK(board.get_value(3, 6) == EMPTY);
}

void BoardTest::test_is_correct_num1()
{
    Board board;
    DO_CHECK(board.is_correct_num(0) == true);
}

void BoardTest::test_is_correct_num2()
{
    Board board;
    DO_CHECK(board.is_correct_num(-1) == false);
}

void BoardTest::test_is_correct_num3()
{
    Board board;
    DO_CHECK(board.is_correct_num(77) == false);    
}

void BoardTest::test_move1()
{
    Board board;
    board.move(1, 4, 'O');
    DO_CHECK(board.can_move(1, 4, 'O') == false);
}

void BoardTest::test_move2()
{
    Board board;
    board.move(4, 8, 'O');
    DO_CHECK(board.get_value(4, 8) == ZERO);
}

void BoardTest::test_move3()
{
    Board board;
    board.move(4, 8, 'O');
    board.move(3, 7, 'X');
    DO_CHECK(board.get_value(3, 7) == CROSS);
}

void BoardTest::test_can_move1()
{
    Board board;
    board.move(3, 5, 'O');
    board.move(2, 6, 'X');
    DO_CHECK(board.can_move(3, 6, 'O') == true);
}

void BoardTest::test_can_move2()
{
    Board board;
    DO_CHECK(board.can_move(2, 10, 'O') == false);
}
   
void BoardTest::test_can_move3()
{
    Board board;
    board.move(2, 5, 'O');
    DO_CHECK(board.can_move(2, 5, 'O') == false);
}

void BoardTest::test_check_row1()
{
    Board board;
    board.move(8, 7, 'O');
    board.move(0, 2, 'X');
    board.move(8, 9, 'O');
    board.move(0, 5, 'X');
    board.move(8, 5, 'O');
    board.move(0, 7, 'X');
    board.move(8, 6, 'O');
    board.move(0, 9, 'X');
    board.move(8, 8, 'O');
    DO_CHECK(board.check_row(8, 5) == true);
}

void BoardTest::test_check_row2()
{
    Board board;
    board.move(3, 2, 'O');
    board.move(1, 6, 'X');
    board.move(3, 4, 'O');
    board.move(4, 6, 'X');
    board.move(3, 6, 'O');
    board.move(4, 9, 'X');
    board.move(3, 5, 'O');
    DO_CHECK(board.check_row(3, 2) == false);
}

void BoardTest::test_check_row3()
{
    Board board;
    DO_CHECK(board.check_row(0, 6) == false);
}

void BoardTest::test_check_column1()
{
    Board board;
    board.move(3, 0, 'O');
    board.move(6, 4, 'X');
    board.move(3, 3, 'O');
    board.move(7, 4, 'X');
    board.move(3, 5, 'O');
    board.move(5, 4, 'X');
    board.move(6, 3, 'O');
    board.move(3, 4, 'X');
    board.move(7, 0, 'O');
    board.move(4, 4, 'X');
    DO_CHECK(board.check_column(3, 4) == true);
}

void BoardTest::test_check_column2()
{
    Board board;
    board.move(8, 7, 'O');
    board.move(0, 1, 'X');
    board.move(6, 7, 'O');
    board.move(0, 3, 'X');
    board.move(7, 7, 'O');
    board.move(0, 7, 'X');
    board.move(9, 7, 'O');
    DO_CHECK(board.check_column(6, 7) == false);
}

void BoardTest::test_check_column3()
{
    Board board;
    DO_CHECK(board.check_column(8, 3) == false);
}
  
void BoardTest::test_check_diagonal_left1()
{
    Board board;
    board.move(7, 3, 'O');
    board.move(2, 0, 'X');
    board.move(5, 1, 'O');
    board.move(2, 2, 'X');
    board.move(6, 2, 'O');
    board.move(2, 4, 'X');
    board.move(9, 5, 'O');
    board.move(2, 6, 'X');
    board.move(8, 4, 'O');
    DO_CHECK(board.check_diagonal_left(5, 1) == true);
}
    
void BoardTest::test_check_diagonal_left2()
{
    Board board;
    board.move(1, 5, 'O');
    board.move(1, 6, 'X');
    board.move(3, 7, 'O');
    board.move(3, 8, 'X');
    board.move(0, 4, 'O');
    board.move(0, 5, 'X');
    board.move(4, 8, 'O');
    DO_CHECK(board.check_diagonal_left(0, 4) == false);
}

void BoardTest::test_check_diagonal_left3()
{
    Board board;
    DO_CHECK(board.check_diagonal_left(3, 3) == true);
}

void BoardTest::test_check_diagonal_right1()
{
    Board board;
    board.move(9, 1, 'O');
    board.move(4, 4, 'X');
    board.move(3, 0, 'O');
    board.move(5, 3, 'X');
    board.move(7, 0, 'O');
    board.move(2, 6, 'X');
    board.move(7, 8, 'O');
    board.move(1, 7, 'X');
    board.move(3, 7, 'O');
    board.move(3, 5, 'X');
    DO_CHECK(board.check_diagonal_right(1, 7) == true);
}

void BoardTest::test_check_diagonal_right2()
{
    Board board;
    board.move(1, 2, 'O');
    board.move(1, 1, 'X');
    board.move(2, 1, 'O');
    board.move(0, 0, 'X');
    board.move(3, 0, 'O');
    board.move(2, 2, 'X');
    board.move(0, 3, 'O');
    DO_CHECK(board.check_diagonal_right(0, 3) == false);
}

void BoardTest::test_check_diagonal_right3()
{
    Board board;
    DO_CHECK(board.check_diagonal_right(6, 7) == false);    
}

void BoardTest::test_is_win1()
{
    Board board;
    board.move(1, 1, 'O');
    board.move(0, 0, 'X');
    board.move(5, 0, 'O');
    board.move(3, 5, 'X');
    board.move(1, 6, 'O');
    DO_CHECK(board.is_win() == NOBODY_WINS);
}

void BoardTest::test_is_win2()
{
    Board board;
    board.move(4, 5, 'O');
    board.move(4, 1, 'X');
    board.move(4, 8, 'O');
    board.move(2, 2, 'X');
    board.move(4, 4, 'O');
    board.move(3, 7, 'X');
    board.move(4, 6, 'O');
    board.move(1, 3, 'X');
    board.move(4, 7, 'O');
    DO_CHECK(board.is_win() == ZERO_WINS);
}

void BoardTest::test_is_win3()
{
    bool player = 0;
    Board board;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((i + 1) % 3) 
            {
                board.move(i, j, player ? 'X' : 'O');
                player ^= 1;
            }
            else
            {
                board.move(i, SIZE - j - 1, player ? 'X' : 'O');
                player ^= 1;
            }
        }
    }
    DO_CHECK(board.is_win() == DRAW);
}

void BoardTest::run_all_tests()
{
    test_get_value1();
    test_get_value2();
    test_get_value3();

    test_is_correct_num1();
    test_is_correct_num2();
    test_is_correct_num3();

    test_move1();
    test_move2();
    test_move3();

    test_can_move1();
    test_can_move2();
    test_can_move3();

    test_check_row1();
    test_check_row2();
    test_check_row3();

    test_check_column1();
    test_check_column2();
    test_check_column3();
  
    test_check_diagonal_left1();
    test_check_diagonal_left2();
    test_check_diagonal_left3();

    test_check_diagonal_right1();
    test_check_diagonal_right2();
    test_check_diagonal_right3();

    test_is_win1();
    test_is_win2();
    test_is_win3();
}