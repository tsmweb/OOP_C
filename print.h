/*
 * Type: IPrint <interface>
 * Description: IPrint interface definition file
 * Author: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#ifndef IPrint_H
#define IPrint_H

#include "object.h"

// IPrint interface method
typedef void (*Print)(const Object* instance);

typedef struct 
{
    Object* instance;
    Print print;
} IPrint;

#endif