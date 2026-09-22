#ifndef GRAPHICSPHYSICALDEVICE_H_
#define GRAPHICSPHYSICALDEVICE_H_
#include <gfx/base/arch/graphicslogicdevice.h>

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