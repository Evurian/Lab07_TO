# 🎮 Ejercicio 04 – Patrón Singleton en un Juego

## 🧩 Descripción General

Este proyecto implementa el **patrón de diseño Singleton** en un contexto de videojuego.  
El objetivo principal es demostrar cómo mantener un **estado global compartido** —como el nivel, el puntaje y las vidas del jugador— al que puedan acceder todos los módulos del sistema: el jugador, los enemigos y la interfaz.

De esta manera, se garantiza que toda la información del juego sea **consistente y centralizada**, evitando duplicación de datos o comportamientos incoherentes.

---

## 🧠 Concepto Clave: Singleton

El patrón **Singleton** pertenece a la categoría de **patrones creacionales**, cuyo propósito es **restringir la creación de objetos a una única instancia** dentro de un programa.

Esta instancia actúa como una especie de **“centro de control global”**, al cual todos los componentes pueden acceder para consultar o modificar información.

### ✨ Beneficios del Singleton
- Asegura que solo exista **una instancia** del controlador global del juego.  
- Facilita el **acceso compartido a los datos** por diferentes partes del programa.  
- Mejora la **coherencia** en el manejo del estado general del juego.

### ⚠️ Desventajas
- Puede **dificultar las pruebas unitarias**, ya que mantiene estado persistente entre ejecuciones.  
- Tiende a **acoplar los módulos** al uso de una instancia global, lo cual reduce la flexibilidad.  
- Si se abusa de su uso, puede transformarse en un **antipatrón**, afectando la mantenibilidad del software.

---

## 🧱 Estructura del Proyecto

El proyecto se compone de dos archivos principales:

- **ControlJuego.cpp:** Contiene la implementación del controlador global del juego mediante el patrón Singleton.  
  Gestiona el nivel actual, el puntaje acumulado y las vidas disponibles.

- **main.cpp:** Simula los diferentes módulos del juego.  
  A través de funciones separadas, el jugador gana puntos, los enemigos reducen vidas y la interfaz muestra el estado global actual.

---

## 🕹️ Funcionamiento del Programa

Durante la ejecución del juego:
1. Se inicializa el estado global del juego con nivel 1, tres vidas y puntaje cero.  
2. El **jugador** incrementa el puntaje al lograr acciones exitosas.  
3. El **enemigo** reduce las vidas del jugador en caso de impacto o error.  
4. La **interfaz** muestra en pantalla el estado actualizado del juego después de cada evento.  
5. Finalmente, el sistema puede aumentar el nivel una vez alcanzado un objetivo, manteniendo siempre el mismo estado global.

El flujo de ejecución refleja cómo **todas las partes del programa comparten una sola instancia del controlador**, cumpliendo así el principio del patrón Singleton.

---

## 🧩 Reflexión y Buenas Prácticas

El patrón Singleton es útil cuando se requiere un **único punto de acceso global** a información o recursos comunes, como configuraciones, registros de logs o controladores de juego.

Sin embargo, se recomienda usarlo con cuidado:
- No debe reemplazar una arquitectura modular.  
- No debe utilizarse para compartir todos los datos del sistema.  
- Es preferible aplicarlo solo cuando la **unicidad de la instancia** sea un requisito esencial del diseño.

---