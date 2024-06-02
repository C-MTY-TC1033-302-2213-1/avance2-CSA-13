/*
- Nombre: Cristóbal Soto Arévalo
- Matricula: A00840739
- Carrera: ITD
- Fecha: 22/05/2024
- ¿Qué aprendí en el desarrollo de esta clase?
  Aprendí a implementar clases en C++, manejar archivos de cabecera y entender mejor cómo funcionan los métodos y constructores en C++.
*/

#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>
using namespace std;

class Episodio {
private:
    string titulo;
    int temporada;
    int calificacion; 

public:
    Episodio();
    Episodio(string _titulo, int _temporada, int _calificacion);

    string getTitulo();
    int getTemporada();
    int getCalificacion();

    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificacion);

    string str();
};

#endif