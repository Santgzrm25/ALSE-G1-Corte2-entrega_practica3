#ifndef LIBRO_H
#define LIBRO_H
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    string isbn;
    bool disponible;
public:
    Libro(string t, string a, string i);
    string getTitulo() const;
    string getAutor() const;
    string getISBN() const;
    bool estaDisponible() const;
    void prestar();
    void devolver();
    void mostrarInformacion() const;
};
#endif