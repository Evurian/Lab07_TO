# 🧩 Ejercicio 02: 

Este programa en C++ implementa el **patrón de diseño Singleton** mediante una clase llamada `Logger`, la cual se encarga de gestionar un **archivo de bitácora (log)** donde se registran los eventos del sistema.  

El objetivo es garantizar que exista **una única instancia del logger** encargada de escribir en el archivo, evitando conflictos o duplicación de registros.

---

## ⚙️ Características principales
- **Instancia única:** Controlada mediante un puntero estático `instancia` y el método `getInstancia()`.  
- **Constructor privado:** Impide la creación directa de objetos desde fuera de la clase.  
- **Archivo de registro único:** Los mensajes se guardan en `bitacora.log`.  
- **Inicialización automática:** Se escribe una cabecera con la fecha y hora de inicio del log.  
- **Métodos principales:**
  - `log(string mensaje)`: Agrega una línea al log con la fecha y hora.  
  - `mostrarLogs()`: Muestra el contenido completo del archivo de bitácora.  
  - `destruirInstancia()`: Libera la instancia creada.  

---

## 🧠 Funcionamiento
1. El método `getInstancia()` crea la única instancia de `Logger` si aún no existe.  
2. Desde distintos punteros (`logger1`, `logger2`, `logger3`) se registran mensajes en el mismo archivo.  
3. Cada mensaje se guarda con una marca de tiempo (`timestamp`) generada automáticamente.  
4. Finalmente, se muestra el contenido completo del log y se destruye la instancia.  


