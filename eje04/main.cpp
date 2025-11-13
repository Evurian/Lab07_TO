#include <iostream>
#include <string>
using namespace std;
#include "ControlJuego.cpp"

// Simulación de módulos del juego
void jugador() {
    ControlJuego::getInstancia().aumentarPuntaje(100);
    cout << "[Jugador] Gana 100 puntos.\n";
}

void enemigo() {
    ControlJuego::getInstancia().perderVida();
    cout << "[Enemigo] Quita una vida.\n";
}

void interfaz() {
    cout << "[Interfaz] Estado actual: ";
    ControlJuego::getInstancia().mostrarEstado();
}

int main() {
    cout << "=== INICIO DEL JUEGO ===\n";
    interfaz();

    jugador();
    interfaz();

    enemigo();
    interfaz();

    ControlJuego::getInstancia().subirNivel();
    cout << "[Sistema] Avanzas al siguiente nivel.\n";
    interfaz();

    cout << "=== FIN DEL JUEGO ===\n";
    return 0;
}
