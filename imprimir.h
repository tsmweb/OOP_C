/*
 * Tipo: IImprimir <interface>
 * Descrição: Arquivo de definição da interface IImprimir
 * Autor: Tiago Martins (tiago.tsmweb@gmail.com)
 */
#ifndef IImprimir_H
#define IImprimir_H

#include "object.h"

// método da interface IImprimi
typedef void (*Imprimir)(Object *instance);

typedef struct 
{
    Object *instance;
    Imprimir imprimi;
} IImprimir;

#endif