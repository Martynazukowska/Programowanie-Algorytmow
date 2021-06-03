#ifndef GUI_HPP_
#define GUI_HPP_
#define BUTTON_SZEROKOSC 8
#define BUTTON_WYSOKOSC 8

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL2/SDL_image.h>

class Gui
{
  public:
    bool init();
    void execGame();

    const int SCREEN_WIDTH = 680;
    const int SCREEN_HEIGHT = 680;

    void klikniecieMyszka(SDL_Event& klikniecie);

  private:

    void draw();

    bool gameIsRunning = false;     //flaga czy gra powinna dalej chodzic 

    SDL_Window* window = nullptr;
    SDL_Surface* surface = nullptr;
    TTF_Font* font = nullptr;
    SDL_Surface* pion = nullptr;
    SDL_Surface* szachownica = nullptr;
    SDL_Surface* proba = nullptr;
};

#endif /* GAME_GUI_HPP_ */
