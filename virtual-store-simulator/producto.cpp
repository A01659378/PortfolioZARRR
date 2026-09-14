#include <iostream>
#include "producto.h"

Producto::Producto(){
    
}

Producto::Producto(string ID0, string nombre0, float precio0, int cantidad0){
    ID = ID0;
    nombre = nombre0;
    precio = precio0;
    cantidad = cantidad0;
}

void Producto::set_cantidad(int nueva_cant){
    cantidad = nueva_cant;
}

std::string Producto::get_ID()
{
    return ID;
}

std::string Producto::get_nombre()
{
    return nombre;
}

float Producto::get_precio()
{
    return precio;
}

int Producto::get_cantidad()
{
    return cantidad;
}

std::string Producto::imprimir()
{
    return "ID: " + ID + "\nNombre: " + nombre + "\nPrecio: " + std::to_string(precio) + "\nCantidad en stock: " + std::to_string(cantidad);
}