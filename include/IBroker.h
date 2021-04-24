#pragma once
#include "Interfacedllexport.h"

class LIB_EXPORT IBroker {
public:
    enum class INTERFACE_IMPL {
        IPROBLEM,
        ISOLVER,
        TOTAL_INTERFACE_IMPL
    };
    
    IBroker() = default;
    virtual ~IBroker() = 0;

    virtual bool canCastTo(INTERFACE_IMPL impl) const = 0;
    virtual void* getInterfaceImpl(INTERFACE_IMPL impl) const = 0;
    virtual void release() = 0;

private:
    IBroker(const IBroker&) = delete;
    IBroker& operator=(const IBroker&) = delete;
};