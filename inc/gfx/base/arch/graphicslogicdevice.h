#ifndef MAIN_GFX_ARCH_GRAPHICSDEVICE_H_
#define MAIN_GFX_ARCH_GRAPHICSDEVICE_H_

#include <pch.h>
#include <gfx/base/arch/graphicsqueue.h>

// forward declaration.
class graphicsphysicaldevice; 



namespace graphicsdeviceDefs {
    enum class contextType : uint8_t {
        graphics,
        copy,
        compute
    };

    enum class devicefeature : uint8_t {
        geometry_shader = 1u << 0,
        tessellation_shader = 1u << 1,
        sampler_anisotropy = 1u << 2,
        fill_mode_non_solid = 1u << 3,
        depth_clamp = 1u << 4,
        depth_bias_clamp = 1u << 5,
        sample_rate_shading = 1u << 6
    };


};


struct graphicslogicdeviceargs {
    // you need to create the queue capabilities as well
    graphicsphysicaldevice* device;
    graphicsdeviceDefs::devicefeature features;
    std::vector<graphicsqueuereqs> queuerequirements;
    graphicsqueueDefs::capabilities capabilities;
};

class graphicscontext;
using gfxcontext = std::shared_ptr<graphicscontext>;

class graphicslogicdevice {

public:
    graphicslogicdevice(const graphicslogicdeviceargs& _args) : 
        m_physicaldevice { _args.device } {
            assert(m_physicaldevice != nullptr && "Something went wrong! No Physical Device somehow!");

        }


    inline gfxcontext createcontext(graphicsdeviceDefs::contextType _type) {
        return createcontextImpl(_type);
    }

    inline void submitcontext(gfxcontext _context) {
        // do something.
    }
    
protected:
    virtual gfxcontext createcontextImpl(graphicsdeviceDefs::contextType _type) = 0;

    graphicsphysicaldevice* m_physicaldevice;
};

#endif // MAIN_GFX_ARCH_GRAPHICSDEVICE_H_