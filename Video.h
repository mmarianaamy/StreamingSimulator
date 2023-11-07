#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#include <iostream>
#include "string.h"

using namespace std;

class Video{
private:
    int idVideo, duracion, calificacion;
    string titulo, genero;
public:
    Video();
    Video(int, int, int, string, string);
    virtual void muestra();
    int getIdVideo();
    void setIdVideo(int);
    int getDuracion();
    void setDuracion(int);
    int getCalificacion();
    void setCalificacion(int);
    string getTitulo();
    void setTitulo(string);
    string getGenero();
    void setGenero(string);
};

Video::Video(){

}

Video::Video(int v, int d, int c, string t, string g){
    idVideo = v;
    duracion = d;
    calificacion = c;
    titulo = t;
    genero = g;
}

int Video::getIdVideo(){
    return idVideo;
}

void Video::setIdVideo(int n){
    idVideo = n;
}

int Video::getDuracion(){
    return duracion;
}

void Video::setDuracion(int n){
    duracion = n;
}

int Video::getCalificacion(){
    return calificacion;
}

void Video::setCalificacion(int n){
    calificacion = n;
}

string Video::getTitulo(){
    return titulo;
}

void Video::setTitulo(string s){
    titulo = s;
}

string Video::getGenero(){
    return genero;
}

void Video::setGenero(string s){
    genero = s;
}

void Video::muestra(){
    
}

#endif