1. El concepto de agente. Agentes racionales y agentes inteligentes. Arquitecturas de agentes.

Un agente es un sistema capaz de percibir su entorno con la ayuda de sensores y actuar sobre el. Con percibir nos referimos a la capacidad del agente de recibir entradas en cualquier instante. Un agente debe ser flexible, escalable y modular.

Hay 3 condiciones que hacen que sea un agente:
- Que sea capaz de percibir su entorno y responder a los eventos que ocurran.
- Que sea proactivo, es decir, que exhiba comportamientos dirigidos a lograr los objetivos
- Que sea autónomo, es decir, que actúe sin la intervención de un ser humano y tenga control sobre sus propias decisiones y estado interno.

Un agente inteligente es un agente racional que pasa el test de Turing.
Un agente racional es aquel que para cada secuencia de percepciones posible toma aquella decisión que le permite alcanzar el mejor resultado posible. Dicho de otra manera, un agente racional es aquel que toma aquella decisión que supuestamente le permite maximizar su beneficio.

Según el nivel de abstracción podemos diferenciar 3 tipos de arquitecturas:
- Arquitecturas deliberativas: Los agentes deliberativos contienen un modelo o representación simbólica del mundo. Estos agentes toman las decisiones aplicando un razonamiento lógico al modelo que contienen con la idea de alcanzar unos objetivos.
- Arquitecturas reactivas: Los agentes reactivos no contienen un modelo o representación del mundo sino que toman sus decisiones en base a las percepciones que reciben.
- Arquitecturas híbridas: Mezclan comportamientos de las dos arquitecturas anteriores.

A nivel topológico, podemos diferenciar:
- Arquitecturas horizontales: Las arquitecturas horizontales son usadas por los agentes reactivos y se caracterizan porque todas sus capas están diseñadas para reaccionar.
- Arquitecturas verticales: Las arquitecturas verticales son usadas por los agentes deliberativos e híbridos y se caracterizan porque no todas las capas están diseñadas para reaccionar.


2. Características de los Agentes reactivos y deliberativos. Similitudes y diferencias. Arquitecturas.

Los agentes reactivos siguen un ciclo acción-reacción y no tienen ningún modelo o representación del mundo, aunque si el agente está dotado de memoria puede ir construyendolo. Estos no realizan razonamientos complejos sino que reaccionan a las entradas que reciben. Los agentes con memoria mantienen un estado interno lo que les permite tomar decisiones con mayor información que sólo sus percepciones.

Estos agentes se diseñan completamente, en el sentido de que hay que establecer una reacción para cada posible situación del mundo. Las principales características de estos agentes son que no realizan razonamientos complejos, que almacenan todo en memoria y usan arquitecturas horizontales.

Los agentes reactivos simples reaccionan directamente a sus percepciones mientras que los agentes reactivos basados en memoria mantienen un estado interno lo que les permite seguir el rastro de aquellos aspectos del mundo que no son evidentes según las percepciones actuales. Por último los agentes reactivos basados en utilidad buscan maximizar su "felicidad".

Los agentes deliberativos contienen un modelo o representación símbolica del mundo y elaboran un plan a partir de los efectos de las acciones sobre ese modelo. Las decisiones tomadas se obtienen como resultado de aplicar un razonamiento lógico al modelo que contienen. Estos agentes no reaccionan a los eventos y usan arquitecturas verticales.    



3. Métodos de búsqueda no informada.

Los métodos de búsqueda no informada son estrategias de búsqueda que evalúan si el siguiente estado, que a priori no se conoce, es mejor o peor que el anterior. No dependen de la información del sistema a la hora de resolverlo, sino que proporcionan métodos generales para recorrer árboles de búsqueda asociados a la representación del problema, por lo que pueden usarse en muchas situaciones.

Podemos encontrar varios como:
- Búsqueda primero en anchura: Consiste en expandir todos los nodos de un nivel de profundidad del árbol antes de expandir cualquier nodo del siguiente nivel de profundidad. Esta búsqueda consume lo mismo en espacio que en tiempo (mas un nodo raíz). Una variante de este método es la búsqueda primero en anchura con coste uniforme que consiste en expandir los nodos de menor coste.
- Búsqueda primero en profundidad: Consiste en expandir el nodo más profundo de la frontera de la búsqueda. Esta búsqueda llega hasta lo más profundo del árbol de búsqueda donde los nodos no tienen sucesores. En esta búsqueda la memoria no supone un problema ya que en cuanto un nodo es expandido y sus hijos recorridos éste puede eliminarse. Cabe la posibilidad de que se produzcan bucles infinitos en esta búsqueda como resultaod de la existencia de grafos o subgrafos con profundidad ilimitada. Para solucionar este problema se establece un límite de profundidad L, dando origen a la variante búsqueda primero en profundidad con profundidad limitada. Otra variante de este método es la búsqueda primero en profundidad con profundidad iterativa, donde el límite de profundidad L va aumentando gradualmente hasta encontrar una solución.
- Búsqueda bidireccional: Esta búsqueda consiste en realizar dos búusquedas simultáneas, una que recorre desde el inicio o raíz hacia adelante y otra desde un nodo hoja hacia atrás.


4. El concepto de heurística. Cómo se construyen las heurísticas. Uso de las heurísticas en IA.

Una heurística es un modelo, principio o criterio que se usa para decidir cual, entre una serie de cauces alternativos de acción promete ser más efectivo a la hora de lograr una meta. Es muy importante que la heurística elegida funcione bien ya que una mala heurística supone un problema para el correcto funcionamiento del algoritmo, por ello es importante mantener un compromiso entre la necesidad de que los criterios sean sencillos y que sea capaz de discriminar entre buenas y malas opciones.
Cabe destacar que en el algoritmo A* cuyo objetivo es establecer una ruta entre un origen y un destino, la distancia manhattan se considera buena heurística y la distancia euclídea no.

Habitualmente las heurísticas se construyen a partir del uso de modelos simplificados del dominio del problema. Hay 3 condiciones que debe cumplir una heurística:
a) Que resuelva el problema aunque la solución que ofrezca no sea óptima.
b) Que haga uso de la información dada del espacio del problema.
c) Debe ser simple, manejable y computable.

Hoy en día las heurísticas se usan en muchos aspectos de la IA como:
- Simplificación de problemas: Se proponen problemas sencillos cuya solución sea idéntica a la del problema inicial.
- Virus/Spam scanning: Se usan patrones para detectar virus o spam.
- Algoritmos de búsqueda:
  - Juegos de posición como el ajedrez, las damas o el problema de las ocho reinas.
  - Resolución de puzzles como el 8-puzzle
  - Búsqueda de caminos mínimos.


5. Los métodos de escalada. Caracterización general. Variantes.

Los métodos de escalada se basan en búsqueda local, que consiste en buscar la mejor solución en el vecindario de una solución inicial, e ir viajando por el espacio de soluciones hasta encontrar un óptimo (local o global). Se dividen en dos grupos:
- los métodos irrevocables: en los que no es posible dar marcha atrás si el camino no es adecuado.
- los métodos tentativos: en los que sí es posible dar marcha atrás si el camino es adecuado.

Las características de estos métodos son:
- Es informado: Utiliza la información de estado para seleccionar un nodo u otro.
- No exhaustivo: No explora todo el espacio de soluciones.
- Encuentra buenas soluciones pero no siempre la mejor ya que es no exhaustivo
- Es eficiente ya que no explora todo el espacio de soluciones.

Algunas variantes de estos métodos son:
- algoritmo de escalada simple: Considera que la vecindad de un nodo es el conjunto de hijos obtenidos secuencialmente hasta encontrar uno mejor que el padre. Así, se parte de una solución inicial, se obtiene su vecindad, si no hay ningún hijo mejor que el padre se para y en caso contrario se escoge al mejor hijo como nodo en curso y el proceso continúa.
- algoritmo de escalada por la máxima pendiente: Considera que la vecindad de un nodo es el conjunto de hijos obtenidos secuencialmente. Así, se parte de una solución inicial, se obtiene su vecindad, si no hay ningún hijo meejor que el padre se para y en caso contrario se escoge el mejor hijo como nodo en curso y el proceso continúa.
- Variaciones estocásticas:
  - Algoritmo de escalada estadística: Se generan los hijos y se escoge aleatoriamente entre los mejores.
  - Algoritmo de escalada de primera opción: Se generan los hijos aleatoriamente y escogo el primero mejor que el padre.
  - Algoritmo de escalada de reinicio aleatorio: Si la búsqueda falla se intenta de nuevo con otra solución inicial generada aleatoriamente.
  - Enfriamiento simulado: Se basa en los principios de la termodinámica. Se realiza controlando la frecuencia de movimientos de escape mediante ua función de probabilidad que hará disminuir la probabilidad de estos movimientos hacia soluciones peores.
  - Algoritmos genéticos.


6. Características esenciales de los métodos primero el mejor.

Los métodos primero el mejor se caracterizan por ser estrategias de búsqueda informada en la que los algoritmos de búsqueda se aplican a árboles o grafos. En estos métodos, un nodo n es seleccionado o no para su expansión en base a una función de evaluación f(n).

Estos algoritmos evalúan los nodos del árbol de búsqueda mediante una función heurística h(n) y se selecciona aquellos nodos cuyo valor sea más favorable para alcanzar el objetivo, donde h(n) es el coste estimado del camino más barato entre el nodo n y el nodo objetivo.

Estos métodos suelen implementarse con una cola de prioridad donde se almacenan los nodos válidos que aún no han sido evaluados en orden ascendente de f(n)-valores y con una lista para aquellos nodos que ya han sido evaluados.

Estos métodos suelen ser óptimos para buscar soluciones aunque consumen mucho espacio en memoria.

Una variante de estos métodos es la búsqueda voraz primero el mejor en el que se seleccionan los nodos más cercanos al nodo objetivo, es decir, la función de evaluación se corresponde con la función heurística (f(n) = h(n)).


7. Elementos esenciales del algoritmo A*.

El algoritmo a* pertenece a los métodos primero el mejor y su objetivo es el de establecer una ruta mínima entre un estado origen y un estado destino. Sus elementos esenciales son:
- función de evaluación f(n) : es el mínimo coste calculado cuyo valor es la suma de h(n) y g(n) donde:
  - h(n) es la distancia estimada entre el nodo actual y el nodo destino y cuyo valor viene dado por una función heurística.
  - h(n) es el coste acumulado de ir desde el nodo inicial al nodo actual, es decir, es la suma de todo el coste del recorrido del nodo inicial al nodo n.
- lista de abiertos: es una lista donde se guardaran aquellos movimientos o nodos que son válidos pero que aún no han sido evaluados
- lista de cerrados: es una lista donde se guardan aquellos movimientos que ya han sido evaluados

El algoritmo a* consiste en lo siguiente:
1. Metemos el nodo inicial en la lista de abiertos.
2. Seleccionamos el mejor nodo de la lista de abiertos.
3. Obtenemos sus nodos sucesores
4. Para cada nodo sucesor, si no estaba en la lista de cerrados y no estaba en la lista de abiertos se añade a la lista de abiertos. Si ya estaba en la lista de abiertos pero su coste es mejor que el que se encuentra en abiertos se actualiza la lista de abiertos.
5. Se mete el nodo actual en la lista de cerrados
6. Se repite todo desde el paso 2 hasta que el nodo actual sea el destino en cuyo caso se recorren todos sus nodos antecesores hasta llegar al nodo inicial lo cuál corresponderá al camino que buscábamos.


8. Elementos esenciales de un algoritmo genético.

Los algoritmos genéticos son métodos adaptativos o sistemáticos que se usan para resolver problemas de optimización y búsqueda. Estos métodos estan basados en el proceso genético de los seres vivos.
Un algoritmo genético es una variante de la búsqueda de haz estocástica en la que los estados sucesores se generan combinando dos estados padres.

Las etapas de estos algoritmos son:
- Inicialización: Se genera aleatoriamente una población inicial, que está constituida por un conjunto de cromosomas que representan las posibles soluciones del sistema.
- Evaluación: A cada cromosoma se le aplica una función de aptitud para saber que tan buena es la solución que están codificando.
- Condición de término: El algoritmo genético deberá detenerse cuando alcance la solución óptima pero esta normalmente se desconoce, por lo que se deben usar otros criterios de parada. Normalmente se usan 2 criterios:
  - Correr el algoritmo un determinado número de veces
  - Detenerlo cuando no haya cambios en la función objetivo.
Mientras no se cumpla la condición de término se hace lo siguiente:
- Selección: Después de saber la aptitud de cada cromosoma se eligen los cromosomas que serán cruzados.
- Recombinación: La recombinación es el principal operador genético, representa la reproducción sexual, la cual opera sobre 2 cromosomas y genera 2 descendientes donde se combinan las características de ambos padres.
- Mutación: Se modifica al azar parte del cromosoma de los individuos, lo que permite alcanzar zonas del espacio de búsqueda que no estaban cubiertas antes.
- Reemplazo: Una vez aplicados los operadores genéticos, se seleccioan los mejores individuos para conformar la población siguiente.


Terminología de los algoritmos genéticos:
- Cromosoma: Vector representación de una solución al problema.
- Gen: Característica/Variable/Atributo concreto del vector de representación de una solución
- Población: Conjunto de soluciones al problema.
- Adecuación al entorno: Valor de función objetivo
- Selección natural: Operador de selección
- Reproducción sexual: Operador de cruce
- Mutación: Operador de mutación
- Cambio generacional: Operador de reemplazamiento.
