#include "Board.h"

Board::Board()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            _table[i][j] = EMPTY;
        }
    }
}

value Board::get_value(int x, int y) const
{
    return _table[x][y];
}

bool Board::is_correct_num(int k) const
{
    return (0 <= k && k < SIZE);
}

void Board::move(int x, int y, char sign)
{
    if (sign == 'O')
    {
        _table[x][y] = ZERO;
    }
    if (sign == 'X')
    {
        _table[x][y] = CROSS;
    }
}

bool Board::can_move(int x, int y, char sign) const
{
    return (is_correct_num(x) && is_correct_num(y) && _table[x][y] == EMPTY);
}

bool Board::check_row(int x, int y) const
{
    if (y + LENGTH > SIZE) return false;

    for (int i = 0; i < LENGTH - 1; i++)
    {
        if (_table[x][y + i] != _table[x][y + i + 1])
        {
            return false;
        }
    }

    return true;
}

bool Board::check_column(int x, int y) const
{
    if (x + LENGTH > SIZE) return false;

    for (int i = 0; i < LENGTH - 1; i++)
    {
        if (_table[x + i][y] != _table[x + i + 1][y])
        {
            return false;
        }
    }

    return true;
}

bool Board::check_diagonal_left(int x, int y) const
{
    for (int i = 0; i < LENGTH - 1; i++)
    {
        if (_table[x + i][y + i] != _table[x + i + 1][y + i + 1])
        {
            return false;
        }
    }

    return true;
}

bool Board::check_diagonal_right(int x, int y) const
{
    for (int i = 0; i < LENGTH - 1; i++)
    {
        if (_table[x + i][y - i] != _table[x + i + 1][y - i - 1])
        {
            return false;
        }
    }

    return true;
}

status Board::is_win() const
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (check_row(i, j) || check_column(i, j)) 
            {
                if (_table[i][j] == ZERO)
                {
                    return ZERO_WINS;
                }
                if (_table[i][j] == CROSS)
                {
                    return CROSS_WINS;
                }
            }
        }
    }
    
    for (int i = 0; i <= SIZE - LENGTH; i++)
    {
        for (int j = 0; j <= SIZE - LENGTH; j++)
        {
            if (check_diagonal_left(i, j))
            {
                if (_table[i][j] == ZERO)
                {
                    return ZERO_WINS;
                }
                if (_table[i][j] == CROSS)
                {
                    return CROSS_WINS;
                }
            }
        }
    }

    for (int i = 0; i <= SIZE - LENGTH; i++)
    {
        for (int j = LENGTH - 1; j < SIZE; j++)
        {
            if (check_diagonal_right(i, j))
            {
                if (_table[i][j] == ZERO)
                {
                    return ZERO_WINS;
                }
                if (_table[i][j] == CROSS)
                {
                    return CROSS_WINS;
                }
            }
        }
    }

    int count_cell = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (_table[i][j] != EMPTY) count_cell++;
        }
    }

    if (count_cell == SIZE * SIZE) return DRAW;

    return NOBODY_WINS;
}