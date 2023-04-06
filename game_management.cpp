#include"game_management.hpp"
game_management:: game_management(){
 isRunning=true;}
 game_management:: ~game_management(){
 }
 void game_management::init(string title){
 if(SDL_Init(SDL_INIT_VIDEO)<0){
    isRunning = false;
 }
 else{
    gWindow=SDL_CreateWindow("game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,0);
    gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
    isRunning=true;
 }
background.loadImg("SpaceBackground.jpg",gRenderer);
plane1.loadImg("spaceship.png", gRenderer);
 background.Render(gRenderer);
SDL_RenderPresent(gRenderer);
plane1.Render(gRenderer);
SDL_RenderPresent(gRenderer);
bool quit=true;
while(quit){
    while(SDL_PollEvent(&gEvent)!=0){
        plane1.Control(gEvent,gRenderer);
        if(gEvent.type==SDL_QUIT){
            isRunning=false;
            quit=false;
        }
    }
SDL_RenderPresent(gRenderer);
}
}
void game_management::handle_event(){
     while(SDL_PollEvent(&gEvent)){
        if(gEvent.type==SDL_QUIT){
            isRunning=false;
     }
     plane1.Control(gEvent,gRenderer);
     }
          }


void game_management:: handle_game(){
   // SDL_RenderClear(gRenderer);
   plane1.Render(gRenderer);
   SDL_RenderPresent(gRenderer);

   plane1.Show(gRenderer);
   plane1.Move();
   }

void game_management:: clean(){
 SDL_DestroyWindow(gWindow);
 SDL_DestroyRenderer(gRenderer);
 gWindow=NULL;
 gRenderer=NULL;
 SDL_Quit();
 }
