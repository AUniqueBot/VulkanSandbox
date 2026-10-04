#ifndef MAIN_GFX_ARCH_GRAPHICSCONTEXT_H_
#define MAIN_GFX_ARCH_GRAPHICSCONTEXT_H_

#include <pch.h>


struct drawargs {
    uint32_t offset;
    uint32_t size;
};

struct drawindexedargs {
    uint32_t startindex;
    uint32_t indexcount;
};


class graphicscontext {
    inline void draw(const drawargs& _args) const {
        drawImpl(_args);
    }
    inline void drawindexed(const drawindexedargs& _args) const {
        drawindexedImpl(_args);
    }


private:
    virtual void drawImpl(const drawargs& _args) const = 0;
    virtual void drawindexedImpl(const drawindexedargs& _args) const = 0;
};

#endif // MAIN_GFX_ARCH_GRAPHICSCONTEXT_H_