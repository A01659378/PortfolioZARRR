#include "producto.h"
#include "inventario.h"
#include "carrito.h"
#include "tienda.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

Tienda::Tienda()
{
    
}

void Tienda::mostrar_opciones(){
    while(true){
        int opcion;
        cout << "***** MENU PRINCIPAL *****" << endl;
        cout << "1) Seleccionar producto\n2) Ver carrito de compras\n3) Terminar compra\n4) Salir" << endl;
        cin >> opcion;
        if(opcion==1){
            string ID_selec;
            int cant_selec;

            cout << "\n***** SELECCIONAR PRODUCTO *****" << endl;
            inventario.mostrar_inventario();
            cout << "\n¿Qué producto deseas comprar?\nPor favor escribe el ID correspondiente al producto tal cual como se muestra en el inventario:" << endl;
            cin >> ID_selec;
            Producto producto = inventario.buscar_producto(ID_selec);
            if (producto.get_ID() == ID_selec){
                cout << "¿Cuántas unidades deseas comprar?" << endl;
                cin >> cant_selec;
                cout << endl;
                if(cant_selec < producto.get_cantidad()){
                    carrito.añadir_producto(producto, cant_selec);
                    inventario.actualizar_cantidad(ID_selec, cant_selec);
                    carrito.actualizar_cantidad(ID_selec, cant_selec);
                }else{
                    cout << "Cantidad solicitada no disponible en inventario." << endl;
                    cout << endl;
                }
            }else{
                cout << "Por favor selecciona un ID existente" << endl;
                cout << endl;
            }        
        }else if(opcion == 2){
            cout << "\nHasta ahora estos son los productos de tu carrito: " << endl;
            carrito.mostrar_carrito();
            cout << endl;
        }else if(opcion == 3){
            cout << "El total de tu compra es: " << carrito.calcula_total() << endl;
            cout << "¡Muchas gracias por comprar en TiendaEliAbi.com!" << endl;
            cout << endl;
        }else if(opcion == 4){
            break;
        }else{
            cout << "Por favor selecciona una opción existente." << endl;
            cout << endl;
            break;
        }
    } 
}