#ifndef GRAPHICSPHYSICALDEVICE_H_
#define GRAPHICSPHYSICALDEVICE_H_
#include <gfx/base/arch/graphicslogicdevice.h>

namespace graphicsphysicaldeviceDefs {
    enum class capabilities : uint8_t {
        none = 1u << 0,
        graphics = 1u << 1,
        compute = 1u << 2,
        transfer = 1u << 3
    };

    inline bool testcapability(const capabilities& _totest, const capabilities& _test) {
        return (uint8_t)_totest & (uint8_t)_test;
    }
}


class graphicsphysicaldevice {
public:
    virtual ~graphicsphysicaldevice() = default;

public:
    std::shared_ptr<graphicslogicdevice> createlogicdevice() {
        return std::shared_ptr<graphicslogicdevice>(createlogicdeviceImpl());
    }
private:
    virtual graphicslogicdevice* createlogicdeviceImpl() = 0;

};


#endif // GRAPHICSPHYSICALDEVICE_H_