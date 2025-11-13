#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

class Logger {
private:
    static Logger* instancia;
    string nombreArchivo;
    
    Logger() {
        nombreArchivo = "bitacora.log";
        inicializarArchivo();
    }
    
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    // Inicializa el archivo de log
    void inicializarArchivo() {
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            time_t ahora = time(0);
            tm* tiempoLocal = localtime(&ahora);
            archivo << "=== Log iniciado el " 
                    << put_time(tiempoLocal, "%Y-%m-%d %H:%M:%S") 
                    << " ===" << endl << endl;
            archivo.close();
        } else {
            cerr << "Error al inicializar el archivo de log" << endl;
        }
    }
    
    // Obtiene el timestamp actual
    string obtenerTimestamp() const {
        time_t ahora = time(0);
        tm* tiempoLocal = localtime(&ahora);
        stringstream ss;
        ss << put_time(tiempoLocal, "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }
    
public:
    // Método para obtener la única instancia
    static Logger* getInstancia() {
        if (instancia == nullptr) {
            instancia = new Logger();
        }
        return instancia;
    }
    
    // Registra un mensaje en el archivo de log
    void log(const string& mensaje) {
        ofstream archivo(nombreArchivo, ios::app);
        if (archivo.is_open()) {
            string timestamp = obtenerTimestamp();
            string lineaLog = "[" + timestamp + "] " + mensaje;
            archivo << lineaLog << endl;
            archivo.close();
            cout << "Log registrado: " << lineaLog << endl;
        } else {
            cerr << "Error al escribir en el log" << endl;
        }
    }
    
    // Muestra el contenido completo del archivo de log
    void mostrarLogs() const {
        cout << "\n=== Contenido del archivo de log ===" << endl;
        ifstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            string linea;
            while (getline(archivo, linea)) {
                cout << linea << endl;
            }
            archivo.close();
        } else {
            cerr << "Error al leer el archivo de log" << endl;
        }
    }
    
    static void destruirInstancia() {
        if (instancia != nullptr) {
            delete instancia;
            instancia = nullptr;
        }
    }
};

Logger* Logger::instancia = nullptr;


int main() {
    cout << string(70, '=') << endl;
    cout << "EJERCICIO 02: Logger con recursos compartidos" << endl;
    cout << string(70, '=') << endl;
    cout << endl;
    
    // Crear múltiples instancias del logger
    cout << "--- Usando logger1 ---" << endl;
    Logger* logger1 = Logger::getInstancia();
    logger1->log("Inicio de la aplicación");
    
    cout << "\n--- Usando logger2 ---" << endl;
    Logger* logger2 = Logger::getInstancia();
    logger2->log("Procesando datos del usuario");
    
    cout << "\n--- Usando logger3 ---" << endl;
    Logger* logger3 = Logger::getInstancia();
    logger3->log("Operación completada exitosamente");
    
    // Agregar más logs desde diferentes "instancias"
    cout << "\n--- Más logs desde logger1 ---" << endl;
    logger1->log("Guardando información en la base de datos");
    
    cout << "\n--- Más logs desde logger2 ---" << endl;
    logger2->log("Enviando notificación al usuario");
        
    // Mostrar el contenido del archivo
    logger1->mostrarLogs();
    
    Logger::destruirInstancia();
    
    return 0;
}