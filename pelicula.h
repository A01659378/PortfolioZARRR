#ifndef _PELICULA_H_
#define _PELICULA_H_

#include "video.h"
#include "contenido.h"
#include <string>
#include <ostream>
using std::ostream;
using std::string;

class Pelicula : public Video, public Contenido{
    private:
        string genero;
    public:
        Pelicula();
        Pelicula(string id1, string nombre1, float duracion1, float calificacion1, string fecha_estreno1, string genero1);
        void operator > (float calif);
        friend ostream & operator << (ostream &os, Pelicula &pelicula);
        void filtrarCalificacion(float calificacion1);
        void filtrarGenero(string genero1);
        void calificar(string nombre1, float calificacion1);
        void mostrar(string nombre_serie);
        string getNombre();
};

#endif