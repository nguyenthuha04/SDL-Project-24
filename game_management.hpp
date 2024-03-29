#ifndef GAME_MANAGEMENT_H_
#define GAME_MANAGEMENT_H_
#include "common.hpp"
#include "base.hpp"
#include "space_ship.hpp"
#include"chicken.hpp"
#include"Explosion.hpp"
#include"Text.hpp"
#include"boss.hpp"
using namespace std;
class game_management{
public:
    game_management();
    ~game_management();
    void init(std :: string title);
    void handle_event();
    void handle_boss();
    void handle_chicken();
    void handle_game();
    void clean();
    void menu(const std:: string& item);
    void reset_game();
    bool get_running(){return isRunning;}
    bool check_collision(const SDL_Rect& object1, const SDL_Rect& object2);
    bool check_mouse_vs_item(const int &x, const int& y, const SDL_Rect& rect);
private:
    bool isRunning;
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Event gEvent;
    TTF_Font* g_font_text;
    TTF_Font* g_font_menu;
    TTF_Font* g_font_end_game;
    base background;
    base support;
    space_ship plane1;
    Explosion exp;
    Explosion exp_boss;
    Text kill_text;
    Text heart_text;
    Text hint;
    Text end_game;
    boss Boss;
    int kill;
    float scrolling;
    int time_end_game;
    int count_num_exp;
    int menu_number;
    std:: vector<Chicken*> p_chicken_list;
};
#endif // GAME_MANAGEMENT_H_

