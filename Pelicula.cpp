/*
- Nombre: Cristóbal Soto Arévalo
- Matricula: A00840739
- Carrera: ITD
- Fecha: 02/06/2024
*/
#include "Pelicula.h"

// Constructor por defecto
Pelicula::Pelicula() : Video(){
    oscars = 100;
}

Pelicula:: Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscars) : Video(_iD, _titulo, _duracion, _genero, _calificacion){
    oscars = _oscars;
}

int Pelicula::getOscars(){
    return oscars;
}

string Pelicula::str(){
    return iD + " " + titulo + " " + to_string(duracion) + " " + genero + " " + to_string(calificacion) + " " + to_string(oscars);
}