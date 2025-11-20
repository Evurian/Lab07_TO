#include <iostream>
#include <string>
using namespace std;

class ConexionBD {
private:
    static ConexionBD* instancia;
    bool conectada;
    
    ConexionBD() : conectada(false) {
        cout << "Creando nueva conexion a la base de datos..." << endl;
    }
    
    ConexionBD(const ConexionBD&) = delete;
    
    ConexionBD& operator=(const ConexionBD&) = delete;

public:
    static ConexionBD* obtenerInstancia() {
        if (instancia == nullptr) {
            instancia = new ConexionBD();
        } else {
            cout << "Reutilizando conexion existente..." << endl;
        }
        return instancia;
    }
    
    void conectar() {
        if (!conectada) {
            cout << "Conectando a la base de datos..." << endl;
            conectada = true;
            cout << "Conexion establecida correctamente" << endl;
        } else {
            cout << "Ya existe una conexion activa" << endl;
        }
    }
    
    void desconectar() {
        if (conectada) {
            cout << "Desconectando de la base de datos..." << endl;
            conectada = false;
            cout << "Conexion cerrada" << endl;
        } else {
            cout << "No hay conexion activa para cerrar" << endl;
        }
    }
    
    bool estado() {
        string estadoActual = conectada ? "CONECTADA" : "DESCONECTADA";
        cout << "Estado de la conexion: " << estadoActual << endl;
        return conectada;
    }
    
    // Destructor
    ~ConexionBD() {
        if (conectada) {
            desconectar();
        }
        cout << "Destruyendo instancia de ConexionBD" << endl;
    }
    
    static void liberarInstancia() {
        if (instancia != nullptr) {
            delete instancia;
            instancia = nullptr;
        }
    }
};

ConexionBD* ConexionBD::instancia = nullptr;


int main() {

    cout << "\n1. Creando primera conexion..." << endl;
    ConexionBD* conexion1 = ConexionBD::obtenerInstancia();
    conexion1->estado();
    
    cout << "\n2. Intentando conectar..." << endl;
    conexion1->conectar();
    conexion1->estado();
    
    cout << "\n3. Intentando crear segunda conexion..." << endl;
    ConexionBD* conexion2 = ConexionBD::obtenerInstancia();
    conexion2->estado();
    
    cout << "\n4. Verificando identidad de las instancias..." << endl;
    cout << "Son la misma instancia: " << (conexion1 == conexion2 ? "SI" : "NO") << endl;
    cout << "Direccion de conexion1: " << conexion1 << endl;
    cout << "Direccion de conexion2: " << conexion2 << endl;
    
    cout << "\n5. Intentando conectar desde conexion2..." << endl;
    conexion2->conectar();
    
    cout << "\n6. Desconectando..." << endl;
    conexion1->desconectar();
    conexion1->estado();
    
    cout << "\n7. Verificando estado desde conexion2..." << endl;
    conexion2->estado();

    
    cout << "\n9. Liberando instancia..." << endl;
    ConexionBD::liberarInstancia();
    

    return 0;
}