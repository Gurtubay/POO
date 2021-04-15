#include <iostream>

using namespace std;

class Media{
    public:
        string nombre;
        float duracion;
        string genero;
        int calificacion;

    public:
        Media(string nom, float dur, string gen, int calif){
            nombre = nom;
            duracion = dur;
            genero = gen;
            calificacion = calif;
        }
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
    public:
        Pelicula(string, float, string, int);
};//Clase hija Pelicula

Pelicula::Pelicula(string _nombre, float _duracion, string _genero, int _calificacion):Media(_nombre,_duracion,_genero,_calificacion){

}

class  Serie : public Media{
    public:
        int episodio;
        int temporada;
    
    public:
        Serie(string, float, string, int, int, int);
        int getEpisodio(){
            return episodio;
        }
        int  getTemporada(){
            return temporada;
        }
        void print(){
            cout << "Nombre: "  << nombre << endl;
            cout << "Duracion: "  << duracion << endl;
            cout << "Genero: "  << genero << endl;
            cout << "Calificacion: "  << calificacion << endl;
            cout << "Episodio: "  << episodio << endl;
            cout << "Temporada: "  << temporada << endl;
            
        }
}; //Clase hija Serie

Serie::Serie(string _nombre, float _duracion, string _genero, int _calificacion, int _episodio, int _temporada):Media(_nombre,_duracion,_genero,_calificacion){
    episodio = _episodio;
    temporada = _temporada;
}

int main (){
    Pelicula avenger("Avengers", 2.5, "accion", 5);
    avenger.imprimir();
    Serie vikings("Vikings", 1.0, "Historia", 4, 5, 6);
    vikings.print();
    return 0;
}
