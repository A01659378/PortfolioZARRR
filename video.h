#ifndef _VIDEO_H_
#define _VIDEO_H_

#include <string>
using std::string;

class Video
{    
        protected:
        string nombre;
        float calificacion;
        string id;
        float duracion;
        
        public:
        string fecha_estreno;
        Video();
        Video(string id1, string nombre1, float duracion1, float calificacion1, string fecha_estreno1);
        bool operator == (string nombre1);
        string getNombre();
};

#endif