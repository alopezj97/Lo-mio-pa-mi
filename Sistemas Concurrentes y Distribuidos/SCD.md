# TEMA 1
## Conceptos básicos

- Programa secuencial: Declaraciones de datos + Conjunto de instrucciones sobre dichos datos que se deben ejecutar en secuencia.
- Programa concurrente: Conjunto de programas secuenciales ordinarios que se pueden ejecutar lógicamente en paralelo
- Proceso: Ejecución de un programa secuencial.
- Concurrencia: Describe el potencial para la ejecución paralela, es decir, el solapamiento ral o virtual de varias actividades en el tiempo.
- Programación Concurrente (PC): Conjunto de notaciones y técnicas de programación usadas para expresar paralelismo potencial y resolver problemas de sincronización y comunicación.
  - La PC es independiente de la implementación del paralelismo. Es una abstracción.
- Programación paralela: Su principal objetivo es acelerar la resolución de problemas concretos mediante el aprovechamiento de la capacidad de procesamiento en paralelo del hardware disponible.
- Programación distribuida: Su principal objetivo es hacer que varios componentes software localizados en diferentes ordenadores trabajen juntos.
- Programación de tiempo real: Se centra en la programación de sistemas que están funcionando continuamente, recibiendo entradas y enviando salidas a/desde componentes hardware (sistemas reactivos), en los que se trabaja con restricciones muy estrictas en cuanto a la respuesta temporal (sistemas de tiempo real).

## Motivación

La programación concurrente aunque es más compleja mejora la eficiencia y hace mejoras en la calidad:

**Mejoras en la eficiencia**: La PC permite aprovechar mejor los recursos hardware existentes.
  - En sistemas de un solo procesador:
    - Al tener varias tareas, cuando la tarea que tiene el control del procesador necesita realizar una E/S cede el control a otra tarea evitando la espera ociosa del procesador.
    - También permite que varios usuarios usen el sistema de manera interactiva (sistemas operativos multiusuarios).
  - En sistemas con varios procesadores: Reparte tareas entre procesadores, reduciendo el tiempo de ejecución.

**Mejoras en la calidad**: Muchos programas se entienden mejor en términos de varios procesos secuenciales ejecutándose concurrentemente que como un único programa secuencial.
  - Ejemplos: Servidor web para reserva de vuelos (cada petición de usuario como un proceso), servidor del comportamiento de una gasolinera (los clientes, servidores y empleados son procesos que cambian de estados).

## Consideraciones sobre el hardware

**Tipos de paralelismo**:
  - Paralelismo virtual -> Monoprocesador -> La CPU alterna instrucciones de varios procesos
  - Paralelismo real (o híbrido):
    - Multiprocesador de memoria compartida: Sincronización y comunicación mediante variables compartidas.
    - Sistemas distribuidos: No tiene memoria común (cada CPU la suya) aunque están conectadas por una red de interconexión

**Mecanismos de implementación de la concurrencia**:
  - Dependen fuertemente de la arquitectura.
  - En los monoprocesadores consideran una máquina virtual que presenta un sistema Multiprocesador o sistema distribuido proporcionando una base para ejecutar procesos concurrentes.

**Concurrencia en sistemas monoprocesador**
  - Multiprogramación: El SO gestiona cómo múltiples procesos se reparten los ciclos de CPU.
  - Servicio interactivo a varios usuarios.
  - Sincronización y comunicación mediante variables compartidas.

**Concurrencia en multiprocesadores de memoria compartida**

  - Los procesadores pueden compartir o no físicamente la misma memoria, pero comparten un espacio de deirecciones compartido.
  - La interacción entre los procesos se puede implementar mediante variables compartidas  alojadas en el espacio de direcciones compartido.

**Concurrencia en sistemas distribuidos**

  - No hay memoria común, cada procesador tiene su espacio de direcciones.
  - Los procesadores interaccionan transfiriéndose datos a tráves de una red de interconexión.
  - La programación distribuida da lugar a otros problemas además de la concurrencia (tratamiento de fallos, transparencia).

## Modelo abstracto de concurrencia

**Sentencias atómicas y no atómicas**

- Sentencia atómica (indivisible); Una sentencia de un proceso en un programa concurrente es atómica si siempre se ejecuta de principio a fin sin verse afectada (en la ejecución) por otras sentencias en ejecución de otros procesos del programa.
  - No se verá afectada cuando el efecto sobre el conjunto de valores de las variables y registros de todos los procesos de la ejecución de la sentencia no dependa nunca de cómo se estén ejecutando otras instrucciones.
  - Ejemplos: Leer una variable de memoria y meterla en un registro. Incrementar el valor de un registro. Escribir en memoria el contenido de un registro.
  - Ejemplos de sentencias no atómicas: Incrementar el valor de una variable.

**Ejecución concurrente**
- Sistemas Estáticos : Nº de procesos fijados en el código fuente del programa. Los procesos se activan al lanzar el programa.

- Sistemas Dinámicos : Nº de procesos variable que se pueden activar en cualquier momento de la ejecución.

**Definición estática de procesos**

var ... {vars. compartidas}

process NomP [indice: 1..9 ó a..b] ;
var ... {vars.locales}
begin
...
end

**Definición de procesos con fork-join**

- fork: sentencia que especifica que la rutina nombrada puede comenzar su ejecución, al mismo tiempo que comienza la sentencia siguiente.
- join: sentencia que espera la terminación de la rutina nombrada, antes de comenzar la sentencia siguiente.

  procedure P1 ;
  begin
  A ;
  fork P2 ; -> procedure P2 ; begin D ; end
  B ;
  join P2 ;
  C ;
  end

**Definición de procesos con cobegin-coend**

Tras el cobegin se ejecutan todas a la vez y terminan todas a la vez en el coend.

  begin
  A ;
  cobegin
    B ; C ; D ;
  coend
  E ;
  end

Impone 1 única entrada y 1 única salida.

## Exclusión mutua y sincronización

En general, el entremezclado de secuencias es completamente arbitrario. Sin embargo, se dice que hay una condición de sincronización cuando hay alguna restricción sobre el orden en el que se pueden mezclar las instrucciones.

Un caso particular es la exclusión mutua, son secuencias finitas de instrucciones que deben ejecutarse de principio a fin por un único proceso.

Al conjunto de dichas secuencias de instrucciones se le denomica sección crítica (SC).

Ocurre exclusión mutua (EM) cuando, en cada instante de tiempo, hay como mucho uno de ellos ejecutando cualquier instrucción de la sección crítica.

Una condición de sincronización es aquella condición que nos indica cuales de las posibles interfoliaciones son correctas (produce, consume, produce, consume ...)

## Propiedades de los sistemas concurrentes

**Corrección de un programa concurrente**
- Propiedad de un programa concurrente: Atributo del programa que es cierto para todas las posibles secuencias de interfoliación. Hay 2 tipos:
  - Propiedad de seguridad (safety)
  - Propiedad de vivacidad (liveness)

**Propiedades de seguridad**:
Deben cumplirse en cada instante (del tipo: nunca pasará nada malo).
  - Son propiedades estáticas.
  - Para cumplirlas se suelen restringir las posibles interfoliaciones.
  - Ejemplos : exclusión mutua (2 procesos nunca entrelazan ciertas subsecuencias de operaciones), Ausencia de Interbloqueo (los procesos nunca esperarán algo que nunca va a suceder), seguridad en el Productor-Consumidor (el consumidor debe consumir todos los datos en el orden adecuado).

**Propiedades de vivacidad**:
Deben cumplirse eventualmente (del tipo: realmente sucede algo bueno).
  - Son propiedades dinámicas.
  - Ejemplos: ausencia de inanición (un proceso no puede ser indefinidamente pospuesto), equidad (todos los procesos deben avanzar con cierta equidad, es decir, a la par).
