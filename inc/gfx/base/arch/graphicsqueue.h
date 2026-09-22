#ifndef GRAPHICSQUEUE_H_
#define GRAPHICSQUEUE_H_

#include <gfx/base/arch/graphicsphysicaldevice.h>


namespace graphicsqueueDefs {
    enum class capabilities : uint8_t {
        none = 1u << 0,
        graphics = 1u << 1,
        compute = 1u << 2,
        transfer = 1u << 3
    };

    bool testcapability(const capabilities& _totest, const capabilities& _test) {
        return (uint8_t)_totest & (uint8_t)_test;
    }
};

class graphicsqueue {
public:
    graphicsqueue(
        graphicsqueueDefs::capabilities _capabilities
    ) : m_capabilities{_capabilities} {};
    virtual ~graphicsqueue() = default;
    
    inline bool testcapability(
        const graphicsqueueDefs::capabilities& _test
    ) {
        return graphicsqueueDefs::testcapability(m_capabilities, _test);
    }

protected:
    graphicsqueueDefs::capabilities m_capabilities;
};


#endif // GRAPHICSQUEUE_H_