#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <vector>
#include "Libro.h"
using namespace std;

class Biblioteca {
private:
    vector<Libro> libros;
public:
    void agregarLibro(const Libro& libro);
    void eliminarLibro(string isbn);
    void buscarPorAutor(string autor) const;
    void mostrarLibrosDisponibles() const;
};
#endif