#ifndef MAIN_GFX_ARCH_GRAPHICSDEVICE_H_
#define MAIN_GFX_ARCH_GRAPHICSDEVICE_H_

#include <pch.h>
#include <vulkan/vulkan.hpp>


struct graphicsdevice {
    vk::PhysicalDevice m_physicaldevice;
    vk::Device m_device;
};

#endif // MAIN_GFX_ARCH_GRAPHICSDEVICE_H_