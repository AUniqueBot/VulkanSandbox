#ifndef MAIN_GFX_ARCH_GRAPHICSDEVICE_H_
#define MAIN_GFX_ARCH_GRAPHICSDEVICE_H_

#include <pch.h>


namespace graphicsdeviceDefs {
    enum class contextType : uint8_t {
        graphics,
        copy,
        compute
    };



};

class graphicscontext;
using gfxcontext = std::shared_ptr<graphicscontext>;

class graphicslogicdevice {
    
    inline gfxcontext createcontext(graphicsdeviceDefs::contextType _type) {
        return createcontextImpl(_type);
    }

    inline void submitcontext(gfxcontext _context) {
        // do something.
    }
    
protected:
    virtual gfxcontext createcontextImpl(graphicsdeviceDefs::contextType _type) = 0;


};

#endif // MAIN_GFX_ARCH_GRAPHICSDEVICE_H_