# Tema 3. Modelos de Datos

Recordemos que del modelo de datos surgen los datos, del modelo de procesos surgen los procesos, y de la suma de ambas partes surge el sistema de información.

**Tipos de modelos de datos**:
- Modelo relacional
- Modelo orientado a objetos
- Modelo objeto-relacional (es una extensión del relacional con algunas características del modelo de objetos)
- Modelos para bases de datos NoSQL
- Otros modelos de datos

**Concepto**

Representación, relativamente sencilla, orientada a la descripción de los datos del mundo real y que, usualmente describe:
- La estructura de los datos (table)
- Las condiciones que deben cumplir los datos
- Cómo se manejan los datos (insert, delete, update, select...)

**Representación**

Tienen asociados una serie de conceptos, que describen un conjunto de datos y operaciones para manipular los datos. Dichos conceptos tienen asociados una construcción lingüística y una gráfica.

**Clases**

- En el Modelo Conceptual representan la realidad en un alto nivel de abstracción. Genera el Esquema Conceptual.
- En el Modelo Lógico, o Modelo de Base de Datos, describen las relaciones lógicas entre los datos y la base de datos. Genera el Esquema Lógicp.

**Características**

- Los elementos de un modelo representan Entidades genéricas
- Los valores concretos se denominan instancias u ocurrencias de una entidad.
- Cada SGBD se asocia a un modelo de datos específico, aunque puede haber excepciones.

**Contenidos**

- Respecto a los datos: Se representan mediante el Lenguaje de Definición de Esquema (LDE) del SGBD.
  - Datos o Entidades
  - Propiedades de los Datos
  - Relaciones de los Datos
  - Restricciones de los Datos

- Respecto a las operaciones: Se representa mediante el Lenguaje de Manipulación de Datos (LMD) del SGBD.
  - Operaciones de los Datos.
  - Operaciones sobre Relaciones de los Datos.
  - Relaciones entre Operaciones.

## Modelo de Datos de Fichero Plano

**Características:**

- Modelo más simple
- Matriz bidimensional de elementos, sin relaciones con otras matrices.
- Miembros en una misma columna tienen valores del mismo tipo.
- Miembros de la misma fila están relacionados entre ellos.

## Modelo de Datos Jerárquico

**Características:**

- Modelo creado por IBM en los años 60.
- Datos organizados en una estructura arbórea.
- Relaciones 1:N entre los datos.
- Las relaciones entre datos se establecen siempre a nivel físico.
- Muy eficiente en relaciones de datos con estructura jerárquica.

## Modelo de Datos en Red

**Características:**

- Modelo creado a partir de las especificaciones del grupo CODASYL.
- Generalización del modelo jerárquico
- Permite relaciones N:N en una estructura tipo árbol que permite múltiples padres.
- De este modo se reducen las redundancias.
- Desaparece la herencia de los campos.
- La integridad de datos, asociada a los arcos padre-hijo, se mantiene.

## Modelo de Datos Relacional

Basado en el concepto de **Relación**, que formalmente puede verse como un par de conjuntos (R,r) donde:
- R se denomina esquema
- r se denomina instancia

Un **esquema** es un conjunto: R = {A1:D1, A2:D2, ..., An:Dn} donde:
- Ai son atributos, es decir, una representación de un elemento de información del "mundo" que es susceptible de tomar valores
- Di son los dominios de los atributos, es decir, los posibles valores que toman los atributos.

Una **instancia** es la aplicación de un esquema a un conjunto finito de datos r pertenece al conjunto D1xD2x...xDn (contenido de una tabla o parte de ella en un momento dado).
Visualmente, es una estructura bidimensional formada por columnas (atributos) y filas (tuplas).

Una **base de datos relacional** es un conjunto finito de relaciones.

Una **instancia de la BD** es una colección de instancias de las relaciones. Sin embargo, no todas las instancias de las relaciones de datos son válidas. Puede no mantenerse la correción semántica. Para mantener la semántica se deben respetar las restricciones de integridad, es decir, unas reglas que mantienen correcta la información que almacena.

El esquema de una base de datos es una colección de esquemas de relación junto con una serie de restricciones de integridad.

Una instancia de la base de datos es válida si respeta las reglas de integridad.

Para mantener la semántica se deben respetar las restricciones de integridad:
- Restricciones específicas que provienen de la semántica del atributo y son propias de cada base de datos concreta (ej: edad >= 0)
- Restricciones genéricas, son aquellas que se aplican a los atributos en función del papel que desempeñan en la estructura de la BD. Son meta-reglas, normas genéricas que generan reglas. Giran en torno a los conceptos de clave primaria y externa.

### ACID

Transacciones (= cualquier elemento que manipule, elimine, modifique, cree, etc información) ACID (Atomicidad, Consistencia, Isolation (aislamiento) y Durabilidad), que garantizan la consistencia y estabilidad de las operaciones pero requieren una gestión de bloqueo sofisticada:
- Atomicidad: es la propiedad que asegura que la operación se ha realizado o no, y por lo tanto, no puede quedar a medias ante un fallo del sistema. Por ejemplo, en el caso de una transacción bancaria o se ejecuta tanto el depósito como la deducción o ninguna acción es realizada.
- Consistencia: Integridad. La propiedad de consistencia sostiene que cualquier transacción llevará a la base de datos desde un estado válido a otro también válido (de acuerdo con las restricciones y reglas establecidas en la BD).
- Aislamiento: La ejecución concurrente de dos transacciones da como resultado un estado del sistema que sería el mismo que si se hubieran ejecutado secuencialmente.
- Durabilidad: Persistencia. Es la propiedad que asegura que una vez establecida una transacción, ésta persistirá y no se perderán los cambios aunque falle el sistema.

### Otros elementos del modelo de datos relacional

Un conjunto CC de atributos en una relación se dicen que son claves candidatas si se verifica lo siguiente:
- Unicidad. Si dos instancias de la relación coinciden en lso atributos de la clave candidata, entonces coinciden en el resto de atributos de la relación.
- Minimalidad (o Irreducibilidad). La propiedad anterior no se verifica para cualquier subconjunto propio de CC.
  - Se llama superclave si solo verifica la unicidad.
  - Se llama clave primaria a una clave candidata elegida por el diseñador (sólo una por relación)

Dada una clave primaria CP de una relación R, y un conjunto de atributos CE de otra relación S, con CE contenido en CP. Se dice CE es clave externa respecto a CP si el dominio activo de CE está contenido en el dominio activo de CP.

Propiedades de las relaciones:
- No hay orden en las tuplas
- No hay orden en los atributos
- No hay tuplas duplicadas (es un conjunto)
- El esquema de toda relación tiene una clave primaria.
- Los valores de los atributos son atómicos (no tienen estructura)

Reglas de integridad:
- Integridad de entidad: Los atributos de una clave primaria no pueden tomar valores nulos.
- Integridad referencial: El valor de una clave externa debe ser igual a un valor del dominio activo de la clave primaria, o nulo.

¿Cómo mantener la integridad del sistema?
- Integridad de entidad: Comprobar que los atributos que forman parte de una clave primaria son no nulos y que el valor conjunto de ellos no está repetido en procesos de Inserción y Actualización.
- Integridad referencial:
  - Inserción. Comprobar que el valor de la clave externa es nulo o concuerda con un valor de la clave primaria.
  - Actualización. Si se actualiza la clave externa, comprobar las condiciones de clave externa. Si se actualiza la clave primaria, actualizar en cadena la clave externa.
  - Borrado. Si se borra la clave primaria, borrado en cadena o valor nulo en cadena de la clave externa.

SQL es el lenguaje de consultas predominante. Basado en:
- Algebra relacional (teoría de conjuntos). Obtiene resultado aplicando varios operadores (8).
- Cálculo Relacional (lógica de primer orden).
  - Orientado a tuplas
  - Orientado a dominios

SQL presenta dos sublenguajes:
- DDL (Data Description Language) que permite definir y manejar esquemas de estructuras relacionales (relaciones, vistas, ...).
- DML (Data Management Language) que permita manipular instancias de estructuras relaciones (tuplas).


## Modelo de Datos Orientado a Objetos

Motivación:
- Necesidad de los Lenguajes OO
  - Los modelos de datos y las estructuras de los LPOO están desacoplados.
  - Persistencia de Objetos (más allá de los programas): Persistencia para guardar/almacenar objetos por lo que necesito bases de datos.
  - Almacenamiento más eficiente y gestión de datos en memoria secundaria.
  - Independencia de los datos respecto de los programas.
  - Lenguaje de consulta eficiente y de alto nivel (independiente de la estructura física).
  - Gestión de transacciones que permita: acceso concurrente, integridad, seguridad y recuperación ante fallos.
  - Control de integridad.
- Limitaciones de Bases de Datos Relacionales
  - Presentan estructuras simples (ej: imposición de 1FN)
  - Poca riqueza semántica
  - No soportan tipos definidos por el usuario (sólo dominios)
  - No soportan recursividad
  - Falta de procedimientos/disparadores.
  - No admite herencia.

Por todo lo anterior, las bases de datos relacionales no se consideran apropiadas para aplicaciones que manejen estructuras de datos complejas.

¿Qué ocurre si convertimos objetos y relaciones al modelo relacional? La traducción de objetos a tablas implica:
- Mayor tiempo de desarrollo. El tiempo empleado en generar el código para la traducción de objetos a tablas y viceversa.
- Errores debidos precisamente a esa traducción.
- Inconsistencias debidas a que el ensamblaje / desensamblaje puede realizarse de forma diferente en las distintas aplicaciones.
- Mayor tiempo de ejecución empleado para el ensamblaje / desensamblaje.

Manifiesto de los sistemas de base de datos orientados (1989): Establecieron una serie de características:
- Obligatorias: Imprescindibles satisfacerlas para ser calificadas como OO.
  - Al ser un SGBD
    - Persistencia
    - Gestón del almacenamiento secundario
    - Concurrencia
    - Recuperación ante fallos
    - Lenguajes ad-hoc para manipulación
  - Al ser OO
    - Objetos complejos
    - Identidad del objeto
    - Encapsulamiento
    - Tipos o clases
    - Herencia
    - Polimorfismo, sobrecarga y vinculación dinámica (método que se puede aplicar a distintos objetos de distintas clases).
    - Extensibilidad
    - Completitud de cálculos (lenguaje de propósito general)
- Opcionales: Pueden añadirse para mejorar el sistema.
  - Herencia múltiple
  - Verificación e inferencia del tipo
  - Distribución
  - Transacciones de diseño
- Abiertas: Posibilidades adicionales aceptables, a aplicar a juicio del diseñador.
  - Paradigma de programación
  - Sistema de representación (tipos atómicos y constructores)
  - Sistema de tipos
  - Uniformidad (¿todo objetos?)

El sistema de gestión de bases de datos de un modelo de datos orientado a objetos es similar a una base de datos relacional, pero con un modelo de base de datos orientada a objetos.
Soporta objetos, clases y herencia directamente en los esquemas de bases de datos y en el lenguaje de consulta.  

Reglas generales para el modelado objeto/relacional:
- Cada clase persistente tiene una tabla de base de datos correspondiente.
- Campos de objetos con tipos de datos primitivos (enteros, caracteres, cadenas, etc.) se asignan a columnas en la tabla de base de datos asociada.
- Cada fila de una tabla de base de datos corresponde a una instancia de su clase persistente asociada.
- Cada relación de objeto de muchos a muchos requiere una tabla de join al igual que las entidades de base de datos con muchos-a-muchos requieren tabla de joins.
- La herencia es modelada a través de una relación uno-a-uno entre las dos tablas que corresponden a la clase y subclase.

Manifiesto de los SGBD de 3a Generación: Además de los servicios tradicionales de gestión de datos, los SGBD-3G proporcionarán gestión de objetos y reglas más ricas:
- Un SGBD-3G debe tener un sistema de tipos rico.
- La herencia es una buena idea.
- Las funciones (procedimientos y métodos) son una buena idea.
- Las IDOs para los registros deberían asignarse por el SGBD sólo si no se dispone de una clave primaria.
- Las reglas (disparadores, restricciones) se convertirán en una característica primordial de los sistemas futuros.

**Desafíos**:
- La BD no escala con el tráfico a un coste aceptable.
- El tamaño del esquema de datos crece desproporcionadamente.
- El sistema de información genera muchos datos temporales que no corresponden al almacén de datos principal (carritos de compra, personalización de portales).
- Tener que desnormalizar la BD por razones de rendimiento o por conveniencia para utilizar los datos en una aplicación. (ej: si hemos hecho muchos join)
- La BD contiene grandes cantidades de texto o imágenes en columnas como BLOBs (Binary Large Objects)
- Se ejecutan consultas sobre los datos que implican relaciones jerárquicas complejas; recomendaciones o consultas de inteligencia de negocio.
- Se usan transacciones locales que no necesitan ser muy durables.

Solución: NoSQL

## NoSQL

**Concepto**

"Not only SQL", categoría general de sistemas de gestión de bases de datos que difiere de los RDBMS en diferentes modos:
- No usan SQL (aunque podrían) como el principal lenguaje de consultas.
- Los datos almacenados no requieren estructuras fijas como tablas.
- Normalmente no soportan operaciones JOIN.
- Normalmente no garantizan completamente ACID (atomicidad, consistencia, aislamiento y durabilidad).
- Habitualmente escalan bien horizontalmente (si se añaden nodos o pcs)

**Modelo BASE vs ACID**

- BAsic availability: Siempre se obtiene una respuesta del sistema a una petición de datos aunque esta sea un fallo o que sean inconsistentes o estén en fase de cambio.
- Soft-state: el estado del sistema cambia constantemente a lo largo del tiempo, incluso aunque no hayan entradas de datos en ese periodo, debido a la consistencia eventual.
- Eventual consistency: eventualmente, el sistema se volverá consistente a partir de que deje de recibir datos. Los datos se propagarán pero el sistema seguirá recibiendo datos sin evaluar la consistencia de los datos para cada transmisión antes de avanzar a la siguiente.

El modelo de datos NoSQL se ha diseñado para potenciar aspectos como:
- Flexibilidad: las bases de datos NoSQL generalmente ofrecen esquemas flexibles que permiten un desarrollo más rápido y más iterativo. El modelo de datos flexible hace que las bases de datos NoSQL sean ideales para datos semiestructurados y no estructurados.
- Escalabilidad: las bases de datos NoSQL generalmente están diseñadas para escalar usando clústeres distribuidos de hardware en lugar de escalar añadiendo servidores caros y sólidos. Algunos proveedores de la nube manejan estas operaciones fuera el alcance, como un servicio completamente administrado.
- Alto rendimiento: la base de datos NoSQL está optimizada para modelos de datos específicos (como documentos, clave-valor y gráficos) y patrones de acceso que permiten un mayor rendimiento que el intento de lograr una funcionalidad similar con bases de datos relacionales.
- Altamente funcional: las bases de datos NoSQL proporcionan API altamente funcionales y tipos de datos que están diseñados específicamente para cada uno de sus respectivos modelos de datos.

**Teorema de Brewer**: Es imposible para un sistema computacional distribuido ofrecer simultáneamente las siguientes tres garantías:
  - Consistencia: todos los nodos ven los mismos datos al mismo tiempo.
  - Availability: garantiza que cada petición recibe una respuesta acerca de si tuvo éxito o no. Cada cliente siempre puede leer y escribir.
  - Partition tolerance: el sistema tiene que seguir funcionando aunque existan fallos o caídas parciales en alguna de las partes en que se divida el sistema.

**Taxonomía de Soluciones NoSQL**

- Bases de datos de Clave-Valor: Su precursor fue Amazon Dynamo. Basadas en DHT (Distributed Hash Tables).
- Bases de datos de Familia de Columnas: Su precursor fue Google BigTable.
  - Modelo de datos: familia de columnas, esto es, un modelo tabular donde cada fila puede tener una configuración diferente de columnas. Guardan datos por columna en vez de las BBDD tradicionales que lo hacen por filas.
  - Buenas en:
    - Gestión de tamaño
    - Cargas de escrituras masivas orientadas al stream
    - Alta disponibilidad
    - MapReduce
- Bases de datos de Documentos: Su precursor fue Lotus Notes.
  - Modelo de datos: colecciones de documentos (JSON,XML,BSON) que contienen colecciones de claves-valor.
  - Buenas en:
    - Modelado de datos natural
    - Amigables al programador
    - Desarrollo rápido
    - Orientadas a la web: CRUD
- Bases de datos de Grafos: Inspiradas por Euler y la teoría de grafos.
  - Modelo de datos: nodos, relaciones con pares clave valor en ambos
  - Buenas en:
    - Modelar directamente un dominio en forma de grafo, una manera común de representar y entender datasets.
    - Excelente rendimiento cuando los datos están interconectados y no tabulares.
    - Realizar operaciones transaccionales que exploten las entidades.

**¿NoSQL or not NoSQL?**

Los principales problemas de NoSQL son:
- Complejidad
- Instalación
- Consultas (comprender bien MapReduce)
- Los modelos de datos usados
- Su falta de madurez

¿Dónde usarlas?
- Datos sociales
- Procesado de datos (Hadoop)
- Búsqueda (Lucene)
- Caching (memcache)
- Data Warehousing

¿Qué problema quieres resolver?
- Transacciones
- Grándes volúmentes de datos (Exabytes)
- Estructura de los datos


- En NoSQL, generalmente los datos son recuperados de manera mucho más rápida que en un RDBMS, sin embargo las consultas que se peuden hacer son más limitadas y requieren trasladar complejidad a la aplicación.
- RDBMS para escribir usan locks y redos para garantizar ACID, pero NoSQL no soporta a menudo ACID. Si quieres soporte transaccional integral debes seguir usando RDBMS. Aplicaciones que generan informes emplean consultas complejas para las que NoSQL no es muy adecuado.
- Aplicando MapReduce, las bases de datos NoSQL pueden paralelizar operaciones complejas como agregaciones estadísticas, filtros, agrupaciones o ordenación.
- Desde un punto de vista de sistemas deberíamos considerar la combinación de SQL y NoSQL: Linkedin comenzó sólo con un RDBMS, pero desarrolló su propia BD NoSQL (Voldemort). Facebook también tiene una estructura híbrida.

## NewSQL, Tendencias

Las BBDD NoSQL son una clara alternativa a los RDBMS. sobre todo para algunas aplicaciones sociales y web que requieren elevada escalabilidad.

No son idóneas para todo, de hecho en la mayoría de los casos las RDBMS deberían seguir siendo la primera opción: La capacidad de hacer JOIN y las garantías ACID son muy importantes para muchas aplicaciones.

Las RDBMS actuales evolucionan para incorporar capacidades de NoSQL -> NewSQL.

Lo que se va a estilar es persistencia polígota : consiste en descomponer el sistema en subsistemas y para cada subsistema y sus datos elegir la base de datos más adecuada en función de sus características y luego comunicar todas las BD.
