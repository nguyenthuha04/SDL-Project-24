#include"space_ship.hpp"
space_ship::space_ship(){
 rect_.x=SCREEN_WIDTH/2;
 rect_.y=SCREEN_HEIGHT-HEIGHT_MAIN;
 rect_.w=WIDTH_MAIN;
 rect_.h=HEIGHT_MAIN;
 x_val_=0;
 y_val_=0;
 status_=true;}
 space_ship::~space_ship(){}
 void space_ship:: Control(SDL_Event event, SDL_Renderer* screen){
       switch(event.type){
  case SDL_KEYDOWN:
      switch(event.key.keysym.sym){
         case SDLK_UP:
             if(y_val_-HEIGHT_MAIN/4>=0) y_val_= y_val_ - HEIGHT_MAIN/4;
             break;
         case SDLK_DOWN:
            if(y_val_+HEIGHT_MAIN/4<=SCREEN_HEIGHT+HEIGHT_MAIN/3) y_val_= y_val_ + HEIGHT_MAIN/4;
            break;
         case SDLK_LEFT:
             if(x_val_+WIDTH_MAIN/2>=0) x_val_= x_val_ - WIDTH_MAIN/2;
             break;
         case SDLK_RIGHT:
             if(x_val_+WIDTH_MAIN/3<=SCREEN_WIDTH-WIDTH_MAIN/3) x_val_= x_val_ + WIDTH_MAIN/3;
             break;
        }
  case SDL_KEYUP:
      switch(event.key.keysym.sym){
         case SDLK_UP:
             if(y_val_+HEIGHT_MAIN/4>=0) y_val_= y_val_ + HEIGHT_MAIN/4;
             break;
         case SDLK_DOWN:
            if(y_val_-HEIGHT_MAIN/4<=SCREEN_HEIGHT-HEIGHT_MAIN/3) y_val_= y_val_ - HEIGHT_MAIN/4;
            break;
         case SDLK_LEFT:
             if(x_val_+WIDTH_MAIN/2>=0) x_val_= x_val_ + WIDTH_MAIN/2;
             break;
         case SDLK_RIGHT:
             if(x_val_+WIDTH_MAIN/3<=SCREEN_WIDTH-WIDTH_MAIN/3) x_val_= x_val_ - WIDTH_MAIN/3;
             break;
        }

  }
}

void space_ship:: Show(SDL_Renderer* screen){
if(status_==true){
    Render(screen);
}
}
void space_ship:: Move(){
   if(status_==true){
    rect_.x+=x_val_;
     if(rect_.x<0|| rect_.x+WIDTH_MAIN>SCREEN_WIDTH){
        rect_.x-=x_val_;
    }
     rect_.y+=y_val_;
     if(rect_.y<0|| rect_.y+HEIGHT_MAIN>SCREEN_HEIGHT){
        rect_.x-=x_val_;
    }
   }
}
