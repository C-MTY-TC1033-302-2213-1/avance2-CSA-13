/*
- Nombre: Cristóbal Soto Arévalo
- Matricula: A00840739
- Carrera: ITD
- Fecha: 22/05/2024
*/

#include "Video.h"


//Constructores
 Video::Video(){
    iD = "0000";
    titulo = "Cristobal";
    duracion = 10;
    genero = "Educacion";
    calificacion = 100;
 }


 Video::Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion){
          iD = _iD;
          titulo = _titulo;
          duracion = _duracion;
          genero = _genero;
          calificacion = _calificacion;
}

//Métodos de acceso 
string Video::getId(){
    return iD;
    
}
string Video::getTitulo(){
    return titulo;
    
}
int Video::getDuracion(){
    return duracion;
    
}
string Video::getGenero(){
    return genero;
    
}
double Video::getCalificacion(){
    return calificacion;
    
}

//Métodos modificadores
void Video::setId(string _iD){
    iD = _iD;
}
void Video::setTitulo(string _titulo){
    titulo = _titulo;   
}
void Video::setDuracion(int _duracion){
    duracion = _duracion;
}
void Video::setGenero(string _genero){
    genero = _genero;  
}
void Video::setCalificacion(double _calificacion){
    calificacion = _calificacion;   
}

//Otros Métodos
string Video::str(){
    return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' + genero + 
    ' ' + to_string(calificacion); 
}