#ifndef _SERIE_H_
#define _SERIE_H_

#include <string>
#include <vector>
#include <ostream>
#include "episodio.h"
#include "contenido.h"

using std::string;
using std::vector;
using std::ostream;

class Serie : public Contenido{
    private:
        vector <Episodio*>episodios;
        string idSerie;
        string nombreSerie;
        string generoSerie;
    public:
        Serie();
        Serie(string id1, string nombre1, string genero1);
        void operator > (float calif);
        friend ostream & operator << (ostream &os, Serie &serie);
        void agregarEpisodios(Episodio *episodio2);
        void filtrarCalificacion(float calificacion4);
        void filtrarGenero(string genero5);
        void calificar(string nombre3, float calificacion3);
        void mostrar(string nombre_serie);
        string getNombre();
};

#endif