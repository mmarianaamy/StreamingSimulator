#include <iostream>
#include <string>
#include "Video.h"

using namespace std;

class Episode:public Video{
private:
    std::string serie;
    int numEp, numTemp;
public:
    Episode();
    Episode(int, int, int, std::string, std::string, std::string, int, int);
    void setSerie(string);
    string getSerie();
    void setNumEp(int);
    int getNumEp();
    void setNumTemp(int);
    int getNumTemp();
    void muestra();
};

Episode::Episode(){
    
}

Episode::Episode(int v, int d, int c, string t, string g, string s, int ne, int nt):Video(v, d, c, t, g){
    serie = s;
    numEp = ne;
    numTemp = nt;
}

void Episode::setSerie(string s){
    serie = s;
}

string Episode::getSerie(){
    return serie;
}

void Episode::setNumEp(int n){
    numEp = n;
}

int Episode::getNumEp(){
    return numEp;
}

void Episode::setNumTemp(int n){
    numTemp = n;
}

int Episode::getNumTemp(){
    return numTemp;
}

void Episode::muestra(){
    cout << getIdVideo() << " " << getTitulo() << " Serie: " << serie << " Temporada: " << numTemp << " Episodio: " << numEp << " Genero: " << getGenero() << " Duracion: " << getDuracion() << " Calificacion: " << getCalificacion() << endl;
}