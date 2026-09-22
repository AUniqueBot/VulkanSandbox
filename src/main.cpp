#include <pch.h>
#include <main/arch/window.h>
#include <gfx/vulkan/arch/vulkan_graphicsinstance.h>

int main() {

    
    vulkan_graphicsinstance gfxinstance;
    window w(
        windowconfig{
            .name="Vulkan Playground",
            .dimensions=glm::ivec2(1920, 1080),
            .flags=
                SDL_WINDOW_VULKAN |
                SDL_WINDOW_RESIZABLE,
                .graphicsinstance = &gfxinstance
        }
    );


    w.init();
    w.update();
    w.destroy();
}