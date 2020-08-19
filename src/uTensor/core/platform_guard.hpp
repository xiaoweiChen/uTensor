#ifndef PLATFORM_GUARD_H
#define PLATFORM_GUARD_H

#define UTENSOR_PLATFORM_MBED 0
#ifdef MBED
#define UTENSOR_PLATFORM 0
#endif

#define UTENSOR_PLATFORM_ARDUINO 1
#ifdef ARDUINO
#define UTENSOR_PLATFORM 1
#endif

#define UTENSOR_PLATFORM_X86 2
#ifdef X86
#define UTENSOR_PLATFORM 2
#endif

#endif