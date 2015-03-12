#ifndef LIME_SDL_RENDERER_H
#define LIME_SDL_RENDERER_H


#include <SDL.h>
#include <graphics/Renderer.h>


namespace lime {
	
	
	class SDLRenderer : public Renderer {
		
		public:
			
			SDLRenderer (Window* window);
			~SDLRenderer ();
			
			virtual void Flip ();

			void MakeCurrent ();
			
			SDL_Renderer* sdlRenderer;
			SDL_Window* sdlWindow;
			SDL_GLContext glContext;
			SDL_sem *vsyncStart;

			void VSyncThread ();
		
	};
	
	
}


#endif
