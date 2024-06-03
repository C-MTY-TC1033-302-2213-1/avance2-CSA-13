/*
- Nombre: Cristóbal Soto Arévalo
- Matricula: A00840739
- Carrera: ITD
- Fecha: 22/05/2024
*/
#ifndef VIDEO_H
#define VIDEO_H
#include <string>
using namespace std;
//Atributos de la clase
class Video{
    protected:
        string iD;
        string titulo;
        int duracion;
        string genero;
        double calificacion;
//Métodos
public:
    //contructores
    Video();
    Video(string _iD ,string _titulo, int _duracion, string _genero, double _calificacion);

    //Métodos de acceso 
    string getId();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    //Métodos modificadores
    void setId(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);

    //Otros Métodos
    virtual string str();
};

#endif