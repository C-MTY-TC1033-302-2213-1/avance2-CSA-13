#include "Polimorfismo.h"

using namespace std;

// Constructor por defecto - inicializa el arreglo y la cantidad de videos
Polimorfismo::Polimorfismo() {
    for (int index = 0; index < MAX_VIDEOS; index++) {
        arrPtrVideos[index] = nullptr;
    }
    cantidad = 0;
}

// Metodos modificadores
    void Polimorfismo::setPtrVideo(int index, Video *video){
        //Validar index - entre >=0 y < cantidad
        if ( index >= 0 && index < cantidad){
            // Modificar el apuntador
            arrPtrVideos[index] = video;
        }
    }
    void Polimorfismo::setCantidad(int _cantidad){
        //Cambia el valor del atributo cantidad con la condiciones de los valores
        //validar valor de _cantidad
        if(_cantidad >= 0 && _cantidad < MAX_VIDEOS){
            cantidad = _cantidad;
        }
    }

    // Métodos de acceso
    Video* Polimorfismo::getPtrVideo(int index){
        //Validar que exista el index
        if ( index >= 0 && index < cantidad){
            return arrPtrVideos[index];
        }
        //Si no existe
        return nullptr;
    }

    int Polimorfismo::getCantidad(){
        return cantidad;
    }

    // Otros métodos
    void Polimorfismo::reporteInventario(){
        // Declaración de contadores
        int contPeliculas, contSeries;

        //Inicializar 
        contPeliculas = 0;
        contSeries = 0;

        //Recorrrer todo el arreglo de ptr usando un for
        for (int index = 0; index < cantidad; index++){
            // * indireccion (ptr)
            cout << arrPtrVideos[index] -> str() << endl;

            if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
                contPeliculas++;
            }
            else if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
                contSeries++;
            }
        }
        //Fuera del for desplegamos los totales
        cout << "Peliculas = " << contPeliculas << endl;
        cout << "Series = " << contSeries << endl;
    }

    void Polimorfismo::reporteCalificacion(double _calificacion){

        //contador total 
        int total;
        //inicializar contador
        total = 0; 
        for(int index = 0; index < cantidad; index++){
            //verificar calificacion == _calificacion
            if (arrPtrVideos[index] -> getCalificacion() == _calificacion){
                 cout << arrPtrVideos[index] -> str() << endl;
                 total++;
            }
        }
        //Desplegar el total fuera del for
        cout << "Total = " << total << endl;
    }
    /* Despliega la información de todas las Series y Peliculas que
   tienen el genero indicado en el parámetro de entrada,
   al final despliega la cantidad que cumplió (ver casos de prueba).
   Total = ##
    */
    void Polimorfismo::reporteGenero(string _genero){
        int total = 0;  // Contador para la cantidad que cumple con el género

    // Recorre todo el arreglo de videos
        for (int index = 0; index < cantidad; index++) {
            // Verifica si el género del video coincide con el género buscado
            if (arrPtrVideos[index]->getGenero() == _genero) {
                cout << arrPtrVideos[index]->str() << endl;
                total++;
            }
        }
        // Desplegar el total fuera del for
        cout << "Total = " << total << endl;
    }
    /* Despliega la información de todas las Peliculas que existan en el arreglo,
    al final despliega la cantidad en existencia.
    Total Peliculas = ##
    en caso de que no existan peliculas debe
    desplegar No peliculas con salto de línea al final (ver casos de prueba)
    */

    void Polimorfismo::reportePeliculas() {
        int totalPeliculas = 0;  // Contador para la cantidad de películas

        // Recorre todo el arreglo de videos
        for (int index = 0; index < cantidad; index++) {
            // Verifica si el video es una Pelicula
            if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)) {
                cout << arrPtrVideos[index]->str() << endl;
                totalPeliculas++;
                }
        }
        // Verifica si hay películas en el arreglo
        if (totalPeliculas > 0) {
            // Desplegar el total fuera del for
            cout << "Total Peliculas = " << totalPeliculas << endl;
            } else {
            cout << "No peliculas" << endl;
        }
    }
    /* Despliega todas las Series que existan en el arreglo,
   al final despliega la cantidad en existencia.
   Total Series = ##
   en caso de que no existan Series debe
   desplegar No series con salto de línea al final
*/

    void Polimorfismo::reporteSeries() {
        int totalSeries = 0;  // Contador para la cantidad de series

        // Recorre todo el arreglo de videos
        for (int index = 0; index < cantidad; index++) {
            // Verifica si el video es una Serie
            if (typeid(*arrPtrVideos[index]) == typeid(Serie)) {
                cout << arrPtrVideos[index]->str() << endl;
                totalSeries++;
            }
        }

        // Verifica si hay series en el arreglo
        if (totalSeries > 0) {
            // Desplegar el total fuera del for
            cout << "Total Series = " << totalSeries << endl;
            } else {
            cout << "No series" << endl;
        }
    }

// Método para leer y procesar el archivo
void Polimorfismo::leerArchivo(string _nombre) {
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada;
    string row[7];
    string line, word;
    int cantidadPeliculas = 0;
    int cantidadSeries = 0;
    int iR = 0, index;
    double promedio;

    entrada.open(_nombre, ios::in);
    if (!entrada.is_open()) {
        cerr << "No se pudo abrir el archivo: " << _nombre << endl;
        return;
    }

    while (getline(entrada, line)) {
        stringstream s(line);
        iR = 0;

        while (getline(s, word, ',')) {
            row[iR++] = word;
        }

        if (row[0] == "P") {
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            cantidadPeliculas++;
        } else if (row[0] == "S") {
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            cantidadSeries++;
        } else if (row[0] == "E") {
            index = stoi(row[1]) - 500;
            arrPtrSeries[index]->agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
        }
    }

    // Copiar las series al arreglo de videos y calcular su promedio
    for (int index = 0; index < cantidadSeries; index++) {
        promedio = arrPtrSeries[index]->calculaPromedio();
        arrPtrSeries[index]->setCalificacion(promedio);
        arrPtrSeries[index]->calculaDuracion();
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    }

    // Copiar las películas al arreglo de videos
    for (int index = 0; index < cantidadPeliculas; index++) {
        arrPtrVideos[cantidad] = arrPtrPeliculas[index];
        cantidad++;
    }

    /* Desplegar todo el contenido del arreglo de videos (comentar)
    for (int index = 0; index < cantidad; index++) {
        //cout << index << " " << arrPtrVideos[index]->str() << endl;
    }
*/
    entrada.close();
}