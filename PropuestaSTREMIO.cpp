#include <stdio.h>
#include<iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Media {
public:
	string Id;
	string nombre;
	float duracion;
	string genero;
	int calificacion;

public:
	Media();
	Media(string, string, float, string, int);

	void setId(string);
	string getId();

	void setNombre(string);
	string getNombre();

	void setDuracion(float);
	float getDuracion();

	void setGenero(string);
	string getGenero();

	void setCalif(int);
	int getCalif();

	virtual string imprimir();

}; //Clase Media
Media::Media() {
};
//Constructor Media
Media::Media(string _id, string _nom, float _dur, string _gen, int _calif) {
	Id = _id;
	nombre = _nom;
	duracion = _dur;
	genero = _gen;
	calificacion = _calif;
}
// Setters y Getters Media
void Media::setId(string _id) {
	Id = _id;
}
string Media::getId() {
	return Id;
}

void Media::setNombre(string _nom) {
	nombre = _nom;
}
string Media::getNombre() {
	return nombre;
}

void Media::setDuracion(float _dur) {
	duracion = _dur;
}
float Media::getDuracion() {
	return duracion;
}

void Media::setGenero(string _gen) {
	genero = _gen;
}
string Media::getGenero() {
	return genero;
}

void Media::setCalif(int _calif) {
	calificacion = _calif;
}
int Media::getCalif() {
	return calificacion;
}

string Media::imprimir() {
	return Id + ", " + nombre + ", " + to_string(duracion + ", " + genero + ", " + to_string(calificacion);
}//Metodos Media



//------------------------Clase Pelicula----------------------------------//
class Pelicula : public Media {
public:
	Pelicula();
	Pelicula(string, string, float, string, int);
	~Pelicula();
	string imprimir();
};//Clase hija Pelicula
//Metodos Pelicula
Pelicula::Pelicula() :Media() {

}
Pelicula::Pelicula(string Id, string nombre, float duracion, string genero, int calificacion) : Media(Id, nombre, duracion, genero, calificacion) {
}
Pelicula::~Pelicula() {

}
string Pelicula::imprimir() {
	return Media::imprimir() + ".";
}




//---------------------------------Clase Serie-----------------------------------------//
class Serie : public Media {
private:
	int episodio;
	int temporada;
public:
	Serie();
	Serie(string, string, float, string, int, int, int);
	~Serie();
	void setTemporada(int);
	int getTemporaada();
	void setEpisodio(int);
	int getEpisodio();
	string imprimir();

};//Clase hija Serie
//Metodos Serie
Serie::Serie() :Media() {

}

Serie::Serie(string Id, string nombre, float duracion, string genero, int calificacion, int _temporada, int _episodio) : Media(Id, nombre, duracion, genero, calificacion) {
	temporada = _temporada;
	episodio = _episodio;
}

Serie::~Serie() {

}

void Serie::setTemporada(int _temp) {
	temporada = _temp;
}
int Serie::getTemporaada() {
	return temporada;
}

void Serie::setEpisodio(int _epi) {
	episodio = _epi;
}
int Serie::getEpisodio() {
	return episodio;
}

string Serie::imprimir() {
	return Media::imprimir() + ", " + to_string(temporada) + ", " + to_string(episodio);
}


//-------------------------Clase PeliculaSSSSSSSS---------------------------//
class Peliculas {
private:
	Pelicula *arrPtrPeliculas[20];
	int Cant;
public:
	Peliculas();
	void leerPeliculas();
	void imprimir();
	int getCantidadPeliculas();
	void porNombreP(string);
	void porGeneroP(string);
	void porCalificacionP(int);
	void porIdP(string);
	void porDuracionP(float);

};//Clase Peliculas
//Metodos Peliculas
Peliculas::Peliculas() {
	int Cant;
	for (int iR = 0; iR < 20; iR++) {
		arrPtrPeliculas[iR] = nullptr;
	}
}

void Peliculas::leerPeliculas()
{
	fstream fin;

	//Lectura archivo Peliculas
	fin.open("ListaPeliculas.csv", ios::in);
	string row[5];
	string line, word;
	Cant = 0;
	while (getline(fin, line))
	{
		cout << Cant << ". " << line << endl;
		stringstream s(line);
		int iR = 0;

		while (getline(s, word, ','))  //Almacena las palabras 

		{
			row[iR++] = word;
			//Esto es nuestro limite para palabras ,
		}

		//Se realiza el arreglo para la lectura de peliculas

		arrPtrPeliculas[Cant] = new Pelicula(row[0], row[1], stoi(row[2]), row[3], stoi(row[4]));
		cout << "ID: " << row[0] << "\n";
		cout << "Nombre: " << row[1] << "\n";
		cout << "Duracion: " << row[2] << "\n";
		cout << "Genero: " << row[3] << "\n";
		cout << "Calficacion: " << row[4] << "\n";

		cout << "Dentro del objeto: " << arrPtrPeliculas[Cant]->imprimir() << endl;
		Cant = Cant + 1;
		cout << "\n";
		cout << "\n";
	}
	fin.close();

}
//lecturas de peliculas por tipo de entrada, se aplica el polimorfismo

void Peliculas::imprimir() {
	leerPeliculas();

	cout << " ID    Nombre     Duracion     Genero  Calificacion  \n";
	cout << "--------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		cout << arrPtrPeliculas[iR]->imprimir() << endl;
	}
}

void Peliculas::porIdP(string _id) {
	cout << "\n";
	cout << "\n";
	cout << " ID    Titulo     Duracion     Genero    Calificacion \n";
	cout << "-------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		if (arrPtrPeliculas[iR]->getId() == _id)
			cout << arrPtrPeliculas[iR]->imprimir() << endl;
	}
}

void Peliculas::porNombreP(string _nom) {
	cout << "\n";
	cout << "\n";
	cout << " ID    Titulo     Duracion     Genero    Calificacion \n";
	cout << "-------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		if (arrPtrPeliculas[iR]->getNombre() == _nom)
			cout << arrPtrPeliculas[iR]->imprimir() << endl;
	}
}

void Peliculas::porGeneroP(string _gen) {
	cout << "\n";
	cout << "\n";
	cout << " ID    Titulo     Duracion     Genero    Calificacion \n";
	cout << "-------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		if (arrPtrPeliculas[iR]->getGenero() == _gen)
			cout << arrPtrPeliculas[iR]->imprimir() << endl;
	}
}
void Peliculas::porDuracionP(float _dur) {
	cout << "\n";
	cout << "\n";
	cout << " ID    Titulo     Duracion     Genero    Calificacion \n";
	cout << "-------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		if (arrPtrPeliculas[iR]->getDuracion() == _dur)
			cout << arrPtrPeliculas[iR]->imprimir() << endl;
	}
}

void Peliculas::porCalificacionP(int _calif) {
	cout << "\n";
	cout << "\n";
	cout << " ID    Titulo     Duracion     Genero    Calificacion \n";
	cout << "-------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		if (arrPtrPeliculas[iR]->getCalif() == _calif)
			cout << arrPtrPeliculas[iR]->imprimir() << endl;
	}
}

//----------------------------Clase SerieSSSSSSSSSS--------------------------------//
class Series {
private:
	Serie *arrPtrSeries[40];
	int Cant;
public:
	Series();
	void leerSeries();
	void imprimir();
	int getCantidadSeries();
	void porNombreS(string);
	void porGeneroS(string);
	void porCalificacionS(int);
	void porIdS(string);
	void porDuracionS(float);
	void porTemporada(int);
	void porEpisodio(int);
};

Series::Series() {
	int Cant;
	for (int iR = 0; iR < 40; iR++) {
		arrPtrSeries[iR] = nullptr;
	}
}

void Series::leerSeries()
{
	fstream fin;

	//Lectura de la lista de series
	fin.open("ListaSeries.csv", ios::in);
	string row[7];
	string line, word;
	Cant = 0;
	while (getline(fin, line)) //Selecciona la linea  
	{
		cout << Cant << ". " << line << endl;
		stringstream s(line);
		int iR = 0;

		while (getline(s, word, ','))  //Almacena las palabras 

		{
			row[iR++] = word;
			//Esto es nuestro limite para palabras ,
		}


		//Arreglo para el conteo y despligue de series 
		arrPtrSeries[Cant] = new Serie(row[0], row[1], stoi(row[2]), row[3], stoi(row[4]), stoi(row[5]), stoi(row[6]));
		cout << "ID: " << row[0] << "\n";
		cout << "Nombre: " << row[1] << "\n";
		cout << "Duracion: " << row[2] << "\n";
		cout << "Genero: " << row[3] << "\n";
		cout << "Calficacion: " << row[4] << "\n";
		cout << "Temporada: " << row[5] << "\n";
		cout << "Episodio: " << row[6] << "\n";

		cout << "Dentro del objeto: " << arrPtrSeries[Cant]->imprimir() << endl;
		Cant = Cant + 1;
		cout << "\n";
		cout << "\n";
	}
	fin.close();

}
//Lectura por tipo de datos series, se aplica el polimorfismo
void Series::imprimir() {
	leerSeries();

	cout << " ID    Nombre     Duracion     Genero  Calificacion     Temporada Episodio  \n";
	cout << "-----------------------------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		cout << arrPtrSeries[iR]->imprimir() << endl;
	}
}


void Series::porIdS(string _id) {
	cout << "\n";
	cout << "\n";
	cout << " ID  Titulo  Duracion   Genero   Calificacion   Temporada   Episodio \n";
	cout << "-------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		if (arrPtrSeries[iR]->getId() == _id)
			cout << arrPtrSeries[iR]->imprimir() << endl;
	}
}

void Series::porNombreS(string _nom) {
	cout << "\n";
	cout << "\n";
	cout << " ID    Titulo     Duracion     Genero    Calificacion   Temporada   Episodio\n";
	cout << "-------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		if (arrPtrSeries[iR]->getNombre() == _nom)
			cout << arrPtrSeries[iR]->imprimir() << endl;
	}
}

void Series::porGeneroS(string _gen) {
	cout << "\n";
	cout << "\n";
	cout << " ID    Titulo     Duracion     Genero    Calificacion    Temporada   Episodio\n";
	cout << "-------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		if (arrPtrSeries[iR]->getGenero() == _gen)
			cout << arrPtrSeries[iR]->imprimir() << endl;
	}
}

void Series::porDuracionS(float _dur) {
	cout << "\n";
	cout << "\n";
	cout << " ID    Titulo     Duracion     Genero    Calificacion    Temporada   Episodio\n";
	cout << "-------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		if (arrPtrSeries[iR]->getDuracion() == _dur)
			cout << arrPtrSeries[iR]->imprimir() << endl;
	}
}

void Series::porCalificacionS(int _calif) {
	cout << "\n";
	cout << "\n";
	cout << " ID    Titulo     Duracion     Genero    Calificacion    Temporada   Episodio\n";
	cout << "-------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		if (arrPtrSeries[iR]->getCalif() == _calif)
			cout << arrPtrSeries[iR]->imprimir() << endl;
	}
}

void Series::porTemporada(int _tem) {
	cout << "\n";
	cout << "\n";
	cout << " ID    Titulo     Duracion     Genero    Calificacion    Temporada   Episodio\n";
	cout << "-------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		if (arrPtrSeries[iR]->getTemporaada() == _tem)
			cout << arrPtrSeries[iR]->imprimir() << endl;
	}
}

void Series::porEpisodio(int _epi) {
	cout << "\n";
	cout << "\n";
	cout << " ID    Titulo     Duracion     Genero    Calificacion    Temporada   Episodio\n";
	cout << "-------------------------------------------------------\n";
	for (int iR = 0; iR < Cant; iR++) {
		if (arrPtrSeries[iR]->getEpisodio() == _epi)
			cout << arrPtrSeries[iR]->imprimir() << endl;
	}
}
//Setters
int Peliculas::getCantidadPeliculas() {
	return Cant;
}

int Series::getCantidadSeries() {
	return Cant;
}



int main() {
	int op;
	int op1;
	int op2;
	string id;
	string nom;
	string gen;
	float dur;
	int calif;
	int temp;
	int epi;

	Peliculas l1;
	Series s1;
	do {
		cout << "\n"; cout << "\n"; cout << "\n";
		cout << "-----------STREMIO------------\n";
		cout << "1. Cargar media\n";
		cout << "2. Consulta por clase \n";
		cout << "Seleccione una opcion: ";
		cin >> op;
		switch (op) {
		case 1: //Casos de opciones 
		{
			cout << "1. Cargar peliculas\n";
			cout << "2. Cargar series\n";
			cout << "Seleccione una opcion: ";
			cin >> op1;
			switch (op1)
			{
			case 1:
				l1.leerPeliculas();
				break;

			case 2:
				s1.leerSeries();
				break;
			}
			break;
		}
		case 2:
		{
			cout << "1. Cargar peliculas\n";
			cout << "2. Cargar series\n";
			cout << "Seleccione una opcion: ";
			cin >> op1;
			switch (op1)
			{//Opciones de lectura peliculas
			case 1:
				cout << "1. Por Id\n";
				cout << "2. Por nombre\n";
				cout << "3. Por Genero\n";
				cout << "4. Por Duracion\n";
				cout << "5. Por Calificacion\n";
				cout << "Seleccione una opcion: ";
				cin >> op2;
				switch (op2)
				{
				case 1:
					cout << "\n";
					cout << "\n";
					cout << "Id: ";
					cin >> id;
					l1.porIdP(id);
					break;

				case 2:
					cout << "\n";
					cout << "\n";
					cout << "Nombre: ";
					cin >> nom;
					l1.porNombreP(nom);
					break;

				case 3:
					cout << "\n";
					cout << "\n";
					cout << "Genero: ";
					cin >> gen;
					l1.porGeneroP(gen);
					break;

				case 4:
					cout << "\n";
					cout << "\n";
					cout << "Duracion minima: ";
					cin >> dur;
					l1.porDuracionP(dur);

				case 5:
					cout << "\n";
					cout << "\n";
					cout << "Calificacion minima: ";
					cin >> calif;
					l1.porCalificacionP(calif);
				}

				break;
				//Opciones de lectura para serie
			case 2:
				cout << "1. Por Id\n";
				cout << "2. Por nombre\n";
				cout << "3. Por Genero\n";
				cout << "4. Por Duracion\n";
				cout << "5. Por Calificacion\n";
				cout << "6. Por Temporada\n";
				cout << "7. Por Episodio\n";
				cout << "Seleccione una opcion: ";
				cin >> op2;
				switch (op2)
				{
				case 1:
					cout << "\n";
					cout << "\n";
					cout << "Id: ";
					cin >> id;
					s1.porIdS(id);
					break;

				case 2:
					cout << "\n";
					cout << "\n";
					cout << "Nombre: ";
					cin >> nom;
					s1.porNombreS(nom);
					break;

				case 3:
					cout << "\n";
					cout << "\n";
					cout << "Genero: ";
					cin >> gen;
					s1.porGeneroS(gen);
					break;

				case 4:
					cout << "\n";
					cout << "\n";
					cout << "Duracion minima: ";
					cin >> dur;
					s1.porDuracionS(dur);
					break;

				case 5:
					cout << "\n";
					cout << "\n";
					cout << "Califificacion minima: ";
					cin >> calif;
					s1.porCalificacionS(calif);
					break;

				case 6:
					cout << "\n";
					cout << "\n";
					cout << "Temporada: ";
					cin >> temp;
					s1.porTemporada(temp);
					break;

				case 7:
					cout << "\n";
					cout << "\n";
					cout << "Episodio: ";
					cin >> epi;
					s1.porEpisodio(epi);
					break;
					break;
				}
			}
		}
		}
	}
	//Opcion de salida Stremio 
	while (op != 3);
	{ cout << "Vuelve pronto :)" << endl;
	}
	return 0;
}