#ifndef BASE_H_
#define BASE_H_
#include "Common.hpp"
class base{
 public:
     base();
     ~base();
     void SetRect(const float &x, const float &y){
     rect_.x=x;
     rect_.y=y;
     }
     SDL_Rect GetRect(){ return rect_;}
     bool loadImg(std :: string path, SDL_Renderer* ren);
     void Render(SDL_Renderer* screen, const SDL_Rect* clip=NULL);
     void Clean();
 protected:
    SDL_Rect rect_;
    SDL_Texture* object_;
};
#endif //

