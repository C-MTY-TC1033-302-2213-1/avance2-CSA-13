/*
- Nombre: Cristóbal Soto Arévalo
- Matricula: A00840739
- Carrera: ITD
- Fecha: 22/05/2024
*/

#ifndef SERIE_H
#define SERIE_H

#include "Episodio.h"
#include "Video.h"

class Serie : public Video {
private:
    Episodio episodios[5];
    int cantidad;

public:
    Serie();
    Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion); // Nuevo constructor

    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad);

    Episodio getEpisodio(int posicion);
    int getCantidad();

    double calculaPromedio();
    void calculaDuracion(); // Nuevo método
    string str();
    
    void agregaEpisodio(Episodio episodio);
};

#endif