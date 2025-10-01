#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

// Estructuras para las tablas de la base de datos
struct Autor {
    int id;
    string nombre;
    string nacionalidad;
};

struct Libro {
    int id;
    string titulo;
    string isbn;
    int ano_publicacion;
    int id_autor;
};

struct Estudiante {
    int id;
    string nombre;
    string grado;
};

struct Prestamo {
    int id;
    int id_libro;
    int id_estudiante;
    string fecha_prestamo;
    string fecha_devolucion;
};

class BibliotecaDB {
private:
    vector<Autor> autores;
    vector<Libro> libros;
    vector<Estudiante> estudiantes;
    vector<Prestamo> prestamos;
    
    // Contadores para IDs automaticos
    int next_autor_id;
    int next_libro_id;
    int next_estudiante_id;
    int next_prestamo_id;

public:
    // Constructor principal
    BibliotecaDB();
    
    // Metodos para guardar y cargar datos
    void cargarDatosIniciales();
    void guardarDatos();
    void cargarDatos();
    
    // Metodos para manejar Autores
    void agregarAutor();
    void listarAutores();
    void buscarAutorPorID();
    void actualizarAutor();
    void eliminarAutor();
    
    // Metodos para manejar Libros
    void agregarLibro();
    void listarLibros();
    void buscarLibroPorID();
    void buscarLibrosPorAutor();
    void actualizarLibro();
    void eliminarLibro();
    
    // Metodos para manejar Estudiantes
    void agregarEstudiante();
    void listarEstudiantes();
    void buscarEstudiantePorID();
    void actualizarEstudiante();
    void eliminarEstudiante();
    
    // Metodos para manejar Prestamos
    void agregarPrestamo();
    void listarPrestamos();
    void buscarPrestamosPorEstudiante();
    void devolverLibro();
    void listarPrestamosActivos();
    
    // Funciones de ayuda y validacion
    bool autorExiste(int id);
    bool libroExiste(int id);
    bool estudianteExiste(int id);
    bool libroDisponible(int id_libro);
    string obtenerNombreAutor(int id_autor);
    string obtenerNombreEstudiante(int id_estudiante);
    string obtenerTituloLibro(int id_libro);
    
    // Menus del sistema
    void menuPrincipal();
    void menuAutores();
    void menuLibros();
    void menuEstudiantes();
    void menuPrestamos();
};

#endif