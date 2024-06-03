/*
- Nombre: Cristóbal Soto Arévalo
- Matricula: A00840739
- Carrera: ITD
- Fecha: 22/05/2024
*/
#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include <iostream>
#include "Video.h"

using namespace std;

class Pelicula : public Video {
private:
    int oscars; // Número de premios Óscar ganados

public:
    // Constructores
    Pelicula();
    Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscars);

    // Métodos
    int getOscars(); // Getter para oscars

    void setOscars(int _oscars);

    string str();
};

#endif