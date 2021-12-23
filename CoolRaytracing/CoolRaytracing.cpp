#include <iostream>
#include "CApp.h"


int main(int *argc, char *argv[])
{
    SDL_SetMainReady();
    CApp theApp;
    return theApp.OnExecute();
}