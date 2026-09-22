#include <gfx/vulkan/arch/vulkan_graphicspresentation.h>
#include <sdl3/SDL_vulkan.h>

vulkan_graphicspresentation::vulkan_graphicspresentation(
    SDL_Window *_window,
    VkInstance& _vkinstance 
) : r_instance{_vkinstance}, p_window{_window} {
    
    VkSurfaceKHR surface;
    bool res = SDL_Vulkan_CreateSurface(p_window, r_instance, nullptr, &surface);
    if (!res) {
        SDL_Vulkan_DestroySurface(r_instance, surface, nullptr);
    }
    m_surface = std::move(surface);
}

vulkan_graphicspresentation::~vulkan_graphicspresentation() {
    SDL_Vulkan_DestroySurface(r_instance, m_surface, nullptr);
}

bool vulkan_graphicspresentation::init() {

}
void vulkan_graphicspresentation::acquire() {

}
void vulkan_graphicspresentation::present() {

}