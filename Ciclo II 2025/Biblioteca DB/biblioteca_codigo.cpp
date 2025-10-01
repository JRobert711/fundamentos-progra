#include "biblioteca.h"

// Constructor - inicializa y carga datos
BibliotecaDB::BibliotecaDB() {
    // Inicializar contadores
    next_autor_id = 10006;
    next_libro_id = 106;
    next_estudiante_id = 206;
    next_prestamo_id = 306;
    
    // Cargar datos existentes
    cargarDatos();
    
    // Si no hay datos, cargar ejemplos
    if (autores.empty()) {
        cargarDatosIniciales();
    }
}

// Cargar datos de ejemplo si no existen archivos
void BibliotecaDB::cargarDatosIniciales() {
    cout << "Cargando datos iniciales..." << endl;
    
    autores = {
        {10001, "James Clear", "Estadounidense"},
        {10002, "J.K. Rowling", "Britanica"},
        {10003, "Isabel Allende", "Chilena"},
        {10004, "Mario Vargas Llosa", "Peruano"},
        {10005, "Julio Cortazar", "Argentino"}
    };
    
    libros = {
        {101, "Habitos atomicos", "978-0307474728", 2018, 10001},
        {102, "Harry Potter y la piedra filosofal", "978-8478884452", 1997, 10002},
        {103, "La casa de los espiritus", "978-8403091281", 1982, 10003},
        {104, "La ciudad y los perros", "978-8420471838", 1963, 10004},
        {105, "Rayuela", "978-8432216421", 1963, 10005}
    };
    
    estudiantes = {
        {201, "Ana Maria Lopez", "Ingenieria de Software"},
        {202, "Carlos Rodriguez", "Literatura"},
        {203, "Sofia Hernandez", "Medicina"},
        {204, "Diego Martinez", "Derecho"},
        {205, "Laura Garcia", "Psicologia"}
    };
    
    prestamos = {
        {301, 101, 201, "2024-01-15", "2024-01-30"},
        {302, 103, 202, "2024-02-10", "2024-02-25"},
        {303, 104, 203, "2024-03-05", ""},
        {304, 101, 204, "2024-03-12", ""},
        {305, 105, 205, "2024-03-18", "2024-04-02"}
    };
    
    // Guardar los datos iniciales en archivos
    guardarDatos();
}

// Guardar todos los datos en archivos de texto
void BibliotecaDB::guardarDatos() {
    // Guardar autores
    ofstream archivoAutores("autores.txt");
    for (auto& autor : autores) {
        archivoAutores << autor.id << "," << autor.nombre << "," << autor.nacionalidad << endl;
    }
    archivoAutores.close();
    
    // Guardar libros
    ofstream archivoLibros("libros.txt");
    for (auto& libro : libros) {
        archivoLibros << libro.id << "," << libro.titulo << "," << libro.isbn << "," 
                     << libro.ano_publicacion << "," << libro.id_autor << endl;
    }
    archivoLibros.close();
    
    // Guardar estudiantes
    ofstream archivoEstudiantes("estudiantes.txt");
    for (auto& estudiante : estudiantes) {
        archivoEstudiantes << estudiante.id << "," << estudiante.nombre << "," << estudiante.grado << endl;
    }
    archivoEstudiantes.close();
    
    // Guardar prestamos
    ofstream archivoPrestamos("prestamos.txt");
    for (auto& prestamo : prestamos) {
        archivoPrestamos << prestamo.id << "," << prestamo.id_libro << "," << prestamo.id_estudiante << ","
                        << prestamo.fecha_prestamo << "," << prestamo.fecha_devolucion << endl;
    }
    archivoPrestamos.close();
    
    cout << "Datos guardados correctamente en los archivos!" << endl;
}

// Cargar datos desde archivos de texto
void BibliotecaDB::cargarDatos() {
    cout << "Cargando datos desde archivos..." << endl;
    
    // Cargar Autores
    ifstream archivoAutores("autores.txt");
    if (archivoAutores.is_open()) {
        autores.clear();
        string linea;
        while (getline(archivoAutores, linea)) {
            stringstream ss(linea);
            string token;
            Autor autor;
            
            getline(ss, token, ',');
            autor.id = stoi(token);
            getline(ss, autor.nombre, ',');
            getline(ss, autor.nacionalidad, ',');
            
            autores.push_back(autor);
            // Actualizar el siguiente ID disponible
            if (autor.id >= next_autor_id) {
                next_autor_id = autor.id + 1;
            }
        }
        archivoAutores.close();
        cout << "Autores cargados: " << autores.size() << endl;
    }
    
    // Cargar Libros
    ifstream archivoLibros("libros.txt");
    if (archivoLibros.is_open()) {
        libros.clear();
        string linea;
        while (getline(archivoLibros, linea)) {
            stringstream ss(linea);
            string token;
            Libro libro;
            
            getline(ss, token, ',');
            libro.id = stoi(token);
            getline(ss, libro.titulo, ',');
            getline(ss, libro.isbn, ',');
            getline(ss, token, ',');
            libro.ano_publicacion = stoi(token);
            getline(ss, token, ',');
            libro.id_autor = stoi(token);
            
            libros.push_back(libro);
            // Actualizar el siguiente ID disponible
            if (libro.id >= next_libro_id) {
                next_libro_id = libro.id + 1;
            }
        }
        archivoLibros.close();
        cout << "Libros cargados: " << libros.size() << endl;
    }
    
    // Cargar Estudiantes
    ifstream archivoEstudiantes("estudiantes.txt");
    if (archivoEstudiantes.is_open()) {
        estudiantes.clear();
        string linea;
        while (getline(archivoEstudiantes, linea)) {
            stringstream ss(linea);
            string token;
            Estudiante estudiante;
            
            getline(ss, token, ',');
            estudiante.id = stoi(token);
            getline(ss, estudiante.nombre, ',');
            getline(ss, estudiante.grado, ',');
            
            estudiantes.push_back(estudiante);
            // Actualizar el siguiente ID disponible
            if (estudiante.id >= next_estudiante_id) {
                next_estudiante_id = estudiante.id + 1;
            }
        }
        archivoEstudiantes.close();
        cout << "Estudiantes cargados: " << estudiantes.size() << endl;
    }
    
    // Cargar Prestamos
    ifstream archivoPrestamos("prestamos.txt");
    if (archivoPrestamos.is_open()) {
        prestamos.clear();
        string linea;
        while (getline(archivoPrestamos, linea)) {
            stringstream ss(linea);
            string token;
            Prestamo prestamo;
            
            getline(ss, token, ',');
            prestamo.id = stoi(token);
            getline(ss, token, ',');
            prestamo.id_libro = stoi(token);
            getline(ss, token, ',');
            prestamo.id_estudiante = stoi(token);
            getline(ss, prestamo.fecha_prestamo, ',');
            getline(ss, prestamo.fecha_devolucion, ',');
            
            prestamos.push_back(prestamo);
            // Actualizar el siguiente ID disponible
            if (prestamo.id >= next_prestamo_id) {
                next_prestamo_id = prestamo.id + 1;
            }
        }
        archivoPrestamos.close();
        cout << "Prestamos cargados: " << prestamos.size() << endl;
    }
}

// ========== METODOS PARA AUTORES ==========

void BibliotecaDB::agregarAutor() {
    Autor nuevoAutor;
    nuevoAutor.id = next_autor_id++;
    
    cout << "=== AGREGAR NUEVO AUTOR ===" << endl;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nuevoAutor.nombre);
    cout << "Nacionalidad: ";
    getline(cin, nuevoAutor.nacionalidad);
    
    // Verificar si ya existe un autor con el mismo nombre
    for (auto& autor : autores) {
        if (autor.nombre == nuevoAutor.nombre) {
            cout << "Error: Ya existe un autor con ese nombre." << endl;
            return;
        }
    }
    
    autores.push_back(nuevoAutor);
    cout << "Autor agregado correctamente! ID: " << nuevoAutor.id << endl;
    guardarDatos(); // Guardar cambios
}

void BibliotecaDB::listarAutores() {
    cout << "\n=== LISTA DE AUTORES ===" << endl;
    if (autores.empty()) {
        cout << "No hay autores registrados." << endl;
        return;
    }
    for (auto& autor : autores) {
        cout << "ID: " << autor.id << " | Nombre: " << autor.nombre 
             << " | Nacionalidad: " << autor.nacionalidad << endl;
    }
}

void BibliotecaDB::buscarAutorPorID() {
    int id;
    cout << "ID del autor a buscar: ";
    cin >> id;
    
    for (auto& autor : autores) {
        if (autor.id == id) {
            cout << "Autor encontrado:" << endl;
            cout << "ID: " << autor.id << " | Nombre: " << autor.nombre 
                 << " | Nacionalidad: " << autor.nacionalidad << endl;
            return;
        }
    }
    cout << "Autor no encontrado." << endl;
}

void BibliotecaDB::actualizarAutor() {
    int id;
    cout << "ID del autor a actualizar: ";
    cin >> id;
    
    for (auto& autor : autores) {
        if (autor.id == id) {
            cout << "Nuevo nombre: ";
            cin.ignore();
            getline(cin, autor.nombre);
            cout << "Nueva nacionalidad: ";
            getline(cin, autor.nacionalidad);
            cout << "Autor actualizado correctamente!" << endl;
            guardarDatos(); // Guardar cambios
            return;
        }
    }
    cout << "Autor no encontrado." << endl;
}

void BibliotecaDB::eliminarAutor() {
    int id;
    cout << "ID del autor a eliminar: ";
    cin >> id;
    
    for (auto it = autores.begin(); it != autores.end(); ++it) {
        if (it->id == id) {
            // Verificar si el autor tiene libros
            for (auto& libro : libros) {
                if (libro.id_autor == id) {
                    cout << "No se puede eliminar: El autor tiene libros registrados." << endl;
                    return;
                }
            }
            autores.erase(it);
            cout << "Autor eliminado correctamente!" << endl;
            guardarDatos(); // Guardar cambios
            return;
        }
    }
    cout << "Autor no encontrado." << endl;
}

// ========== METODOS PARA LIBROS ==========

void BibliotecaDB::agregarLibro() {
    Libro nuevoLibro;
    nuevoLibro.id = next_libro_id++;
    
    cout << "=== AGREGAR NUEVO LIBRO ===" << endl;
    cout << "Titulo: ";
    cin.ignore();
    getline(cin, nuevoLibro.titulo);
    cout << "ISBN: ";
    getline(cin, nuevoLibro.isbn);
    cout << "Ano de publicacion: ";
    cin >> nuevoLibro.ano_publicacion;
    
    // Verificar si ya existe un libro con el mismo ISBN
    for (auto& libro : libros) {
        if (libro.isbn == nuevoLibro.isbn) {
            cout << "Error: Ya existe un libro con ese ISBN." << endl;
            return;
        }
    }
    
    int id_autor;
    cout << "ID del Autor: ";
    cin >> id_autor;
    
    if (!autorExiste(id_autor)) {
        cout << "Error: El autor con ID " << id_autor << " no existe." << endl;
        return;
    }
    
    nuevoLibro.id_autor = id_autor;
    libros.push_back(nuevoLibro);
    cout << "Libro agregado correctamente! ID: " << nuevoLibro.id << endl;
    guardarDatos(); // Guardar cambios
}

void BibliotecaDB::listarLibros() {
    cout << "\n=== LISTA DE LIBROS ===" << endl;
    if (libros.empty()) {
        cout << "No hay libros registrados." << endl;
        return;
    }
    for (auto& libro : libros) {
        cout << "ID: " << libro.id << " | Titulo: " << libro.titulo 
             << " | ISBN: " << libro.isbn << " | Ano: " << libro.ano_publicacion
             << " | Autor: " << obtenerNombreAutor(libro.id_autor) << endl;
    }
}

void BibliotecaDB::buscarLibroPorID() {
    int id;
    cout << "ID del libro a buscar: ";
    cin >> id;
    
    for (auto& libro : libros) {
        if (libro.id == id) {
            cout << "Libro encontrado:" << endl;
            cout << "ID: " << libro.id << " | Titulo: " << libro.titulo 
                 << " | ISBN: " << libro.isbn << " | Ano: " << libro.ano_publicacion
                 << " | Autor: " << obtenerNombreAutor(libro.id_autor) << endl;
            return;
        }
    }
    cout << "Libro no encontrado." << endl;
}

void BibliotecaDB::buscarLibrosPorAutor() {
    int id_autor;
    cout << "ID del Autor: ";
    cin >> id_autor;
    
    if (!autorExiste(id_autor)) {
        cout << "Autor no encontrado." << endl;
        return;
    }
    
    cout << "\n=== LIBROS DEL AUTOR: " << obtenerNombreAutor(id_autor) << " ===" << endl;
    bool encontrado = false;
    for (auto& libro : libros) {
        if (libro.id_autor == id_autor) {
            cout << "ID: " << libro.id << " | Titulo: " << libro.titulo 
                 << " | ISBN: " << libro.isbn << " | Ano: " << libro.ano_publicacion << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "El autor no tiene libros registrados." << endl;
    }
}

void BibliotecaDB::actualizarLibro() {
    int id;
    cout << "ID del libro a actualizar: ";
    cin >> id;
    
    for (auto& libro : libros) {
        if (libro.id == id) {
            cout << "Nuevo titulo: ";
            cin.ignore();
            getline(cin, libro.titulo);
            cout << "Nuevo ISBN: ";
            getline(cin, libro.isbn);
            cout << "Nuevo ano de publicacion: ";
            cin >> libro.ano_publicacion;
            cout << "Libro actualizado correctamente!" << endl;
            guardarDatos(); // Guardar cambios
            return;
        }
    }
    cout << "Libro no encontrado." << endl;
}

void BibliotecaDB::eliminarLibro() {
    int id;
    cout << "ID del libro a eliminar: ";
    cin >> id;
    
    for (auto it = libros.begin(); it != libros.end(); ++it) {
        if (it->id == id) {
            // Verificar si el libro tiene prestamos activos
            for (auto& prestamo : prestamos) {
                if (prestamo.id_libro == id && prestamo.fecha_devolucion.empty()) {
                    cout << "No se puede eliminar: El libro tiene prestamos activos." << endl;
                    return;
                }
            }
            libros.erase(it);
            cout << "Libro eliminado correctamente!" << endl;
            guardarDatos(); // Guardar cambios
            return;
        }
    }
    cout << "Libro no encontrado." << endl;
}

// ========== METODOS PARA ESTUDIANTES ==========

void BibliotecaDB::agregarEstudiante() {
    Estudiante nuevoEstudiante;
    nuevoEstudiante.id = next_estudiante_id++;
    
    cout << "=== AGREGAR NUEVO ESTUDIANTE ===" << endl;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nuevoEstudiante.nombre);
    cout << "Grado: ";
    getline(cin, nuevoEstudiante.grado);
    
    // Verificar si ya existe un estudiante con el mismo nombre
    for (auto& estudiante : estudiantes) {
        if (estudiante.nombre == nuevoEstudiante.nombre) {
            cout << "Error: Ya existe un estudiante con ese nombre." << endl;
            return;
        }
    }
    
    estudiantes.push_back(nuevoEstudiante);
    cout << "Estudiante agregado correctamente! ID: " << nuevoEstudiante.id << endl;
    guardarDatos(); // Guardar cambios
}

void BibliotecaDB::listarEstudiantes() {
    cout << "\n=== LISTA DE ESTUDIANTES ===" << endl;
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }
    for (auto& estudiante : estudiantes) {
        cout << "ID: " << estudiante.id << " | Nombre: " << estudiante.nombre 
             << " | Grado: " << estudiante.grado << endl;
    }
}

void BibliotecaDB::buscarEstudiantePorID() {
    int id;
    cout << "ID del estudiante a buscar: ";
    cin >> id;
    
    for (auto& estudiante : estudiantes) {
        if (estudiante.id == id) {
            cout << "Estudiante encontrado:" << endl;
            cout << "ID: " << estudiante.id << " | Nombre: " << estudiante.nombre 
                 << " | Grado: " << estudiante.grado << endl;
            return;
        }
    }
    cout << "Estudiante no encontrado." << endl;
}

void BibliotecaDB::actualizarEstudiante() {
    int id;
    cout << "ID del estudiante a actualizar: ";
    cin >> id;
    
    for (auto& estudiante : estudiantes) {
        if (estudiante.id == id) {
            cout << "Nuevo nombre: ";
            cin.ignore();
            getline(cin, estudiante.nombre);
            cout << "Nuevo grado: ";
            getline(cin, estudiante.grado);
            cout << "Estudiante actualizado correctamente!" << endl;
            guardarDatos(); // Guardar cambios
            return;
        }
    }
    cout << "Estudiante no encontrado." << endl;
}

void BibliotecaDB::eliminarEstudiante() {
    int id;
    cout << "ID del estudiante a eliminar: ";
    cin >> id;
    
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        if (it->id == id) {
            // Verificar si el estudiante tiene prestamos activos
            for (auto& prestamo : prestamos) {
                if (prestamo.id_estudiante == id && prestamo.fecha_devolucion.empty()) {
                    cout << "No se puede eliminar: El estudiante tiene prestamos activos." << endl;
                    return;
                }
            }
            estudiantes.erase(it);
            cout << "Estudiante eliminado correctamente!" << endl;
            guardarDatos(); // Guardar cambios
            return;
        }
    }
    cout << "Estudiante no encontrado." << endl;
}

// ========== METODOS PARA PRESTAMOS ==========

void BibliotecaDB::agregarPrestamo() {
    Prestamo nuevoPrestamo;
    nuevoPrestamo.id = next_prestamo_id++;
    
    cout << "=== NUEVO PRESTAMO ===" << endl;
    cout << "ID del Libro: ";
    cin >> nuevoPrestamo.id_libro;
    
    if (!libroExiste(nuevoPrestamo.id_libro)) {
        cout << "Error: El libro con ID " << nuevoPrestamo.id_libro << " no existe." << endl;
        return;
    }
    
    if (!libroDisponible(nuevoPrestamo.id_libro)) {
        cout << "Error: El libro no esta disponible para prestamo." << endl;
        return;
    }
    
    cout << "ID del Estudiante: ";
    cin >> nuevoPrestamo.id_estudiante;
    
    if (!estudianteExiste(nuevoPrestamo.id_estudiante)) {
        cout << "Error: El estudiante con ID " << nuevoPrestamo.id_estudiante << " no existe." << endl;
        return;
    }
    
    cout << "Fecha de prestamo (YYYY-MM-DD): ";
    cin.ignore();
    getline(cin, nuevoPrestamo.fecha_prestamo);
    nuevoPrestamo.fecha_devolucion = "";
    
    prestamos.push_back(nuevoPrestamo);
    cout << "Prestamo registrado correctamente! ID: " << nuevoPrestamo.id << endl;
    guardarDatos(); // Guardar cambios
}

void BibliotecaDB::listarPrestamos() {
    cout << "\n=== LISTA DE PRESTAMOS ===" << endl;
    if (prestamos.empty()) {
        cout << "No hay prestamos registrados." << endl;
        return;
    }
    for (auto& prestamo : prestamos) {
        cout << "ID: " << prestamo.id 
             << " | Libro: " << obtenerTituloLibro(prestamo.id_libro)
             << " | Estudiante: " << obtenerNombreEstudiante(prestamo.id_estudiante)
             << " | Fecha Prestamo: " << prestamo.fecha_prestamo
             << " | Devolucion: " << (prestamo.fecha_devolucion.empty() ? "Pendiente" : prestamo.fecha_devolucion) << endl;
    }
}

void BibliotecaDB::buscarPrestamosPorEstudiante() {
    int id_estudiante;
    cout << "ID del Estudiante: ";
    cin >> id_estudiante;
    
    if (!estudianteExiste(id_estudiante)) {
        cout << "Error: El estudiante no existe." << endl;
        return;
    }
    
    cout << "\n=== PRESTAMOS DEL ESTUDIANTE: " << obtenerNombreEstudiante(id_estudiante) << " ===" << endl;
    bool encontrado = false;
    
    for (auto& prestamo : prestamos) {
        if (prestamo.id_estudiante == id_estudiante) {
            cout << "ID Prestamo: " << prestamo.id 
                 << " | Libro: " << obtenerTituloLibro(prestamo.id_libro)
                 << " | Fecha Prestamo: " << prestamo.fecha_prestamo
                 << " | Devolucion: " << (prestamo.fecha_devolucion.empty() ? "Pendiente" : prestamo.fecha_devolucion) << endl;
            encontrado = true;
        }
    }
    
    if (!encontrado) {
        cout << "El estudiante no tiene prestamos registrados." << endl;
    }
}

void BibliotecaDB::devolverLibro() {
    int id_prestamo;
    cout << "ID del Prestamo a devolver: ";
    cin >> id_prestamo;
    
    for (auto& prestamo : prestamos) {
        if (prestamo.id == id_prestamo && prestamo.fecha_devolucion.empty()) {
            cout << "Fecha de devolucion (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, prestamo.fecha_devolucion);
            cout << "Libro devuelto correctamente!" << endl;
            guardarDatos(); // Guardar cambios
            return;
        }
    }
    
    cout << "Error: Prestamo no encontrado o ya devuelto." << endl;
}

void BibliotecaDB::listarPrestamosActivos() {
    cout << "\n=== PRESTAMOS ACTIVOS ===" << endl;
    bool encontrado = false;
    
    for (auto& prestamo : prestamos) {
        if (prestamo.fecha_devolucion.empty()) {
            cout << "ID Prestamo: " << prestamo.id 
                 << " | Libro: " << obtenerTituloLibro(prestamo.id_libro)
                 << " | Estudiante: " << obtenerNombreEstudiante(prestamo.id_estudiante)
                 << " | Fecha Prestamo: " << prestamo.fecha_prestamo << endl;
            encontrado = true;
        }
    }
    
    if (!encontrado) {
        cout << "No hay prestamos activos." << endl;
    }
}

// ========== FUNCIONES DE AYUDA ==========

bool BibliotecaDB::autorExiste(int id) {
    for (auto& autor : autores) {
        if (autor.id == id) return true;
    }
    return false;
}

bool BibliotecaDB::libroExiste(int id) {
    for (auto& libro : libros) {
        if (libro.id == id) return true;
    }
    return false;
}

bool BibliotecaDB::estudianteExiste(int id) {
    for (auto& estudiante : estudiantes) {
        if (estudiante.id == id) return true;
    }
    return false;
}

bool BibliotecaDB::libroDisponible(int id_libro) {
    for (auto& prestamo : prestamos) {
        if (prestamo.id_libro == id_libro && prestamo.fecha_devolucion.empty()) {
            return false;
        }
    }
    return true;
}

string BibliotecaDB::obtenerNombreAutor(int id_autor) {
    for (auto& autor : autores) {
        if (autor.id == id_autor) return autor.nombre;
    }
    return "Desconocido";
}

string BibliotecaDB::obtenerNombreEstudiante(int id_estudiante) {
    for (auto& estudiante : estudiantes) {
        if (estudiante.id == id_estudiante) return estudiante.nombre;
    }
    return "Desconocido";
}

string BibliotecaDB::obtenerTituloLibro(int id_libro) {
    for (auto& libro : libros) {
        if (libro.id == id_libro) return libro.titulo;
    }
    return "Desconocido";
}

// ========== MENUS DEL SISTEMA ==========

void BibliotecaDB::menuPrincipal() {
    int opcion;
    
    while (true) {
        cout << "\n=== SISTEMA DE BIBLIOTECA ===" << endl;
        cout << "1. Gestion de Autores" << endl;
        cout << "2. Gestion de Libros" << endl;
        cout << "3. Gestion de Estudiantes" << endl;
        cout << "4. Gestion de Prestamos" << endl;
        cout << "5. Guardar Datos" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: menuAutores(); break;
            case 2: menuLibros(); break;
            case 3: menuEstudiantes(); break;
            case 4: menuPrestamos(); break;
            case 5: guardarDatos(); break;
            case 0: 
                guardarDatos();
                cout << "Hasta luego!" << endl;
                return;
            default: 
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    }
}

void BibliotecaDB::menuAutores() {
    int opcion;
    
    while (true) {
        cout << "\n=== GESTION DE AUTORES ===" << endl;
        cout << "1. Agregar Autor" << endl;
        cout << "2. Listar Autores" << endl;
        cout << "3. Buscar Autor por ID" << endl;
        cout << "4. Actualizar Autor" << endl;
        cout << "5. Eliminar Autor" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: agregarAutor(); break;
            case 2: listarAutores(); break;
            case 3: buscarAutorPorID(); break;
            case 4: actualizarAutor(); break;
            case 5: eliminarAutor(); break;
            case 0: return;
            default: cout << "Opcion invalida." << endl;
        }
    }
}

void BibliotecaDB::menuLibros() {
    int opcion;
    
    while (true) {
        cout << "\n=== GESTION DE LIBROS ===" << endl;
        cout << "1. Agregar Libro" << endl;
        cout << "2. Listar Libros" << endl;
        cout << "3. Buscar Libro por ID" << endl;
        cout << "4. Buscar Libros por Autor" << endl;
        cout << "5. Actualizar Libro" << endl;
        cout << "6. Eliminar Libro" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: agregarLibro(); break;
            case 2: listarLibros(); break;
            case 3: buscarLibroPorID(); break;
            case 4: buscarLibrosPorAutor(); break;
            case 5: actualizarLibro(); break;
            case 6: eliminarLibro(); break;
            case 0: return;
            default: cout << "Opcion invalida." << endl;
        }
    }
}

void BibliotecaDB::menuEstudiantes() {
    int opcion;
    
    while (true) {
        cout << "\n=== GESTION DE ESTUDIANTES ===" << endl;
        cout << "1. Agregar Estudiante" << endl;
        cout << "2. Listar Estudiantes" << endl;
        cout << "3. Buscar Estudiante por ID" << endl;
        cout << "4. Actualizar Estudiante" << endl;
        cout << "5. Eliminar Estudiante" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: agregarEstudiante(); break;
            case 2: listarEstudiantes(); break;
            case 3: buscarEstudiantePorID(); break;
            case 4: actualizarEstudiante(); break;
            case 5: eliminarEstudiante(); break;
            case 0: return;
            default: cout << "Opcion invalida." << endl;
        }
    }
}

void BibliotecaDB::menuPrestamos() {
    int opcion;
    
    while (true) {
        cout << "\n=== GESTION DE PRESTAMOS ===" << endl;
        cout << "1. Nuevo Prestamo" << endl;
        cout << "2. Listar Todos los Prestamos" << endl;
        cout << "3. Buscar Prestamos por Estudiante" << endl;
        cout << "4. Devolver Libro" << endl;
        cout << "5. Listar Prestamos Activos" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: agregarPrestamo(); break;
            case 2: listarPrestamos(); break;
            case 3: buscarPrestamosPorEstudiante(); break;
            case 4: devolverLibro(); break;
            case 5: listarPrestamosActivos(); break;
            case 0: return;
            default: cout << "Opcion invalida." << endl;
        }
    }
}

int main() {
    cout << "=== SISTEMA DE GESTION DE BIBLIOTECA ===" << endl;
    cout << "Cargando datos..." << endl;
    
    BibliotecaDB biblioteca;
    
    cout << "\nSistema listo! Use los menus para gestionar la biblioteca." << endl;
    
    biblioteca.menuPrincipal();
    
    return 0;
}
