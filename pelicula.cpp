#include "pelicula.h"
#include "video.h" 

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

ostream & operator << (ostream &os, Pelicula &pelicula){
    os << pelicula.nombre << " " << pelicula.id << " " <<  pelicula.duracion << " " << pelicula.calificacion << " " <<  pelicula.fecha_estreno << " " <<  pelicula.genero << endl;
    return os;
}


void Pelicula::operator > (float calif){
    if (calificacion > calif){
        cout << *this;
    }
}

Pelicula::Pelicula(){
    //constructor vacio
}

Pelicula::Pelicula(string id1, string nombre1, float duracion1, float calificacion1, string fecha_estreno1, string genero1) : Video(id1, nombre1, duracion1, calificacion1, fecha_estreno1){
    genero = genero1;
}

void Pelicula::filtrarCalificacion(float calificacion1){
    if (calificacion > calificacion1){
        cout << *this;
    }
}

void Pelicula::filtrarGenero(string genero1){
    if (genero == genero1){
        cout << endl << "Peliculas: " << endl;
        cout << *this;
    }
}

void Pelicula::calificar(string nombre1, float calificacion1){
    if (nombre == nombre1){
        calificacion = calificacion1;
        cout << *this;
    }
}

void Pelicula::mostrar(string nombre_serie)
{
    if (this->nombre == nombre_serie)
    {
        cout << *this;
    }
}

string Pelicula::getNombre() {
        return nombre;
}