#include "video.h"
#include <iostream>

using std::cout;
using std::endl;

Video::Video()
{
    id = "";
    nombre = "";
    duracion = 0.0;
    calificacion = 0.0;
    fecha_estreno = "";
}

Video::Video(string id1, string nombre1, float duracion1, float calificacion1, string fecha_estreno1)
{
    id = id1;
    nombre = nombre1;
    duracion = duracion1;
    calificacion = calificacion1;
    fecha_estreno = fecha_estreno1;
}

bool Video::operator == (string nombre1){
    if (nombre == nombre1){
        return true;
    }
    return false;
}

string Video::getNombre()
{
    return nombre;
}