#include <iostream>
#include <string>
using namespace std;

class ControlJuego {
private:
    // Atributos del estado global
    int nivel;
    int puntaje;
    int vidas;

    // Constructor privado (para evitar instancias múltiples)
    ControlJuego() {
        nivel = 1;
        puntaje = 0;
        vidas = 3;
    }

    // Evitamos copia o asignación
    ControlJuego(const ControlJuego&) = delete;
    ControlJuego& operator=(const ControlJuego&) = delete;

public:
    // Método estático que devuelve la única instancia
    static ControlJuego& getInstancia() {
        static ControlJuego instancia; // se crea solo una vez
        return instancia;
    }

    // Métodos del juego
    void subirNivel() { nivel++; }
    void aumentarPuntaje(int puntos) { puntaje += puntos; }
    void perderVida() { vidas--; }

    // Mostrar estado
    void mostrarEstado() {
        cout << "Nivel: " << nivel
             << " | Puntaje: " << puntaje
             << " | Vidas: " << vidas << endl;
    }
};