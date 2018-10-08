# Tema 4. Introducción a los sistemas de tiempo real.

## Concepto de sistema de tiempo real. Medidas de tiempo y modelo de tareas.

Los sistemas de tiempo real constituyen un tipo de sistema en el que la ejecución del sistema se debe producir dentro de unos plazos de tiempo predefinidos para que funcione con la suficiente garantía.

En un sistema además concurrente será necesario que todos los procesos sobre un procesador o sobre varios se ejecuten en los plazos de tiempo predefinidos.

El objetivo es ejecutar el lazo de control del sistema en instantes de tiempo prefijados. Por tanto, la condición de los sistemas de tiempo real es que no puede haber retrasos en la ejecución del lazo de control, ya que afecta al rendimiento y provoca perdida de estabilidad.

**Tipos de Sistemas de Tiempo Real**

- Sistema en línea: Siempre está disponible, pero no se garantiza una respuesta en un intervalo de tiempo acotado.
  - Ejemplos: Cajeros automáticos, sistemas de reservas de vuelo.


- Sistema interactivo: Suele ofrecer una respuesta en un tiempo acotado, aunque no importa si ocasionalmente tarda más.
  - Ejemplos: Reproductor DVD, sistemas de aire acondicionado.


- Sistemas de respuesta rápida: El sistema ofrece una respuesta en un tiempo acotado y lo más corto posible:
  - Ejemplos: Sistema anti-incendios, alarmas.

**Propiedades de un Sistema de Tiempo Real**

La corrección del sistema depende de las restricciones temporales, por ello los sistemas de tiempo real tienen que cumplir una serie de propiedades.

- Reactividad : El sistema tiene que interaccionar con el entorno, y responder de la manera esperada a los estímulos externos dentro de un intervalo de tiempo previamente definido.

- Predecibilidad : Implica que la ejecución del sistema tiene que ser determinista, y por lo tanto, se debe garantizar su ejecución dentro de un plazo de tiempo definido.

- Confiabilidad (Dependability) : mide el grado de confianza que se tiene del sistema. Depende de:
  - Disponibilidad (avalaibility) : Capacidad de proporcionar servicios siempre que se solicita.
  - Robustez o tolerancia a fallos (fault tolerant) : Capacidad de operar en situaciones excepcionales sin poseer un comportamiento catastrófico.
  - Fiabilidad (reliability) : Capacidad de ofrecer siempre los mismos resultados bajo las mismas condiciones.
  - Seguridad : Capacidad de protegerse ante ataques o fallos accidentales o deliberados (safety), y a la no vulnerabilidad de los datos (security).

  - Cuando esta propiedad es crítica (su no cumplimiento lleva a la pérdida humana o económica), el sistema se denomina sistema de tiempo real crítico (safety-critical system).
    - Ejemplos: Sistemas de automoción

**Modelo de Tareas**

Un sistema de tiempo real se estructura en tareas que acceden a los recursos del sistema.

Una tarea es un conjunto de acciones que describen el comportamiento del sistema o parte de él en base a la ejecución secuencial de un trozo de código. Equivalente a proceso o hebra.

- La tarea satisface una necesidad funcional concreta.
- La tarea tiene definida unas restricciones temporales a partir de los Atributos Temporales.
- Una tarea activada es una tarea en ejecución o pendiente de ejecutar.
- Decimos que una tarea se activa cuando se hace necesario ejecutarla una vez.
- El instante de activación de una tarea es el instante de tiempo a partir del cual debe ejecutarse.

Los recursos son elementos disponibles para la ejecución de las tareas. Se distinguen dos tipos de recursos:
- Recursos Activos: Procesador, Red...
- Recursos Pasivos: Datos, Memoria, Dispositivos de E/S...

Asumimos que cada CPU se dedica a ejecutar una o más tareas, de acuerdo al esquema de planificación en uso.
- Si una CPU ejecuta más de una tarea, el tiempo de la CPU debe repartirse entre varias tareas.

Los requerimientos de un sistema de tiempo real obligan a asociar un conjunto de atributos temporales a cada tarea de un sistema. Estos atributos son restricciones acerca de cuando se ejecuta activa cada tarea y cuanto puede tardar en completarse desde que se activa.

La planificación de las tareas es una labor de diseño que determina como se le asignan (a lo largo del tiempo) a cada tarea los recursos activos de un sistema (procesador) de forma que se garantize el cumplimiento de las restricciones dadas por los atributos temporales de la tarea :
- Tiempo de cómputo o de ejecución (C) : Tiempo necesario para la ejecución de la tarea.
- Tiempo de respuesta (R) : Tiempo que ha necesitado el proceso para completarse totalmente a partir del instante de activación.
- Plazo de respuesta máxima (D) : Define el máximo tiempo de respuesta posible.
- Periodo (T) : Intervalo de tiempo entre dos activaciones sucesivas en el caso de una tarea periódica.

En función del periodo podemos definir tipos de tareas según la recurrencia de sus activaciones:
- Aperiódica: se activa en instantes arbitrarios (no tiene T)
- Periódica: repetitiva, T es el tiempo exacto entre activaciones.
- Esporádica: repetitiva, T es intervalo mínimo entre activaciones.

El problema de la planificación supone:
- Determinar los procesadores a los que se puede asociar las tareas.
- Determinar las relaciones de dependencias de las tareas:
  - Relaciones de precedencia que hay entre las distintas tareas.
  - Determinar los recursos comunes a los que acceden las distintas tareas.
- Determinar el orden de ejecución de las tareas para garantizar las restricciones especificadas.

Para determinar la planificabilidad de un conjunto de tareas se requiere un esquema de planificación que cubra los dos siguientes aspectos:
- Un algoritmo de planificación, que define un criterio (política de planificación) que determina el orden de acceso de las tareas a los distintos procesadores.
- Un método de análisis (test de planificabilidad) que permite predecir el comportamiento temporal del sistema, y determina si la planificabilidad es factible bajo las condiciones o restricciones especificadas
  - Se pueden comprobar si los requisitos temporales están garantizados en todos los casos posibles.
  - En general se estudia el peor comportamiento posible, es decir, el WCET (Worst Case Execution Time)

**Cálculo de WCET**

Suponemos que siempre se conoce el valor WCET(C_w), que es el máximo valor de C para cualquier ejecución posible de dicha tarea.
Hay dos formas de obetener C_w :
- Medida directa del tiempo de ejecución (en el peor caso) : Se realizan múltiples experimentos, y se hace una estadística.
- Análisis del código, se basa en calcular el peor tiempo:
  - Se descompone el código en un grafo de bloques secuenciales.
  - Se calcula el tiempo de ejecución de cada bloque.
  - Se busca el camino más largo.

Las restricciones temporales para un conjunto de n tareas periódicas se especifican dando una tabla con los valores de Ti, Ci y Di para cada una de ellas (con i = 1..n).
- Lógicamente, la i-ésima tarea ocupa una fracción Ci/Ti del tiempo total de una CPU.
- El factor de utilización U es la suma de esas fracciones para todas las tareas.
- En un hardware con p procesadores, si U > p el sistema no es planificable: incluso dedicando a ejecutar tareas al 100% del tiempo de cada uno de los p procesadores, alguna tarea no podrá acabar en su periodo.

## Esquemas de planificación

Tipos de planificación para un sistema monoprocesador:
- Planificación estática off-line sin prioridades.
- Planificación basada en prioridades de tareas
  - Estáticas: prioridades preasignadas, no cambian:
    - RMS (Rate Monotonic Scheduling): prioridad a la tarea con menor periodo T.
    - DMS (Deadline Monotonic Scheduling): prioridad a la tarea con menor deadline D.
  - Dinámicas: prioridades cambiantes durante la ejecución:
    - EDF (Earliest Deadline First): prioridad a la tarea con el deadline más proximo.
    - LLF (Least Laxity First): prioridad a tarea de menor holgura (tiempo hasta deadline menos tiempo de ejecución restante).

**Planificación Cíclica**

La planificación se basa en diseñar un programa (ejecutivo cíclico) que implementa un plan de ejecución (plan principal) que garantize los requerimientos temporales.
- El programa es un bucle infinito, tal que cada iteración tiene una duración prefijada, siempre igual. El bucle se denomina ciclo principal.
- En cada iteración del bucle principal se ejecuta otro bucle acotado con k iteraciones (constante). Cada iteración dura siempre lo mismo y en ella se ejecutan completamente una o varias tareas. A este bucle interno se le denomina ciclo secundario.
- El entrelazado de las tareas en cada iteración del ciclo principal es siempre el mismo. Una iteración número i del ciclo secundario puede tener un entrelazado distinto a otra iteración número j (i <= i,j <= k)

Las duraciones de ambos ciclos son valores enteros.
- La duración del ciclo principal se denomina hiperperiodo y se escribe como T_M. El hiperperiodo es el m.c.m de los periodos de todas las tareas.
- La duración del ciclo secundario se denomina T_S. Lógicamente, se debe cumplir T_M = k * T_S

Para seleccionar un valor apropiado de T_S se deben tener en cuenta estas restricciones y sugerencia:
- Restricciones: necesariamente se cumplen
  - El valor T_S tiene que ser un divisor del valor T_M.
  - El valor de T_S tiene que ser mayor o igual que el tiempo de cómputo (Ci) de cualquier tarea, es decir, se cumple máximo (C1,C2,...,Cn) >= T_S
- Sugerencia: es aconsejable intentar en principio que el ciclo secundario sea menor o igual que el mínimo deadline: Ts <= mínimo (D1,D2,...,Dn)


Propiedades de la planificación cíclica.
- No hay concurrencia en la ejecución
  - Cada ciclo secundario es una secuencia de llamadas a procedimientos
  - No se necesita un núcleo de ejecución multitarea.
- Los procedimientos pueden compartir datos.
  - No se necesitan mecanismos de exclusión mutua como los semáforos o monitores.
  - No hace falta analizar el comportamiento temporal.
  - El sistema es correcto por construcción.


Problemas de la planificación cíclica.
- Dificultad para incorporar tareas con periodos largos.
- Las tareas esporádicas son difíciles de tratar.
  - Se puede utilizar un servidor de consulta.
- El plan ciclo del proyecto es difícil de construir.
  - Si los periodos son de diferentes órdenes de magnitud el número de ciclos secundarios se hace muy grande.
  - Es el caso más general de sistemas en tiempo real críticos.
- Es poco flexible y difícil de mantener.
  - Cada vez que se cambia una tarea hay que rehacer toda la planificación.


**Planificación con prioridades**

La planificación con prioridades permite solventar los problemas descritos. Cada tarea tiene asociado un valor entero positivo, llamado prioridad de la tarea:
- Es un atributo entero (no negativo) de las tareas, que depende de sus atributos temporales y/o el entrelazamiento entre ellas.
- Por convención se asigna número enteros mayores a tareas más urgentes (más prioritarias).
- La prioridades de cada una de las tareas determinan la selección de la tarea que puede ejecutarse en el (único) procesador cuando este queda libre.
- Las prioridades pueden ser constantes fijadas de antemano (estáticas), o bien pueden cambiar con el tiempo (dinámicas), en este caso se deben calcular cada vez que hay que consultarlas.

En este tipo de planificaciones debe existir una componente software (llamada planificador (scheduler)) capaz de:
- Asignar el procesador a una tarea activa o ejecutable (despachar (dispatch) la tarea).
- Suspender una tarea en ejecución cuando es necesario.
- Una tarea puede estar en varios estados (suspendida, ejecutable, ejecutándose).
- Las tareas ejecutables se despachan para su ejecución en orden de prioridad.

El planificador actua en cada instante de tiempo en el que ocurren alguno de estos dos eventos:
- Una o más de una tarea se activan (pasan al estado ejecutable).
- La tarea en ejecución termina (pasa al estado suspendida).

A continuación, selecciona cualquier tarea A con una prioridad actual P_A máxima entre todas las ejecutables, después:
- Si la CPU está libre, A pasa al estado ejecutándose.
- Si la CPU está ejecutando una tarea B con prioridad actual P_B:
  - Si P_A > P_B, la tarea A pasa al estado ejecutándose y B pasa al estado suspendida.
  - Si P_A <= P_B no hay cambios.

La planificación RMS (Rate Monotonic Scheduling) es un método de planificación estático on-line con asignación mayor prioridad a las taréas más frecuentes (menor Ti).
- A cada tarea i se le asigna una prioridad (Pi) basada en su periodo(Ti), cuando menor sea el periodo mayor será su prioridad.


**Test de Planificabilidad**

Los test de planificabilidad permiten determinar si el conjunto de tareas del sistema es planificable según un algoritmo de planificación antes de su ejecución. Existen diversos tipos de tests aplicables según el algoritmo de planificación:

- Tests de planificabilidad suficientes:
  - En caso de éxito en el test, el sistema es planificable.
  - En caso contrario podría ser planificable o no serlo.
- Test de planificabilidad exactos: (suficiente y necesario)
  - En caso de éxito en el test, el sistema es planificable.
  - En caso de no serlo no es planificable.

*Test de Liu & Laylad*

Es un test suficiente, determina la planificabilidad para un sistema de n tareas periódicas independientes con prioridades RMS.
- Se usan dos valores reales, el factor de utilización (U) y el factor de utilización máximo (U_0(n)).
      U_0(n) = n * (2^(1/n) - 1)
- El valor de U_0(1) es 1. A partir de ahí decrece al crecer n hasta el límite que es ln2.
- Un sistema pasa el test si U <= U_0(n). En ese caso es planificable y en caso contrario no se puede afirmar nada.

**Planificación EDF (Earliest Deadline First)** (dentro de Planificación con prioridades)

Es un esquema de planificación con prioridades dinámicas. Se denomina EDF o bien primero el más urgente.

Una tarea tendrá más prioridad cuanto más proxima a su plazo de respuesta máxima (deadline) se encuentre.

Características:
- En caso de igualdad se hace una elección no determinista de la siguiente tarea a ejecutar.
- Es un algoritmo de planificación dinámica, dado que la prioridad de cada tarea cambia durante la evolución del sistema.
- Es más óptimo porque no es necesario que las tareas sean periódicas.
- Es menos pesimista que RMS.

El test de planificación de Liu & Layland se puede aplicar también para el caso de planificación EDF.
- En este caso un sistema pasa el test si el factor de utilización U <= 1.
- El test ahora es exacto (necesario y suficiente).
