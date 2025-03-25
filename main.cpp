#include "video.h"
#include "pelicula.h"
#include "serie.h"
#include "plataforma.h"
#include "contenido.h"
#include <iostream>
using std::cout;

int main()
{
    Plataforma plataforma = Plataforma();
    plataforma.mostrarMenu();
}