#include "video.h"
#include "contenido.h"
#include "plataforma.h"
#include "pelicula.h"
#include "serie.h"
#include "episodio.h"

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::stringstream;
using std::to_string;
using std::out_of_range;
using std::invalid_argument;
using std::stoi;

Plataforma::Plataforma()
{
    cargarArchivo();
}

void Plataforma::cargarArchivo(){
    string linea;
    string id;
    string nombre;
    string duracion;
    string genero;
    string calificacion;    
    string fecha_estreno;
    string nombre_ep;
    string temporada;
    string num_ep;
    string id_ep;

    ifstream archivo;
    archivo.open ("/workspaces/integrador-A01659378/BasePeliculas.csv");

    getline(archivo, linea); //encabezados
    
    while (getline(archivo, linea)) // leer línea a línea
    {
        stringstream token(linea);
        
        getline(token, id, ',');
        getline (token, nombre, ',');
        getline(token, duracion, ',');
        //getline(token, genero, ',');

        if (linea.find('"', token.tellg()) != string::npos) {
            getline(token, genero, '"'); // Leer hasta el primer conjunto de comillas
            getline(token, genero, '"'); // Leer contenido entre comillas
            token.ignore(1, ','); // Ignorar la coma siguiente
        } else {
            getline(token, genero, ',');
        }

        getline (token, calificacion, ',');
        getline(token, fecha_estreno, ',');
        getline(token, nombre_ep, ',');
        getline (token, temporada, ',');
        getline(token, num_ep, ',');
        getline(token, id_ep, ',');

        float duracionFloat = stof(duracion);
        float calificacionFloat = stof(calificacion);
        
        if (nombre_ep.empty()){
            Pelicula *pelicula = new Pelicula(id, nombre, duracionFloat, calificacionFloat, fecha_estreno, genero);
            agregar(pelicula);
        }else{
            int temporadaInt = stoi(temporada);
            int num_epInt = stoi(num_ep);
            Episodio *episodio = new Episodio(id, nombre_ep, duracionFloat, calificacionFloat, fecha_estreno, temporadaInt, num_epInt, id_ep);
            
            bool serieExiste = false;
            for(int i = 0; i < contenido.size(); i++){
                Serie* serie = dynamic_cast<Serie*>(contenido[i]); //downcasting
                //ver si nombre ya existe 
                //si sí, agregar episodio
                if (serie && serie->getNombre() == nombre) {
                    serie->agregarEpisodios(episodio);
                    serieExiste = true;
                    break;
                }
            }
            //si no, crear serie
            if (serieExiste == false) {
                Serie* nuevaSerie = new Serie(id, nombre, genero);
                nuevaSerie->agregarEpisodios(episodio);
                agregar(nuevaSerie);
            }
        }
    }
    archivo.close();
}

void Plataforma::mostrarMenu()
{
        while(true)
        {
            string option;
            int opcion;
            cout << endl;
            cout << "***** MENÚ PRINCIPAL *****" << endl;
            cout << "\n 1) Videos mayores a...\n 2) Videos de cierto género\n 3) Episodios de una serie\n 4) Comparar películas\n 5) Calificar un video\n 6) Salir" << endl;
            cin >> option;

            try 
            {
                opcion = stoi(option); // Convierte la entrada a un número entero
                if (opcion < 1 || opcion > 6) 
                {
                    throw out_of_range("Número fuera de rango.");
                }

                if(opcion==1)
                {
                    float calif;
                    cout << "Ingrese la calificación para mostrar los videos mayores a esta: ";
                    cin >> calif;
                    for(int i=0; i<contenido.size(); i++)
                    {
                        contenido[i]->filtrarCalificacion(calif);
                    }
                }

                else if(opcion==2)
                {
                    string genero;
                    cout << "Ingrese el género: ";
                    cin.ignore();
                    getline(cin,genero);
                    for(int i=0; i<contenido.size(); i++)
                    {
                        contenido[i]->filtrarGenero(genero);
                    }
                }
                
                else if(opcion==3)
                {
                    string nombreSerie;
                    cout << "Ingrese el nombre de la serie para mostrar sus episodios: " << endl;
                    cin.ignore();
                    getline(cin,nombreSerie);
                    cout << "Nombre de los episodios de la serie: " << endl;
                    for(int i=0; i<contenido.size(); i++)
                    {
                        contenido[i]->mostrar(nombreSerie);
                    }
                }

                else if(opcion==4)
                {
                    float calificacion1;
                    cout << "Ingrese la calificación para comparar películas: " << endl;
                    cin >> calificacion1;
                    for(int i=0; i<contenido.size(); i++)
                    {
                        Pelicula* p = dynamic_cast<Pelicula*>(contenido[i]);
                        if(p!=0){
                            contenido[i]->operator>(calificacion1);
                        }
                    }
                }
                else if(opcion==5)
                {
                    string nombre3;
                    float calificacion3;
                    cout << "Ingrese el nombre del video: ";
                    cin.ignore();
                    getline(cin,nombre3);
                    cout << "Ingrese la calificación: ";
                    cin >> calificacion3;
                    for(int i=0; i<contenido.size(); i++)
                    {
                        contenido[i]->calificar(nombre3, calificacion3);
                    }
                }
                else if(opcion==6)
                {
                    break;
                }

            } 
            catch (invalid_argument &) 
            {
            cout << "Error: Entrada no válida. Por favor ingrese un número entre 1 y 6." << endl;
            } 
            catch (out_of_range &) 
            {
            cout << "Error: La opción debe estar entre 1 y 6. Intente de nuevo." << endl;
            }
        }  
}

void Plataforma::agregar(Contenido* cont){
    contenido.push_back(cont);
}