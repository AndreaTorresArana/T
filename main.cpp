#include <iostream>
#include <string>

const int TAM = 100;

class Empleado {
private:
    int ClaveEmpleado;
    std::string Nombre;
    std::string Domicilio;
    float Sueldo;
    std::string ReportaA;

public:
    Empleado() : ClaveEmpleado(0), Nombre("Sin nombre"), Domicilio("Sin domicilio"), Sueldo(0.0), ReportaA("Sin jefe") {}

    Empleado(int ce, std::string n, std::string d, float s, std::string ra)
        : ClaveEmpleado(ce), Nombre(n), Domicilio(d), Sueldo(s), ReportaA(ra) {}

    int getClave() const {
        return ClaveEmpleado;
    }

    friend std::istream& operator >>(std::istream& i, Empleado& e) {

        std::cout << "\n Ingresa clave: ";
        i >> e.ClaveEmpleado;
        std::cout << "\n Ingresa nombre: ";
        i.ignore();
        std::getline(i, e.Nombre);
        std::cout << "\n Ingresa domicilio: ";
        std::getline(i, e.Domicilio);
        std::cout << "\n Ingresa sueldo: ";
        i >> e.Sueldo;
        std::cout << "\n Ingresa la persona a la que reporta: ";
        i.ignore();
        std::getline(i, e.ReportaA);
        return i;
    }

    friend std::ostream& operator <<(std::ostream& o, const Empleado& e) {
        o << "\n Clave: " << e.ClaveEmpleado;
        o << "\n Nombre:" << e.Nombre;
        o << "\n Domicilio: " << e.Domicilio;
        o << "\n Sueldo:" << e.Sueldo;
        o << "\n Reporta a: " << e.ReportaA;
        return o;
    }
};

class Pila {
private:
    Empleado datos[TAM];
    int ult;
    int inserta(Empleado, int);
    bool elimina(int);

public:
    Pila() : ult(-1) {}

    bool vacia() const {
        return ult == -1;
    }

    bool llena() const {
        return ult == TAM - 1;
    }

    void push(Empleado empleado) {
        if (!llena()) {
            datos[++ult] = empleado;
        }
    }

    void pop() {
        if (!vacia()) {
            --ult;
        }
    }

    Empleado& top() {
        if (!vacia()) {
            return datos[ult];
        }
        throw std::out_of_range("La pila está vacía");
    }
     friend std::ostream& operator<<(std::ostream & o, Pila& L);
};

int main() {
    Pila pila;
    int opcion;

    do {
        std::cout << "\n***Menu:***" << std::endl;
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Top" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                Empleado empleado;
                std::cin >> empleado;
                pila.push(empleado);
                std::cout << "Empleado apilado correctamente." << std::endl;
                break;
            }
            case 2:
                try {
                    pila.pop();
                    std::cout << "Empleado desapilado correctamente." << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cerr << "La pila esta vacia. No se puede realizar Pop." << std::endl;
                }
                break;
            case 3:
                try {
                    std::cout << "Informacion del empleado en la cima de la pila:" << std::endl;
                    std::cout << pila.top();
                } catch (const std::out_of_range& e) {
                    std::cerr << "La pila esta vacia. No hay elemento en la cima." << std::endl;
                }
                break;
            case 4:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cerr << "Opcion no valida. Intente nuevamente." << std::endl;
        }
    } while (opcion != 4);

    return 0;
}
