#ifndef GRAPHICSINSTANCE_H_
#define GRAPHICSINSTANCE_H_
#include <pch.h>

#include <gfx/base/arch/graphicsphysicaldevice.h>

// abstract class does nothing on its own.
class graphicsinstance {
public:
    friend class window;
public:
    virtual void init() = 0;
    virtual void cleanup() = 0;
    
    inline void setselecteddevice(uint32_t _t) { m_selecteddevice = _t; };
public:
    std::vector<std::unique_ptr<graphicsphysicaldevice>> m_devicelist;
    uint32_t m_selecteddevice{};
};



#endif // GRAPHICSINSTANCE_H_