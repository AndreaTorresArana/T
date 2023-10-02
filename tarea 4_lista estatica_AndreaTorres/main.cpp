#include <iostream>
#include <string>

const int TAM = 100;

class Empleado {
private:
    std::string nombre;
    int edad;

public:
    Empleado() : nombre("Sin nombre"), edad(0) {}

    Empleado(std::string nombre, int edad) : nombre(nombre), edad(edad) {}

    friend std::ostream& operator<<(std::ostream& o, Empleado& e) {
        o << "Nombre: " << e.nombre << "\tEdad: " << e.edad << std::endl;
        return o;
    }

    bool operator==(const Empleado& other) {
        return nombre == other.nombre && edad == other.edad;
    }
};

class ListaEmpleados {
private:
    Empleado datos[TAM];
    int ult;

public:
    ListaEmpleados() : ult(-1) {}

    bool vacia() const {
        return ult == -1;
    }

    bool llena() const {
        return ult == TAM - 1;
    }

    int agregar(const Empleado& emp) {
        if (llena()) {
            std::cout << "La lista de empleados está llena. No se pudo agregar." << std::endl;
            return 0;
        }
        ult++;
        datos[ult] = emp;
        std::cout << "Empleado agregado exitosamente." << std::endl;
        return 1;
    }

    int buscar(const Empleado& emp) {
        if (vacia()) {
            std::cout << "La lista de empleados está vacía." << std::endl;
            return -1;
        }

        for (int i = 0; i <= ult; i++) {
            if (datos[i] == emp) {
                std::cout << "Empleado encontrado en la posición " << i << std::endl;
                return i;
            }
        }

        std::cout << "Empleado no encontrado." << std::endl;
        return -1;
    }

    int eliminar(int pos) {
        if (vacia()) {
            std::cout << "La lista de empleados está vacía." << std::endl;
            return -1;
        }

        if (pos < 0 || pos > ult) {
            std::cout << "Posición inválida. No se puede eliminar el empleado." << std::endl;
            return -1;
        }

        for (int i = pos; i < ult; i++) {
            datos[i] = datos[i + 1];
        }

        ult--;
        std::cout << "Empleado eliminado exitosamente." << std::endl;
        return 1;
    }

    int insertar(const Empleado& emp, int pos) {
        if (llena()) {
            std::cout << "La lista de empleados está llena. No se pudo insertar." << std::endl;
            return 0;
        }

        if (pos < 0 || pos > ult + 1) {
            std::cout << "Posición inválida. No se puede insertar el empleado." << std::endl;
            return 0;
        }

        for (int i = ult + 1; i > pos; i--) {
            datos[i] = datos[i - 1];
        }

        datos[pos] = emp;
        ult++;
        std::cout << "Empleado insertado exitosamente." << std::endl;
        return 1;
    }

    void mostrarTodos() {
        if (vacia()) {
            std::cout << "La lista de empleados está vacía." << std::endl;
            return;
        }

        std::cout << "Lista de empleados:" << std::endl;
        for (int i = 0; i <= ult; i++) {
            std::cout << "Posición " << i << ":" << std::endl;
            std::cout << datos[i];
        }
    }
};

int main() {
    ListaEmpleados lista;

    while (true) {
        std::cout << "\nMenú de opciones:" << std::endl;
        std::cout << "1. Agregar Empleado" << std::endl;
        std::cout << "2. Buscar Empleado" << std::endl;
        std::cout << "3. Eliminar Empleado" << std::endl;
        std::cout << "4. Insertar Empleado" << std::endl;
        std::cout << "5. Mostrar Todos los Empleados" << std::endl;
        std::cout << "6. Salir" << std::endl;

        int opcion;
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nombre;
                int edad;
                std::cout << "Ingrese el nombre del empleado: ";
                std::cin >> nombre;
                std::cout << "Ingrese la edad del empleado: ";
                std::cin >> edad;
                Empleado nuevoEmpleado(nombre, edad);
                lista.agregar(nuevoEmpleado);
                break;
            }
            case 2: {
                std::string nombre;
                int edad;
                std::cout << "Ingrese el nombre del empleado a buscar: ";
                std::cin >> nombre;
                std::cout << "Ingrese la edad del empleado a buscar: ";
                std::cin >> edad;
                Empleado empleadoBusqueda(nombre, edad);
                lista.buscar(empleadoBusqueda);
                break;
            }
            case 3: {
                int pos;
                std::cout << "Ingrese la posición del empleado a eliminar: ";
                std::cin >> pos;
                lista.eliminar(pos);
                break;
            }
            case 4: {
                std::string nombre;
                int edad;
                int pos;
                std::cout << "Ingrese el nombre del empleado a insertar: ";
                std::cin >> nombre;
                std::cout << "Ingrese la edad del empleado a insertar: ";
                std::cin >> edad;
                Empleado nuevoEmpleado(nombre, edad);
                std::cout << "Ingrese la posición donde desea insertar el empleado: ";
                std::cin >> pos;
                lista.insertar(nuevoEmpleado, pos);
                break;
            }
            case 5:
                lista.mostrarTodos();
                break;
            case 6:
                std::cout << "Saliendo del programa." << std::endl;
                return 0;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                break;
        }
    }

    return 0;
}
