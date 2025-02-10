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

	void aumentarStock(int cantidad) {
		if (cantidad > Stock){
			cout << "no hay suficiente stock" << endl;
		}
		else {
			Stock -= cantidad;
			cout << "sotck actualizado" << Stock << endl;
		}	
	}
	float obtenervalor() const { return * precio; }
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
	Cout << "ingrese el codigo del producto a actualizar:";
	cin >> codigo;
	for (auto &)
}
