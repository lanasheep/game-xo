#pragma once

const char symbol[] = {'O', 'X', '.'};

class View 
{
  public:

    View(Board &board, bool silent_mode);

    void change_player();

    void show_board() const; 
    void do_game_cycle();

  private:

    Board *_board;

    bool player;
    bool is_silent;
};