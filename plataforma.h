#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include "contenido.h"
#include "pelicula.h"
#include <string>
#include <ostream>
#include <vector>
using std::vector;
using std::ostream;
using std::string;

class Plataforma{
    public:
    vector <Contenido*> contenido;
    Plataforma();
    void cargarArchivo();
    void mostrarMenu();
    void agregar(Contenido* cont);
};

#endif