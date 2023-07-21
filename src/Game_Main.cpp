#include "./Game_Title.h"

int main(int argc, char *argv[])
{
    Game_Title *game_title = new Game_Title;

    game_title->init_all_module();

    game_title->open_and_play_title_music();
    game_title->window_render_resource();

    game_title->get_events();

    delete game_title;

    return EXIT_SUCCESS;
}