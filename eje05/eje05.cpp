#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <mutex>
#include <thread>

using namespace std;

class Logger {
private:
    static Logger* instancia;
    static std::mutex mtx;   // Mutex para proteger la creación
    string nombreArchivo;

    // Constructor privado
    Logger() {
        nombreArchivo = "bitacora.log";
        inicializarArchivo();
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Inicializa el log
    void inicializarArchivo() {
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            time_t ahora = time(0);
            tm* tiempoLocal = localtime(&ahora);

            archivo << "=== Log iniciado el "
                    << put_time(tiempoLocal, "%Y-%m-%d %H:%M:%S")
                    << " ===\n\n";
        }
    }

    string obtenerTimestamp() const {
        time_t ahora = time(0);
        tm* tiempoLocal = localtime(&ahora);
        stringstream ss;
        ss << put_time(tiempoLocal, "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }

public:
    // --- Singleton Thread-Safe con double-checked locking ---
    static Logger* getInstancia() {
        if (instancia == nullptr) {          // 1. Verificación sin bloqueo
            lock_guard<mutex> lock(mtx);     //    Bloqueo
            if (instancia == nullptr) {      // 2. Verificación con bloqueo
                instancia = new Logger();    //    Creación segura
            }
        }
        return instancia;
    }

    void log(const string& mensaje) {
        ofstream archivo(nombreArchivo, ios::app);
        if (archivo.is_open()) {
            archivo << "[" << obtenerTimestamp() << "] " << mensaje << "\n";
        }
    }

    void mostrarLogs() const {
        ifstream archivo(nombreArchivo);
        string linea;

        cout << "\n=== Log ===\n";
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
    }

    static void destruirInstancia() {
        lock_guard<mutex> lock(mtx);
        delete instancia;
        instancia = nullptr;
    }
};

// Inicialización de variables estáticas
Logger* Logger::instancia = nullptr;
std::mutex Logger::mtx;
void escribirLog(int id) {
    Logger::getInstancia()->log("Mensaje desde hilo " + to_string(id));
}

int main() {
    thread h1(escribirLog, 1);
    thread h2(escribirLog, 2);
    thread h3(escribirLog, 3);

    h1.join();
    h2.join();
    h3.join();

    Logger::getInstancia()->mostrarLogs();

    return 0;
}

