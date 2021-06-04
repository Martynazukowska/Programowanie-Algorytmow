// #include "game/gui.hpp"
// #include <cstdlib>
// #include <iostream>

// // sudo apt install ...
// // yay -S sdl2 sdl2_ttf

// int main(int argc, char* argv[])
// {
//     Gui gui;  //tworzymy obietkt GUI

//     if(!gui.init())                                 //gdy inicjalizacja się nie powiedzie
//     {
//         std::cerr << "Game initialization failed\n";
//         return EXIT_FAILURE;
//     }

//     gui.execGame();                                 //odpal gre

//     return EXIT_SUCCESS;
// }

#include "game/button.hpp"
#include "game/element.hpp"
#include "game/plansza.hpp"
#include "game/grafika.hpp"
                                                   
#include <SDL2/SDL_image.h>                                                
#include <SDL2/SDL.h>                                                      

#include <cstdio>
#include <string>
#include <iostream>


using namespace std;

int main( int argc, char* args[] ){

	std::cout<<"chociaz tu ";

	
    Graphics graphics;
	StanGry *gm = new StanGry(); 


	if( !graphics.init() )
    {
		cout<<"Nie udało sie zaincjalizowac\n";
	}
	else{
		if( !graphics.loadMedia() )
        {
			cout<<"Nie udalo sie zaladowac madiow\n";
		}
		else
		{
            gm->start(TrybGry::GAME_MAIN_MENU);            
    	}
        graphics.close();

	    return 0;
    }
}

