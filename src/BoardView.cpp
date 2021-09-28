#include <stdio.h>
#include <cstdlib>

#include "Board.h"
#include "BoardView.h"

View::View(Board &board, bool silent_mode)
{
    player = 0;
    is_silent = silent_mode;
    _board = &board;
}

void View::change_player()
{
    player ^= 1;
}

void View::show_board() const
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("\n");
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c", symbol[_board->get_value(i, j)]);
        }
    }
}

void View::do_game_cycle()
{
    if (!is_silent) show_board();

    while (true)
    {
        if (!is_silent) printf("\n");
        printf("%c move: ", symbol[player]);

        int x, y;
        scanf("%d%d", &x, &y);

        if (x == -1 && y == -1)
        {
            exit(0);
        }

        if (_board->can_move(x, y, symbol[player])) 
        {
            _board->move(x, y, symbol[player]);
            break;
        }
        else printf("Bad move!");
        if (is_silent) printf("\n");
    }

    change_player();

    status current = _board->is_win();

    if (current != NOBODY_WINS)
    {
        show_board();

        if (current == DRAW)
        {
            printf("\nDraw.\n");
        }
        else
        {
            printf("\n%c wins!\n", symbol[current]);
        }
        
        exit(0);
    }
}