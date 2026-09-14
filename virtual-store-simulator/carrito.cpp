#include "carrito.h"
#include "producto.h"
#include "inventario.h"
#include <vector>
#include "tienda.h"

using std::vector;

Carrito::Carrito(){
    total = 0;
    cantidad_pedida = 0;
}

void Carrito::añadir_producto(Producto p, int cant){
    carrito.push_back(p);
    cantidades.push_back(cant);
    /*cantidad_pedida = cant;
    if(cant < p.get_cantidad()){
        int cantidad_en_stock = p.get_cantidad() - cant;
    }*/
}

float Carrito::calcula_total(){
    total = 0;
    for(int i = 0; i < carrito.size(); i++) {
        total += carrito[i].get_precio() * cantidades[i];
    } 
    return total;
}

void Carrito::mostrar_carrito(){
    for(int i = 0; i < carrito.size(); i++) {
        Producto producto = carrito[i];
        cout << producto.imprimir() << endl;
        cout << "Cantidad solicitada: " << cantidades[i] << endl;
        cout << "******************" << endl;
    }
}

void Carrito::actualizar_cantidad(string id, int nueva_cantidad){
    for(int i = 0; i < carrito.size(); i++) {
        if (id == carrito[i].get_ID()) {
            nueva_cantidad = carrito[i].get_cantidad() - nueva_cantidad;
            carrito[i].set_cantidad(nueva_cantidad);
            break;
        }
    }
}