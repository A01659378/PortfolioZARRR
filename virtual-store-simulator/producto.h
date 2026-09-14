#ifndef _PRODUCTO_H_
#define _PRODUCTO_H_ 

#include <string>

using std::string;

class Producto 
{ 
    private:
    std::string ID;
    std::string nombre;
    float precio;
    int cantidad;

    public:
    Producto();
    Producto(std::string ID0, std::string nombre0, float precio0, int cantidad0);
    void set_cantidad(int nueva_cant);
    std::string get_ID();
    std::string get_nombre();
    float get_precio();
    int get_cantidad();
    std::string imprimir();
}; 

#endif