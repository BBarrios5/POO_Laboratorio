#include <iostream>

using namespace std;

// Clase base Animal
class Animal {
protected:
    string nombre;
    int edad;

public:
    // Constructor
    Animal(const string& n, int e) : nombre(n), edad(e) {}

    // Método virtual para hacer sonidos (permite polimorfismo)
    virtual void hacerSonido() const {
        cout << nombre << " hace un sonido desconocido." << endl;
    }

    // Destructor virtual para evitar fugas de memoria en la herencia
    virtual ~Animal() {}
};

// Clase derivada Perro (hereda de Animal)
class Perro : public Animal {
public:
    // Constructor que usa el constructor de la clase base
    Perro(const string& n, int e) : Animal(n, e) {}

    // Sobrescribe el método hacerSonido
    void hacerSonido() const override {
        cout << nombre << " dice: Guau" << endl;
    }
};

// Clase Automovil
class Automovil {
private:
    string marca;
    int velocidad;

public:
    // Constructor
    Automovil(const string& m, int v) : marca(m), velocidad(v) {}

    // Método para acelerar el automóvil
    void acelerar() {
        velocidad += 10;
        cout << "El automovil " << marca << " ahora va a " << velocidad << " km/h." << endl;
    }
};

// Clase Persona
class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor
    Persona(const string& n, int e) : nombre(n), edad(e) {}

    // Método para saludar
    void saludar() const {
        cout << "Hola, mi nombre es " << nombre << " y tengo " << edad << " anios." << endl;
    }
};

// Función principal
int main() {
    // Crear objetos y llamar métodos
    Perro miPerro("Rex", 5);
    miPerro.hacerSonido();

    Automovil miCoche("Toyota", 60);
    miCoche.acelerar();

    Persona persona1("Carlos", 30);
    persona1.saludar();

    return 0;
}
