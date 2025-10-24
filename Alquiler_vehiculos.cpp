#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    string placa;
    bool disponible;
public:
    Vehiculo(string marca, string modelo, string placa)
        : marca(marca), modelo(modelo), placa(placa), disponible(true) {}
    virtual string mostrarInformacion() const {
        return "Marca: " + marca + ", Modelo: " + modelo + ", Placa: " + placa;
    }
    bool estaDisponible() const {
        return disponible;
    }
    void alquilar() {
        disponible = false;
    }
    void devolver() {
        disponible = true;
    }
    string getPlaca() const {
        return placa;
    }
    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
private:
    int capacidadPasajeros;
public:
    Auto(string marca, string modelo, string placa, int capacidadPasajeros)
        : Vehiculo(marca, modelo, placa), capacidadPasajeros(capacidadPasajeros) {}

    string mostrarInformacion() const override {
        return Vehiculo::mostrarInformacion() + ", Capacidad: " + to_string(capacidadPasajeros) + " pasajeros";
    }
};

class Bicicleta : public Vehiculo {
private:
    string tipo;
public:
    Bicicleta(string marca, string modelo, string placa, string tipo)
        : Vehiculo(marca, modelo, placa), tipo(tipo) {}

    string mostrarInformacion() const override {
        return Vehiculo::mostrarInformacion() + ", Tipo: " + tipo;
    }
};

class SistemaAlquiler {
private:
    vector<Vehiculo*> vehiculos;
public:
    void registrarVehiculo(Vehiculo* v) {
        vehiculos.push_back(v);
        cout << "Vehículo registrado: " << v->mostrarInformacion() << endl;
    }
    void mostrarVehiculosDisponibles() const {
        cout << "\nVehículos disponibles:\n";
        bool hayDisponibles = false;
        for (auto v : vehiculos) {
            if (v->estaDisponible()) {
                cout << " - " << v->mostrarInformacion() << endl;
                hayDisponibles = true;
            }
        }
        if (!hayDisponibles)
            cout << "No hay vehículos disponibles en este momento.\n";
    }
    void alquilarVehiculo(string placa) {
        for (auto v : vehiculos) {
            if (v->getPlaca() == placa && v->estaDisponible()) {
                v->alquilar();
                cout << "Vehículo alquilado: " << v->mostrarInformacion() << endl;
                return;
            }
        }
        cout << "Vehículo no disponible o placa incorrecta.\n";
    }
    void devolverVehiculo(string placa) {
        for (auto v : vehiculos) {
            if (v->getPlaca() == placa && !v->estaDisponible()) {
                v->devolver();
                cout << "Vehículo devuelto: " << v->mostrarInformacion() << endl;
                return;
            }
        }
        cout << "No se encontró un vehículo alquilado con esa placa.\n";
    }
    ~SistemaAlquiler() {
        for (auto v : vehiculos)
            delete v;
    }
};

int main() {
    SistemaAlquiler sistema;
    int opcion;
    do {
        cout << "\n========= SISTEMA DE ALQUILER DE VEHÍCULOS =========";
        cout << "\n1. Registrar vehiculo";
        cout << "\n2. Mostrar vehiculos disponibles";
        cout << "\n3. Alquilar vehiculo";
        cout << "\n4. Devolver vehiculo";
        cout << "\n5. Salir";
        cout << "\nSeleccione una opción: ";
        cin >> opcion;
        cin.ignore(); // limpiar buffer

        if (opcion == 1) {
            int tipo;
            cout << "\nSeleccione el tipo de vehiculo:";
            cout << "\n1. Auto";
            cout << "\n2. Bicicleta";
            cout << "\nOpción: ";
            cin >> tipo;
            cin.ignore();

            string marca, modelo, placa;
            cout << "Marca: ";
            getline(cin, marca);
            cout << "Modelo: ";
            getline(cin, modelo);
            cout << "Placa: ";
            getline(cin, placa);

            if (tipo == 1) {
                int capacidad;
                cout << "Capacidad de pasajeros: ";
                cin >> capacidad;
                cin.ignore();
                sistema.registrarVehiculo(new Auto(marca, modelo, placa, capacidad));
            } 
            else if (tipo == 2) {
                string tipoBici;
                cout << "Tipo de bicicleta: ";
                getline(cin, tipoBici);
                sistema.registrarVehiculo(new Bicicleta(marca, modelo, placa, tipoBici));
            } 
            else {
                cout << "Tipo inválido.\n";
            }
        } 
        else if (opcion == 2) {
            sistema.mostrarVehiculosDisponibles();
        } 
        else if (opcion == 3) {
            string placa;
            cout << "Ingrese la placa del vehículo a alquilar: ";
            getline(cin, placa);
            sistema.alquilarVehiculo(placa);
        } 
        else if (opcion == 4) {
            string placa;
            cout << "Ingrese la placa del vehículo a devolver: ";
            getline(cin, placa);
            sistema.devolverVehiculo(placa);
        } 
        else if (opcion == 5) {
            cout << "\nSaliendo del sistema.\n";
        } 
        else {
            cout << "Opción no válida.\n";
        }
    } while (opcion != 5);
    return 0;
}
