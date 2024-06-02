/*/¿Qué aprendí en el desarrollo de la clase Polimorfismo? Aprendí a implementar y 
aplicar conceptos de polimorfismo en C++, permitiendo manejar objetos de distintas 
clases derivadas a través de punteros base, y a utilizar typeid para identificar 
tipos en tiempo de ejecución, mejorando la flexibilidad y extensibilidad del código.
*/
#ifndef POLIMORFISMO_H
#define POLIMORFISMO_H
#include "Polimorfismo.h"

#include <sstream>
#include <iostream>
#include <string>
#include <typeinfo>
#include <fstream>
#include <stdio.h>
#include "Video.h"
#include "Serie.h"
#include "Pelicula.h"
#include "Episodio.h"

const int MAX_VIDEOS = 100; // Definición del tamaño máximo del arreglo de videos

class Polimorfismo {
private:
    Video* arrPtrVideos[MAX_VIDEOS]; // Arreglo de punteros a objetos de tipo Video
    int cantidad; // Cantidad de videos en el arreglo

public:
    Polimorfismo(); // Constructor por defecto

    void leerArchivo(std::string _nombre); // Método para leer archivos

    // Metodos modificadores
    void setPtrVideo(int index, Video *video);
    void setCantidad(int _cantidad);

    // Métodos de acceso
    Video* getPtrVideo(int index);
    int getCantidad();

    // Otros métodos
    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();
};

#endif // POLIMORFISMO_H