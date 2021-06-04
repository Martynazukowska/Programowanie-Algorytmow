#ifndef GRAFIKA_HPP
#define GRAFIKA_HPP

#include "element.hpp"
#include "button.hpp"
#include "dane.hpp"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>


#include <string> 

class Graphics{
    public: 

        bool init();
        bool loadMedia();
        void close(); 

        const int SCREEN_WIDTH = 680;
        const int SCREEN_HEIGHT = 680;
}; 
#endif 

