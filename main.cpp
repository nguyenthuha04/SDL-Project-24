
#include"game_management.hpp"
int main(int argc, char*argv[])
{

    game_management game;
    game.init("game");
    game.menu("START");
    while(game.get_running()){

        game.handle_event();
        game.handle_game();
    }
    game.clean();

    return 0;
        }
