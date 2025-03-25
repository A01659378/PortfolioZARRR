#ifndef _EPISODIO_H_
#define _EPISODIO_H_

#include "video.h"
#include <string>
#include <ostream>
using std::ostream;
using std::string;

class Episodio:public Video
{
    private:
        int temporada;
        int num_episodio;
        string id_episodio;
    public:
        Episodio();
        Episodio(string id1, string nombre1, float duracion1, float calificacion1, string fecha_estreno1, int temporada1, int num_episodio1, string id_episodio1);
        void operator > (float calif);
        friend ostream & operator << (ostream &os, Episodio &episodio);
        void mostrar(string nombreSerie);
        void calificar(string nombre3, float calificacion3);
        void filtrarCalificacion(float calificacion4);
        string getId();
};

#endif