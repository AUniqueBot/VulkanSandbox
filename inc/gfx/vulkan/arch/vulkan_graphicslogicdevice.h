#ifndef VULKAN_GRAPHICSDEVICE_H_
#define VULKAN_GRAPHICSDEVICE_H_

#include <pch.h>
#include <vulkan/vulkan.hpp>
#include <gfx/base/arch/graphicslogicdevice.h>
#include <gfx/vulkan/arch/vulkan_graphicsphysicaldevice.h>


class vulkan_graphicslogicdevice : public graphicslogicdevice {
public:
    vulkan_graphicslogicdevice(const graphicslogicdeviceargs& _args);

protected:
    gfxcontext createcontextImpl(graphicsdeviceDefs::contextType _type) override;
private:
    vk::Device m_logicdevice;
};


#endif // VULKAN_GRAPHICSDEVICE_H_