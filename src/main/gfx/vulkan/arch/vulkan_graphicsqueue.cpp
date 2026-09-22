#include <gfx/vulkan/arch/vulkan_graphicsqueue.h>


vulkan_graphicsqueue::vulkan_graphicsqueue(
    vk::Queue _queue,
    graphicsqueueDefs::capabilities _capabilities
) : graphicsqueue(_capabilities), m_queue(_queue) {
    
}
vulkan_graphicsqueue::~vulkan_graphicsqueue() {
    
}