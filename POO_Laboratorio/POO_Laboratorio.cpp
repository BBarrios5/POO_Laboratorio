#include <iostream>
#include <vector>
using namespace std;

class Producto {
private:
	string nombre;
	float precio;
	int Codigo;
	int Stock;
public:
	Producto(string nom, int cod, float prec, int stk) : nombre(nom), Codigo(cod), 
		     precio(prec), Stock(stk) {}

	void mostrar() const {
		cout << "codigo:" << Codigo << " nombre: "
			 << nombre << " precio: " << precio << " stock: " << Stock << endl;
	}

	int obtenerCodigo() const { return Codigo;}
	int obtenerStock() const { return Stock; }

	void actualizarStock(int cantidad) {
		if (cantidad < 0 && -cantidad > Stock){
			cout << "no hay suficiente stock" << endl;
		}
		else {
			Stock += cantidad;
			cout << "sotck actualizado" << Stock << endl;
		}	
	}
	float obtenervalor() const { return  precio; }
};	

void agregarproducto(vector <Producto>& inventario) {
	string nombre;
	int codigo, stock;
	float precio;

	cout << "ingrese el nombre del Producto: ";
	cin >> nombre;
	cout << "ingrese el codigo del Producto: ";
	cin >> codigo;
	cout << "ingrese el precio del Producto: ";
	cin >> precio;
	cout << "ingrese el stock del Producto: ";
	cin >> stock;

	inventario.emplace_back(nombre, codigo, precio, stock);
}

void mostrarinventario(const vector <Producto>& inventario) {
	if (inventario.empty()) {
		cout << "no hay productos en el inventario" << endl;
		return;
	}
	for (const auto& producto : inventario) {
		producto.mostrar();
	}
}

void buscarproducto(const vector <Producto>& inventario) {
	int codigo;
	cout << "ingrese el codigo del producto a buscar: ";
	cin >> codigo;
	for (const auto& producto : inventario) {
		if (producto.obtenerCodigo() == codigo) {
			cout << "producto encontrado" << endl;
			producto.mostrar();
			return;
		}
	}
	cout << "producto no encontrado" << endl;
}

void actualizarStock(vector <Producto>& inventario) {
	int codigo, cantidad;
	cout << "ingrese el codigo del producto a actualizar:";
	cin >> codigo;
	for (auto& Producto : inventario) {
		if (Producto.obtenerCodigo() == codigo) {
			cout << "ingrese la cantidad a modificar positivo para sumar, negativo para restar: ";
			cin >> cantidad;
			Producto.actualizarStock(cantidad);
			return;
		}
	}
	cout << "producto no encontrado" << endl;
};

void calcularvalortotal(vector <Producto>& inventario) {
	float total = 0;
	for (const auto& Producto : inventario) {
		total += Producto.obtenervalor() * Producto.obtenerStock(); 
	}
	cout << "El valor total del inventario es Q " << total << endl; 
}

void eliminarproducto(vector <Producto>& inventario) {
	int codigo;
	cout << "ingrese el codigo del producto a eliminar:";
	cin >> codigo;
	for (auto it = inventario.begin(); it != inventario.end(); ++it) {
		if (it->obtenerCodigo() == codigo) {
			inventario.erase(it);
			cout << "producto eliminado correctamente" << endl;
			return;
		}
	}
	cout << "porducto no encontrado" << endl;
}

int main() {
	vector <Producto> inventario;
	int opcion;
	do {
		cout << "1. agregar producto" << endl;
		cout << "2. mostrar inventario" << endl;
		cout << "3. buscar producto" << endl;
		cout << "4. actualizar stock" << endl;
		cout << "5. calcular valor total" << endl;
		cout << "6. eliminar producto" << endl;
		cout << "7. salir" << endl;
		cout << "ingrese una opcion: ";
		cin >> opcion;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Opcion no valida, intente de nuevo.\n";
			continue;
		}

		switch (opcion) {
		case 1: agregarproducto(inventario); break;
		case 2: mostrarinventario(inventario); break;
		case 3: buscarproducto(inventario); break;
		case 4: actualizarStock(inventario); break;
		case 5: calcularvalortotal(inventario); break;
		case 6: eliminarproducto(inventario); break;
		case 7: cout << "salir del programa \n"; break;
		default: cout << "opcion invalida, intente de nuevo.\n";
		}
	} while (opcion != 7);
	return 0;
}