#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Usuario.h"
#include "Pelicula.h"
#include "Episode.h"

using namespace std;

ifstream archivo(string s){
    ifstream a(s);
    return a;
}

int main(){
    int op = 0;
    Usuario yo;
    
    string line, c;
    vector<Video*> lista;

    ifstream inputFile;
    
    Episode ejemplo;

    cout << "Programa de streaming" << endl;
    while(op != 10){
        op = 0;
        string intento;
        cout << "---------" << endl;
        cout << "Opcion 0: Cargar archivo de datos" << endl;
        cout << "Opcion 1: Videos disponibles" << endl;
        cout << "Opcion 2: Filtrar por calificacion" << endl;
        cout << "Opcion 3: Filtrar por genero" << endl;
        cout << "Opcion 4: Mostrar datos de usuario" << endl;
        cout << "Opcion 5: Modificar datos de usuario" << endl;
        cout << "Opcion 6: Agregar video a lista" << endl;
        cout << "Opcion 7: Filtrar por serie y calificacion" << endl;
        cout << "Opcion 8: Filtrar peliculas por calificacion" << endl;
        cout << "Opcion 9: Cambiar la calificacion" << endl;
        cout << "Opcion 10: Salir" << endl;
        cout << "---------" << endl;
        cout << "Ingresa la opcion deseada: ";
        try
        {
            cin >> intento;
            if (intento.find_first_not_of("0123456789") != string::npos)
            {
                throw runtime_error("Eso no es una opcion valida, vuelve a intentar.");
            }
            else{
                op = stoi(intento);
            }

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        string input = "", p; 
        bool encontrado;
        int cali = 6;

        switch (op)
        {
        case 0:
            cout << "Ingresa el nombre del archivo: ";
            cin >> input;
            inputFile = archivo(input);
            while (getline(inputFile, line)){
                std::stringstream ss(line);

                vector<string> detalles;

                while(getline(ss, c, ' ')){
                    detalles.push_back(c);
                }

                if (detalles[0] == "p"){
                    lista.push_back(new Pelicula(stoi(detalles[1]), stoi(detalles[4]), stoi(detalles[5]), detalles[2], detalles[3]));
                }else if (detalles[0] == "e"){
                    lista.push_back(new Episode(stoi(detalles[1]), stoi(detalles[4]), stoi(detalles[5]), detalles[2], detalles[3], detalles[6], stoi(detalles[7]), stoi(detalles[8])));
                }

            }
            break;
        case 1:
            for (int i = 0; i < size(lista); i++){
                Video *current = lista[i];
                current -> muestra();
            }
            break;
        case 2:
            while (cali == 6){
                try{
                    cout << "Ingresa la calificacion deseada: ";
                    cin >> input;
                    if (input.find_first_not_of("012345") != string::npos)
                    {
                        throw std::runtime_error("Eso no es una opcion valida, vuelve a intentar.");
                    }
                    else{
                        cali = stoi(input);
                    }
                }
                catch(const std::exception& e){
                    std::cerr << e.what() << '\n';
                }
            }
            
            for (int i = 0; i < size(lista); i++){
                Video *current = lista[i];
                if (current -> getCalificacion() == cali){
                    current -> muestra();
                }
            }
            break;
        case 3:
            cin.ignore();
            cin.clear();
            cout << "Ingresa el genero deseado: ";
            getline(cin, input);
            
            for (int i = 0; i < size(lista); i++){
                Video *current = lista[i];
                if (current -> getGenero() == input){
                    current -> muestra();
                }
            }
            break;
        case 4:
            cout << "Nombre: " << yo.getNombre() << endl;
            cout << "Cuenta: " << yo.getCuenta() << endl;
            for(int i = 0; i < yo.getContadorVideos(); i++){
                for (int j = 0; j < size(lista); j++){
                    if (lista[j]->getIdVideo() == yo.getUnIDMisVideos(i)){
                        lista[j] -> muestra();
                        break;
                    }
                }
            }
            break;
        case 5:
            cin.ignore();
            cin.clear();
            cout << "Nombre: ";
            getline(cin, input);
            yo.setNombre(input);
            cout << "Cuenta: ";
            getline(cin, input);
            yo.setCuenta(input);
            break;
        case 6:
            while (input == ""){
                try{
                    cout << "Ingresa el id del video que desea agregar: ";
                    cin >> input;
                    if (input.find_first_not_of("0123456789") != string::npos)
                    {
                        throw std::runtime_error("Eso no es una opcion valida, vuelve a intentar.");
                    }
                    else{
                        cali = stoi(input);
                    }
                }
                catch(const std::exception& e){
                    input = "";
                    std::cerr << e.what() << '\n';
                }
                if (cali == 0){
                    break;
                }
                encontrado = false;
                for (int j = 0; j < size(lista); j++){
                    if (lista[j]->getIdVideo() == cali){
                        yo+=cali;
                        encontrado = true;
                        break;
                    }
                }
                if (encontrado == false){
                    cout << "Ese video no existe, vuelve a intentar" << endl;
                    input = "";
                }
                
            }
            break; 
        case 7:
            while (cali == 6){
                try{
                    cout << "Ingresa la calificacion deseada: ";
                    cin >> input;
                    if (input.find_first_not_of("012345") != string::npos)
                    {
                        throw std::runtime_error("Eso no es una opcion valida, vuelve a intentar.");
                    }
                    else{
                        cali = stoi(input);
                    }
                }
                catch(const std::exception& e){
                    std::cerr << e.what() << '\n';
                }
            }

            cin.ignore();
            cin.clear();
            cout << "Ingresa la serie deseada: ";
            getline(cin, input);
            
            for (int i = 0; i < size(lista); i++){
                Video *current = lista[i];
                if (current -> getCalificacion() == cali){
                    if (auto p = dynamic_cast<Episode*>(current)){
                        if (p -> getSerie() == input){
                            current->muestra();
                        }
                    }
                }
            }
            break;
        case 8:
            while (cali == 6){
                try{
                    cout << "Ingresa la calificacion deseada: ";
                    cin >> input;
                    if (input.find_first_not_of("012345") != string::npos)
                    {
                        throw std::runtime_error("Eso no es una opcion valida, vuelve a intentar.");
                    }
                    else{
                        cali = stoi(input);
                    }
                }
                catch(const std::exception& e){
                    std::cerr << e.what() << '\n';
                }
            }

            for (int i = 0; i < size(lista); i++){
                Video *current = lista[i];
                if (current -> getCalificacion() == cali){
                    if (auto p = dynamic_cast<Pelicula*>(current)){
                        current -> muestra();
                    }
                }
            }

            break;
        case 9:
            while (input == ""){
                cin.ignore();
                cin.clear();
                cout << "Ingresa el video deseado: ";
                getline(cin, input);
                encontrado = false;
                for (int j = 0; j < size(lista); j++){
                    if (lista[j]->getTitulo() == input){
                        while (cali == 6){
                            try{
                                cout << "Ingresa la calificacion deseada: ";
                                cin >> input;
                                if (input.find_first_not_of("012345") != string::npos)
                                {
                                    throw std::runtime_error("Eso no es una opcion valida, vuelve a intentar.");
                                }
                                else{
                                    cali = stoi(input);
                                    lista[j]->setCalificacion(cali);
                                }
                            }
                            catch(const std::exception& e){
                                std::cerr << e.what() << '\n';
                            }
                        }
                        encontrado = true;
                        break;
                    }
                }
                if (encontrado == false){
                    cout << "Ese video no existe, vuelve a intentar" << endl;
                    input = "";
                }
            } 
            break;
        case 10:
            cout << "Adios" << endl;
            break;
        default:
            cout << "Esa no es una opción válida, vuelve a intentar." << endl;
        }
        
    }
    return 0;
}