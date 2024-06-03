/*
- Nombre: Cristóbal Soto Arévalo
- Matricula: A00840739
- Carrera: ITD
- Fecha: 22/05/2024
*/

#include "Serie.h"
#include <iostream>
using namespace std;

Serie::Serie() : Video() {
    cantidad = 0;
}

// Nuevo constructor
Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion) 
    : Video(_iD, _titulo, _duracion, _genero, _calificacion) {
    cantidad = 0;
}

void Serie::setEpisodio(int posicion, Episodio episodio) {
    if (posicion < cantidad && posicion >= 0) {
        episodios[posicion] = episodio;
    } else {
        cout << "No se pudo agregar el episodio";
    }
}

void Serie::setCantidad(int _cantidad) {
    cantidad = _cantidad;
}

Episodio Serie::getEpisodio(int posicion) {
    Episodio epi;

    if (posicion < cantidad && posicion >= 0) {
        return episodios[posicion];
    }
    cout << "No se encontro el episodio";
    return Episodio();
}

int Serie::getCantidad() {
    return cantidad;
}

double Serie::calculaPromedio() {
    double acum = 0.0;

    for (int index = 0; index < cantidad; index++) {
        acum += episodios[index].getCalificacion();
    }

    if (cantidad > 0) {
        return acum / cantidad;
    } else {
        return 0;
    }
}

void Serie::calculaDuracion() {
    int duracionTotal = 0;

    for (int index = 0; index < cantidad; index++) {
        duracionTotal += episodios[index].getTemporada();
    }

    duracion = duracionTotal; // Asignar la duración total de la serie
}

string Serie::str(){
    string str = Video::str() + " " + to_string(cantidad) + "\n";
    for (int index = 0; index < cantidad; index++){
        str += episodios[index].str() + "\n";
    }
    return str;
}

void Serie::agregaEpisodio(Episodio episodio) {
    if (cantidad < 5) {
        episodios[cantidad++] = episodio;
    } else {
        cout << "No se pudo agregar el episodio";
    }
}