#ifndef VULKAN_GRAPHICSDEVICE_H_
#define VULKAN_GRAPHICSDEVICE_H_

#include <pch.h>
#include <vulkan/vulkan.hpp>
#include <gfx/base/arch/graphicslogicdevice.h>

class vulkan_graphicslogicdevice : public graphicslogicdevice {
public:


protected:
    gfxcontext createcontextImpl(graphicsdeviceDefs::contextType _type) override;
private:
    vk::PhysicalDevice m_physicaldevice;
};


#endif // VULKAN_GRAPHICSDEVICE_H_