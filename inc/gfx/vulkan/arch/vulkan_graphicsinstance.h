#ifndef VULKAN_GRAPHICSINSTANCE_H_
#define VULKAN_GRAPHICSINSTANCE_H_

#include <pch.h>
#include <gfx/base/arch/graphicsinstance.h>

#include <gfx/vulkan/arch/vulkan_graphicslogicdevice.h>



class vulkan_graphicsinstance : public graphicsinstance {
public:
    void init() override;
    void cleanup() override;

private:
    void pickbestdevice();
private:
    VkInstance m_instance;
    VkApplicationInfo m_appinfo;
    VkInstanceCreateInfo m_instanceCreateInfo;
};


#endif // VULKAN_GRAPHICSINSTANCE_H_