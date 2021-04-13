#include <iostream>

using namespace std;

class Media{
    public:
        string nombre;
        float duracion;
        string genero;
        int calificacion;

    public:
        string getNombre(){
            return nombre;
        }
        float getDuracion(){
            return duracion;
        }
        string getGenero(){
            return genero;
        }
        int getCalif(){
            return calificacion;
        }
        void imprimir(){
            cout << "Nombre: "  << nombre << endl;
            cout << "Duracion: "  << duracion << endl;
            cout << "Genero: "  << genero << endl;
            cout << "Calificacion: "  << calificacion << endl;
            
        }

}; //Clase Media

class Pelicula : public Media{

};//Clase hija Pelicula

class  Serie : public Media{
    public:
        int episodio;
        int temporada;
    
    public:
        int getEpisodio(){
            return episodio;
        }
        int  getTemporada(){
            return temporada;
        }
}; //Clase hija Serie