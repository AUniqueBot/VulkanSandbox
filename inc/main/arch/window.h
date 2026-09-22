#ifndef WINDOW_H_
#define WINDOW_H_

#include <pch.h>
#include <sdl3/SDL.h>
#include <SDL3/SDL_vulkan.h>

#include <gfx/base/arch/graphicsinstance.h>


struct windowconfig {
    // do nothing
    std::string name;
    glm::ivec2 dimensions;   
    SDL_WindowFlags flags;
    graphicsinstance* graphicsinstance;
};

class graphicsinstance;
class window {
public:
    window(windowconfig _config = {});

    void init();
    void update();
    void destroy();

protected:
    void pollevents();

private:
    SDL_Window* p_window;
    std::string m_windowname;
    glm::ivec2  m_dimensions;
    SDL_WindowFlags m_windowflags;

private:
    graphicsinstance* p_gfxinstance;    
};


#endif // WINDOW_H_