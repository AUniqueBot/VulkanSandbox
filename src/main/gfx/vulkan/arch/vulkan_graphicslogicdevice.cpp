#include <gfx/vulkan/arch/vulkan_graphicslogicdevice.h>


namespace {
    std::vector<vk::DeviceQueueCreateInfo> generatequeuecreateinfolist(
        const std::vector<graphicsqueuereqs>& _reqs
    ) {
        using CreateInfo = vk::DeviceQueueCreateInfo;
        std::vector<vk::DeviceQueueCreateInfo> data(_reqs.size());
        for (const graphicsqueuereqs& req : _reqs) {
            CreateInfo info(
                vk::DeviceQueueCreateFlagBits(), // Flags
                0,              // Queue family index
                req.queuecount,                            // Queue count
                &req.priority                // Pointer to queue priority array
            );
            data.push_back(info);

        }
        
        return data;
    }
};


vulkan_graphicslogicdevice::vulkan_graphicslogicdevice(
    const graphicslogicdeviceargs& _args
) : graphicslogicdevice(_args) {
    // we expect specifically the vk version here.
    // on construction use the physical device to do stuff.
    using vk_physicaldevice = vulkan_graphicsphysicaldevice; 
    vk_physicaldevice& physDevice = 
        *static_cast<vk_physicaldevice*>(m_physicaldevice); // get extensions.            
    
    
    // queue creation info factory.

    vk::PhysicalDeviceFeatures features{};
    

    vk::DeviceCreateInfo info;

    auto extensions = physDevice.getextensions(); // get extensions from
    info.enabledExtensionCount = static_cast<uint32_t>(extensions.size());

    



    m_logicdevice = physDevice.vk_createdevice(info);
    
}

gfxcontext vulkan_graphicslogicdevice::createcontextImpl(
    graphicsdeviceDefs::contextType _type
) {
    

    return nullptr;
}

