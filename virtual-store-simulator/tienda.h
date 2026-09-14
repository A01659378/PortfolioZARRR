#ifndef _TIENDA_H_
#define _TIENDA_H_

#include "inventario.h"
#include "carrito.h"

class Tienda
{
    private:
    Inventario inventario;
    Carrito carrito;
    
    public:
    Tienda();
    void mostrar_opciones();
};

#endif