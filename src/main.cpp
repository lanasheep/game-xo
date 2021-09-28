#include <string.h>

#include "Board.h"
#include "BoardView.h"

int main(int argc, char const *argv[])
{
    bool silent_mode;

    if (argc == 2 && strcmp(argv[1], "silent") == 0)
    {
        silent_mode = true;
    }
    else
    {
        silent_mode = false;
    }

    Board game_board;
    View game_view(game_board, silent_mode);

    while (true)
    {
        game_view.do_game_cycle();
    }

    return 0;
}