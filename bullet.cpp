#include"bullet.hpp"

bullet::bullet(){
x_val_=0;
y_val_=0;
is_move_=false;
bullet_type_=BLASTER;
}
bullet::~bullet(){
}
void bullet::loadImgBullet(SDL_Renderer*screen){
 if(bullet_type_==BLASTER ){
    loadImg("blaster.png",screen);
 }
}
 void bullet:: HandleMoveSpaceShipBullet(){
 rect_.y+=y_val_;
 if(rect_.y<-rect_.h){
    is_move_=false;}
 }
 void bullet:: HandleMoveChickenBullet(){
 rect_.y+=y_val_;
 if(rect_.y>SCREEN_HEIGHT){
        is_move_=false;

 }
 }
 void bullet::HandleMoveBossBullet(const int& x_border, const int&y_border){
 rect_.y+=y_val_;
 if(rect_.y>y_border){
    is_move_=false;
 }
 }


