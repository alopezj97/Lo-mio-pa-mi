# Seminario 3. Historias de usuario

## ¿Qué son las HU?

- Es una descripción simple de una tarea concreta que aporta valor al usuario o al negocio.
- Se pueden ver como una corta declaración de intención que describe algo que el sistema necesita hacer para el usuario.
- Suelen obtenerse de las reuniones con los "stakeholders".
- Las historias tienen que ser simples, cortas, fáciles de entender, de aceptar y recordar, sin que tengan que escribirse todos sus detalles.
- Se describen usando tarjetas (descripción escrita en lenguaje del negocio (es decir, sin detalles técnicos) que identifica y recuerda el requisito y ayuda a la priorización).

## Objetivo de las HU

- El objetivo de las HU es principalmente, lograr la interacción con el equipo y con el usuario, por encima de documentar los requisitos que hay en el sistema.
- Hay que justificar el beneficio de todo lo que aparece en una HU.

## ¿Qué no son las HU?

- No es un requisito del sistema (algo que el sistema deba hacer), sino que hay que verlo como algo negociable (necesitaríamos hacer algo similar a esto).
- Es más bien un elemento de comunicación entre stakeholders, cliente o usuario y equipo para ver cuáles son las necesidades (nos fijamos en el qué más que en el cómo).

## Historias de usuario / Casos de uso

| Concepto | Casos de Uso | Historias de usuario |
| -------- | ------------ | -------------------- |
| Objetivo | Modelas la interacción entre un 'actor' y el Sistema | Redactar una descripción breve de una funcionalidad tal y como la percibe el usuario. |
| Estructura | Texto detallado donde se sigue una plantilla predefinida a completar con conceptos técnicos (objetivo, resumen, actor, evento disparador, extensiones, etc.) | Corta y consistente en una o dos frases escritas en el lenguaje del usuario. |
| Planificación | No se utilizan para planificar | Se utilizan para planificar |
| Agilidad | Requieren tiempo para análisis y la redacción de plantillas predefinidas. | Se pueden escribir en pocos minutos. |
| Comprensión | Suelen ser de difícil comprensión, incluso para personal técnico. | Fáciles de leer y comprender. |
| Mantenimiento | Suelen pertenecer a documentos con cientos de páginas. Difíciles de mantener. | Muy fáciles de mantener. |
| Comunicación | Modelo textual asociado con diagramas: todo tiene que estar escrito | Basada en la comunicación verbal y orientada a la colaboración y discusión para clarificar detalles. |
| Soporte | Escritos en documentos con el objetivo de que estos sean archivados como documentos de referencia. | Escritas en tarjetas (teóritcas o reales) con el objetivo de que sean usadas directamente. |
| Duración | Pueden ser implementadas en varias iteraciones | Debe ser implementada y probada en una única iteración. |
| Autores | Definidos por 'intérpretes' (analistas, consultores, etc.) | Posibilidad de ser definidas por usuarios y clientes. |
| Pruebas | La definición de pruebas se redacta en documentación separada. | Contienen 'Pruebas de Aceptación' en el reverso de la tarjeta. |
| Contexto | Proporcionan una visión más general del Sistema y la integración en él. | Proporciona una versión menos obvia, por eso las pruebas y el feedback de los usuarios son tan importante en las metodologías ágiles. |
| Metodología | Asociado con RUP | Asociado con Programación Externa (aunque pueden usarse en RUP).|

## ¿Quién escribe las HU?

- En XP: El cliente
- En SCRUM: El Product Owner (con ayuda de clientes, stakeholders, equipo de desarrollo) o su representante.
- En la realidad: Cualquier miembro del equipo de desarrollo con conocimiento suficiente en el dominio del problema.
- Realmente, escriben las HU aquellos que puedan expresar las necesidades reales del sistema.
- Hay que participar en las reuniones donde se detallan y se priorizan.
- Hay que identificar y organizar a los usuarios del sistema. (Roles o personas)

- Roles del sistema:
  - Podemos usar una sesión de Brainstorming para definirlos.
  - Definición de los roles. (Frecuencia de uso del software, objetivos que se plantean, forma habitual de acceso, etc.)

## Formato de una HU

- Cómo: Quién es el usuario o grupo de usuarios que participan en la historia, normalmente es un "rol de usuario", el que usará la funcionalidad descrita por esta historia.
- Quiero: Es la actividad, el eje de la historia, qué hace el usuario en la historia.
- Para: Es el propósito de la historia, la meta que quiere alcanzar el usuario al ejecutar la historia.

Ejemplo: "Como cliente quiero comparar los precios de dos hoteles para reservar un viaje."

## Elementos de una HU "CCC"

- Tarjeta (Card): Representa las 2-3 sentencias usadas para describir la intención de la HU.
- Conversación: Detalles sobre la HU obtenidos de la conversación con el usuario o cliente.
- Confirmación: Cómo el equipo confirmará que la HU ha sido implementada (Test de aceptación).

## Información de una HU

- Es una descripción corta que no incluye detalles.
- Los detalles se trabajan durante la etapa de "Conversación".
- Una tarjeta con demasiados detalles limita la conversación con el cliente.

Ejemplo: "Un cliente puede pagar un viaje usando una tarjeta de crédito. Nota: Se pueden aceptar VISA, MASTERCARD y AMERICANEXPRESS, el resto de discutirá"

## Narración de la HU

¿Dónde están los detalles de la HU?
- Se describen en las conversaciones entre el equipo y los usuarios. (Conversación)
- Se delimita la parte a abordar por la HU usando las "pruebas de aceptación". (Confirmación)
  - Flujos alternativos en la actividad
  - Límites de aceptación
  - Pruebas de aceptación por parte de los clientes.

## Buscar detalles de la HU (Conversación)

"Como cliente quiero cancelar una reserva"
- ¿Qué coste le va a provocar al cliente la cancelación?
- ¿Todos los clientes van a tener el mismo coste?
- ¿Se puede cancelar en cualquier momento?
- ¿Se puede realizar una cancelación total o parcial?
- ¿A quién se notifica la cancelación?
- ¿Es lo mismo para todos los hoteles?

## Pruebas de aceptación (Confirmación)

- Se usan para expresar muchos de los detalles que se obtienen de la conversación entre clientes y desarrolladores.
- Se usan a dos niveles:
  - Características que se añaden a la tarjeta de la HU.
  - Pruebas que se usan para demostrar que la HU ha sido correctamente desarrollada.
- Los programadores pueden usarlos para mejorar el desarrollo ya que se describen antes de codificar nada.
- Podemos añadir pruebas de aceptación mientras añadan valor y claridad a la HU.
- No hay que olvidar que el equipo de desarrollo realiza pruebas de unidad sobre los módulos que se desarrollen, independientemente de las pruebas de aceptación definidas.
- Se podrían describir usando el formato (Behavior-Driven Development):
  - Dado un sistema donde existe un usuario con nombre "idprueba".
  - Cuando alguien intenta registrarse con nombre "idprueba".
  - Entonces el sistema muestra un mensaje indicando que el nobmre "idprueba" ya existe.

## Características de las HU

- Son cortas y fáciles de leer, entendibles por los desarrolladores, interesados y usuarios.
- Representan incrementos pequeños de funcionalidad valorada, que puede ser desarrollada en un período de días o semanas.
- Son relativamente fáciles de estimar porque el esfuerzo de implementar la funcionalidad puede determinarse rápidamente.
- No se gestionan documentos grandes o pesados, sino más bien en listas organizadas que pueden ordenarse más fácilmente y reordenarse a medida que se descubre nueva información.
- Necesitan poco o ningún mantenimiento y se pueden desechar con seguridad después de la implementación.
- Las historias de usuario, y el código que se crea a continuación, sirven como documentación, la cual también es elaborada de manera incremental.

## Tamaño de una HU

- Historias cerradas. Cuando termina con el logro de un objetivo significativo, y que permite que el usuario sienta que ha conseguido algo valioso.
- Tienen que ser lo suficientemente pequeñas como para ser estimables.
- Tienen que ser lo suficientemente pequeñas como para ser programadas en una sola iteración (2 días a 2 semanas).

## HU terminada (Done)

- Definir qué significa que una HU está "terminada".
- La definición de "terminado" es un acuerdo de calidad entre los desarrolladores y los clientes.
- Se puede establecer una definición de "terminada" para todas las HU o en un "terminado" específico para algunas HU.
- Aspectos a considerar en la definición de "terminada":
  - Tipos de prueba y el grado de prueba.
  - Nivel de calidad del producto software (métricas, etc.)
  - Nivel de documentación
  - Entorno específico en que concluye el trabajo: en prepro, testing, producción.
  - etc.

## ¿Por qué HU?

- Mantenemos una relación cercana con el cliente.
- Nos centramos en los aspectos relevantes actuales aplazando los detalles para cuando sean necesarios.
- Desarrollo oportunista (Requisitos emergentes).
- Facilita el trabajo iterativo.
- Buen tamaño para planificar y estimar.

## Granularidad de las HU

- Temas: Grandes proyectos, peticiones globales sin más análisis ni detalles. Subproductos. (Ej: Planificador de viajes, gestor de ofertas de hoteles, sitio Web para socios).
- Épicas: Súper historias de usuario, más concretas que los Temas. Conjunto de HU relacionadas entre sí. (Ej: Sistema de búsqueda para hoteles, anotador de satisfacción de instalaciones y viajes, filtros aplicados a las búsquedas, comparador avanzado de ofertas).
- Historias de Usuario: Una manera simple de describir una tarea concisa que aporta valor.
- Tareas: Las HU pueden ser divididas en diversas tareas por necesidades técnicas o de desarrollo. (Ej: crear la pantalla de presentación de resultados de la búsqueda de hoteles, crear los métodos de consulta a la BD)

## Requisitos no funcionales

Los RNF pueden tratarse como restricciones asignadas a cualquiera de los elementos que tratamos en las pilas en desarrollo (Temas, Épicas, HU y Tareas).

## Modelo I.N.V.E.S.T.

¿Cuándo consideramos que una historia de usuario es buena?
- Independiente: Una historia debería ser independiente de otras (lo más posible).
- Negociable: Las HU no son un contraro o un requerimiento que es software debe implementar.
- Valiosa: Tiene que tener valor para el cliente (para el usuario o para el comprador). El cliente las escribe, no son un contrato y son negociables.
- Estimable: Para permitir que se pueda priorizar y planificar la historia.
- Suscinta: Una buena historia debe ser pequeña en esfuerzo (2-3 personas/semana de trabajo)
- Testeable: Una historia necesita poder probarse para que ocurra la etapa de "Confirmación".

## Pila de producto (Product backlog)

"Lista priorizada de HU que contiene toda la funcionalidad deseable del producto".
- Prioridad: Valor que le da el cliente a la HU (Medida en la que permite satisfacer sus necesidades).
- Cubre todas las funcionalidades necesarias.
- Se revisa/actualiza frecuentemente.
- Es una herramienta de planificación y gestión.

## Proceso de definición de las HU

- Toma de requisitos en reuniones con usuarios/clientes (entrevistas, cuestionarios, observación).
- Informar de la visión general transmitida por el cliente.
- Crear HU (reuniones de escritura de HU).
- Actuar sobre cada HU mediante un estudio funcional y técnico realizado en equipo.
- Definir criterios de aceptación.
- Estimar el tamaño de las HU para priorizarlas.
- Descomponer las HU en tareas.

## Estimar el tamaño de las HU

- Puntos de Historia: Tamaño relativo de una historia comparado con otras historias estimadas por el mismo equipo (esfuerzo necesario + complejidad + riesgo + ...)
- Días ideales: Un día de trabajo sin interrupciones.
- Estimado por el equipo de desarrollo.

### Planning Poker

- Técnica para realizar una estimación en base al consenso entre los estimadores.
- Existe un moderador que no estima y gestiona la reunión.
- El desarrollador con más conocimiento de una determinada característica proporciona una breve introducción sobre la misma. El equipo tiene la oportunidad de hacer preguntas y discutir para aclarar los supuestos y riesgos.
- Cada persona coloca una carta del mazo boca abajo representando su estimación. Todo el mundo muestra sus cartas a la vez.
- A las personas con estimaciones fueras del promedio (altas y bajas) se les da un tiempo para ofrecer su justificación para la estimación y la discusión continúa.
- Se repite el proceso de cálculo hasta que se alcance un consenso.
- Se asegura de respetar los tiempos asignados a cada estimación, permitiendo hacer de esta reunión un ejercicio productivo y eficiente.

## Priorización de las HU

- Requeridas o críticas: Sin las cuales la solución no puede vivir (entregas primeras del proyecto).
- Importantes: Sin las cuales el sistema puede vivir durante algún tiempo (entregas intermedias del proyecto).
- Opcionales: Si hay tiempo y presupuesto se construyen. (entregas finales del proyecto).
- No se construirán: Por restricciones de presupuesto o de tiempo o no tienen ningún valor para el negocio.
- Las HU pueden ser negociadas con el cliente y van a evolucionar a lo largo del proyecto.

- Priorizar las HU en base al valor para el cliente (Valor de Negocio).
- Tener en cuenta el tamaño y los riesgos de cada objetivo.
- Método MoSCow
  - Must : se debe completar este requerimiento para finalizar el proyecto.
  - Should : se debe completar este proyecto por todos los medios, pero el éxito del proyecto no depende de él.
  - Could : se debería completar este requerimiento si su implementación no afecta a la consecución de los objetivos principales del proyecto.
  - Would : se puede completar este requerimiento si sobra tiempo de desarrollo (o en futuras versiones del mismo).


## Descomposición de una HU en tareas

- Las HU hay que descomponerlas en tareas que puedan ser tratadas de forma individual por el equipo de desarrollo.
- La duración de una tarea debe estar entre medio día a 3 o 4 días de trabajo.
- Una vez terminada la tarea se debe generar un producto entregable.
- No dedicar mucho tiempo a estudiar detalles de las tareas.
- Incluir tareas de pruebas y automatización.

## Velocidad del equipo

- Es la cantidad de puntos de historia que un equipo puede completar en una iteración.
- Se calcula por observación en varias iteraciones del proyecto.
- Permite planificar las HU que se abordaran en una iteración.

## Patrones para partir HU grandes

1. Pasos del flujo de trabajo : Identificamos los pasos que realiza el usuario para hace runa actividad e implementamos esos pasos de forma incremental.
2. Variaciones de las reglas de negocio : Las HU pueden resultar sencillas sino tenemos en cuenta todas las posibles reglas de negocio que hay que aplicar.
3. El mayor esfuerzo de desarrollo: Algunas veces podemos partir una HU en varias partes de forma que las primeras tendrán un mayor esfuerzo de desarrollo y las siguientes van a consistir en añadir mayor funcionalidad.
4. Sencillo / complejo : Si durante la descripción de la HU cada vez se va complicando y parece ser más larga, hay que parar y preguntarse, ¿qué es lo más simple que podría funcionar? Luego podemos añadir variaciones y complejidad sobre nuevas HU.
5. Variaciones en datos : Las variaciones sobre los datos a usar pueden ser un origen de aumento de la complejidad.
6. Métodos de entrada de datos (Vista del IU) : Muchas veces la complejidad está en el IU más que en la funcionalidad. Podemos empezar con una funcionalidad básica y añadir posteriormente una interacción más rica.
7. Niveles de calidad del sistema : Muchas veces las primeras implementaciones no son lo suficientemente eficientes como podrían ser. El equipo puede aprender mucho del desarrollo y posteriormente darle un mayor valor al cliente.
8. Operaciones múltiples : Operaciones como gestionar, administrar, controlar pueden ser divididas en múltiples operaciones.
9. Escenarios de un caso de uso : Si partimos de un estudio de casos de uso, podemos partir cada uno de ellos en escenarios individuales.

## SPIKE

Tipo de HU usada para gestionar una dificultad técnica. Tiempo necesario para reducir un riesgo o una incertidumbre de un problema técnico o para aumentar la seguridad sobre una estimación de una HU.

SPIKE Técnico: Analizar varias aproximaciones técnicas en el dominio de la solución del problema.
- Decidir si comprar o desarrollar algo para la solución.
- Evaluar el rendimiento de una solución propuesta.
- Evaluar el impacto de carga de una nueva HU.

SPIKE funcional: Si hay una incertidumbre importante en cómo el usuario debe interactuar con el sistema. Puede darse por:
- El equipo no tiene suficiente conocimiento sobre un dominio y usamos la HU para familiarizarnos con el dominio o una tecnología nueva.
- Tenemos una HU grande y la estimación necesita ser partida en trozos y analizar lo que implica.
- La HU  tiene riesgos técnicos y el equipo necesita realizar un prototipo o algo de desarrollo para ganar confianza en el desarrollo o el diseño a realizar.
- La HU tiene riesgo funcional y no está claro como tiene que actuar el sistema con usuarios para alcanzar los objetivos planteados.

### Reglas sobre SPIKE

- Se tratan como otras HU (las ponemos en el backlog, las priorizamos, las estimamos, etc.)
- Su resultado no es código, es información útil para otras HU. Debe generar una decisión, un prototipo, una demostración de un diseño, o una solución parcial de un problema.
- La solución de un SPIKE debe ser demostrable al equipo de desarrollo.
- Un SPIKE, como cualquier HU, debe ser aceptada usando criterios de aceptación definidos en la HU.
- Puede ser interesante dejar la resolución del SPIKE para una interacción diferente a la de la HU que lo creó.
