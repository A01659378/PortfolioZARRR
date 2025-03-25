#include "serie.h"
#include "video.h"
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

Serie::Serie()
{
    episodios = {};
    idSerie = "";
    nombreSerie = "";
    generoSerie = "";
}

Serie::Serie(string id1, string nombre1, string genero1)
{
    idSerie = id1;
    nombreSerie = nombre1;
    generoSerie = genero1;
}

void Serie::operator>(float calif)
{
    for (int i = 0; i < episodios.size(); i++)
    {
        *episodios[i] > calif;
        cout << *this;
    }
}

ostream &operator<<(ostream &os, Serie &serie)
{
    os << serie.nombreSerie << " " << serie.idSerie << " " << serie.generoSerie << " " << endl;
    return os;
}

void Serie::agregarEpisodios(Episodio *episodio2)
{
    episodios.push_back(episodio2);
}

void Serie::filtrarCalificacion(float calificacion4)
{
    for (int i = 0; i < episodios.size(); i++)
    {
        episodios[i]->filtrarCalificacion(calificacion4);
    }
    cout << *this;
}

void Serie::filtrarGenero(string genero5)
{
    if (this->generoSerie == genero5)
    {
        cout << endl << "Serie:" << endl;
        cout << *this;
        cout << "Episodios: " << endl;
        for (int i = 0; i < episodios.size(); i++)
        {
                cout << *episodios[i];
        }
    }
}

void Serie::calificar(string nombre3, float calificacion3)
{
    if (this->nombreSerie == nombre3)
    {
        cout << "Tu calificación ha sido registrada con éxito en estos episodios." << endl;
        for (int i = 0; i < episodios.size(); i++)
        {
            episodios[i]->calificar(nombre3, calificacion3);
            cout << *episodios[i];
        }
    }
}



void Serie::mostrar(string nombre_serie)
{
    if (this->nombreSerie == nombre_serie)
    {
        for (int i = 0; i < episodios.size(); i++)
        {
            //cout << episodios[i]->getId() << endl;
            cout << *episodios[i];
        }
    }
}

string Serie::getNombre() 
{
    return nombreSerie;
}