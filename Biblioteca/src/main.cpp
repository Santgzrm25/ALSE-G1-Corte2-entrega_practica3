#include <iostream>
#include "Biblioteca.h"
using namespace std;

int main() {
    Biblioteca biblioteca;
    int opcion;
    string titulo, autor, isbn;
    do {
        cout << "\n====== MENÚ BIBLIOTECA ======\n";
        cout << "1. Agregar libro\n";
        cout << "2. Eliminar libro\n";
        cout << "3. Buscar por autor\n";
        cout << "4. Mostrar libros disponibles\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                cout << "Título: ";
                getline(cin, titulo);
                cout << "Autor: ";
                getline(cin, autor);
                cout << "ISBN: ";
                getline(cin, isbn);
                biblioteca.agregarLibro(Libro(titulo, autor, isbn));
                break;
            case 2:
                cout << "Ingrese el ISBN del libro a eliminar: ";
                getline(cin, isbn);
                biblioteca.eliminarLibro(isbn);
                break;
            case 3:
                cout << "Ingrese el autor: ";
                getline(cin, autor);
                biblioteca.buscarPorAutor(autor);
                break;
            case 4:
                biblioteca.mostrarLibrosDisponibles();
                break;
            case 5:
                cout << "Saliendo del sistema.\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 5);
    return 0;
}