#ifndef VULKAN_GRAPHICSPRESENTATION_H_
#define VULKAN_GRAPHICSPRESENTATION_H_


#include <sdl3/SDL.h>
#include <gfx/base/arch/graphicspresentation.h>
#include <vulkan/vulkan.hpp>

class vulkan_graphicspresentation : public graphicspresentation {
public:
    vulkan_graphicspresentation(
        SDL_Window* _window, 
        vk::Instance& _vkinstance
    );
    ~vulkan_graphicspresentation() override;
public:
    bool init() override;
    void acquire() override;
    void present() override;

private:
    vk::Instance& r_instance;
    SDL_Window* p_window;
    vk::SurfaceKHR m_surface;
    vk::SwapchainKHR m_swapchain;
};


#endif // VULKAN_GRAPHICSPRESENTATION_H_