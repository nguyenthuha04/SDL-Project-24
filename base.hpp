#ifndef BASE_H_
#define BASE_H_
#include "Common.hpp"
class base{
 public:
     base();
     ~base();
     void SetRect(const int &x, const int &y){
     rect_.x=x;
     rect_.y=y;
     }
     SDL_Rect GetRect(){ return rect_;}
     bool loadImg(string path, SDL_Renderer* ren);
     void Render(SDL_Renderer* screen, const SDL_Rect* clip=NULL);
     void Clean();
 protected:
    SDL_Rect rect_;
    SDL_Texture* object_;
};
#endif // BASEOBJECT_H_
