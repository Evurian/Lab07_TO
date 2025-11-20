# Ejercicio 03: Conexión Simulada a Base de Datos

Este programa en **C++** implementa el patrón de diseño **Singleton** mediante una clase llamada `ConexionBD`, la cual se encarga de gestionar una conexión simulada a una base de datos.  
El objetivo es garantizar que exista **una única conexión activa** en todo el sistema, evitando múltiples conexiones innecesarias que desperdicien recursos.

---

## Características principales

- **Instancia única:** Controlada mediante un puntero estático `instancia` y el método `obtenerInstancia()`.
- **Constructor privado:** Impide la creación directa de objetos desde fuera de la clase.
- **Control de estado:** Mantiene un registro interno del estado de la conexión (conectada/desconectada).
- **Prevención de duplicados:** Se deshabilitan el constructor de copia y el operador de asignación (`= delete`).

### Métodos principales
- `conectar()`: Establece la conexión a la base de datos si aún no está conectada.  
- `desconectar()`: Cierra la conexión activa si existe.  
- `estado()`: Consulta y muestra el estado actual de la conexión.  
- `liberarInstancia()`: Libera la memoria de la instancia creada.

---

## Funcionamiento

1. El método `obtenerInstancia()` crea la única instancia de `ConexionBD` si aún no existe.  
2. Desde distintos punteros (`conexion1`, `conexion2`, `conexion3`) se verifica que todos apuntan a la misma instancia.  
3. Se prueba la conexión y desconexión desde diferentes referencias, confirmando que el estado es compartido.  
4. Se valida que no es posible conectar dos veces ni desconectar cuando no hay conexión activa.  
5. Finalmente, se libera la instancia única y se destruye correctamente.

---
