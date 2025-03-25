#ifndef _CONTENIDO_H_
#define _CONTENIDO_H_

#include <string>
#include <ostream>
using std::ostream;
using std::string;

class Contenido{
    public:
        virtual void operator > (float calificacion) = 0;
        virtual void filtrarCalificacion(float calificacion) = 0;
        virtual void filtrarGenero(string genero) = 0;
        virtual void calificar(string nombre, float calificacion) = 0;
        virtual void mostrar(string nombre_serie) = 0;
        virtual string getNombre() = 0;
};

#endif