#ifndef GAME_MANAGEMENT_H_
#define GAME_MANAGEMENT_H_
#include "common.hpp"
#include "base.hpp"
#include "space_ship.hpp"
using namespace std;
class game_management{
public:
    game_management();
    ~game_management();
    void init(string title);
    void handle_event();
    void handle_game();
    void clean();
    bool get_running(){return isRunning;}
private:
    bool isRunning;
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Event gEvent;
    base background;
    space_ship plane1;};
#endif // GAME_MANAGEMENT_H_
