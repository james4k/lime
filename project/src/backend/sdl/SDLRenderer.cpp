#include "SDLApplication.h"
#include "SDLWindow.h"
#include "SDLRenderer.h"
#include "../../graphics/opengl/OpenGLBindings.h"


namespace lime {


	static int VSyncThread (void *data) {

		SDLRenderer *renderer = (SDLRenderer *)data;
		renderer->VSyncThread ();
		return 0;

	}


	static void PushUpdateEvent (SDLRenderer *renderer) {
		
		SDL_Event event;
		SDL_UserEvent userevent;
		userevent.type = SDL_USEREVENT;
		userevent.code = 0;
		userevent.data1 = renderer;
		userevent.data2 = NULL;
		event.type = SDL_USEREVENT;
		event.user = userevent;
		
		SDL_PushEvent (&event);
		
	}
	
	
	SDLRenderer::SDLRenderer (Window* window) {
		
		currentWindow = window;
		sdlWindow = ((SDLWindow*)window)->sdlWindow;
		
		int sdlFlags = SDL_RENDERER_ACCELERATED;
		
		if (window->flags & WINDOW_FLAG_VSYNC) sdlFlags |= SDL_RENDERER_PRESENTVSYNC;
		
		sdlRenderer = NULL;
		//sdlRenderer = SDL_CreateRenderer (sdlWindow, -1, sdlFlags);

		SDL_GL_SetSwapInterval (1);
		glContext = SDL_GL_CreateContext (sdlWindow);
		
		OpenGLBindings::Init ();

		vsyncStart = SDL_CreateSemaphore (0);
		SDL_CreateThread (lime::VSyncThread, "VSync", this);

	}
	
	
	SDLRenderer::~SDLRenderer () {
		
		if (sdlRenderer) {
			
			SDL_DestroyRenderer (sdlRenderer);
			
		}

		if (glContext) {

			SDL_GL_DeleteContext (glContext);
			glContext = 0;
			SDL_SemPost (vsyncStart);

		}
		
	}
	
	
	void SDLRenderer::Flip () {
		
		SDL_GL_MakeCurrent (NULL, 0);
		SDL_SemPost (vsyncStart);
		
	}


	void SDLRenderer::MakeCurrent () {

		SDL_GL_MakeCurrent (sdlWindow, glContext);

	}


	void SDLRenderer::VSyncThread () {

		for (;;) {

			SDL_SemWait (vsyncStart);
			if (glContext == 0) {
				return;
			}

			int start = SDL_GetTicks ();
			SDL_GL_MakeCurrent (sdlWindow, glContext);
			SDL_GL_SwapWindow (sdlWindow);
			SDL_GL_MakeCurrent (NULL, 0);

			((SDLApplication *)currentWindow->currentApplication)->PostVSync ();
			PushUpdateEvent (this);
			
		}

	}
	
	
	Renderer* CreateRenderer (Window* window) {
		
		return new SDLRenderer (window);
		
	}
	
	
}
