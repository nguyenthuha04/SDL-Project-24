#ifndef SPACE_SHIP_H_
#define SPACE_SHIP_H_
#include<vector>
#include "common.hpp"
#include "base.hpp"
#include"bullet.hpp"
#define WIDTH_MAIN 130
#define HEIGHT_MAIN 122
#define MAIN_SPEED 10
#define MAIN_HEART 3
using namespace std;
class space_ship : public base{
public:
    space_ship();
    ~space_ship();
    enum BULLET_SPEED{
     BLASTER_SPEED=11,
     };

 void Control(SDL_Event,SDL_Renderer*screen/*, int bullet_level*/);
 void Move();
 void Show(SDL_Renderer*screen);
 void set_bullet_list(vector<bullet*> bullet_list){
 bullet_list_=bullet_list;}
 vector<bullet*> get_bullet_list(){ return bullet_list_;}
 void HandleBullet(SDL_Renderer * screen);
 void RemoveBullet(const int& idx);
 void set_bul_type(const int& bul_type){ bullet_type_=bul_type;}
 int get_bul_type()const{return bullet_type_;}
 void set_status(const bool& Status){status_=Status;}
 int get_status()const{return status_;}
 float get_bullet_damage()const{return bullet_damage_;}
 void set_heart(const int& Heart){ heart_=Heart;}
 int  get_heart()const {return heart_;}
 void decrease_heart(){heart_--;}


private:
    vector<bullet*> bullet_list_;
    int x_val_;
    int y_val_;
    int bullet_type_;
    bool status_;
    int heart_;
    int bullet_damage_;

};

#endif

