#include <sdl3/SDL_vulkan.h>
#include <vulkan/vulkan.hpp>
#include <gfx/vulkan/arch/vulkan_graphicsinstance.h>
#include <gfx/vulkan/arch/vulkan_graphicsphysicaldevice.h>


namespace {
    VkApplicationInfo generateappinfo() {
        VkApplicationInfo appInfo {
            .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
            .pApplicationName = "Vulkan Sandbox",
            .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
            .apiVersion = VK_API_VERSION_1_4
        };
        return appInfo;
    }

    VkInstanceCreateInfo generateinstanceinfo(VkApplicationInfo& appInfo) {
        uint32_t extcount;
        const char* const*  ext{};
        ext = SDL_Vulkan_GetInstanceExtensions(&extcount);
        

        VkInstanceCreateInfo createInfo {
            .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
            .pApplicationInfo = &appInfo,
            .enabledLayerCount = 0,
            .enabledExtensionCount = extcount,
            .ppEnabledExtensionNames = ext
        };
        
        return createInfo;
    }

    void getphysicaldevices(
        std::vector<std::unique_ptr<graphicsphysicaldevice>>& devicelist,
        const VkInstance& instance
    ) {
        uint32_t devicecount;
        vkEnumeratePhysicalDevices(instance, &devicecount, nullptr);
        std::vector<VkPhysicalDevice> devices(devicecount);
        vkEnumeratePhysicalDevices(instance, &devicecount, devices.data());
        for (VkPhysicalDevice& device : devices) {
            devicelist.push_back(
                std::make_unique<vulkan_graphicsphysicaldevice>(device)
            );
        }
    }

}



void vulkan_graphicsinstance::init() {
    m_appinfo = generateappinfo();
    m_instanceCreateInfo = generateinstanceinfo(m_appinfo);
    VkResult res = vkCreateInstance(&m_instanceCreateInfo, nullptr, &m_instance);
    if (res != VK_SUCCESS) {
        throw("instance creation failed.");
    }
    getphysicaldevices(m_devicelist, m_instance);
    // pick the best one out of these.
    pickbestdevice();


}
void vulkan_graphicsinstance::cleanup() {
    vkDestroyInstance(m_instance, nullptr);
}

void vulkan_graphicsinstance::pickbestdevice() {
    // statistics tracking


    uint32_t bestindex{};
    uint32_t bestscore{};
    for (uint32_t i{}; i < m_devicelist.size(); ++i) {
        auto& deviceptr = m_devicelist.at(i); 
        auto& device = reinterpret_cast<vulkan_graphicsphysicaldevice*>(deviceptr.get())->m_device;
        vk::PhysicalDeviceProperties props = device.getProperties();
        uint32_t score{};

        
        if (props.deviceType == vk::PhysicalDeviceType::eDiscreteGpu) {
            score += 1000;
        }
        else if (props.deviceType == vk::PhysicalDeviceType::eIntegratedGpu) {
            score += 750;
        }
        score += props.limits.maxImageDimension2D;   
        // score += props.limits.

        if (bestscore < score) {
            bestscore = score;
            bestindex = i;
        }
    }
    setselecteddevice(bestindex);
    {
        auto& device = reinterpret_cast<vulkan_graphicsphysicaldevice*>(m_devicelist.at(bestindex).get())->m_device;
        auto props = device.getProperties();    
        std::cout << "selecting gpu: [" << props.deviceName << "]" << std::endl; 
    }
}
