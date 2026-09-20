#include <pch.h>
#include <main/arch/window.h>


int main() {


    window w(
        windowconfig{
            .name="Vulkan Playground",
            .dimensions=glm::ivec2(1920, 1080),
            .flags=
            SDL_WINDOW_RESIZABLE 
                // SDL_WINDOW_VULKAN |
        }
    );

    w.init();
    w.update();
    w.destroy();
}