#include"game_management.hpp"
game_management:: game_management(){
 isRunning=true;
 kill=0;
 scrolling=-(BACKGROUND_HEIGHT-SCREEN_HEIGHT);
 time_end_game=0;
 count_num_exp=0;
 menu_number=0;
 }
 game_management:: ~game_management(){
 }
 void game_management::init(std::string title){
 if(SDL_Init(SDL_INIT_VIDEO)<0){
    isRunning = false;
 }
 else{
    gWindow=SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(gWindow==NULL){
            isRunning=false;
    }
    else{
    gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
    if(gRenderer==NULL){
        isRunning=false;
    }
    else{
    int imgFlags=IMG_INIT_PNG;
    if(!(IMG_Init(imgFlags)& imgFlags)){ isRunning =false;}
    if(TTF_Init()<0){ isRunning=false;}
    g_font_text=TTF_OpenFont("font1.ttf",25);
    g_font_menu=TTF_OpenFont("font1.ttf",50);
    g_font_end_game=TTF_OpenFont("font1.ttf",100);
        if(g_font_text==NULL || g_font_menu==NULL|| g_font_end_game==NULL){
            isRunning=false;}
        }
    }
 }
background.loadImg("background.png",gRenderer);
plane1.loadImg("spaceship.png", gRenderer);

//boss
Boss.loadImg("boss.png",gRenderer);
Boss.set_clips();
Boss.SetRect(-WIDTH_BOSS,-HEIGHT_BOSS);
Boss.set_y_val(BOSS_SPEED);
Boss.set_x_val(BOSS_SPEED*3);
Boss.set_heart(BOSS_HEART);
 bullet* p_bullet=new bullet();
 Boss.InitBullet(p_bullet,gRenderer);
 //init chic
 int t=0;
 int distance_row=0;
 for(int c=0;c<NUMBER_OF_CHICKEN;c++){
    Chicken* p_chicken= new Chicken();
    if(p_chicken){
        p_chicken->loadImg("chicken_red.png",gRenderer);
        p_chicken->set_clips();
        if(t%NUMBER_OF_CHICKENS_PER_ROW==0){
            distance_row-=DISTANCE_BETWEEN_CHICKENS;
            t=0;
        }
    p_chicken->SetRect(15+ t*DISTANCE_BETWEEN_CHICKENS, distance_row);
    p_chicken->set_y_val(CHICKEN_SPEED);
    p_chicken->set_x_val(CHICKEN_SPEED);
    p_chicken->set_heart(CHICKEN_HEART);
    int random=rand()%4;
    if(random<2){
        bullet* p_bullet=new bullet();
        p_chicken->InitBullet(p_bullet,gRenderer);
    }
    p_chicken_list.push_back(p_chicken);
    t++;
    }
 }
 exp.loadImg("exp.png",gRenderer);
 exp.set_clip();
 exp_boss.loadImg("exp.png",gRenderer);
 exp_boss.set_clip();
 support.loadImg("support.png", gRenderer);
 support.SetRect(-10,6);
 kill_text.SetColor(Text:: WHITE);
 heart_text.SetColor(Text:: WHITE);
 hint.SetColor(Text:: WHITE);
 end_game.SetColor(Text:: WHITE);
 isRunning=true;
 }
 bool game_management:: check_collision(const SDL_Rect& object1, const SDL_Rect& object2){
    int left_a=object1.x;
    int right_a=object1.x + object2.w;
    int top_a=object1.y;
    int bottom_a=object1.y + object1.h;

    int left_b=object2.x;
    int right_b=object2.x + object2.w;
    int top_b=object2.y;
    int bottom_b= object2.y + object2.h;
    if(left_a>right_b|| right_a<left_b || top_a>bottom_b || bottom_a<top_b){
        return false;
    }
    return true;
 }
 bool game_management:: check_mouse_vs_item(const int&x, const int&y, const SDL_Rect& rect){
   if(x>=rect.x && x<=rect.x+rect.w && y>=rect.y && y<=rect.y+rect.h){
        return true;}
   return false;
 }
 void game_management:: menu(const std:: string& item){
  base menu;
  base menu2;
  if(!menu.loadImg("menu.png",gRenderer)){
    isRunning=false;
    return;
  }
  if(!menu2.loadImg("menu2.png",gRenderer)){
    isRunning=false;
    return;
  }
  const int number_of_item=4;
  SDL_Rect pos_arr[number_of_item];
  Text text_menu[number_of_item];
  text_menu[0].SetText(item);
  text_menu[0].SetColor(Text:: WHITE);
  text_menu[0].loadText_showText(g_font_menu,gRenderer);
  pos_arr[0].x=SCREEN_WIDTH/2-text_menu[0].GetRect().w/2;
  pos_arr[0].y=SCREEN_HEIGHT-300;
  text_menu[0].SetRect(pos_arr[0].x,pos_arr[0].y);

  text_menu[1].SetText("INFORMATION");
  text_menu[1].SetColor(Text:: WHITE);
  text_menu[1].loadText_showText(g_font_menu,gRenderer);
  pos_arr[1].x=SCREEN_WIDTH/2-text_menu[1].GetRect().w/2;
  pos_arr[1].y=SCREEN_HEIGHT-200;
  text_menu[1].SetRect(pos_arr[1].x,pos_arr[1].y);

  text_menu[2].SetText("QUIT");
  text_menu[2].SetColor(Text:: WHITE);
  text_menu[2].loadText_showText(g_font_menu,gRenderer);
  pos_arr[2].x=SCREEN_WIDTH/2-text_menu[2].GetRect().w/2;
  pos_arr[2].y=SCREEN_HEIGHT-100;
  text_menu[2].SetRect(pos_arr[2].x,pos_arr[2].y);

  text_menu[3].SetText("BACK");
  text_menu[3].SetColor(Text:: WHITE);
  text_menu[3].loadText_showText(g_font_menu,gRenderer);
  pos_arr[3].x=10;
  pos_arr[3].y=10;
  text_menu[3].SetRect(pos_arr[3].x,pos_arr[3].y);

  int xm=0;
  int  ym=0;
  bool quit=true;
  while(quit){
    if(menu_number==0){
        menu.Render(gRenderer);
        for(int i=0;i<number_of_item-1;i++){
            text_menu[i].loadText_showText(g_font_menu,gRenderer);
        }
    }
    else if(menu_number==1){
        menu2.Render(gRenderer);
        text_menu[3].loadText_showText(g_font_menu,gRenderer);
    }
    while(SDL_PollEvent(&gEvent)!=0){
        plane1.Control(gEvent,gRenderer);
        if(gEvent.type==SDL_QUIT){
            isRunning=false;
            quit=false;
        }
        else if(gEvent.type==SDL_MOUSEMOTION){
            xm=gEvent.motion.x;
            ym=gEvent.motion.y;
            for(int i=0;i<number_of_item;i++){
                if(check_mouse_vs_item(xm,ym,text_menu[i].GetRect())){
                    text_menu[i].SetColor(Text:: RED);}
                else{text_menu[i].SetColor(Text::WHITE);}
            }
        }
        if(gEvent.type==SDL_MOUSEBUTTONDOWN){
            xm=gEvent.button.x;
            ym=gEvent.button.y;

            for(int i=0;i<number_of_item;i++){
                if(menu_number==0){
                    if(check_mouse_vs_item(xm,ym,text_menu[i].GetRect())){
                        if(i==0){isRunning=true; quit=false;}
                        else if(i==1){menu_number=1;}
                         else if(i==2){isRunning=false;quit=false;}
                    }
                }
                else if(menu_number==1){
                    if(check_mouse_vs_item(xm,ym,text_menu[3].GetRect())){
                        menu_number=0;
                    }
                }
            }
        }
    }
SDL_RenderPresent(gRenderer);
}
}
void game_management:: reset_game(){
  kill=0;
  count_num_exp=0;
  scrolling =-(BACKGROUND_HEIGHT-SCREEN_HEIGHT);
  time_end_game=0;
  plane1.SetRect(SCREEN_WIDTH/2,SCREEN_HEIGHT-HEIGHT_MAIN);
  plane1.set_status(true);
  plane1.set_heart(CHICKEN_HEART);
  Boss.SetRect(-WIDTH_BOSS,-HEIGHT_BOSS);
  Boss.set_heart(BOSS_HEART);
  for(int i=0;i< Boss.get_bullet_list().size();i++){
    bullet* p_bullet=Boss.get_bullet_list().at(i);
    if(p_bullet){
        p_bullet->SetRect(Boss.GetRect().x+WIDTH_BOSS/2, Boss.GetRect().y+HEIGHT_BOSS);
    }
  }
  int t=0;
  int y_row=-DISTANCE_BETWEEN_CHICKENS;
  for(int c=0;c<NUMBER_OF_CHICKEN;c++){
    Chicken* p_chicken=p_chicken_list.at(c);
    if(t%NUMBER_OF_CHICKENS_PER_ROW==0){
        y_row-=DISTANCE_BETWEEN_CHICKENS;
        t=0;
    }
    p_chicken->set_come_back(true);
    p_chicken->SetRect(10+ t*DISTANCE_BETWEEN_CHICKENS, y_row);
    p_chicken->set_heart(CHICKEN_HEART);
    p_chicken->set_status_right();
    t++;
    for(int i=0;i<p_chicken->get_bullet_list().size();i++){
        bullet* p_bullet=p_chicken->get_bullet_list().at(i);
        if(p_bullet){
            p_bullet->SetRect(p_chicken->GetRect().x+WIDTH_CHICKEN/2-p_bullet->GetRect().w/2,p_chicken->GetRect().y+HEIGHT_CHICKEN);
        }
        }
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
void game_management::handle_boss(){
   //handle boss
   if(kill>=NUMBER_OF_CHICKEN*2 && Boss.get_heart()>=0){
     Boss.show_heart_boss(gRenderer,400,30,Boss.get_heart(),6);
     SDL_Delay(11);
     Boss.Move();
     Boss.Show(gRenderer);
     Boss.MakeBullet(gRenderer);
     // plane  with boss bullet
     bool Col1=false;
     std:: vector<bullet*> boss_bullet_list=Boss.get_bullet_list();
     for(int b=0;b<boss_bullet_list.size();b++){
        bullet*p_bullet=boss_bullet_list.at(b);
        if(p_bullet){
            Col1=check_collision(p_bullet->GetRect(),plane1.GetRect());
        }
     }
     //plane with boss
     bool Col2=check_collision(plane1.GetRect(),Boss.GetRectFrame());
    if(Col1|| Col2){
        //set exp
        int x_pos=(plane1.GetRect().x+WIDTH_MAIN/2)-WIDTH_FRAME_EXP/2;
        int y_pos=(plane1.GetRect().y+HEIGHT_MAIN/2)-HEIGHT_FRAME_EXP/2;
        exp.SetRect(x_pos,y_pos);
        exp.set_frame(0);
        plane1.SetRect(SCREEN_WIDTH*2,SCREEN_HEIGHT*2);
        plane1.set_status(false);
        plane1.decrease_heart();
    }
    //plane bullet with boss
    std:: vector<bullet*> s_bullet_list=plane1.get_bullet_list();
    for(int sb=0;sb<s_bullet_list.size();sb++){
        bullet* p_bullet=s_bullet_list.at(sb);
        if(p_bullet!=NULL){
            bool Col3=check_collision(p_bullet->GetRect(),Boss.GetRectFrame());
            if(Col3){
                Boss.Decrease((plane1.get_bullet_damage()));
                plane1.RemoveBullet(sb);
                if(Boss.get_heart()<0){
                    kill++;
                    //exp
                    int x_pos=(Boss.GetRect().x+WIDTH_BOSS/2)-WIDTH_FRAME_EXP/2;
                    int y_pos=(Boss.GetRect().y+HEIGHT_BOSS/2)-HEIGHT_FRAME_EXP/2;
                    exp_boss.SetRect(x_pos,y_pos);
                    exp_boss.set_frame(0);
                    Boss.SetRect(SCREEN_WIDTH/2,-SCREEN_HEIGHT);
                }
            }
        }
    }
   }
}

void game_management::handle_chicken(){
 if(kill<NUMBER_OF_CHICKEN*2){
    for(int ck=0;ck<p_chicken_list.size() ;ck++){
        Chicken* p_chicken=p_chicken_list.at(ck);
        if(p_chicken){
            SDL_Delay(1);
            p_chicken->Move();
           p_chicken->Show(gRenderer);
            p_chicken->HandleBullet(gRenderer);
        }
    // check plane with chicken bullet
    bool Col1=false;
    std:: vector<bullet*>bullet_list=p_chicken->get_bullet_list();
    for(int b=0;b<bullet_list.size();b++){
        bullet*p_bullet=bullet_list.at(b);
        if(p_bullet){
            Col1=check_collision(p_bullet->GetRect(),plane1.GetRect());
            if(Col1==true){
                p_chicken->RemoveBullet(b);
                break;
            }
        }
    }
    //check plane with chicken
    bool Col2=check_collision(plane1.GetRect(),p_chicken->GetRectFrame());
    if(Col1|| Col2){
        //set exp
        int x_pos=(plane1.GetRect().x+WIDTH_MAIN/2)-WIDTH_FRAME_EXP/2;
        int y_pos=(plane1.GetRect().y+HEIGHT_MAIN/2)-HEIGHT_FRAME_EXP/2;
        exp.SetRect(x_pos,y_pos);
        exp.set_frame(0);
        plane1.SetRect(SCREEN_WIDTH*2,SCREEN_HEIGHT*2);
        plane1.set_status(false);
        plane1.decrease_heart();
    }
    // check main object bullet with chicken
    std:: vector<bullet*> s_bullet_list=plane1.get_bullet_list();
    for(int sb=0;sb<s_bullet_list.size();sb++){
        bullet* p_bullet=s_bullet_list.at(sb);
        if(p_bullet!=NULL){
            bool Col3=check_collision(p_bullet->GetRect(),p_chicken->GetRectFrame());
            if(Col3){
                p_chicken->Decrease((plane1.get_bullet_damage()));
                plane1.RemoveBullet(sb);

                if(p_chicken->get_heart()<0){
                    p_chicken->set_heart(CHICKEN_HEART);
                    kill++;
                    p_chicken->SetRect(p_chicken->GetRect().x,-2*SCREEN_HEIGHT);
                    if(kill>NUMBER_OF_CHICKEN){
                        p_chicken->set_come_back(false);
                    }

                }
            }
        }
    }

 }
 }
}
void game_management:: handle_game(){
    scrolling+=SCREEN_SPEED;
    if(scrolling<0){
        background.Render(gRenderer);
        background.SetRect(0,scrolling);
    }
    else{
        background.Render(gRenderer);
        background.SetRect(0,0);
    }
    //handle mainobj
   plane1.Move();
   plane1.Show(gRenderer);
   plane1.HandleBullet(gRenderer);

   //enemy
   handle_chicken();
   handle_boss();
   //exp
   if(exp.get_frame()<NUMBER_OF_FRAME*2){
    exp.Show(gRenderer);
   }
   if(exp_boss.get_frame()<NUMBER_OF_FRAME*2){
    exp_boss.Show(gRenderer);

   if(exp_boss.get_frame()>=NUMBER_OF_FRAME*2 && count_num_exp<NUMBER_OF_EXP){
    exp_boss.set_frame(0);
    count_num_exp++;
      }
   }
   //game over
   if(plane1.get_heart()==0){
    if(time_end_game<80){
        time_end_game++;
        end_game.SetText("GAME OVER!");
        end_game.SetRect(310,SCREEN_HEIGHT/5);
        end_game.loadText_showText(g_font_end_game,gRenderer);
    }
    else{
        menu("PLAY AGAIN?");
        reset_game();
    }
   }
   else{
    if(plane1.get_status()==false){
        hint.SetText("Press 'ENTER' to revive");
        hint.SetRect(280,SCREEN_HEIGHT/4);
        hint.loadText_showText(g_font_menu,gRenderer);
    }
   }
   //game win
   if(Boss.get_heart()<=0){
    if(time_end_game<530){
        time_end_game++;
        SDL_Delay(10);
        end_game.SetText("WIN GAME !");
        end_game.SetRect(310,SCREEN_HEIGHT/5);
        end_game.loadText_showText(g_font_end_game,gRenderer);
    }
    else{
        menu("PLAY AGAIN?");
        reset_game();
    }
   }
   //support
   support.Render(gRenderer);
   heart_text.SetText(patch:: to_string(plane1.get_heart()));
   heart_text.SetRect(195,15);
   heart_text.loadText_showText(g_font_text,gRenderer);
   kill_text.SetText(patch::to_string(kill));
   kill_text.SetRect(50,15);
   kill_text.loadText_showText(g_font_text,gRenderer);
   SDL_RenderPresent(gRenderer);
}



void game_management:: clean(){
 SDL_DestroyWindow(gWindow);
 SDL_DestroyRenderer(gRenderer);
 gWindow=NULL;
 gRenderer=NULL;
 SDL_Quit();
 IMG_Quit();
 TTF_Quit();

 }

