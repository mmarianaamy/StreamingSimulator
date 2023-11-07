#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Usuario{
private:
    string cuenta, nombre;
    vector<int> misVideos;
    int contadorVideos;
public:
    Usuario();
    int getContadorVideos();
    int getUnIDMisVideos(int);
    int operator +=(int);
    string getNombre();
    string getCuenta();
    void setNombre(string);
    void setCuenta(string);
};

Usuario::Usuario(){
    nombre = "Mariana";
    cuenta = "1234";
    contadorVideos = 0;
}

int Usuario::getContadorVideos(){
    return contadorVideos;
}

int Usuario::getUnIDMisVideos(int n){
    if (n < contadorVideos){
        return misVideos[n];
    }
    return 1000;
}

string Usuario::getNombre(){
    return nombre;
}

string Usuario::getCuenta(){
    return cuenta;
}

void Usuario::setNombre(string s){
    nombre = s;
}

void Usuario::setCuenta(string s){
    cuenta = s;
}

int Usuario::operator +=(int n){
    if (contadorVideos < 20){
        for(int i = 0; i < contadorVideos; i++){
            if (misVideos[i] == n){
                return 0;
            }
        }
        misVideos.push_back(n);
        contadorVideos += 1;
        return 0;
    }
    return 0;
}