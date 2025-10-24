#include <iostream>
#include "Biblioteca.h"
using namespace std;

void Biblioteca::agregarLibro(const Libro& libro) {
    libros.push_back(libro);
    cout << "Libro agregado correctamente.\n";
}
void Biblioteca::eliminarLibro(string isbn) {
    for (auto it = libros.begin(); it != libros.end(); ++it) {
        if (it->getISBN() == isbn) {
            libros.erase(it);
            cout << "Libro eliminado correctamente.\n";
            return;
        }
    }
    cout << "No se encontró ningún libro con ese ISBN.\n";
}

void Biblioteca::buscarPorAutor(string autor) const {
    cout << "\nLibros del autor " << autor << ":\n";
    bool encontrado = false;
    for (const auto& libro : libros) {
        if (libro.getAutor() == autor) {
            libro.mostrarInformacion();
            encontrado = true;
        }
    }
    if (!encontrado)
        cout << "No se encontraron libros de ese autor.\n";
}

void Biblioteca::mostrarLibrosDisponibles() const {
    cout << "\nLibros disponibles:\n";
    if (libros.empty()) {
        cout << "No hay libros registrados aún.\n";
        return;
    }
    for (const auto& libro : libros) {
        libro.mostrarInformacion();
    }
}
