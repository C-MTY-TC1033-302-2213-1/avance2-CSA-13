/*
- Nombre: Cristóbal Soto Arévalo
- Matricula: A00840739
- Carrera: ITD
- Fecha: 02/06/2024
*/

#include "Episodio.h"

Episodio::Episodio(){
    titulo = "";
    temporada = 0;
    calificacion = 0;
}

Episodio::Episodio(string _titulo, int _temporada, int _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

string Episodio::getTitulo(){
    return titulo;
}

int Episodio::getTemporada(){
    return temporada;
}

int Episodio::getCalificacion(){
    return calificacion;
}

void Episodio::setTitulo(string _titulo) {
    titulo = _titulo;
}

void Episodio::setTemporada(int _temporada) {
    temporada = _temporada;
}

void Episodio::setCalificacion(int _calificacion) {
    calificacion = _calificacion;
}


string Episodio::str(){
    return titulo + " " + to_string(temporada) + " " + to_string(calificacion);
}