#ifndef _INVENTARIO_H_
#define _INVENTARIO_H_

#include <vector>
#include <string>
#include "producto.h"
#include <fstream>
#include <iostream>
#include <sstream>

using std::ifstream;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Inventario{
    public:
    vector <Producto> inventario;
    Inventario();
    Producto buscar_producto(string id0); 
    void mostrar_inventario();
    void actualizar_cantidad(string id, int nueva_cantidad);

};

#endif