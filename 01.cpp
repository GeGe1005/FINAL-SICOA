// Programa de libros y su clasificación.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits> // Para validaciones numéricas

using namespace std;

// Definición del struct Libro (cumple con mínimo 7 campos: 2 string, 2 int, 1 float, 1 double, 1 char)
struct Libro {
    string titulo;      // Título del libro
    string autor;       // Autor
    int anio;           // Año de publicación
    float precio;       // Precio en dólares
    double rating;      // Rating (0.0 a 5.0)
    char genero;        // Género ('F' para ficción, 'N' para no ficción)
    int paginas;        // Número de páginas
};

// Función para validar entrada de string (no vacío)
string validarString(const string& mensaje) {
    string entrada;
    do {
        cout << mensaje;
        getline(cin, entrada);
        if (entrada.empty()) {
            cout << "Error: El campo no puede estar vacio. Intente de nuevo.\n";
        }
    } while (entrada.empty());
    return entrada;
}

// Función para validar entrada de int (positivo)
int validarInt(const string& mensaje) {
    int entrada;
    while (true) {
        cout << mensaje;
        cin >> entrada;
        if (cin.fail() || entrada < 0) {
            cout << "Error: Debe ingresar un numero entero positivo. Intente de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer
            return entrada;
        }
    }
}

// Función para validar entrada de float (positivo)
float validarFloat(const string& mensaje) {
    float entrada;
    while (true) {
        cout << mensaje;
        cin >> entrada;
        if (cin.fail() || entrada < 0) {
            cout << "Error: Debe ingresar un numero positivo. Intente de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return entrada;
        }
    }
}

// Función para validar entrada de double (entre 0 y 5)
double validarDouble(const string& mensaje) {
    double entrada;
    while (true) {
        cout << mensaje;
        cin >> entrada;
        if (cin.fail() || entrada < 0 || entrada > 5) {
            cout << "Error: Debe ingresar un numero entre 0.0 y 5.0. Intente de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return entrada;
        }
    }
}

// Función para validar char (solo 'F' o 'N')
char validarChar(const string& mensaje) {
    char entrada;
    while (true) {
        cout << mensaje;
        cin >> entrada;
        entrada = toupper(entrada); // Convertir a mayúscula
        if (entrada == 'F' || entrada == 'N') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return entrada;
        } else {
            cout << "Error: Solo 'F' (ficcion) o 'N' (no ficcion). Intente de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Función para llenar la colección con datos (operacion a)
void llenarColeccion(vector<Libro>& coleccion) {
    int n = validarInt(" Cuantos libros desea agregar? ");
    for (int i = 0; i < n; ++i) {
        Libro libro;
        cout << "\nLibro " << (i + 1) << " :\n";
        libro.titulo = validarString(" Titulo: ");
        libro.autor = validarString(" Autor: ");
        libro.anio = validarInt(" Publicado en: ");
        libro.precio = validarFloat(" Precio: ");
        libro.rating = validarDouble(" Rating (0.0-5.0): ");
        libro.genero = validarChar(" Genero ('F' para ficcion, 'N' para no ficcion): ");
        libro.paginas = validarInt(" Numero de paginas: ");
        coleccion.push_back(libro);
    }
}

// Función para mostrar la matriz en formato tabla (operación b)
void mostrarTabla(const vector<Libro>& coleccion) {
    if (coleccion.empty()) {
        cout << "La coleccion esta vacia.\n";
        return;
    }
    cout << "\nColeccion de Libros:\n";
    cout << "--------------------------------------------------------------------------------\n";
    cout << "| Indice | Titulo          | Autor           | Año | Precio | Rating | Genero | Paginas |\n";
    cout << "--------------------------------------------------------------------------------\n";
    for (size_t i = 0; i < coleccion.size(); ++i) {
        cout << "| " << i << "      | " << coleccion[i].titulo.substr(0, 15) << "... | " 
             << coleccion[i].autor.substr(0, 15) << "... | " << coleccion[i].anio << " | " 
             << coleccion[i].precio << " | " << coleccion[i].rating << " | " << coleccion[i].genero 
             << "      | " << coleccion[i].paginas << "     |\n";
    }
    cout << "--------------------------------------------------------------------------------\n";
}

// Función para insertar un nuevo registro en una posición (operación c)
void insertarRegistro(vector<Libro>& coleccion) {
    if (coleccion.empty()) {
        cout << "La coleccion esta vacia. Insertando al final.\n";
    }
    size_t pos = validarInt("Posicion para insertar (0 para inicio, o indice existente): ");
    if (pos > coleccion.size()) pos = coleccion.size();
    Libro libro;
    cout << "\nNuevo libro:\n";
    libro.titulo = validarString("Titulo: ");
    libro.autor = validarString("Autor: ");
    libro.anio = validarInt("Año: ");
    libro.precio = validarFloat("Precio: ");
    libro.rating = validarDouble("Rating: ");
    libro.genero = validarChar("Genero: ");
    libro.paginas = validarInt("Paginas: ");
    coleccion.insert(coleccion.begin() + pos, libro);
    cout << "Registro insertado.\n";
}

// Función para modificar un registro existente (operación d)
void modificarRegistro(vector<Libro>& coleccion) {
    if (coleccion.empty()) {
        cout << "La coleccion esta vacia.\n";
        return;
    }
    mostrarTabla(coleccion);
    size_t indice = validarInt("Indice del libro a modificar: ");
    if (indice >= coleccion.size()) {
        cout << "Indice invalido.\n";
        return;
    }
    cout << "Modificando libro en indice " << indice << ":\n";
    coleccion[indice].titulo = validarString("Nuevo titulo: ");
    coleccion[indice].autor = validarString("Nuevo autor: ");
    coleccion[indice].anio = validarInt("Nuevo año: ");
    coleccion[indice].precio = validarFloat("Nuevo precio: ");
    coleccion[indice].rating = validarDouble("Nuevo rating: ");
    coleccion[indice].genero = validarChar("Nuevo genero: ");
    coleccion[indice].paginas = validarInt("Nuevo numero de paginas: ");
    cout << "Registro modificado.\n";
}

// Función para eliminar un registro por valor (título) (operación e)
void eliminarRegistro(vector<Libro>& coleccion) {
    if (coleccion.empty()) {
        cout << "La coleccion esta vacia.\n";
        return;
    }
    string tituloBuscar = validarString("Titulo del libro a eliminar: ");
    auto it = find_if(coleccion.begin(), coleccion.end(), [&](const Libro& l) {
        return l.titulo == tituloBuscar;
    });
    if (it != coleccion.end()) {
        coleccion.erase(it);
        cout << "Registro eliminado.\n";
    } else {
        cout << "Libro no encontrado.\n";
    }
}

// Función para ordenar la colección (operación f)
void ordenarColeccion(vector<Libro>& coleccion) {
    if (coleccion.empty()) {
        cout << "La coleccian esta vacia.\n";
        return;
    }
    int opcion = validarInt("Ordenar por precio: 1) Ascendente, 2) Descendente: ");
    if (opcion == 1) {
        sort(coleccion.begin(), coleccion.end(), [](const Libro& a, const Libro& b) {
            return a.precio < b.precio;
        });
        cout << "Ordenado ascendentemente por precio.\n";
    } else if (opcion == 2) {
        sort(coleccion.begin(), coleccion.end(), [](const Libro& a, const Libro& b) {
            return a.precio > b.precio;
        });
        cout << "Ordenado descendentemente por precio.\n";
    } else {
        cout << "Opcion invalida.\n";
    }
}

// Función para encontrar el mayor precio (operación 1 en struct)
void mayorPrecio(const vector<Libro>& coleccion) {
    if (coleccion.empty()) {
        cout << "La coleccion esta vacia.\n";
        return;
    }
    auto maxIt = max_element(coleccion.begin(), coleccion.end(), [](const Libro& a, const Libro& b) {
        return a.precio < b.precio;
    });
    cout << "El libro con mayor precio es: " << maxIt->titulo << " ($" << maxIt->precio << ")\n";
}

// Función para calcular promedio de rating (operación 2 en struct)
void promedioRating(const vector<Libro>& coleccion) {
    if (coleccion.empty()) {
        cout << "La coleccion esta vacia.\n";
        return;
    }
    double suma = 0;
    for (const auto& libro : coleccion) {
        suma += libro.rating;
    }
    cout << "Promedio de rating: " << (suma / coleccion.size()) << "\n";
}

// Función para buscar por título (operación 3 en struct)
void buscarPorTitulo(const vector<Libro>& coleccion) {
    if (coleccion.empty()) {
        cout << "La coleccion esta vacia.\n";
        return;
    }
    string tituloBuscar = validarString("Titulo a buscar: ");
    auto it = find_if(coleccion.begin(), coleccion.end(), [&](const Libro& l) {
        return l.titulo == tituloBuscar;
    });
    if (it != coleccion.end()) {
        cout << "Libro encontrado:\n";
        cout << "Título: " << it->titulo << ", Autor: " << it->autor << ", Año: " << it->anio 
             << ", Precio: $" << it->precio << ", Rating: " << it->rating << ", Genero: " << it->genero 
             << ", Paginas: " << it->paginas << "\n";
    } else {
        cout << "Libro no encontrado.\n";
    }
}

// Función adicional para la matriz: Filtrar por género
void filtrarPorGenero(const vector<Libro>& coleccion) {
    if (coleccion.empty()) {
        cout << "La coleccion esta vacia.\n";
        return;
    }
    char generoFiltro = validarChar("Filtrar por genero ('F' o 'N'): ");
    cout << "\nLibros filtrados:\n";
    for (const auto& libro : coleccion) {
        if (libro.genero == generoFiltro) {
            cout << "Titulo: " << libro.titulo << ", Autor: " << libro.autor << "\n";
        }
    }
}

// Función adicional para el struct: Calcular valor por página
void valorPorPagina(const vector<Libro>& coleccion) {
    if (coleccion.empty()) {
        cout << "La coleccion esta vacia.\n";
        return;
    }
    for (const auto& libro : coleccion) {
        double valor = (libro.paginas > 0) ? (libro.precio / libro.paginas) : 0;
        cout << "Libro: " << libro.titulo << ", Valor por pagina: $" << valor << "\n";
    }
}

// Menú principal interactivo
void menu(vector<Libro>& coleccion) {
    int opcion;
    do {
        cout << "\n--- Menu de Coleccion de Libros ---\n";
        cout << "1. Llenar coleccion\n";
        cout << "2. Mostrar coleccion\n";
        cout << "3. Insertar registro\n";
        cout << "4. Modificar registro\n";
        cout << "5. Eliminar registro\n";
        cout << "6. Ordenar coleccion\n";
        cout << "7. Mayor precio\n";
        cout << "8. Promedio de rating\n";
        cout << "9. Buscar por titulo\n";
        cout << "10. Filtrar por genero (adicional)\n";
        cout << "11. Valor por pagina (adicional)\n";
        cout << "0. Salir\n";
        opcion = validarInt("Seleccione una opcion: ");
        switch (opcion) {
            case 1: llenarColeccion(coleccion); break;
            case 2: mostrarTabla(coleccion); break;
            case 3: insertarRegistro(coleccion); break;
            case 4: modificarRegistro(coleccion); break;
            case 5: eliminarRegistro(coleccion); break;
            case 6: ordenarColeccion(coleccion); break;
            case 7: mayorPrecio(coleccion); break;
            case 8: promedioRating(coleccion); break;
            case 9: buscarPorTitulo(coleccion); break;
            case 10: filtrarPorGenero(coleccion); break;
            case 11: valorPorPagina(coleccion); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

int main() {
    vector<Libro> coleccion; // La "matriz" como vector de structs
    menu(coleccion);
    return 0;
}