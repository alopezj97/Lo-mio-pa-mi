# Tema 2. Desarrollo de Sistemas de Información

## El proceso de desarrollo de software

Etapas:
- Planificación
  - Ámbito del proyecto
  - Estudio de viabilidad
  - Análisis de riesgos
  - Estimación
  - Planificación temporal
  - Asignación de recursos
- Análisis
  - Elicitación de requerimientos (requisitos) (se incluyen prototipos)
    - Requerimientos (requisitos) funcionales
    - Requerimientos (requisitos) no funcionales
  - Modelado (diagramas)
    - Modelado de datos (diagramas E-R)
    - Modelado de procesos (diagramas de flujo de datos)
- Diseño: Estudio de alternativas y diseño arquitectónico
  - Diseño de la base de datos
  - Diseño de las aplicaciones
- Implementación
  - Adquisición de componentes (y elección de los mismos)
  - Creación e integración de los recursos necesarios para que el sistema funcione.
- Pruebas
  - Pruebas de unidad (caja negra, caja blanca, cada componente de forma independiente y con casos límite)
  - Pruebas de integración (comprobamos que la interfaz de los distintos componentes funcionan bien, es decir, cuando unimos componentes)
  - Pruebas alfa (cuando el sistema está acabado, el sistema es usado por el equipo de desarrollo como si fueran clientes)
  - Pruebas beta (pruebas realizadas por cualquier usuario)
  - Test de aceptación (se pasa el sistema al cliente para que le dé el visto bueno definitivo)
- Instalación o despliegue
- Uso y mantenimiento (los últimos tipos de mantenimiento consumen el 60% del tiempo)
  - Mantenimiento adaptativo (adaptarse a nuevos entornos ya sean hardware, software, SO, SW de terceros, etc.)
  - Mantenimiento correctivo (corregir errores)
  - Mantenimiento perfectivo (mejorar lo que hay)
  - Mantenimiento evolutivo (añadir o quitar funcionalidades)


## Modelos de ciclo de vida

### Modelo en cascada (o clásico)

El modelo en cascada (también conocido como "ciclo de vida clásico") no es el único, ni tampoco el mejor en muchas situaciones.

Características:
- Hacer las cosas bien y para siempre, es decir, no se avanza a la siguiente etapa si está todo completo y bien.
- Sólo se vuelve a la etapa anterior en un instante dado y no a 2 anteriores.
- No suele ser buen modelo ya que casi nunca se conocen todos los requisitos desde el principio.

### Desarrollo de prototipos

- Ventaja: Permite al cliente aclarar requisitos, además de que el cliente pueda ver una primera versión.
- Desventaja: el prototipo no es el sistema, es una parte. No se debe olvidar que hay que llevar a cabo la transición de prototipo a sistema final con lo que ello supone en tiempo y mejoras.

### Modelo en espiral o iterativo

Consisten en, a partir de un prototipo, ir iterando añadiéndole nuevas funcionalidades hasta alcanzar el sistema final.
- Ventaja: Ayuda a aclarar los requisitos y el cliente puede ver el avance.

El modelo en espiral es parte de los iterativos pero se caracteriza por la prevención de riesgos. En cada iteración se evalúan las alternativas y se identifican los riesgos. Finalmente se escoge la alternativa de menor riesgo.


## Desarrollo de un SI basado en Bases de Datos

### Análisis (de requerimientos)

Se debe recabar la información sobre el uso que se piensa dar al sistema de información.

Tareas: Elicitación de los requisitos del sistema (obtención de requisitos de datos, requisitos funcionales y restricciones semánticas):
- Identificación de las principales áreas de la aplicación y de los distintos grupos de usuarios.
- Estudio y análisis de la documentación existente relativa a las aplicaciones.
- Estudio del entorno de operación actual.
- Estudio del uso de la información (transacciones, frecuencias y flujos de datos).

Resultado: Documento de especificación de requisitos:
- Descripción del sistema en lenguaje natural
- Lista de requerimientos (organizados de forma jerárquica).

### Diseño

**Diseño conceptual**: producir un esquema conceptual (diagramas E-R) de la base de datos, independientemente del SGBD.

Objetivos:
- Comprensión de la estructura, semántica, relaciones y restricciones de la BD.
- Descripción estable del contenido de la base de datos.
- Comunicación entre usuarios, analistas y diseñadores.

Características deseables del modelo conceptual:
- Expresividad (diferentes tipos de datos, relaciones y restricciones)
- Sencillez (lo bastante simple para que los usuarios lo comprendan)
- Minimalidad (número pequeño de conceptos básicos)
- Representación gráfica (notación gráfica fácil de interpretar)
- Formalidad (especificación formal y sin ambigüedad de los datos)

Enfoques para el diseño del esquema conceptual:
- Enfoque centralizado : Los requisitos de distintas aplicaciones y grupos de usuarios se combinan en un único conjunto de requisitos antes de comenzar el diseño del esquema.
- Enfoque de integración de vistas : Se diseña un esquema (o vista) para cada tipo de usuarios o aplicaciones basado únicamente en sus requisitos. Durante la etapa de integración de vistas, dichos esquemas se combinan o integran para formar un esquema conceptual global (del cual cada vista individual puede considerarse un esquema externo).

Tareas:
  - Modelado de los datos del sistema.
Resultado:
  - Diagrama E/R, diagrama CASE*Method, o diagrama de clases UML.

**Diseño lógico**: Consiste en crear un esquema conceptual y los esquemas externos en el modelo de datos del SGBD elegido (se deben pasar los diagramas E-R al modelo relacional que es el que usa oracle).

Tareas: Transformar los esquemas obtenidos en el diseño conceptual en un conjunto de estructuras propias del modelo abstracto de datos elegido.

**Diseño físico**: (crear la base de datos como tal. Algunos SGBD son sql, oracle, postgresql).

Tareas:
- Estimar adecuadamente los diferentes parámetros físicos de nuestra base de datos, mediante técnicas analíticas (modelos matemáticos de rendimiento) y/o técnicas experimentales (prototipos, simulación o pruebas de carga).
- Preparar las sentencias DDL correspondientes a las estructuras identificadas durante la etapa de diseño lógico de la base de datos (CREATE TABLE ...).

Resultado: Conjunto de sentencias DDL escritas en el lenguaje del SGBD elegido (incluyendo la creación de índices, selección de parámetros físicos, etc.).

**Resumen**:
- Diseño conceptual: Descripción del esquema de la base de datos utilizando un modelo de datos conceptual.
- Diseño lógico: Descripción de la base de datos con un modelo de datos implementable (p.ej: el modelo relacional).
- Diseño físico: Descripción de la base de datos a nivel interno.

**Diseño funcional**: Es el diseño de los procesos. Se divide en dos partes:
- Modelado de Flujo de Datos: Diagramas de Flujo de Datos (DFD) en donde se ve como fluyen los datos, quién hace/recibe qué dato.
- Modelado de Flujo de Control: Se representan cada proceso del Modelado de Flujo de Datos de forma algorítmica.

### Implementación

Se elige el SGBD (oracle, SQL, PostgreSQL, MySQL...) y se crean aplicaciones o interfaces gráficas para implementar las funcionalidades o requisitos funcionales. Por ejemplo, el crear disparadores para ciertas condiciones que nosotros queramos.

## Arquitectura para sistemas de información

### Arquitectura centralizada

Apareció primero, es la más simple. Tenemos por un lado una supercomputadora donde estaba todo, la BD, las interfaces de usuario, funcionalidades y lógica de la aplicación. Por otro lado tenemos los ordenadores "tontos" (dumb) sin ninguna funcionalidad.

### Arquitectura cliente-servidor

Se tiene una mejora sustancial aunque tenemos problemas de portabilidad o mantenimiento. Si se cambia la lógica se tienen que cambiar todos los clientes.

### Arquitectura por niveles (o webservices)

- Capa de datos o BD.
- Capa de aplicaciones o lógica y funcionalidad.
- Capa de presentación donde se almacenan las interfaces de usuario.

Tecnología que utiliza un conjunto de protocolos y estándares que sirven para intercambiar datos entre aplicaciones mediante la adopción de estándares abiertos basados en web.

Hay aplicaciones que están creados para distintos lenguajes o SO. Meediante este sistema se pueden comunicar entre ellos.
