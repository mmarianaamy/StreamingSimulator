#include <iostream>
#include "Video.h"

class Pelicula:public Video{
public:
    Pelicula();
    Pelicula(int v, int d, int c, string t, string g);
    void muestra();
};

Pelicula::Pelicula(int v, int d, int c, string t, string g):Video(v, d, c, t, g){
    
}

void Pelicula::muestra(){
    cout << getIdVideo() << " " << getTitulo() << " Genero: " << getGenero() << " Duracion: " << getDuracion() << " Calificacion: " << getCalificacion() << endl;
}

