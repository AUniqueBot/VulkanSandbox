#include <main/arch/window.h>


window::window(windowconfig _config) {
    m_windowname = _config.name;
    m_dimensions = _config.dimensions;
    m_windowflags = _config.flags;
    p_gfxinstance = _config.graphicsinstance;
}

void window::init() {
    if (!SDL_Init(SDL_INIT_VIDEO)){
        return;
    }



    p_window = SDL_CreateWindow(
        m_windowname.c_str(), 
        m_dimensions.x, m_dimensions.y, 
        m_windowflags
    );
    if (!p_window) {
        std::printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
        SDL_Quit();
    }
    
    if (p_gfxinstance) {
        p_gfxinstance->init();
    }
}
void window::update() {

    if (!p_window) return;
    bool breakout{};
    while (!breakout) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                breakout = true;
            } 
        }
    }
}
void window::destroy() {
    if (p_window)  {   
        SDL_Window* deleted = p_window;
        p_window = nullptr;
        
        SDL_DestroyWindow(deleted);
    }
    SDL_Quit();

}
