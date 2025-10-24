#include <iostream>
#include "Libro.h"
using namespace std;

Libro::Libro(string t, string a, string i)
    : titulo(t), autor(a), isbn(i), disponible(true) {}

string Libro::getTitulo() const { return titulo; }
string Libro::getAutor() const { return autor; }
string Libro::getISBN() const { return isbn; }
bool Libro::estaDisponible() const { return disponible; }

void Libro::prestar() { disponible = false; }
void Libro::devolver() { disponible = true; }

void Libro::mostrarInformacion() const {
    cout << "Título: " << titulo << "\nAutor: " << autor
         << "\nISBN: " << isbn
         << "\nEstado: " << (disponible ? "Disponible" : "Prestado")
         << "\n----------------------\n";
}
