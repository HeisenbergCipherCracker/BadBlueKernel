#ifndef __CACTUSOSLIB__API_H
#define __CACTUSOSLIB__API_H

#include <types.h>

namespace LIBHeisenKernel
{
    class API
    {
    public:
        /**
         * Initialize the CactusOS Api for this process
        */
        static void Initialize();
    };
}

#endif