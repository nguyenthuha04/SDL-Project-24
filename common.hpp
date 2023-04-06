#ifndef COMMON_H_
#define COMMON_H_
#include<bits/stdc++.h>
#include<string>
#include<SDL.h>
#include<SDL_image.h>
using namespace std;
const int BACKGROUND_WIDTH=1200;
const int BACKGROUND_HEIGHT=3840;
const int SCREEN_WIDTH=1000;
const int SCREEN_HEIGHT=700;
const int SCREEN_SPEED=0.5;

const string WINDOW_TITLE= "game";
struct StatusChicken{
int turn_left;
int turn_right;
int turn_up;
int turn_down;
};
#endif
