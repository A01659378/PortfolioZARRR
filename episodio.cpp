#include "episodio.h"
#include "video.h"
#include <iostream>
using std::cout;
using std::endl;

Episodio::Episodio()
{
    temporada = 0;
    num_episodio = 0;
    id_episodio = "";
}

Episodio::Episodio(string id1, string nombre1, float duracion1, float calificacion1, string fecha_estreno1, int temporada1, int num_episodio1, string id_episodio1):Video(id1, nombre1, duracion1, calificacion1, fecha_estreno1)
{
    temporada = temporada1;
    num_episodio = num_episodio1;
    id_episodio = id_episodio1;
}

void Episodio::operator>(float calif)
{
    if (calificacion > calif)
    {
        cout << *this;
    }
}

ostream &operator<<(ostream &os, Episodio &episodio)
{
    os << episodio.nombre << " " << episodio.id_episodio << " " << episodio.duracion << " " << episodio.calificacion << " " << episodio.temporada << " " << episodio.num_episodio << " " << episodio.fecha_estreno << endl;
    return os;
}

void Episodio::mostrar(string nombreSerie)
{
    if (this->nombre == nombreSerie)
    {
        cout << *this;
    }
}

void Episodio::calificar(string nombre3, float calificacion3)
{
    this->calificacion = calificacion3;
}

void Episodio::filtrarCalificacion(float calificacion4)
{
    if (this->calificacion > calificacion4)
    {
        cout << *this;
    }
}

string Episodio::getId()
{
    return this->id_episodio;
}
