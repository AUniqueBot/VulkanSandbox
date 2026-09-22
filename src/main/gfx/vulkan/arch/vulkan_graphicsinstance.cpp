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


}
void vulkan_graphicsinstance::cleanup() {
    vkDestroyInstance(m_instance, nullptr);
}