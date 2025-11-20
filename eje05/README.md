
# 📝 Ejercicio 05 – Singleton Thread-Safe para un Logger Multihilo

## 🧩 Descripción General

Este proyecto implementa una versión **segura en entornos multihilo** del patrón de diseño **Singleton**, aplicada al módulo **Logger**, responsable de registrar eventos en un archivo de bitácora.

El objetivo principal es garantizar que, incluso si múltiples hilos acceden simultáneamente a la instancia, **solo se cree un único objeto Logger**, evitando corrupción del archivo o duplicación de instancias.

Para lograrlo se utiliza la técnica **double-checked locking**, un método eficiente que asegura la creación controlada y sincronizada del Singleton.

---

## 🧠 Concepto Clave: Singleton Thread-Safe

El patrón **Singleton** pertenece a los patrones creacionales y su propósito es asegurar la existencia de **una única instancia global** accesible desde todo el programa.
En entornos multihilo, un Singleton tradicional puede fallar porque varios hilos podrían intentar crear la instancia al mismo tiempo.

---

## 🔐 Double-Checked Locking
Este ejercicio emplea esta técnica para mejorar seguridad y rendimiento. El proceso es:

- Comprobar si la instancia es **nullptr** sin bloqueo.
- Utilizar **std::mutex** para bloquear el acceso cuando es necesario.
- Volver a comprobar si la instancia sigue siendo **nullptr**.
- Crear la instancia de forma segura dentro de la sección crítica.

Este enfoque minimiza el uso del mutex y evita condiciones de carrera.

---

## 🧱 Estructura del Proyecto
El proyecto consta de un único archivo principal:

**eje05.cpp**

Incluye:

- La clase **Logger** implementada como Singleton thread-safe.
- Uso de **std::mutex** para sincronizar el acceso entre hilos.
- Aplicación del mecanismo double-checked locking.
- Métodos para registrar mensajes y mostrar la bitácora.
- Un **main()** de prueba que demuestra el funcionamiento del patrón en ambiente multihilo.

---

## 🔧 Funcionamiento del Programa

Durante su ejecución:

- Varios hilos solicitan acceso al logger mediante **Logger::getInstancia()**.
- Solo un hilo crea la instancia del singleton gracias al double-checked locking.
- Los hilos escriben mensajes en un mismo archivo **bitacora.log**.
- La instancia única gestiona las escrituras de forma segura y ordenada.
- El usuario puede visualizar todos los registros generados con **mostrarLogs()**.
- El flujo demuestra cómo mantener consistencia y unicidad incluso bajo concurrencia.

---

## 🧩 Reflexión y Buenas Prácticas

El patrón Singleton es útil cuando se necesita un **punto global de acceso** a un recurso compartido, como un logger, un manejador de configuración o una conexión de base de datos.

Sin embargo, se recomienda:

- Usarlo solo cuando la unicidad de instancia sea indispensable.
- Proteger adecuadamente las instancias en aplicaciones multihilo.
- Evitar abusar del patrón para no generar acoplamiento excesivo.
- Considerar alternativas más flexibles cuando se requiera escalabilidad.

Este ejercicio ejemplifica cómo adaptar un Singleton básico para hacerlo seguro, robusto y eficiente en aplicaciones concurrentes modernas.
