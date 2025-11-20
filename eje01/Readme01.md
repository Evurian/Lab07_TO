Este programa en C++ implementa el **patrón de diseño Singleton**, utilizando una clase llamada `Configuracion` que almacena y gestiona parámetros globales del sistema, como el idioma y la zona horaria.  
Garantizar que exista **una única instancia** de la clase `Configuracion` durante toda la ejecución del programa, evitando duplicados y manteniendo una configuración centralizada.

## Características principales
- **Instancia única:** Se controla mediante un puntero estático `instancia` y un método `getInstancia()`.  
- **Constructor privado:** Impide la creación de objetos fuera de la clase.  
- **Bloqueo de copia:** Se eliminan el constructor de copia y el operador de asignación.  
- **Método de destrucción controlada:** `destruirInstancia()` libera la memoria utilizada por la instancia.  
- **Métodos de acceso y modificación:** `getIdioma()`, `setIdioma()`, `getZonaHoraria()`, `setZonaHoraria()`.  
- **Visualización:** `mostrarConfiguracion()` muestra los valores actuales y la dirección de memoria del objeto.

## Ejecución
1. Se obtiene la instancia mediante `getInstancia()`.
2. Se modifica la configuración a través de diferentes punteros (`config1`, `config2`, `config3`).
3. Se demuestra que todos apuntan al **mismo objeto**, compartiendo los mismos datos.
4. Finalmente, se destruye la instancia con `destruirInstancia()`.

El programa mostrará que todas las referencias (`config1`, `config2`, `config3`) tienen la **misma dirección de memoria**, confirmando que solo existe **una única instancia**.
