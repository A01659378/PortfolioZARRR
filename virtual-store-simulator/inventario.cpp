#include "inventario.h"
#include "producto.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::ifstream;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::stoi;
using std::stof;

Inventario::Inventario(){
    ifstream archivo;
    archivo.open("C:\\Users\\Abi\\Documents\\GitHub\\3-integrador-A01659378\\inventario.csv");
    string linea;
    while (getline(archivo, linea)){
        stringstream token(linea);
        string id;
        string nombre;
        string precio_string;
        string cantidad_string;
        getline(token, id, ','); //comillas sencillas = char
        getline(token, nombre, ',');
        getline(token, precio_string, ',');
        getline(token, cantidad_string, ',');
        float precio = stof(precio_string);
        int cantidad = stoi(cantidad_string);
        //aqui se manda llamar el constructor de producto
        Producto producto = Producto(id, nombre, precio, cantidad);
        inventario.push_back(producto);   
    }
    archivo.close();
}

void Inventario::mostrar_inventario(){
    for(int i = 0; i < inventario.size(); i++) {
        Producto producto = inventario[i];
        cout << producto.imprimir() << endl;
        cout << "******************" << endl;
    }
}

void Inventario::actualizar_cantidad(string id, int nueva_cantidad){
    for (int i = 0; i < inventario.size(); i++) {
        if (id == inventario[i].get_ID()) {
            nueva_cantidad = inventario[i].get_cantidad() - nueva_cantidad;
            inventario[i].set_cantidad(nueva_cantidad);
            break;
        }
    }
}

Producto Inventario::buscar_producto(string id0){
    Producto p_vacio;
    for(int i = 0; i < inventario.size(); i++) {
        if(id0 == inventario[i].get_ID()){
            return  inventario[i];
        }
    }
    return p_vacio;
}