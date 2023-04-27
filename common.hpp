#ifndef COMMON_H_
#define COMMON_H_
#include<string>
#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<sstream>
namespace patch{
 template<typename T> std:: string to_string(const T& n)
 {
     std:: ostringstream stm;
     stm << n;
     return stm.str();
 }
 }
using namespace std;
const int BACKGROUND_WIDTH=1200;
const int BACKGROUND_HEIGHT=3840;
const int SCREEN_WIDTH=1200;
const int SCREEN_HEIGHT=700;
const float SCREEN_SPEED=1.4;

const int COLOR_KEY_R=170;
const int COLOR_KEY_G=170;
const int COLOR_KEY_B=170;


const int NUMBER_OF_CHICKEN=30;

const int NUMBER_OF_EXP=3;
const int BOSS_HEART=200;
const int CHICKEN_HEART=3;
const int DISTANCE_BETWEEN_CHICKENS=68 ;
const int NUMBER_OF_CHICKENS_PER_ROW=10;

struct StatusChicken{
int turn_left;
int turn_right;
int turn_up;
int turn_down;
};
#endif

