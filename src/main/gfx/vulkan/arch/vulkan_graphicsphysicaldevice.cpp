#include <gfx/vulkan/arch/vulkan_graphicsphysicaldevice.h>

vulkan_graphicsphysicaldevice::vulkan_graphicsphysicaldevice(vk::PhysicalDevice _device) {
    m_device = _device;
}
vulkan_graphicsphysicaldevice::~vulkan_graphicsphysicaldevice(){

}


graphicslogicdevice* 
    vulkan_graphicsphysicaldevice::createlogicdeviceImpl(
        
    ) {
    return new vulkan_graphicslogicdevice(
        graphicslogicdeviceargs{
            .device = this
        }
    ); 
} 

std::vector<vk::ExtensionProperties> vulkan_graphicsphysicaldevice::getextensions() const {
    auto extensions = m_device.enumerateDeviceExtensionProperties();
    return extensions;
}

vk::Device vulkan_graphicsphysicaldevice::vk_createdevice(const vk::DeviceCreateInfo& _args) const {
    return m_device.createDevice(_args);
}
