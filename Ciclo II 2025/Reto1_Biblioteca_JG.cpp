//Trabajo realizado por: Julio Roberto Guardado Quijano
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

// Definición de la clase Libro (mejorada)
class Libro {
public:
    std::string titulo;
    std::string autor;
    int añoPublicacion;
    bool estaDisponible;

    Libro() : añoPublicacion(0), estaDisponible(true) {}

    void mostrarDetallesCompletos() const {
        std::cout << "Titulo: " << titulo << std::endl;
        std::cout << "Autor: " << autor << std::endl;
        std::cout << "Año de publicacion: " << añoPublicacion << std::endl;
        std::cout << "Estado: " << (estaDisponible ? "Disponible" : "Prestado") << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
};

// Definición de la clase Usuario para interactuar con la biblioteca.
class Usuario {
public:
    std::string nombre;
    int id;
    std::vector<std::string> librosPrestados;

    Usuario(const std::string& nombreUsuario, int idUsuario) : nombre(nombreUsuario), id(idUsuario) {}

    void mostrarDetalles() const {
        std::cout << "Usuario: " << nombre << " (ID: " << id << ")" << std::endl;
        if (librosPrestados.empty()) {
            std::cout << "No tiene libros prestados." << std::endl;
        } else {
            std::cout << "Libros prestados:" << std::endl;
            for (const auto& libro : librosPrestados) {
                std::cout << " - " << libro << std::endl;
            }
        }
        std::cout << "-----------------------------" << std::endl;
    }
};

// Definición de la clase Biblioteca con archivo txt
class Biblioteca {
private:
    std::vector<Libro> coleccion; //Vector de libros (como una lista)
    std::vector<Usuario> usuarios; //lo mismo pero con los usuarios

public:
    void agregarLibro(const Libro& nuevoLibro) { 
        for (const auto& libro : coleccion) {
            if (libro.titulo == nuevoLibro.titulo) {
                std::cout << "Error: El libro \"" << nuevoLibro.titulo << "\" ya existe en la biblioteca." << std::endl;
                return;
            }
        }
        coleccion.push_back(nuevoLibro);
        std::cout << "Libro agregado con exito!" << std::endl;
        guardarEnArchivo("biblioteca.txt");
    }

    void mostrarInventario() {
        if (coleccion.empty()) {
            std::cout << "El inventario esta vacio." << std::endl;
            return;
        }
        std::cout << "\n--- Inventario de biblioteca ---" << std::endl;
        for (const auto& libro : coleccion) {
            libro.mostrarDetallesCompletos();
        }
    }
//Funciones que permiten encontrar los datos de libros y usuarios, se usarán en otras funciones
    Libro* buscarLibro(const std::string& tituloBuscado) {
        for (auto& libro : coleccion) {
            if (libro.titulo == tituloBuscado) {
                return &libro;
            }
        }
        return nullptr;
    }

    Usuario* buscarUsuario(int idUsuario) {
        for (auto& usuario : usuarios) {
            if (usuario.id == idUsuario) {
                return &usuario;
            }
        }
        return nullptr;
    }
//Funciones para registrar y mostrar detalles de los usuarios
    void registrarUsuario(const std::string& nombre, int id) {
        if (buscarUsuario(id)) {
            std::cout << "Error: Ya existe un usuario con ese ID." << std::endl;
            return;
        }
        usuarios.emplace_back(nombre, id);
        std::cout << "Usuario registrado con exito!" << std::endl;
        guardarEnArchivo("biblioteca.txt");
    }

    void mostrarUsuarios() {
        if (usuarios.empty()) {
            std::cout << "No hay usuarios registrados." << std::endl;
            return;
        }
        std::cout << "\n--- Lista de Usuarios ---" << std::endl;
        for (const auto& usuario : usuarios) {
            usuario.mostrarDetalles();
        }
    }

    void prestarLibro(const std::string& tituloPrestamo, int idUsuario) {
        Libro* libro = buscarLibro(tituloPrestamo);
        Usuario* usuario = buscarUsuario(idUsuario);

        if (!usuario) {
            std::cout << "Usuario no encontrado." << std::endl;
            return;
        }
        if (libro == nullptr) {
            std::cout << "El libro no existe en la biblioteca." << std::endl;
        } else if (!libro->estaDisponible) {
            std::cout << "El libro no está disponible." << std::endl;
        } else {
            libro->estaDisponible = false;
            usuario->librosPrestados.push_back(libro->titulo);
            std::cout << "Libro prestado con exito a " << usuario->nombre << "!" << std::endl;
            guardarEnArchivo("biblioteca.txt");
        }
    }

    void devolverLibro(const std::string& tituloDevolucion, int idUsuario) {
        Libro* libro = buscarLibro(tituloDevolucion);
        Usuario* usuario = buscarUsuario(idUsuario);

        if (!usuario) {
            std::cout << "Usuario no encontrado." << std::endl;
            return;
        }
        if (libro == nullptr) {
            std::cout << "El libro no existe en la biblioteca." << std::endl;
        } else if (libro->estaDisponible) {
            std::cout << "El libro ya estaba disponible." << std::endl;
        } else {
            libro->estaDisponible = true;

            // quitar de la lista de libros prestados del usuario
            auto& prestamos = usuario->librosPrestados;
            prestamos.erase(std::remove(prestamos.begin(), prestamos.end(), std::string(libro->titulo)), prestamos.end());

            std::cout << "Libro devuelto con exito!" << std::endl;
            guardarEnArchivo("biblioteca.txt");
        }
    }

    void guardarEnArchivo(const std::string& nombreArchivo) {
        std::ofstream archivo(nombreArchivo);
        if (!archivo) {
            std::cout << "Error al abrir el archivo para guardar." << std::endl;
            return;
        }

        for (const auto& libro : coleccion) {
            archivo << libro.titulo << ";" 
                    << libro.autor << ";" 
                    << libro.añoPublicacion << ";" 
                    << libro.estaDisponible << "\n";
        }
        archivo.close();
    }

    void cargarDesdeArchivo(const std::string& nombreArchivo) {
        std::ifstream archivo(nombreArchivo);
        if (!archivo) {
            std::cout << "No se encontro archivo previo. Se inicia biblioteca vacia." << std::endl;
            return;
        }

        coleccion.clear();
        std::string linea;
        while (std::getline(archivo, linea)) {
            Libro libro;
            size_t pos1 = linea.find(";");
            size_t pos2 = linea.find(";", pos1 + 1);
            size_t pos3 = linea.find(";", pos2 + 1);

            libro.titulo = linea.substr(0, pos1);
            libro.autor = linea.substr(pos1 + 1, pos2 - pos1 - 1);
            libro.añoPublicacion = std::stoi(linea.substr(pos2 + 1, pos3 - pos2 - 1));
            libro.estaDisponible = (linea.substr(pos3 + 1) == "1");

            coleccion.push_back(libro);
        }
        archivo.close();
    }
};

int main() { //Función principal que desplegará el menú.
    Biblioteca miBiblioteca;
    int opcion = 0;

    // cargar estado previo
    miBiblioteca.cargarDesdeArchivo("biblioteca.txt");

    while (opcion != 7) {
        std::cout << "\n--- BIBLIOTECA DIGITAL ---" << std::endl;
        std::cout << "1. Anadir libro" << std::endl;
        std::cout << "2. Mostrar inventario" << std::endl;
        std::cout << "3. Registrar usuario" << std::endl;
        std::cout << "4. Mostrar usuarios" << std::endl;
        std::cout << "5. Prestar libro" << std::endl;
        std::cout << "6. Devolver libro" << std::endl;
        std::cout << "7. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        if (opcion == 1) {
            Libro nuevoLibro;
            std::cout << "Ingrese el titulo: ";
            std::getline(std::cin, nuevoLibro.titulo);
            std::cout << "Ingrese el autor: ";
            std::getline(std::cin, nuevoLibro.autor);
            std::cout << "Ingrese el año de publicacion: ";
            std::cin >> nuevoLibro.añoPublicacion;
            std::cin.ignore();
            miBiblioteca.agregarLibro(nuevoLibro);
        }
        else if (opcion == 2) {
            miBiblioteca.mostrarInventario();
        }
        else if (opcion == 3) {
            std::string nombre;
            int id;
            std::cout << "Ingrese el nombre del usuario: ";
            std::getline(std::cin, nombre);
            std::cout << "Ingrese el ID del usuario: ";
            std::cin >> id;
            std::cin.ignore();
            miBiblioteca.registrarUsuario(nombre, id);
        }
        else if (opcion == 4) {
            miBiblioteca.mostrarUsuarios();
        }
        else if (opcion == 5) {
            std::string titulo;
            int id;
            std::cout << "Ingrese el titulo del libro a prestar: ";
            std::getline(std::cin, titulo);
            std::cout << "Ingrese el ID del usuario: ";
            std::cin >> id;
            std::cin.ignore();
            miBiblioteca.prestarLibro(titulo, id);
        }
        else if (opcion == 6) {
            std::string titulo;
            int id;
            std::cout << "Ingrese el titulo del libro a devolver: ";
            std::getline(std::cin, titulo);
            std::cout << "Ingrese el ID del usuario: ";
            std::cin >> id;
            std::cin.ignore();
            miBiblioteca.devolverLibro(titulo, id);
        }
        else if (opcion == 7) {
            miBiblioteca.guardarEnArchivo("biblioteca.txt");
            std::cout << "Saliendo del programa..." << std::endl;
        }
        else {
            std::cout << "Opcion invalida. Intente nuevamente." << std::endl;
        }
    }

    return 0;
}