#ifndef VULKAN_GRAPHICSPHYSICALDEVICE_H_
#define VULKAN_GRAPHICSPHYSICALDEVICE_H_
#include <gfx/base/arch/graphicsphysicaldevice.h>
#include <gfx/vulkan/arch/vulkan_graphicslogicdevice.h>

class vulkan_graphicsphysicaldevice : public graphicsphysicaldevice {
public:
    vulkan_graphicsphysicaldevice(vk::PhysicalDevice _device);
    ~vulkan_graphicsphysicaldevice();

    std::vector<vk::ExtensionProperties> getextensions() const;
    vk::Device vk_createdevice(const vk::DeviceCreateInfo& _args) const;

private:
    graphicslogicdevice* createlogicdeviceImpl() override;


private:
    friend class vulkan_graphicsinstance;
    vk::PhysicalDevice m_device;
    std::vector<vk::QueueFamilyProperties> m_queuefamilies;
};


#endif // VULKAN_GRAPHICSPHYSICALDEVICE_H_