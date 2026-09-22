#include <gfx/vulkan/arch/vulkan_graphicsphysicaldevice.h>

vulkan_graphicsphysicaldevice::vulkan_graphicsphysicaldevice(vk::PhysicalDevice _device) {
    m_device = _device;
}
vulkan_graphicsphysicaldevice::~vulkan_graphicsphysicaldevice(){

}