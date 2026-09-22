#ifndef VULKAN_GRAPHICSPHYSICALDEVICE_H_
#define VULKAN_GRAPHICSPHYSICALDEVICE_H_
#include <gfx/base/arch/graphicsphysicaldevice.h>
#include <gfx/vulkan/arch/vulkan_graphicslogicdevice.h>

class vulkan_graphicsphysicaldevice : public graphicsphysicaldevice {
public:
    vulkan_graphicsphysicaldevice(vk::PhysicalDevice _device);
    ~vulkan_graphicsphysicaldevice();
private:
    graphicslogicdevice* createlogicdeviceImpl() override {
        return new vulkan_graphicslogicdevice; 
    }    
private:
    vk::PhysicalDevice m_device;

};


#endif // VULKAN_GRAPHICSPHYSICALDEVICE_H_