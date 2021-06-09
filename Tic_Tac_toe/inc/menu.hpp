#ifndef MENU_HHP
#define MENU_HHP
#include <SDL2/SDL.h>
#include "zmienne_globalne.hpp"
#include "sdl.hpp"
#include<iostream>
class menu
{
private:
    int cos;
public:
    void rysuj();
    int sprawdz_rozmiar();
    int sprawdz_ilosc_w_rzedzie();
};

void menu::rysuj()
{

    int szerokosc_komorki  = WIDTH/6;
    int wysokosc_komorki = HEIGHT/6;

    SDL_FRect rect;        
    rect.h = HEIGHT/6;       
    rect.w = WIDTH/6;    
    rect.x = 0;             
    rect.y = HEIGHT/3;         
    
    SDL_SetRenderDrawColor(renderer,255, 255, 0, 255);
    SDL_RenderFillRectF(renderer, &rect); 

    rect.x = szerokosc_komorki;   
    SDL_SetRenderDrawColor(renderer,153, 255, 51, 255);                      
    SDL_RenderFillRectF(renderer, &rect);              

    rect.x = 2*szerokosc_komorki;   
    SDL_SetRenderDrawColor(renderer,51, 204, 255, 255);                      
    SDL_RenderFillRectF(renderer, &rect); 

    rect.x = 3*szerokosc_komorki;   
    SDL_SetRenderDrawColor(renderer, 204, 102, 255, 255);                      
    SDL_RenderFillRectF(renderer, &rect); 

    rect.x = 4*szerokosc_komorki;   
    SDL_SetRenderDrawColor(renderer, 255, 0, 102, 255);                      
    SDL_RenderFillRectF(renderer, &rect); 

    rect.x = 5*szerokosc_komorki;   
    SDL_SetRenderDrawColor(renderer,255, 0, 0, 255);                      
    SDL_RenderFillRectF(renderer, &rect); 

    rect.y = HEIGHT*2/3;  
    rect.x = 0; 
    //drugi rzad
    SDL_SetRenderDrawColor(renderer,255, 255, 0, 255);
    SDL_RenderFillRectF(renderer, &rect); 

    rect.x = szerokosc_komorki;   
    SDL_SetRenderDrawColor(renderer,153, 255, 51, 255);                      
    SDL_RenderFillRectF(renderer, &rect);              

    rect.x = 2*szerokosc_komorki;   
    SDL_SetRenderDrawColor(renderer,51, 204, 255, 255);                      
    SDL_RenderFillRectF(renderer, &rect); 

    rect.x = 3*szerokosc_komorki;   
    SDL_SetRenderDrawColor(renderer, 204, 102, 255, 255);                      
    SDL_RenderFillRectF(renderer, &rect); 

    rect.x = 4*szerokosc_komorki;   
    SDL_SetRenderDrawColor(renderer, 255, 0, 102, 255);                      
    SDL_RenderFillRectF(renderer, &rect); 

    rect.x = 5*szerokosc_komorki;   
    SDL_SetRenderDrawColor(renderer,255, 0, 0, 255);                      
    SDL_RenderFillRectF(renderer, &rect); 

    framecount++;
    int timerFPS = SDL_GetTicks() - lastFrame;
    if(timerFPS<(1000/60))
    {
        SDL_Delay((1000/60)-timerFPS);
    }

    SDL_RenderPresent(renderer);
}

/**
 *  \brief  sprawdza , który przycisk został klikniety 
 * 
 *  \return rozmiar planszy
 */
int menu::sprawdz_rozmiar() 
{ 
    int szerokosc_komorki = WIDTH/6;

    SDL_Event event;  

    while(SDL_PollEvent(&event))
    {                                    
        if(event.type == SDL_QUIT)
        {
            return 0;
        }                           
        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        if(keystates[SDL_SCANCODE_ESCAPE])
        {
            return 0;
        }              
        
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {                             
            // zakres 3x3                         
            if(event.button.x < szerokosc_komorki && event.button.x>0 && event.button.y<HEIGHT/2 && event.button.y>HEIGHT/3 )
            {
                return 3; 
            }
            // zakres 4x4 
            if(event.button.x < 2*szerokosc_komorki && event.button.x>szerokosc_komorki && event.button.y<HEIGHT/2 && event.button.y>HEIGHT/3)
            {
                return 4; 
            } 
            // zakres 5x5                        
            if(event.button.x < 3*szerokosc_komorki && event.button.x>2*szerokosc_komorki && event.button.y<HEIGHT/2 && event.button.y>HEIGHT/3)
            {
                return 5; 
            }
            // zakres 6x6 
            if(event.button.x < 4*szerokosc_komorki && event.button.x>3*szerokosc_komorki &&  event.button.y<HEIGHT/2 && event.button.y>HEIGHT/3)
            {
                return 6; 
            }
            // zakres 7x7                         
            if(event.button.x < 5*szerokosc_komorki && event.button.x>4*szerokosc_komorki && event.button.y<HEIGHT/2 && event.button.y>HEIGHT/3)
            {
                return 7; 
            }
            // zakres 8x8 
            if(event.button.x < 6*szerokosc_komorki && event.button.x>5*szerokosc_komorki && event.button.y<HEIGHT/2 && event.button.y>HEIGHT/3)
            {
                return 8; 
            }  
        }
    }
    return 1;
}

int menu::sprawdz_ilosc_w_rzedzie() 
{ 
    int szerokosc_komorki = WIDTH/6;

    SDL_Event event;  

    while(SDL_PollEvent(&event))
    {                                    
        if(event.type == SDL_QUIT)
        {
            return 0;
        }                           
        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
        if(keystates[SDL_SCANCODE_ESCAPE])
        {
            return 0;
        }              
        
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {                             
            // zakres 3x3                         
            if(event.button.x < szerokosc_komorki && event.button.x>0 && event.button.y<HEIGHT*5/6 && event.button.y>HEIGHT*2/3 )
            {
                return 3; 
            }
            // zakres 4x4 
            if(event.button.x < 2*szerokosc_komorki && event.button.x>szerokosc_komorki && event.button.y<HEIGHT*5/6 && event.button.y>HEIGHT*2/3)
            {
                return 4; 
            } 
            // zakres 5x5                        
            if(event.button.x < 3*szerokosc_komorki && event.button.x>2*szerokosc_komorki && event.button.y<HEIGHT*5/6 && event.button.y>HEIGHT*2/3)
            {
                return 5; 
            }
            // zakres 6x6 
            if(event.button.x < 4*szerokosc_komorki && event.button.x>3*szerokosc_komorki &&  event.button.y<HEIGHT*5/6 && event.button.y>HEIGHT*2/3)
            {
                return 6; 
            }
            // zakres 7x7                         
            if(event.button.x < 5*szerokosc_komorki && event.button.x>4*szerokosc_komorki && event.button.y<HEIGHT*5/6 && event.button.y>HEIGHT*2/3)
            {
                return 7; 
            }
            // zakres 8x8 
            if(event.button.x < 6*szerokosc_komorki && event.button.x>5*szerokosc_komorki && event.button.y<HEIGHT*5/6 && event.button.y>HEIGHT*2/3)
            {
                return 8; 
            }  
        }
    }
    return 1;
}

#endif






