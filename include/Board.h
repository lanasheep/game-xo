#pragma once

enum value
{
    ZERO, 
    CROSS, 
    EMPTY
};

enum status
{
    ZERO_WINS, 
    CROSS_WINS, 
    NOBODY_WINS, 
    DRAW
};

const int SIZE = 10;
const int LENGTH = 5;

class Board 
{
  public:

    Board();

    value get_value(int x, int y) const;

    bool is_correct_num(int k) const;

    void move(int x, int y, char sign); 
    bool can_move(int x, int y, char sign) const;

    bool check_row(int x, int y) const;
    bool check_column(int x, int y) const;
    bool check_diagonal_left(int x, int y) const;
    bool check_diagonal_right(int x, int y) const;

    status is_win() const; 

  private:
    value _table[SIZE][SIZE];
};