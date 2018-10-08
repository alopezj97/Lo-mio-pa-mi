# TEMA 1 : Introducción a la Ingeniería del Software

## El producto Software

### Naturaleza del software

El **Software tiene naturaleza dual**, se comporta tanto:
- como un **producto** en tanto que proporciona potencial de cómputo y es un trasformador de información.
- como un **vehículo** en tanto que actúa como base para el control de la computadora (SO), actúa como base para la comunicación de información (redes), actúa como base para la creación y control de otros programas (herramientas y ambientes de software).

### Definición de software

El software es:
1. Instrucciones o programas
2. Estructuras de datos y los propios datos
3. Documentación

### Características del software

- No se fabrica en el sentido clásico.
- No se desgasta pero se deteriora.
- La mayor parte del software se construye para uso individualizado.

### Tipos y dominios de aplicación del software

**Tipos de software**

- Software genérico: Producido por una organización y vendido a cualquier cliente.
- Software a medida: Sistema desarrollado por una empresa para un cliente particular.

**Dominios de aplicación**

- Software de sistemas: Programas que proporcionan servicio a otros programas.
- Software de aplicación: Resuelven una necesidad específica.
- Software de ingeniería y ciencias: Implementa algoritmos devoradores de números
- Software empotrado: Se encuentra dentro del producto e implementa y controla características y funciones para el usuario final y para el sistema en sí.
- Software de gestión: Proporciona una serie de funciones para el uso de muchos consumidores diferentes.
- Aplicaciones Web: Aplicaciones diversas que tienen en común software de red.
- Software de Inteligencia Artificial: Implementa algoritms no numéricos para resolver problemas complejos difíciles de tratar computacionalmente o con análisis directo.

### Proceso de producción

Definición -> Construcción -> Evolución

**Problemas**:
- Comunicación entre personas
- Incumplimiento de la planificación
- Incorporar cambios en etapas avanzadas del proceso supone mucho coste.

## El concepto de Ingeniería del Software

### Definición de Ingeniería del Software

Se propuso en 1968 para discutir la crisis del software.

"Aplicación de un enfoque sistemático, disciplinado y cuantificable al desarrollo, operación y mantenimiento del software".

### Terminología usada en Ingeniería del Software

- Sistema: Conjunto de elementos relacionados entre sí y con el medio, que forman una unidad o un todo organizativo.
- Sistema basado en computadora: Conjunto o disposición de elementos organizados para cumplir una meta predefinida al procesar información.
- Sistema software: Conjunto de piezas o elementos software relacionados entre sí y organizados en subsistemas.
- Modelos: Representación de un sistema en un determinado lenguaje.
- Principios: Elementos adquiridos mediante el conocimiento, que definen las características que debe poseer un modelo para ser una representación adecuada de un sistema.
- Herramientas: Instrumentos que permiten la representación de modelos.
- Técnicas: Modo de utilización de las herramientas.
- Heurísticas: Conjunto de reglas empíricas, que al ser aplicadas producen modelos que se adecuan a los principios.
- Métodos: Secuencia de actividades para la obtención de un producto, que describen cómo usar las herramientas y las heurísticas.


## El proceso de desarrollo del software

El proceso de desarrollo o ciclo de vida del software es la estrategia que define la división y ubicación temporal de las etapas que se realizan durante el desarrollo software.

Las etapas se caracterizan por las tareas que se realizan y por el producto que se obtiene.

Los modelos de ciclo de vida del software son representaciones abstractas del proceso de desarrollo del software.

**Etapas principales**:
- Especificación de requisitos: Se analiza el problema y se crea un documento donde se indican las funcionalidades que debe tener el software y las restricciones sobre cómo debe hacerlo.
- Diseño: Se busca una solución del problema a resolver y se describen sus componentes, sus relaciones y funciones.
- Implementación: Se traduce el diseño a un lenguaje de programación, es decir, se genera el código.
- Validación: Se revisa todo lo que se ha obtenido y se prueba el código.
- Mantenimiento y evolución: Se solucionan fallos y se adapta el código a nuevos entornos.
- Planificación: Estimación del tiempo y de los costes de desarrollo.

### Modelos de ciclo de vida del software

- **El modelo en cascada**: Considera las tareas de especificación, desarrollo, validación y evolución y las representa como fases separadas.
  - Una fase no comienza hasta que finaliza la anterior.
  - No es lineal ya que existe retroalimentación de una fase a otra.
  - Cada iteración supone mucho coste y con rediseño significativo.
  - Ventaja: Dado que en cada fase hay como resultado documentación, ésta es muy buena.
  - Problema: La rigidez del modelo a la hora de dividir un proyecto en las etapas.
  - Debe usarse cuando los requisitos sean bien comprendidos y sea poco probable que cambien.


- **Desarrollo incremental**: Intercala actividades de especificación, desarrollo y validación. El sistema se desarrolla como una serie de versiones (incrementos) y cada versión añade funcionalidad a la anterior.
  - Se desarrolla una implementación inicial y se refina por medio de muchas versiones.
  - Resulta más barato y fácil realizar cambios en el software conforme se diseña.
  - Dado que cada incremento incorpora funcionalidades el cliente puede evaluar el desarrollo desde una etapa temprana. Y si un incremento no cumple lo requerido sólo se cambia ese incremento.
  - Ventajas: Los cambios son menos costosos, el cliente puede evaluar el desarrollo y la entrega es más rápida.
  - Desventajas: La documentación que se genera es mala y la estructura del sistema se degrada con cada incremento, por lo que no es recomendable para sistemas grandes con larga duración donde varios equipos llevan a cabo el desarrollo.


- **Ingeniería del software orientada a la reutilización**: Se basa en la existencia de componentes reusables. El proceso de desarrollo se centra en integrar esos componentes en vez de desarrollarlos desde el principio.
  - Se analizan componentes que implementan las funcionalidades que queremos.
  - Se diseña el sistema con los componentes encontrados y se desarrolla el software que no se halla podido adquirir y se integran los componentes para crear el nuevo sistema.
  - Ventajas: Se disminuye la cantidad de software que hay que desarrollar por lo que se disminuye así el tiempo, los costes y los riesgos.
  - Desventajas: Se pierde control sobre la evolución del sistema ya que las componentes que utilizamos no son nuestras y no sabemos como van a evolucionar. Además las componentes cumplen unas funcionalidades concretas, si las necesidades de los usuarios ya no nos sirven.


### Modelos orientados al cambio

Estos modelos tienen dos objetivos:

- Reducir los costes del rehacer, para ello:
  - Se evitan los cambios mediante actividades que anticipan posibles cambios antes de que se requieran.
  - Se diseña de manera que los cambios no supongan mucho coste.

- Enfrentar los cambios

  - Mediante el desarrollo de un **prototipo desechable** se comprueban los requisitos del cliente y la factibilidad de algunas decisiones de diseño.
    - Ventajas: Permite obtener nuedas ideas, descubrir fortalezas y debilidades, así como comprobar la factibilidad y permitir al cliente participar en el desarrollo.
    - Problemas: No se deben entregar prototipos como versión final ni aunque vayamos mal de tiempo.

  - Mediante **incrementos o prototipo evolutivo** se entregan al cliente para que compruebe si es lo que quería.
    - Ventajas: Es sencillo incorporar cambios, los servicios más importantes reciben mayores pruebas, los clientes pueden ver si se cumplen sus requisitos.
    - Problemas: La mayoría de los sistemas tienen una serie de recursos que se usan para diferentes partes del sistema por lo que no siempre es posible dividirlo en incrementos.
    - Este enfoque no es el mejor cuando los sistemas son grandes (mucha gente en diferentes ubicaciones), son embebidos o dependen del hardware o sistemas en los que la seguridad y protección del sistema sea estricta.

  - A raíz de los anteriores surgió el **proceso unificado**, que es un modelo híbrido entre el prototipo desechable y la entrega incremental.
    - Identifica cuatro fases en el proceso de desarrollo del software:
      - Concepción: Ver si el sistema solucionaría el problema de la empresa y ver las entidades externas que actuarán con el sistema.
      - Elaboración: Comprensión del problema, establecer un marco del sistema y diseñar un plan.
      - Construcción: Programación y prueba del sistema.
      - Transición: Poner al sistema en un ambiente real.

  - Por último tenemos los **métodos ágiles** que son un conjunto de métodos que enfatizan el enfoque iterativo (tanto en cada fase como en conjunto), la adaptabilidad del proceso y la colaboración, reduciendo al mínimo la documentación y los procedimientos.
    - Son útiles para equipos pequeños y se necesita que el proceso de desarrollo se adapte rápidamente.



# TEMA 2.1: Ingeniería de requisitos

## Introducción al modelado de requisitos

### Ingeniería de requisitos ¿Qué es?

Todas las actividades que resuelven la pregunta ¿Qué va a hacer el software?, es decir:
- identificar y documentar las necesidades del cliente
- analizar la viabilidad de esas necesidades
- negociar una solución razonable
- crear un documento que describa un software que satisfaga las necesidades
- analizar y validar el documento
- controlar la evolución de las necesidades

Para ello, debemos de tener en cuenta los siguientes factores:
- complejidad del problema
- la forma de identificar los requisitos por parte del cliente
- dificultades de comunicación entre desarrolladores y usuarios
- dificultades de comunicación entre desarrolladores
- requisitos que no se pueden obtener fácilmente
- naturaleza cambiante de los requisitos

El modelado de requisitos es la parte del desarrollo más importante ya que si se hace de manera incorrecta va a suponer mucho trabajo luego.

### Concepto de requisito

Dos definiciones:

- Capacidad que debe de tener un sistema para satisfacer una especificación o documento formal.
- Propiedad que un software debe tener para resolver un problema concreto.

### Actividades de la Ingeniería de Requisitos

- **Estudio de viabilidad**: ¿Es conveniente realizar el desarrollo del software? ¿Soluciona el software los problemas? ¿Se puede desarrollar? ¿Se puede desarrollar con las restricciones de costo y tiempo?

- **Obtención de requisitos**: Debemos obtener el propósito y las funcionalidades del sistema.
  - El objetivo es delimitar las fronteras del sistema y elaborar un glosario de términos.
  - Para llevarlo a cabo se usan entrevistas, casos de uso, análisis etnográfico...
  - Al finalizar esta etapa se generan: documento de entrevista, lista estructurada de requisitos, diagrama de casos de uso, plantillas y diagramas de actividad.

- **Análisis de requisitos**: Se estudian las necesidades del usuario para obtener una definición detallada de los requisitos.
  - El objetivo es: detectar conflictos entre requisitos, clasificación de requisitos, negociación, modelado conceptual, establecer las bases para el diseño.

- **Especificación de requisitos**: Proceso de documentar el comportamiento requerido del sistema software.
  - El objetivo es detallar los requisitos, crear un modelo formal, crear los casos de uso y crear prototipos.
  - Al finalizar esta etapa se generan los diagramas de paquetes, los diagramas de clases y los diagramas de secuencia y contratos.

- **Validación de requisitos**: Se examinan los requisitos para asegurarse de que definen el sistema que el cliente y los usuarios desean.
  - Para facilitar el proceso se puede crear prototipos, crear simulaciones, usar otras herramientas...
  - Recordemos que validación (las necesidades del documento son realmente las necesidades requeridas) != verificación (comprobar el correcto funcionamiento de un requisito en el sistema desarrollado)


### Actores

Los actores son cada uno de los diferentes roles que pueden desempeñar la misma o distintas personas.

- Usuarios: Operan con el software
- Clientes: Tienen interés en adquirir un software
- Analistas de mercado: Recaban necesidades del mercado
- Reguladores: Encargado de hacer cumplir normativas
- Ingenieros del software: Encargados de plantear y desarrollar soluciones que satisfagan a todos los involucrados en un proyecto software.

### Propiedades de los requisitos

- Completos: Todos los aspectos del sistema están representados en el modelo de requisitos
- Consistentes: Los requisitos no se contradicen entre sí.
- No ambiguos.
- Correctos: Representan exactamente lo que el cliente quiere y el desarrollador construirá
- Realistas: Adaptados a la tecnología y presupuesto disponible.
- Verificables: Se pueden diseñar pruebas que verifiquen que el sistema satisface los requisitos.
- Trazables: Debe ser posible hacer un seguimiento de cada requisito que permita conocer su estado en cada momento.
- Identificables: Cada requisito debe tener un identificador único que lo distinga.
- Cuantificables: Es deseable que se pueda medir el grado de cumplimiento de un requisito en términos precisos.

### Tipos de requisitos

- Funcionales: Especifican las funciones que un sistema, o componente de un sistema, debe ser capaz de llevar a cabo.
- No Funcionales: Especifican aspectos técnicos que debe incluir un sistema. Se clasifican en:
  - Restricciones: limitaciones de los desarrolladores
  - Calidades: características de un sistema que importan a los clientes o usuarios del mismo.
- De información: Describen necesidades de almacenamiento de información en el sistema.

Si nos centramos en los requisitos no funcionales, podemos clasificarlos en 3 tipos:
- Requisitos del producto: Detallan limitacioines o comportamientos exigidos al producto (cantidad de memoria, velocidad de respuesta)
- Requisitos de la organización: Relacionadas con normativas de funcionamiento (estándares de desarrollo, documentación a entregar, plazos de entrega...)
- Requisitos externos: Aspectos externos al sistema (requisitos legales...)


# TEMA 2.2: Obtención de requisitos

Mediante la obtención de requisitos debemos determinar cuáles son los requisitos del sistema a desarrollar para llegar a un conocimiento suficiente del problema a resolver.

La obtención de requisitos debe:
- Determinar fuentes de información en:
  - Objetivos generales o de alto nivel del software: Constituyen el motivo fundamental por el que el desarrollo se lleva a cabo.
  - Dominio del problema: Del cual, el ingeniero puede tener un conocimiento limitado, pero otros actores pueden poseer información valiosa.
  - Actores del proceso: Puntos de vista diferentes tanto de la organización como del software a desarrollar.
  - Entorno de operación: Permitirá establecer las restricciones del proyecto y los costes que comportarán.
  - Entorno de organización: Al que debe adaptarse el software.
- Establecer técnicas de obtención de requisitos
  - Entrevistas
  - Escenarios: Herramienta para contextualizar los requisitos (casos de uso de UML)
  - Prototipos: Pueden servir para clarificar requisitos
  - Reuniones de grupo
  - Observación o técnicas etnográficas: Permite aprender cómo se llevan a cabo las tareas de usuario.
  - Otras: Estudio de documentos y formularios actualmente en uso, visitas a otras instalaciones similares...

## Proceso de obtención de requisitos

1. Obtener información sobre el dominio del problema y el sistema actual.
  - A partir de este paso se obtiene una introducción al sistema y glosario de términos.
2. Preparar las reuniones (identificar implicados, conocer las necesidades y resolver conflictos)
  - A partir de este paso se obtiene documentación.
3. Identificar y revisar los objetivos del sistema.
  - De cada objetivo se puede describir su importancia, urgencia, estado y estabilidad.
4. Identificar y revisar los requisitos de informacion
  - De cada requisito se puede describir:
    - objetivos y requisitos asociados
    - descripción del requisito
    - contenido
    - Tiempo de vida o requisitos temporales
    - Ocurrencias simultáneas
    - Importancia, urgencia, estado y estabilidad
5. Identificar y revisar los requisitos funcionales
  - De cada requisito se puede describir:
    - objetivos y requisitos asociados
    - Secuencia de acciones
    - Frecuencia
    - Rendimiento
    - Importancia, urgencia, estado y estabilidad.

6. Identificar y revisar los requisitos no funcionales
  - De cada requisito se puede describir:
    - Objetivos y requisitos asociados
    - Importancia, urgencia, estado y estabilidad.
  - Cómo captarlos? Respondiendo a preguntas sobre:
    - Facilidad de uso
    - Fiabilidad
    - Rendimiento
    - Soporte
    - Implementación
    - Interfaz
    - Operación
    - Empaquetado
    - Legales

De este proceso surge una lista estructurada de requisitos.

## Técnicas de entrevistas

- Fases de una entrevista
  - Planificación: Clarificar cuáles son los datos que se desean obtener, determinando qué personas se deben entrevistar, cuándo y en qué lugar.
  - Preparación: Los entrevistadores preparan preguntas, se informan sobre el entrevistado y se fija fecha y lugar para la entrevista.
  - Inicio: Exposición general de cómo va a ser desarrollada la entrevista y se solicita colaboración y autorización para tomar notas.
  - Desarrollo: Realización de las preguntas.
  - Cierre: Se resume la información anotada y se comprueba que contamos con toda la información solicitada.
  - Conclusiones: Se elabora un resumen formal de la entrevista.

## Técnicas etnográficas

Son técnicas de observación que se usan para entender los procesos operacionales y ayudar a derivar requisitos sociales y de organización.

Son efectivas para dos tipos de requisitos:
- Requisitos que se derivan de la forma en la que realmente trabaja la gente
- Requisitos derivados de la cooperación y el conocimiento de las actividades de otras personas.


# TEMA 2.3: Modelados de casos de uso

## Introducción

El modelado de casos de uso es una técnica de ingeniería de requisitos que permite:
- delimitar el sistema a estudiar
- determinar el contexto de uso del sistema
- describir el punto de vista de los usuarios del sistema

Se usa durante las distintas fases del desarrollo para:
- obtener y analizar requisitos
- especificar requisitos
- usarlo como base en el proceso de diseño y su validación
- guiar el diseño de la interfaz de usuario y facilitar la construcción de prototipos
- probar el software y asegurar la calidad durante el proceso de desarrollo

Los elementos que componen el modelo de casos de uso son:
- actores
- casos de uso
- relaciones entre
  - actores
  - actores y casos de uso
  - casos de uso

Para la representación y descripción de estos elementos se usan:
- diagramas de casos de uso de UML
- plantillas estructuradas para los actores y casos de uso

## Diagrama de casos de uso

Son diagramas de UML que representa gráficamente a todos los elementos que forman parte del modelo de casos de uso junto con la frontera del sistema.

## Actores

Son una abstracción de entidades externas al sistema que interactúan directamente con él.

Los actores tienen un rol a la hora de interactuar con el sistema. Por eso la misma persona puede desempeñar varios roles simultáneamente o un rol puede ser desempeñado por varias personas.

**Tipos de actores**:
- Principales: Además de interactuar con el caso de uso son los que lo activan.
- Secundarios: Interactúan con el caso de uso pero no lo activan.

Los actores pueden ser:
- Personas
- Dispositivos de E/S
- Sistemas informáticos externos
- Temporizador o reloj

**Relación entre actores**:
- Generalización (herencia): Expresa un comportamiento común entre actores, es decir, se relaciona de la misma forma con los mismos casos de uso.

## Casos de uso

Los casos de uso especifican la secuencia de acciones, incluidas secuencias variantes y de error, que un sistema o subsistema puede realizar al interactuar con actores externos.

**Tipos de casos de uso**: en función de su importancia pueden ser:
- Primarios : procedimientos comunes más importantes
- Secundarios : Procesos de error o poco comunes
- Opcionales : Puede que no se implementen

**Características**:
- Son iniciados por un actor que, junto con otros actores, intercambian datos o control con el sistema a través de él.
- Son descritos desde el punto de vista de los actores que interactúan con él.
- Tienen que tener una utilidad concreta para algún actor.
- Acotan una funcionalidad del sistema.
- Describen un fragmento de la funcionalidad del sistema de principio a fin, y tienen que acabar y proporcionar un resultado.
- Se documentan con texto informal.

## Descripción de actores

Los actores se describen o documentan con una plantilla.

## Descripción de casos de uso

Contenido de una descripción de caso de uso:
- El inicio: cuándo y qué actor lo produce
- El fin: cuándo se produce y qué se obtiene
- La interacción: que mensajes intercambian los actores y el sistema.
- El objetivo: para qué se usa o qué intenta el caso de uso
- Cronología y origen de las interacciones.
- Repeticiones de comportamiento: qué acciones se repiten
- Situaciones opcionales o de error: qué situaciones alternativas se presentan en el caso de uso

**Tipos de descripciones:**
- Dependiendo del procesamiento
  - Básico (poco detalle)
  - Extendido (mucho detalle)
- Dependiendo de su nivel de abstracción
  - Esencial (muy abstracto)
  - Real (muy concreto)

La descripción de un caso de uso se realizan por medio de una plantilla.

**Escenarios**: Secuencia específica y concreta de acciones e interacciones entre los actores y el sistema objeto de estudio.

**Tipos de escenarios**:
- Básico: Funcionalidad básica y normal del caso de uso
- Secundario: Funcionalidades alternativas y situaciones de error

## Relaciones en el modelo de casos de uso

**Tipos de relaciones**:
- Asociación : Comunicación entre un actor y un caso de uso en el que participa.
- Inclusión: Inserción de comportamiento adicional dentro del caso de uso base que explícitamente hace referencia al caso de uso de inclusión.
  - Permite incluir el comportamiento de un caso de uso en el flujo de otro caso de uso.
  - Al caso de uso que incluye se le denomina caso de uso base y al incluido caso de uso de inclusión.
  - El caso de uso base se ejecuta hasta que se alcanza el punto en el que se encuentra la referencia al caso de uso de inclusión, momento en el que se pasa la ejecución a dicho caso. Cuando este se termina, el control regresa al caso de uso base.
  - El caso de uso de inclusión es utilizado por el caso de uso base.
  - El caso de uso base no está completo sin todos sus casos de uso de inclusión.
  - El caso de uso de inclusión puede ser compartido por varios casos de uso base.
  - El caso de uso de inclusión no es opcional y es necesario para que tenga sentido el caso de uso base.

- Extensión: Inserción de fragmentos de comportamiento adicional sin que el caso de uso base sepa de los casos de uso de extensión.
  - Esta relación especifica que el comportamiento del caso de uso base puede ser extendido por otro caso de uso bajo determinadas condiciones.
  - El caso de uso base declara uno o más puntos de extensión donde se enganchan nuevos comportamientos.
  - El caso de uso base no sabe nada de los casos de uso de extensión y está completo sin sus extensiones; de hecho, los puntos de extensión no tienen numeración en el flujo de eventos del caso de uso base.
  - El caso de uso de extensión no tiene sentido de forma separada de un caso de uso base.

- Generalización: Relación entre un caso de uso general y otro más específico, que hereda y añade características al caso de uso general.
  - Heredan todo del caso de uso general.
  - Pueden anular características del caso de uso general, salvo relaciones, puntos de extensión y precondiciones.

Debemos usar relaciones cuando simplifiquen el modelo.
El uso de muchos <<include>> hace que se tenga que ver más de un caso de uso para tener una idea completa.
Las relaciones <<extend>> son complejas y difíciles de entender por los usuarios/clientes.
La generalización debe evitarse a menos que tengamos casos de uso padres abstractos.

## Proceso de construcción de casos de uso

1. Identificación de los actores
2. Identificación de los principales casos de uso de cada actor
  - ¿Cuáles son las tareas principales que realiza cada actor?
  - ¿Qué información del sistema debe adquirir, producir o cambiar?
3. Identificación de nuevos casos de uso a partir de los existentes. Hay cuatro situaciones posibles:
  - Variaciones significativas de los casos de uso (en función de qué actor lo realiza o sobre qué objeto se aplica)
  - Casos de uso opuestos (necesitamos uno que haga exactamente lo contrario que un caso de uso existente)
  - Caso de uso que precede a uno existente (¿Qué tiene que ocurrir para poder hacer esta acción?)
  - Caso de uso que sucede a uno existente (¿Qué ocurre después de este caso de uso?).
4. Creación del diagrama de casos de uso
5. Creación de las plantillas de los casos de uso básicos.
6. Definición de prioridades y selección de casos de uso primarios
7. Escribir los casos de uso extendidos y crear prototipos de la interfaz de usuario.

**Estructuración del diagrama de casos de uso**

Diagrama de paquetes: Diagrama de UML usado para describir la estructuración de un sistema en base a agrupaciones lógicas. También muestra las dependencias entre agrupaciones.

Se usan para agrupar de forma lógica los casos de uso en diferentes diagramas de casos de uso.

Diagramas de actividad: Diagrama de UML para la descripción del comportamiento que tiene un conjunto de tareas o procesos.

Se usan para representar los procesos de negocio de una empresa, o para representar los flujos de un caso de uso de forma gráfica.


# TEMA 2.4: Análisis y especificación de requisitos

## Introducción

Fase de la ingeniería de requisitos en la que se examinan los requisitos para delimitarlos y definir exactamente cada uno de ellos.

Se trata fundamentalmente de:
- Detectar y resolver conflictos entre requisitos
- Delimitar el software y establecer con qué elementos externos interacciona.
- Elaborar los requisitos del sistema para obtener, a partir de ellos, los requisitos del software a desarrollar.

El objetivo principal del análisis de los requisitos es refinar, estructurar y describir los requisitos para una comprensión más precisa y fácil de mantener que ayude a estructurar el sistema completo.

Actividades durante el análisis:
- Clasificación de los requisitos: Establecer un conjunto de categorías y situar cada requisito en ellas.
- Priorización de los requisitos: Determinar la importancia relativa de cada requisito en relación con los demás.
- Modelado conceptual: Representar los requisitos con un lenguaje o notación que comprendan quienes van a tratar con ellos.
- Situación de los requisitos en la arquitectura del sistema: Establecer qué elementos del sistema software van a satisfacer los distintos requisitos. Permite descubrir nuevos requisitos.
- Negociación de los requisitos: Detectar y resolver problemas, definir de manera precisa los límites del sistema y cómo éste debe interaccionar con su entorno.

Especificación de requisitos: Completa descripción de los requisitos del sistema a desarrollar.

Una especificación debe ser:
- Completa
- Verificable
- Consistente
- Modificable
- Susceptible de permitir seguimientos
- Utilizable durante las fases de operación y mantenimiento
- No debe contener ambigüedades


## Análisis y especificación orientada a objetos

El análisis orientado a objetos examina y representa los requisitos desde la perspectiva de los objetos que se encuentran en el dominio del problema.

Los métodos de análisis orientado a objetos se centran en obtener dos tipos de modelos:
- Estáticos o de estructura
- Dinámicos o de comportamiento

¿Por qué usar análisis orientado a objetos? -> Difumina la barrera entre el "qué"" y el "cómo"
- Los términos usados en los modelos están cercanos a los del mundo real.
- Se modelan tanto elementos y propiedades estáticas como dinámicas del ámbito del problema.
- Se manejan conceptos comunes durante el análisis, diseño e implementación del software.


## Obtención del modelo estático: Diagramas de conceptos

Proceso general:
- Identificar los principales conceptos y sus relaciones y documentarlos.
- Partir del modelo de casos de usos, de la lista de requisitos y del glosario de términos.
- Representarlos con un diagrama de clases de UML en el que podrá haber
  - Conceptos o clases conceptuales
  - Asociaciones entre conceptos
  - Generalizaciones de conceptos
  - Atributos de los conceptos

Pasos a seguir:
1. Identificar e incorporar conceptos
  1.1. Identificar los conceptos (encontrar términos que se corresponden con sustantivos o frases nominales y establecer una lista de categorías de conceptos y rellenarla)
  1.2. Seleccionar los conceptos relevantes del problema
  1.3. Representarlos, como clases, en el diagrama de conceptos.
2. Identificar e incorporar asociaciones (relaciones entre conceptos)
  2.1. Identificar las posibles asociaciones
  2.2. Representarlas en el diagrama y seleccionar las que sean válidas.
  2.3. Asignarles nombre
  2.4. Identificar la multiplicidad
3. Identificar e incorporar generalizaciones
  3.1. Identificar posibles generalizaciones
  3.2. Validar las estructuras encontradas
  3.3. Representarlas en el modelo conceptual
4. Identificar e incorporar atributos
  4.1. Identificar atributos
  4.2. Representarlos en el diagrama
5. Estructurar el modelo (diagramas de paquetes)


## Obtención del modelo de comportamiento : Diagramas de secuencia del sistema y Contratos

**Diagrama de secuencia del sistema**: Diagrama de secuencia de UML en el que se muestran cómo los eventos generados por los actores provocan la ejecución de una operación por el sistema, siendo visto éste como una caja negra.

Pasos a seguir, para todos los casos de uso:
1. Identificar los actores que inician las operaciones
2. Asignar un nombre a todo el sistema
3. Identificar y nombrar las operaciones principales del sistema a partir de las descripciones de los casos de uso
4. Determinar los parámetros de las operaciones
5. Incluir las operaciones en la clase que identifica a todo el sistema
6. Hacer una descripción informal de la funcionalidad de cada operación.


**Contratos**: Documento que describe lo que una operación se propone lograr, sin decir cómo lo conseguirá. Define la especificación de una operación sin entrar en su implementación. Suele redactarse con un estilo declarativo.

Contenido del contrato:
- Nombre: Nombre de la operación y sus parámetros (viene del diagrama de secuencia del sistema)
- Responsabilidad: Descripción informal de las responsabilidades que debe cumplir la operación.
- Tipo: Concepto, clase o interfaz responsable de la operación (nombre de la clase del sistema)
- Notas: Notas de diseño, algoritmo...
- Excepciones: Casos excepcionales
- Salida: Mensajes o datos que proporciona
- Precondiciones: Suposición acerca del estado del sistema o de los objetos del modelo conceptual antes de ejecutar la operación.
- Poscondiciones: Estado del sistema o de los objetos del modelo conceptual después de la ejecución de la operación. (Expresadas en pasado)

| Nombre | incluirNotaExpediente (idAsignatura, idAlumno, nota) |
| Responsabilidad | Incluye una asignatura con su nota en el expediente de un alumno |
| Tipo | SAP |
| Notas | |
| Excepciones | Si el alumno identificado por idAlumno no existe ó si la asignatura identificada por idAsignatura no existe |
| Salida | |
| Precondiciones | |
| Poscondiciones | Fue creado un objeto, calif, de la clase Calificación debidamente inicializado, fue creado un enlace entre calif y el objeto de la clase Expediente identificado por idAlumno, fue creado un enlace entre calif y el objeto de la clase Asignatura identificado por idAsignatura |
