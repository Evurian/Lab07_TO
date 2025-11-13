#include <iostream>
#include <string>

using namespace std;

class Configuracion {
private:
    // Instancia única (Singleton)
    static Configuracion* instancia;
    
    // Atributos de configuración
    string idioma;
    string zonaHoraria;
    
    // Constructor privado para evitar instanciación directa
    Configuracion() {
        idioma = "Español";
        zonaHoraria = "UTC-5";
    }
    
    // Eliminar constructor de copia y operador de asignación
    Configuracion(const Configuracion&) = delete;
    Configuracion& operator=(const Configuracion&) = delete;
    
public:
    static Configuracion* getInstancia() {
        if (instancia == nullptr) {
            instancia = new Configuracion();
        }
        return instancia;
    }
    
    string getIdioma() const {
        return idioma;
    }
    
    void setIdioma(const string& nuevoIdioma) {
        idioma = nuevoIdioma;
    }
    
    string getZonaHoraria() const {
        return zonaHoraria;
    }
    
    void setZonaHoraria(const string& nuevaZonaHoraria) {
        zonaHoraria = nuevaZonaHoraria;
    }
    
    void mostrarConfiguracion() const {
        cout << "=== Configuración del Sistema ===" << endl;
        cout << "Idioma: " << idioma << endl;
        cout << "Zona Horaria: " << zonaHoraria << endl;
        cout << "Dirección del objeto: " << this << endl;
        cout << endl;
    }
    
    static void destruirInstancia() {
        if (instancia != nullptr) {
            delete instancia;
            instancia = nullptr;
        }
    }
};

// Inicializar el puntero estático
Configuracion* Configuracion::instancia = nullptr;


int main() {
    cout << string(70, '=') << endl;
    cout << "EJERCICIO 01: Singleton básico (Configuración)" << endl;
    cout << string(70, '=') << endl;
    cout << endl;
    
    Configuracion* config1 = Configuracion::getInstancia();
    config1->mostrarConfiguracion();
    
    Configuracion* config2 = Configuracion::getInstancia();
    config2->setIdioma("Inglés");
    config2->setZonaHoraria("UTC-3");
    config2->mostrarConfiguracion();
    
    cout << "--- Verificando que config1 también cambió ---" << endl;
    config1->mostrarConfiguracion();
    
    Configuracion* config3 = Configuracion::getInstancia();
    config3->mostrarConfiguracion();
    
    Configuracion::destruirInstancia();
    
    return 0;
}