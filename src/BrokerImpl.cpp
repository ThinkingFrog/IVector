/*
#include "IBroker.h"
#include "IProblem.h"
#include "Interfacedllexport.h"

namespace {
    class BrokerImpl : public IBroker {
    private:
        static BrokerImpl* m_instance;
    public:
        static BrokerImpl* instance() {
            if (m_instance == nullptr)
                m_instance = new (std::nothrow) BrokerImpl();
            return m_instance;
        }

        bool canCastTo(INTERFACE_IMPL impl) const override {
            return (impl == INTERFACE_IMPL::IPROBLEM);
        }

        void* getInterfaceImpl(INTERFACE_IMPL impl) const override {
            // return (impl == INTERFACE_IMPL::IPROBLEM) ? IProblem::createProblem() : NULL;
        }

        void release() override {
            delete m_instance;
            m_instance = nullptr;
        }
    };
    BrokerImpl* BrokerImpl::m_instance = nullptr;
};

extern "C" {
    LIB_EXPORT void* getBroker() {
        return (void*) BrokerImpl::instance();
    }
}

APP

typedef void* (*ptr_getBroker)();

#ifndef _WIN32
    #define LIB void*
    #define LOAD_LIBRARY(lib_name) dlopen(lib_name, RTLD_LAZY)
    #define GET_BROKER(lib) dlsym(lib)
    #define CLOSE_LIBRARY(lib) dlclose(lib)
#else
    #define LIB HINSTANCE
    #define LOAD_LIBRARY(lib_name) ::LoadLibrary(lib_name)
    #define GET_BROKER(lib) ::GetProcAddress(lib)
    #define CLOSE_LIBRARY(lib) ::FreeLibrary(lib)

int main() {
    LIB lib = LOAD_LIBRARY("");
    if (lib == NULL)
        //выход
    ptr_getBroker pGetBroker = (ptr_getBroker)GET_BROKER(lib);
    IBroker* pBroker = reinterpreter_cast<IBroker*>((*pGetBroker)());
    
    bool isProblem = pBroker->canCastTo(IPROBLEM);
    if (!isProblem)
        //выход

    IProblem pProblem = reinterpreter_cast<IProblem*>(pBroker->gerInterfaceImpl(IPROBLEM));

    ...
    
    pBroker->release();
    CLOSE_LIBRARY(lib);
}
*/