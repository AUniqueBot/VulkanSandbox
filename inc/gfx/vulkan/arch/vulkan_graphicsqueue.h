#ifndef VULKAN_GRAPHICSQUEUE_H_
#define VULKAN_GRAPHICSQUEUE_H_

#include <gfx/base/arch/graphicsqueue.h>
#include <vulkan/vulkan.hpp>

class vulkan_graphicsqueue : public graphicsqueue {
public:
    vulkan_graphicsqueue(vk::Queue _queue) ;
    ~vulkan_graphicsqueue() override;

private:
    vk::Queue m_queue;
};

#endif // VULKAN_GRAPHICSQUEUE_H_