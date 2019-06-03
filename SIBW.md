# DUDAS

- Tema 2, Alojamiento web, ventajas e inconvenientes de las distintas posibilidades
- Tema 2, diferencia entre programas ejecutables en el servidor y usar lenguajes de scripting
- Tema 2, tenemos que saber cómo se hace el tema de evitar que nuestro servidor muestre ciertos archivos o la gestión de URLs limpias?
- Tema 4, XML tenemos que sabernos la Sintaxis?
- Tema 4, Lenguajes para la web semántica, tenemos que sabernoslos?
- Tema 5, decretos y leyes nada no?
- Tema 5, niveles de seguridad
- Respecto de Javascript, el codigo puede ir inyectado en cualquier lugar, o bien referenciado tras el body no? Pero el código jQuery/AJAX tiene que ir inyectado si o si no?

# Sistemas de Información Basados en Web

## Tema 1 : Introducción a los sistemas de información basados en web

### Objetivos

- Conocer la historia y evolución de Internet y los Sistemas Web
- Identificar las particularidades del software desarrollado como Sistema Web
- Comprender la importancia de los SIBW

### Internet

Internet es un conjunto descentralizado de redes de comunicación interconectadas que utilizan la familia de protocolos TCP/IP, lo cual garantiza que las redes físicas heterogéneas que la componen formen una red lógiica única de alcance mundial.

El modelo de red de Internet está basado en el uso de 4 capas:
- Capa de aplicación -> DNS y http
- Capa de transporte
- Capa de internet -> IP
- Capa de acceso a red -> más cercana al hardware

### Protocolo IP

El protocolo IP asigna una dirección unívoca (dirección IP) a cada elemento conectado a la red. Las direcciones IP sirven para identificar de manera única una conexión.

Hay dos versiones de este protocolo:
- IPv4
  - Direcciones de 32 bits (xxx.xxx.xxx.xxx -> 2^32 direcciones)
  - Fijas o dinámicas (Las IPs fijas se dan a aquellos servicios que se tienen que mantener fijos o operativos mientras que las IPs dinámicas son para los clientes que sólo consumen. Las direcciones IPs dinámicas nos la asigna nuestro operador cuando nos conectamos).
  - Se están quedando cortas (por eso surgieron las IPs dinámicas o IPv6)
  - Hay algunas direcciones reservadas a subredes privadas.
- IPv6
  - Direcciones de 128 bits
  - Compatible hacia atrás
  - Se suelen expresar las direcciones en hexadecimal separado por :

### Servicio de DNS

El servicio de DNS nos permite identificar nombres inteligibles con direcciones IP.

Características:
- Dominios estructurados en árbol (varios niveles, mínimo 2)
- Primer nivel: .com (comercial), .es (España), .org (organización), .net (red), .edu (instituciones educativas con el visto bueno de EEUU)
- Primer nivel de 2 letras: paises y regiones (es, en, etc.)
- Primer nivel de 3 o más letras: otros usos
- Siguientes niveles: divisiones u subdominios. .ugr.es el de la izquierda suele corresponder a una máquina concreta

### Protocolo HTTP

El protocolo HTTP (HyperText Transfer Protocol) define un formato estándar de intercambio de recursos en la web.

Características:
- Implementa un esquema cliente / servidor
- No es seguro ya que el contenido de las comunicaciones se manda y recibe en texto plano.
- No está orientado a contexto: cada petición es completamente independiente.
- HTTP es de tipo pull: solo se inicia la interacción desde el cliente.

Funcionamiento:
1. El cliente quiere un recurso: introduce URL en navegador.
2. Navegador crea una petición http y la envía al servidor web y puerto correspondientes.
3. El servidor analiza la petición y obtiene el recurso solicitado.
4. El servidor web construye una respuesta http con el recurso.
5. El servidor web envía la respuesta al cliente.
6. El cliente recibe y procesa la respuesta.

Mensajes HTTP:
- Tipos
  - Peticiones: Usan un verbo y especifican el recurso.
  - Respuestas: Incluye un código + el recurso solicitado.
- Verbos HTTP:
  - GET : Para obtener un recurso.
  - POST : Envía información (puede provocar cambios en el servidor)
  - PUT : Para añadir recursos
  - DELETE : Para añadir recursos
  - HEAD : Igual que GET pero obtiene sólo la cabecera.
- Algunas particularidades:
  - GET
    - Se almacenan en historial y caché
    - Se pueden marcar como favoritos
    - Toda la información de la petición se ve en la URL
    - Tiene restricción de longitud
  - POST
    - No se almacenan en historial y caché
    - No se pueden marcar como favoritos
    - No tiene restricción de longitud
  - Ambos son igual de seguros o inseguros.

### URL

El localizador Uniforme de Recuros (URL) es una secuencia de caracteres que permite nombrar recursos en Internet de forma unívoca.

Sintaxis : scheme://[user[:pass]@]host[:port][/directory[/.../]]/file

De manera simplificada: protocolo://maquina/recurso

Hay que tener en cuenta que la URL es sensible a mayúsculas y minúsculas y que siempre hay un recurso por defecto.

### Servidores Web

Un servidor web o servidor HTTP es un programa informático que procesa una aplicación del lado del servidor, realizando conexiones bidireccionales o unidireccionales y síncronas o asíncronas con el cliente y generando o cediendo una respuesta en cualquier lenguaje o aplicación del lado del cliente.

Ejemplos:
- Apache
- Microsoft Internet Information Services
- Nginx
- node.js
- ...

## Tema 2 : Tecnologías de desarrollo web

### Objetivos

- Identificar los recursos necesarios para la puesta en marcha de un proyecto web.
- Conocer tecnologías de desarrollo de SIW
- Conocer la importancia de seguir normas de estilos y estándares.
- Ser capaz de decidir y justificar las tecnologías que se usarán.

### Elección del Dominio

A la hora de escoger el dominio de nuestra web debemos considerar los siguientes aspectos:
- Facilidad de escritura y lectura
- ¿Caracteres ajenos al inglés?
- Evitar caracteres no alfabéticos
- Evitar palabras que puedan ser confundidas fácilmente.
- Usar un Top Level Domain de acuerdo con la aplicación (.com si es con fines financieros, .edu si es educativo, etc.)

Datos necesarios para el registro de dominio:
- Propietario (registrant)
- Contacto administrativo (administrative contact)
- Contacto de pago (billing contact)
- Contacto técnico (technical contact) -> Mantiene el DNS

Al registrar el dominio es importante asegurarnos que aparecemos como propietarios del dominio. ¡Cuidado con los dominios regalados!

### Alojamiento Web

Cosas que necesitaremos:
- Espacio de alojamiento
- Bases de datos
- E-mail
- Ancho de banda

Posibilidades:
- Contratar alojamiento compartido
- Contratar un servidor dedicado (virtual o no)
- Usar un servidor propio y alojarlo en un centro de datos (housing)
- Usar un servidor propio y alojar en nuestras infraestructuras.
- Usar un servidor gratuito.

### Tecnologías Web del lado del Cliente

- HTML: HyperText Markup Language: Estructura y contenido que vamos a mostrar.
- CSS: Cascade Style Sheets: Estética y formato (independiente del contenido)
- Javascript: Código dinámico del lado del cliente.
  - Permite ejecutar código en el cliente (navegador)
  - Funciones:
    - Insertar o modificar contenido y estilos en la página web.
    - Recoger información del navegador y equipo cliente.
    - Reaccionar a eventos generados en el navegador.
    - Comunicarse con el servidor sin recargar la página Web (Ajax)

Es important separar bien las tres componentes.

### JQuery

JQuery es una biblioteca de Javascript que simplifica la programación y la interoperabilidad entre navegadores.

Facilita:
- Seleccionar elementos del DOM
- Gestionar eventos
- Manipular el DOM
- Manipular CSS
- Hacer llamadas AJAX fácilmente

### AJAX

AJAX (Asynchronous Javascript and XML) es una técnica de desarrollo web para crear Rich Internet Applications. Una parte muy importante de la aplicación se ejecuta en el cliente.

Características:
- Asíncrono
- Intercambio de información por medio de XML o JSON
- Interfaz de petición por medio de XMLHttpRequest
- Recomendación: Usar la biblioteca JQuery

### Generación dinámica de contenidos (páginas dinámicas)

¿Cómo podemos generar contenido dinámicamente?
- Programas ejecutables en el servidor
- Usar lenguajes de scripting

La idea principal es componer (controlador) las páginas web (vista) dinámicamente extrayendo la información de una fuente de datos (modelo).

#### Ejecución de programas en el servidor

Si optamos por ejecutar programas o aplicaciones en el servidor, estos programas o aplicaciones reciben el nombre de CGIs (Common Gateway Interfaces), pues permiten al cliente (navegador web) solicitar datos de un programa ejecutado en un servidor web.

La puesta en funcionamiento de esta opción es:
- configurar el servidor web para que ante una petición se lance un ejecutable.
- La salida del ejecutable se manda como respuesta a la petición.

Ventajas o inconvenientes de esta alternativa:
- Los ejecutables pueden ser dependientes de la máquina.
- Hay que vigilar la eficiencia si hay que hacer cálculos intensivos.
- "Dificultad" de programación (bajo nivel)

##### Ejecución en el servidor: Python

Python es un lenguaje que cada vez más se está usando para desarrollo web usando para ello habitualmente algún framework como Flask, Django, etc.

##### Ejecución en el servidor: Java Servlets

Los Java Servlets son programas en Java que se ejecutan en el servidor y atienden peticiones http.

Características:
- Heredan de la clase HttpServlet e implementan doGet y/o doPost.
- Devuelven como respuesta lo que se envíe a un Writer (out.println)
- Usualmente servidos con el servidor Tomcat.

#### Lenguajes de Scripting: PHP, ASP, Perl, JSP

Las características de los lenguajes de scripting son:
- Código interpretado
- Se puede intercalar en la plantilla de HTML
- Por defecto el servidor tiene los scripts en su directorio de páginas web pero si los identifica como scripts (por su extensión) ejecuta el intérprete.

Las ventajas o inconvenientes de esta opción son:
- Más a alto nivel
- Desarrollo rápido
- Puede ser dificil implementar bien el MVC.

##### ASP, ASP.net

ASP (Active Server Pages) es la tecnología propietaria de Microsoft. Pensado originalmente para correr sobre IIS (Internet Information Services, servicio que convierte un PC en un servidor web). Originalmente basado en Visual Basic. Actualmente cualquier lenguaje .NET.

Características:
- Se compila el lenguaje a un lenguaje intermedio (Intermediate Language - IL)
- De IL se compila a código máquina con un compilador JIT.
- El código intermedio impone una serie de restricciones a los lenguajes .NET que se usen.

##### JSP

Java Server Pages permite insertar código Java en el HTML usando la etiqueta <% ... %>

Características:
- Usa internamente servlets.
- El servidor Tomcat transforma la página JSP a un servlet y lo ejecuta.
- El servlet compilado se cachea.

### PHP : Hypertext Preprocesor

Nace como un preprocesador de páginas web para darles algo de contenido dinámico. A día de hoy se ha convertido en uno de los estándares para la web y existen muchos módulos que le aportan funcionalidad (como enlaces a casi todas las bases de datos usuales).

Es importante aclarar que el código PHP se ejecuta en el SERVIDOR, el HTML se interpreta en el CLIENTE y el código Javascript se ejecuta en el CLIENTE.

#### PHP : Pistas para desarrollo eficiente con PHP

Separación MVC : Al ser un lenguaje que se puede intercalar en el HTML puede ser difícil implementar MVC.

Buenas prácticas :
- Separar completamente la vista el Controlador:
  - Los ficheros de la vista (los que contienen HTML deben tener el mínimo PHP posible)
  - Los ficheros del controlador no deben tener nada de HTML.
- Separar completamente el Modelo del Controlador:
  - El modelo encapsula toda la interacción con la fuente de datos (BD).
  - En el controlador no debería aparecer ni una llamada directa la fuente de datos.
  - Una buena posibilidad puede ser usar un ORM (o al menos un acceso a BD orientado a objetos).

### Uso de un motor de plantillas (Twig)

Para una mejor separación de la Vista y el Controlador es muy recomendable usar un motor de plantillas como Twig.

Características:
- Lenguaje de plantillas reducido y simple (apto para diseñadores)
- Fácil aprendizaje
- Previene malas prácticas
- Libre (y gratuito)

La herencia de Twig permite reutilizar templates y partes de templates. En los templates podemos crear una estructura de bloques que podemos redefinir en los hijos. Con la función parent() podemos renderizar el bloque padre.

### Jugando un poco con el servidor web

Por defecto Apache estará sirviendo todos los ficheros y directorios en nuestra carpeta base, pero si por ejemplo queremos evitar servir la carpeta templates podemos modificar el archivo "etc/apache2/sites-available/000-default.conf", reiniciar el servicio y redirigir cualquier acceso a la carpeta /templates a un error 404 con "RedirectMatch 404 /templates".

También podemos cambiar el sistema de gestión de URLs para conseguir URL limpias.

### Arquitecturas Orientadas a Servicios

Los SOA (Service Oriented Architecture) es un estandar para publicar y usar servicios.

Características:
- Los servicios intercambian mensajes XML sobre http.
- Busca mínimo acoplamiento.
- SOAP: Simple Object Access Protocol. 3 actores: proveedor, consumidor y publicador.

### REST: Representational State Transfer

Es un tipo de arquitectura de software.

Características:
- Protocolo cliente / servidor sin estado.
- Sus operaciones están bien definidas (CRUD sobre POST, GET, PUT, DELETE explicitamente)
- Sintaxis universal a través de la URI.
- Tipo de información enviado: usualmente XML o JSON.

## Tema 3 : Análisis y diseño de sistemas web

### Objetivos

- Conocer las peculiaridades de los sistemas web y adaptar las metodologías de desarrollo a los mismos.
- Ser capaz de conceptualizar en diagramas y documentos los requisitos de un SIBW.
- Conocer distintas arquitecturas y paradigmas de diseño de sistemas web y aplicarlos en ejemplos concretos.

### Ingeniería de Requisitos (IR)

La Ingeniería de Requisitos ocupa las actividades que llevan a la especificación de las necesidades de usuarios y departamentos interesados así como las restricciones que recaen sobre dicho sistema.

Normalmente el sistema web tendrá que interaccionar con otros sistemas (otro software), o influirá en la manera en que trabajarán los empleados / departamentos.

### Sobre la Ingeniería de Requisitos: Leyes no escritas

- La especificación de requisitos es un problema de comunicación.
- Los interesados y el equipo de desarrollo no escriben correctamente lo que entienden como requisitos.
- La validación de los requisitos se produce tarde.
- El usuario ve el producto final tarde.
- Los requisitos suelen ser inestables y variables (muy malo para el desarrollador).

### Requisitos funcionales

Son aquellos que determinan que debe hacer el software, los servicios que debe prestar y a que datos debe reaccionar.

Ejemplos:
- Elementos de entrada que tendrá el interfaz web.
- Qué funcionalidad tendrá
- Cómo se vinculan las páginas de información entre sí.

En general pueden referirse a:
- Requisitos de la organización: Diferentes puntos de vista de la organización o entorno donde se implantará la solución.
- Requisitos del dominio de la aplicación: Funcionalidad en sí de la aplicación: Contenido de la información, flujo de la información,
estructura de la información.
- Requisitos de navegación: Cómo se pasa de entre distintos elementos de información
- Requisitos de interacción: Lo relativo a la interfaz de usuario.

### Requisitos no funcionales

Son restricciones o condiciones que se imponen al sistema que no tienen que ver con la funcionalidad (también llamados Atributos de calidad).

Ejemplos:
- Requisitos del producto: memoria que se puede usar o plataforma sobre la que debe correr, navegadores soportados, resoluciones de pantalla...
- Requisitos organizacionales: impuestos por el desarrollador como por ejemplo, lenguajes a usar, estándares de desarrollo, metodologías.
- Requisitos externos: normativas legales aplicables, interacción con sistemas externos...

### Extracción de requisitos, algunos mecanismos

- Estudio de viabilidad: Indicado para sistemas novedosos en las que las posibilidades de fracaso son altas. Es imprescindible contar con un especialista que conozca el negocio (clientes, canales de distribución, flujo de la información, interacción de los clientes y el prestador de servicios...)
- Entrevistas: Son fundamentales. No solo con el dueño o jefe, sino con personal de todos los estamentos e incluso con clientes (top-down). Hay que prepararlas y son mejores las preguntas abiertas.
- Desarrollo conjunto de aplicaciones: Sesiones conjuntas entre usuarios y analistas. Aprovechar dinámicas de grupo para obtener requisitos conjuntamente.
- Observación directa - etnografía: Si ya hay un sistema funcionando observar directamente su funcionamiento para entender como se llevan a cabo las tareas en la actualidad. Se analiza no solo el programa sino la interacción con las personas que lo usan y las interacciones entre las personas. Importante: Dejar constancia de que no es una evaluación del personal para que el trabajo se desarrolle como normalmente.

### Elaboración del documento de requisitos

Una vez obtenida la información hay que clasificar, ordenar, priorizar, documentar y especificar los requisitos. Esto no es trivial y lleva tiempo, pero es importante.

Posible estructura del documento:
- Resumen, Autor
- Descripción de escenarios comunes
- Especificaciones detalladas pantalla a pantalla
- Requisitos no incluidos y cuestiones por resolver
- Ideas para el diseño
- Trabajos futuros
- Requisitos funcionales del usuario
- Requisitos funcionales del dominio del problema
- Requisitos no funcionales

### Negociación y validación de requisitos

- Es fundamental negociar y validar los requisitos con el cliente. Normalmente querrá que se satisfagan todos, pero a un coste limitado.
- Puede ser necesaria la firma de un contrato con los mismos: se resalta la importancia de los mismos y se concreta exactamente el alcance del proyecto. Se evitan malentendidos por ambas partes.
- Puede ser interesante ofrecer información sobre precio y obligatoriedad o no de cada requisito.


### Dificultades en la especificación de requisitos

- Límites difusos del sistema: El cliente irá añadiendo requisitos segú describe el problema.
- Diferencias de dominio entre el cliente y el desarrollador: Cada uno es expero en su ámbito y se produce una dificultad en la comprensión
- Volatilidad: Los requisitos cambian. Hay que aprender a gestionar estos cambios.
- Problemas no tecnológicos: Cambios de interlocutor, políticas de empresa, de prioridades...

### Diseño de Aplicaciones Web

Una vez realizada una especificación de requisitos hay que refinar las abstracciones identificadas en la fase previa para organizar los datos, la navegación, la presentación y la arquitectura de la aplicación.

Peculiaridades de las aplicaciones web
- Mayor accesibilidad de la información y servicios (+ usuarios simultáneos)
- Interfaz orientada al documento
- Variedad de tecnologías de gestión, acceso y procesamiento de datos
- Variedad de tecnologías y motores de visualización
- Arquitectura compleja (sistema distribuido, balanceo de carga...)

### Diseño de flujos de trabajo

Usaremos UML (Lenguaje Unificado de Modelado)
- Diagramas de flujo
- Diagramas de secuencia

### Diseño de datos

Usaremos diagramas de clases UML:
- En el caso de bases de datos relacionales la conversión es directa.
- En otros tipos de bases de datos hay que trabajar la conversión.

### Diseño de la navegación

Debemos estructurar las rutas de navegación a través de la información y servicios ofrecidos por nuestro sistema de información web.

Aspectos fundamentales a considerar:
- La estructura del sitio
- Comportamiento del usuario al navegar (acciones del usuario y eventos que desencadena)

### Diseño de la estructura del sitio: IFML

Componentes de cualquier lenguaje de modelado del sitio:
- Ítems atómicos: Elementos de información con instancias de entidades de datos.
- Ítems compuestos: Estructuras compuestas de varios ítems atómicos.
- Estructuras contextuales: estructuraas de navegación para acceder a los ítems (menus, índices, metaetiquetas...)

Interaction Flow Modeling Language - IFML : Estándar para llevar a cabo el diseño estructural de aplicaciones (no necesariamente web). Si seguimos el esquema Modelo, Vista, Controlador fundamentalmente se encarga de la parte de la Vista, pero está claro que depende y hace referencia al modelo y al controlador.

### Modelado con IFML

Abordamos las siguientes perspectivas:
- Especificación de la estructura de la vista (contenedores, relaciones entre ellos...)
- Especificación del contenido de la vista (contenido de las vistas)
- Especificación de eventos (de los que pueden afectar al estado del interfaz)
- Especificación de transición de eventos (efectos de los eventos sobre el interfaz).
- Especificación de los parámetros de conexión (dependencias de entrada/salida entre los componentes de la vista y las acciones).

### Diagramas IFML

- Consisten en uno o más contenedores de vista de alto nivel.
- Internamente puede estructurarse cada contenedor como una jerarquía de sub-contenedores.
- Los contenedores pueden contener componentes de vista (contenido o elementos de entrada de información).
- Los componentes tienen parámetros de entrada y salida. Por ejemplo:
  - Un componente que muestra las propiedades de un objeto tiene como entrada el ID del objeto.
  - Un formulario tiene como parámetros de salida los valores introducidos.
- Los contenedores y componentes se puede asociar con eventos (indica la interacción con el usuario).

### Diseño de la Adaptación

Las aplicaciones web serán usadas probablemente desde diversas partes del mundo y bajo muy distintos dispositivos. La adaptabilidad de las mismas es por tanto fundamental. Normalmente la adaptabilidad se refiere a tres características:
- Localización e internacionalización: Idioma, moneda, horas y fechas, aspectos culturales.
- Personalización y adaptación: Ajustes para cada uno de los usuarios.
- Accesibilidad: Ajustes para las personas con discapacidades.

#### Localización e internacionalización

- Locale : Región geográfica en la que sus habitantes comparten idioma y valores comunes.
- Internacionalización (i18n) : Identificación y separación de todos los elementos específicos que componen los locale.
- Lozalicación (l10n) : Adaptación concreta de los elementos identificados en la i18n para un locale concreto.

Ejemplos de aspectos a tener en cuenta para la l10n:
- Idioma (incluso dialectos)
- Unidades de medida
- Moneda
- Fechas
- Cantidades
- Direcciones
- Metáforas
- Colores
- Referencias históricas
- Gestos, aspecto de las personas

Localización e internacionalización con PHP:
- Crear varias versionas de las páginas con los textos traducidos (¡NO!)
- Usar ficheros de texto con las traducciones y cargar el oportuno.
- Utilizar gettext
- No reinventar la rueda y usar un motor de plantillas que soporte la internacionalización: i18n extension for Twig.

#### Personalización y adaptación

Adaptaciones que se suelen encontrar en aplicaciones web:
- Adaptación de contenidos
- Acciones de navegación automática
- Adaptación de la estructura de navegación.
- Adaptación del layout.

## Tema 4 : Gestión de la información

### Objetivos

- Conocer diversas tecnologías para almacenar la información en plataformas Web.
- Ser capaz de interpretar documentos XML y valorar su uso en soluciones Web.
- Conocer los aspectos básicos de la Web Semántica y su influencia en los sistemas de información basados en Web.

### Tipos de información en la WWW

- Datos desestructurados: Archivos de texto, vídeo, audio, imágenes, presentaciones... Difícil tratamientos y almacenaje en BD.
- Datos semi-estructurados: Con cierta estructura, pero no muy rígida. Ejemplo: Curriculum Vitae.
- Datos estructurados: Todos los registros con una estructura fija y fuertemente tipada.

### Gestión de datos estructurados

La opción típica es usar un modelo relacional. Los Sistemas de Gestión de Bases de Datos (SGBD) relacionales usualmente implementan la mayoría de las funcionalidades necesarias.

Ejemplos de SGBD:
- MySQL
- PostgreSQL
- SQLite
- Oracle

### Gestión de datos semiestructurados

La gestión de datos semiestructurados puede ser más compleja que los datos estructurados.

Posibles formatos para datos semiestructurados: json o XML

SGBD para datos desestructurados: noSQL
- si usamos json -> MongoDB
- si usamos un tipo basado en clave-valor -> Cassandra, BigTable...

#### XML

XML es un metalenguaje de marcas para definir lenguajes de marcas. Es una simplificación de SGML.

Lenguajes derivados de XML:
- XHTML
- Google Site Map
- NewsML: News Markup Language
- OOXML: Office Open XML

##### Sintaxis de XML

- Se forma una jerarquía de contenidos (árbol) que es etiquetado, ilimitado y ordenado.
- Elemento: Formado por etiqueta de apertura, contenido textual y etiqueta de fin.
- Atributos: En la etiqueta de apertura pueden aparecer pares clave-valor.
- Importante, los atributos no están ordenados, el contenido sí. El contenido de los atributos pueden ser sub-árboles. Los atributos pueden ser complejos.
- Prólogo o Cabecera: Se indica la versión de XML, codificación, localización de recursos externos.
- Entidades: referencias o contenidos asignados a constantes.
- Document Type Definition (DTD): es un mecanismo simple de definición de documentos XML.
XML-Schema: Lenguaje de descripción de tipos XML propuesto por el W3C. Muy versatil pero bastante más complicado que los DTDs. Permiten definir tipos y atributos.

- XSL (extensible Stylesheet Language) se usa para darle estilo a los documentos XML. Consta de
  - XSLT: Lenguaje para transformar XML
  - Xpath: Para navegador por los documentos XML
  - XSL-FO: Para formatear los documentos XML

### La web semántica

La web semántica es un conjunto de actividades desarrolladas en el seno de W3C con tendencia a la cración de tecnologías para publicar datos legibles por aplicaciones informáticas. Se basa en la idea de añadir metadatos semánticos y ontológicos a la WWW. Esas informaciones adicionales -que describen el contenido, el significado y la relación de los datos- se deben proporcionar de manera formal, para que así sea posible evaluarlas automáticamente por máquinas de procesamiento.

Una ontología es una descripción formal que proporciona a los usuarios humanos un conocimiento compartido sobre un dominio concreto. Es una definición formal de tipos, propiedades, y relaciones entre entidades que realmente o fundamentalmente existen para un dominio de discurso en particular.

#### Ontologías

Son útiles para:
- Organizar datos
- Mejorar las búsquedas
- Integrar información

Ejemplo: Ontología "Universidad"
- Clases: :Profesor, :Alumno, :Asignatura, :Departamento
- Instancias de clases: :Zerjillo es instancia de :Profesor
- Relaciones: :Imparte(:Zerjillo, :SIBW)
- Herencia: :Profesor es subclase de :Personal
- Restricciones: no :Imparte(:Alumno, :Asignatura)
- Restricción de cardinalidad: :Departamento solo tiene un :Director

#### Lenguajes para la web semántica

- Resource Description Framework (RDF) : Familia de especificaciones de la W3C originalmente diseñado como un modelo de datos para metadatos. Permite describir anotaciones sobre recursos web (asociados a una URI).
- RDF Schema : Extensión semántica de RDF. Un lenguaje primitivo de ontologías que proporciona los elementos básicos para la descripción de vocabularios.
- Web Ontology Language (OWL) : Lenguaje de marcado para publicar y compartir datos usando ontologías en la WWW. OWL tiene como objetivo facilitar un modelo de marcado construido sobre RDF y codificado en XML.

### Gestión de datos desestructurados: búsqueda de información

El problema es que es difícil gestionar fuentes de información tan variada como la que hay en general en la web.

Ante este problema, ¿cómo se las apañan los buscadores?

#### Rastreadores (Crawlers o Spiders)

Un rastreador es un robot que navega por las webs indexando y clasificando los contenidos de las mismas. En el fondo hacen una búsqueda en un grafo (por anchura, por profundidad o esquemas mixtos).

Los mapas del sitio (sitemap) son archivos XML que describen de manera jerárquica la estructura del sitio. Esto facilita la vida a los buscadores.

Se puede pedir a los buscadores que partes de nuestro sitio no sea indexado, por ejemplo, páginas que no se van a ver salvo que se registren (esto se hace con el archivo robots.txt).

### Buscadores: procesamiento de texto

- Fases habituales
  - Tokenización: Extraer palabras
  - Limpieza: Eliminar tokens no útiles
  - Análisis semántico: se relacionan términos similares.
  - Indexación: Asociar términos de búsqueda y términos en el artículo.
  - Evaluar la relevancia del artículo frente a las palabras de búsqueda.

- Técnicas SEO (Search Engine Optimization) : Conjunto de acciones orientadas a mejorar el posicionamiento de un sitio web en la lista de resultados de los buscadores de internet. Trabaja aspectos técnicos como la optimización de la estructura y los metadatos de una web, pero también se aplica a nivel de contenidos, con el objetivo de volverlos más útiles y relevantes para los usuarios.

## Tema 5: Estándares, normativas legales aplicables a la web

### Objetivos

- Conocer el marco legal aplicable a los Sistemas de Información Basados en Web.
- Comprender la necesidad del seguimiento de las recomendaciones y normativas de accesibilidad y usabilidad.

### Normativas de accesibilidad web (WCAG)

El objetivo de la accesibilidad web es conseguir que todo tipo de usuarios puedan percibir, entender, navegar e interactuar con el sistema web.

En España esta normativa esta establecida por:
- Real Decreto 1494/2007 (12 noviembre): Reglamento sobre las condiciones básicas para el acceso a las personas con discapacidad a las tecnologías, productos y servicios relacionados con la sociedad de la información y medios de comunicación social.
- Ley 56/2008 (28 diciembre): Medidas de Impulso de la Sociedad de la Información.

Las pautas de accesibilidad para el contenido web (WCAG 2.0) fueron promovidas por el W3C y surgieron como una evolución de la versión 1.0 donde la principal diferencia es la norma de neutralidad tecnología que inica que las pautas se deben aplicar a cualquier tecnología. Estas pautas son verificables, bien automáticamente, bien manualmente.

### Principios o pautas de accesilibidad

El contenido debe ser:
1. Perceptible: Por al menos un sentido
  - Alternativas textuales para cualquier contenido no textual.
  - Alternativas para multimedia tempo-descendientes.
  - Adaptable, pero sin perder información o estructura.
  - Distinguible (vista y oído) incluyendo distinción entre lo más y menos importante.
2. Operable: Que se pueda interaccionar con el contenido
  - Acceso mediante teclado.
  - Suficiente tiempo.
  - No destellos (evitar ataques epilépticos)
  - Navegable: Mediante medios que ayuden a navegar, localizar el contenido y determinar dónde se encuentran.
3. Comprensible: Legible, entendible, predecible.
  - Legible e inteligible.
  - Predecible (apariencia y operabilidad)
  - Ayuda a la entrada de datos
4. Robusto: Contenido suficientemente descrito para poder ser leido con distintos lectores y tecnologías de asistencia.
  - Compatible: La compatibilidad con los agentes de usuario debe ser máxima (tanto actuales como futuros)

### Niveles WCAG

Se han definido 60 pautas, criterios de éxito o puntos de comprobación y verificación. En base al cumplimiento de estas pautas se consiguen unos niveles de conformidad:

- Nivel de conformidad "A": Se consigue si se cumplen los puntos de verificación de prioridad 1.
  - no especifican cómo se representa la información.
  - son razonablemente aplicables a cualquier sitio web.
  - son comprobables de forma automática. Algunos requieren la evaluación de forma manual. Los criterios de cumplimiento que requieren comprobación manual producen resultados consistentes bajo múltiples verificaciones por personas distintas.

- Nivel de conformidad "AA": Se cumplen los puntos de verificación de prioridad 1 y 2.
  - no especifican cómo se representa la información.
  - son razonablemente aplicables a cualquier sitio web.
  - son comprobables de forma automática. Algunos requieren la evaluación de forma manual. Los criterios de cumplimiento que requieren comprobación manual producen resultados consistentes bajo múltiples verificaciones por personas distintas.

- Nivel de conformidad "AAA": Se cumplen los puntos de verificación de prioridad 1, 2 y 3.
  - son criterios que van más allá de los niveles 1 y 2 y pueden aplicarse para hacer sitios accesibles a más personas con cualquier discapacidad o un tipo concreto de discapacidad.

En caso de que cumplamos algún nivel WCAG debemos incluir una declaración al respecto incluyendo el logotipo e indicar:
- fecha en que se revisó el cumplimiento.
- título, versión y URI de las pautas.
- nivel de conformidad alcanzado.
- alcance (enumeración de las páginas que lo cumplen)
- listado de las tecnologías de las que depende el contenido.

### Evaluación de la accesibilidad

Pasos a seguir:
1. Determinar el alcance de la evaluación
2. Establecer la muestra representativa de las páginas que se van a analizar.
3. Evaluación automática.
4. Evaluación manual
5. Resumir los problemas. Realizar informe.

Evaluación manual:
- Aplicar un listado de puntos de comprobación de las pautas.
- Probar múltiples configuraciones de distintos navegadores existentes.
- Técnicas de filtrado:
  - Desactivar imágenes y comprobar textos alternativos.
  - Desactivar el sonido y comprobar que el contenido del audio está disponible a través de texto equivalente (subtitulado, transcripción).
  - Aumentar el tamaño de fuente: diseño sigue preciso y usable.
  - No es necesario el desplazamiento horizontal con diferentes resoluciones de pantalla y/o con diferentes tamaños de ventana.
  - Visualizar en escala de grises y observar el si el contraste es suficiente.
  - Acceso en la navegación y funcionalidad sólo con teclado.
  - Navegar a través de los enlaces y controles de formulario, además comprobar que los vínculos indican claramente el destino.
  - Acceso en la navegación y funcionalidad desactivando plugins, scripts...
- Acceder y examinar las páginas con un lector de pantallas y navegadores especiales de sólo texto (toda la información disponible y en un orden lógico significativo).
- Leer y evaluar los contenidos: texto claro, sencillo y adecuado.

### La protección de datos.

- Art. 18.4 de la Constitución Española: La ley limitará el uso de la informática para garantizar el honor y la intimidad personal y familiar de los ciudadanos y el pleno ejercicio de sus derechos.
- ¿Qué entendemos por protección de datos? El amparo debido a los ciudadanos contra la posible utilización por terceros, en forma no autorizada, de sus datos personales susceptibles de tratamiento, para, de esta forma, confeccionar una información que, identificable con él, afecte a su entorno personal, social o profesional, en los límites de su intimidad.

### La Agencia de Protección de Datos

Es un ente de Derecho Público, con personalidad jurídica propia y plena capacidad pública y privada. Su finalidad principal es velar por el cumplimiento de la legislación sobre protección de datos personales y controlar su aplicación, en especial en lo relativo a los derechos de información, acceso, rectificación y cancelación de datos.

Funciones:
- Atender las peticiones y reclamaciones presentados por los afectados.
- Proporcionar información acerca de sus derechos.
- Ejercer la potestad sancionadora
- Ordenar el cese o inmovilización de los ficheros que proceda.
- Inspeccionar los ficheros.
- Ejercer el control y adoptar las autorizaciones que procedan para los movimientos internacionales de datos.

### Ley Orgánica de Protección de Datos de Carácter Personal (LOPD)

Pretende garantizar y proteger, en lo que concierne al tratamiento de los datos personales, las libertades públicas y los derechos fundamentales de las personas físicas, y especialmente de su honor e intimidad personal y familiar.

### Clasificación de los datos personales

- Públicos: Conocidos por mucha gente y de fuente o difusión no reconocible: nombre, apellidos, edad, profesión...
- Privados: Los que en ocasiones concretas estamos obligados a proporcionar:
  - Íntimos: El individuo puede proteger de su difusión frente a cualquiera pero que, de acuerdo con un fin determinado, esté obligado -por mandato legal- a dar periódica o regularmente en cumplimiento de sus obligaciones cívicas.
  - Secretos (sensibles, sensibilísimos y sensibilidad especial): El ciudadano no estará obligado a dar a nadie salvo casos excecionales, expresamente regulados en las leyes.
    - Reservados: Bajo ningún concepto, ni por ningún motivo, está obligado el titular a darlos a conocer a terceros si no es así su voluntad.
    - Profundos: Como los reservados pero con algunas excepciones.

### Medidas de seguridad en función del tipo de datos

- Nivel alto
  - Ideología, afiliación sindical, religión, creencias, origen racial, salud o vida sexual.
  - Datos recabados para fines policiales sin consentimiento de las personas afectadas.
  - Derivados de actos de violencia de género.
- Nivel medio
  - Relativos a la comisión de infracciones administrativas o penales.
  - Solvencia Patrimonial y Crédito
  - Aquellos de los que sean responsables las Administraciones Tributarias y se relacionen con el ejercicio de sus potestades tributarias.
  - Aquellos de los que sean responsables las entidades financieras para finalidades relacionadas con la prestación de servicios financieros.
  - Aquellos de los que sean responsables las Entidades Gestoras y Servicios Comunes de la Seguridad Social y Mutuas.
  - Aquellos de los que sean responsables los operadores que presten servicios de comunicaciones electrónicas disponibles al público o exploten redes públicas de comunicaciones electrónicas respecto a los datos tráfico y localización.
  - Aquellos que contengan un conjunto de datos de caracter personal que ofrezcan una definición de las características o de la personalidad de los ciudadanos y que permitan evaluar determinados aspectos de la personalidad o del comportamiento de los mismos.
- Nivel bajo
  - Cualquier otro
- Excepciones
  - Nivel básico para ficheros con ideología, afiliciacón sindical, religión, creencias, origen facial, salud o vida sexual:
    - Única finalidad de realizar una transferencia dineraria a las entidades de las que los afectados sean asociados o miembros.
    - Se trate de ficheros o tratamientos no automatizados en los que de forma incidental o accesoria se contengan aquellos datos sin guardar relación con su finalidad.
    - Se trata de ficheros o tratamientos que contengan datos relativos a la salud, referentes exclusivamente al grado de discapacidad o la simple declaración de la condición de discapacidad o invalidez del afectado, con motivo del cumplimiento de deberes públicos.

### El documento de seguridad

El documento de seguridad es un documento de carácter interno que debe reflejar por escrito todo lo relacionado con las medidas, normas, procedimientos de actuación, reglas y estándares encaminados a garantizar la seguridad de los datos en una organización determinada. Dicho documento debe ser elaborado por el responsable del fichero y, en su caso, por el encargado del tratamiento, y es de obligado cumplimiento para todo el personal que tenga acceso a los sistemas de información.

En caso de que los datos de nuestros clientes sean almacenados en un fichero, este fichero se encontrará sometido a la ley, siendo obligatoria su inscripción en el Registro General de Protección de Datos.

### Aviso Legal

Documento que recoge las cuestiones que la Ley de Servicios de la Información (LSSI) obliga a incluir prácticamente en todas las webs, concretamente en aquellos "prestadores de servicios de la sociedad de la información", es decir personas físicas o jurídicas, que realicen actividades económicas por internet u otros medios telemáticos siempre que la dirección y gestión de su negocio esté centralizada en España o posea una sucursal, oficina o cualquier otro tipo de establecimiento permanente situado en España. Por ejemplo:
- Web corporativa de una empresa
- Tienda ecommerce
- Autónomo con una web corporativa (página informativa sobre sus negocios o como tienda online).
- Blog particular sin incluye publicidad.

### Política de privacidad

Hay que informar a los usuarios del procedimiento llevado a cabo por la Web para recoger los datos personales, permitiendo ver a los usuarios el uso que se les da. Esta Política de Privacidad será aceptada por los usuarios de manera previa en los formularios de recogida de datos, y deberán de ser informados de manera inequívoca:
- De la existencia de un fichero o tratamiento de datos de carácter personal, de la finalidad de la recogida de datos y de los destinatarios.
- Del carácter obligatorio o facultativo de su respuesta a las preguntas que les sean planteadas.
- De las consecuencias de la obtención de los datos o de la negativa a suministrarlos.
- De la posibilidad de ejercitar los derechos de acceso, rectificación, cancelación y oposición.

### Condiciones Generales de Contratación y/o Uso

Si tenemos algún tipo de herramienta, asesoramiento online o comercio electrónico, debemos mostrar este texto legal que el usuario deberá aceptar previo a la formalización de la compra, donde se indique:
- Información clara y detallada de los precios, con mención expresa de si incluyen los impuestos correspondientes y gastos de envío y su importe.
- Descripción del proceso de compra.
- Obligaciones tanto para el vendedor y el comprador
- Condiciones de la compra, plazos, forma de entrega, forma de pago...
- Soluciones en el caso de que el pedido sea defectuoso
- Idioma en el que se va a celebrar el contrato

Además, la LSSICE obliga a confirmar al comprador la realización de la operación, puede ser expuesta por dos vías:
- Mediante email (máximo de 24 horas después de la compra)
- Mediante una pantalla de confirmación al finalizar la compra.

### Política de Cookies

Extracto del artículo 22 de la LSSI: Los prestadores de servicios podrán utilizar dispositivos de almacenamiento y recuperación de datos en equipos terminales de los destinatarios, a condición de que los mismos hayan dado su consentimiento después de que se les haya facilitado información clara y completa sobre su utilización... Cuando sea técnicamente posible y eﬁcaz, el consentimiento del destinatario para aceptar el tratamiento de los datos podrá facilitarse mediante el uso de los parámetros adecuados del navegador o de otras aplicaciones, siempre que aquél deba proceder a su conﬁguración durante su instalación o actualización mediante una acción expresa a tal efecto. Lo anterior no impedirá el posible almacenamiento o acceso de índole técnica al solo ﬁn de efectuar la transmisión de una comunicación por una red de comunicaciones electrónicas o, en la medida que resulte estrictamente necesario, para la prestación de un servicio de la sociedad de la información expresamente solicitado por el destinatario.

Cookies exentas:
- Cookies estrictamente necesarias para prestar un servicio expresamente solicitado por el usuario.
- Cookies necesarias únicamente para permitir la comunicación entre el equipo del usuario y la red.
- Ejemplos:
  - de entrada del usuario
  - de autenticación de usuario
  - de seguridad del usuario
  - de sesión de representación multimedia
  - de carga
  - de personalización de la interfaz
  - de cesta de la compra
  - para rellenar un formulario

Cuidado con:
- Publicidad de terceros
- Servicios externos (contadores de visitas, analíticas, mapas...)
