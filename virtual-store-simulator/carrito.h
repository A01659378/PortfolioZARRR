#ifndef _CARRITO_H_
#define _CARRITO_H_

#include <vector>
#include "producto.h"

using std::vector;

class Carrito{
    public:
    float total;
    vector <Producto> carrito;
    vector <int> cantidades;
    int cantidad_pedida;
    Carrito();
    float calcula_total();
    void añadir_producto(Producto p, int cant);
    void mostrar_carrito();
    void actualizar_cantidad(string id, int nueva_cantidad);
};

#endif