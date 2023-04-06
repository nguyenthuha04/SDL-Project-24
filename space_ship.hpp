#ifndef SPACE_SHIP_H_
#define SPACE_SHIP_H_
#include "common.hpp"
#include "base.hpp"
#define WIDTH_MAIN 130
#define HEIGHT_MAIN 122
#define MAIN_SPEED 8
class space_ship : public base{
public:
    space_ship();
    ~space_ship();
   // enum{};

 void Control(SDL_Event,SDL_Renderer*screen);
 void Move();
 void Show(SDL_Renderer*screen);
private:
    int x_val_;
    int y_val_;
    bool status_;
};

#endif
