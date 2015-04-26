#include "latinga/sdl2/include/sdl.h"
#include "latinga/sdl2/include/sdl_opengl.h"
#include <iostream>
#include "Window.hpp"
using std::cout;

int main(int argc, char* argv[]){

  SDL_Init(SDL_INIT_VIDEO); // Init SDL2
  
  // Create a window. Window mode MUST include SDL_WINDOW_OPENGL for use with OpenGL.
  Window gameWindow;
  gameWindow.create();

  // Now, regular OpenGL functions ...
  glMatrixMode(GL_PROJECTION|GL_MODELVIEW);
  glLoadIdentity();
  glOrtho(-320,320,240,-240,0,1);
 
  // ... can be used alongside SDL2.
  SDL_Event e; 
  e.common.type=0;
  float x = 0.0, y = 30.0;
  
  while(e.type!=SDL_KEYDOWN&&e.type!=SDL_QUIT){  // Enter main loop.
    
    SDL_PollEvent(&e);      // Check for events.
    
    glClearColor(0,0,0,1);          // Draw with OpenGL.
    glClear(GL_COLOR_BUFFER_BIT);   
    glRotatef(10.0,0.0,0.0,1.0);     
    
    SDL_GL_SwapWindow(gameWindow.getWindow());  // Swap the window/buffer to display the result.
    SDL_Delay(10);              // Pause briefly before moving on to the next cycle.
    
  } 

  SDL_Quit();
  return 0;
  
}
