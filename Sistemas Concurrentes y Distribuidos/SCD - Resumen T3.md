# Tema 3. Sistemas basados en paso de mensajes.

## Mecanismos básicos en sistemas basados en paso de mensajes

Anteriormente hemos visto los sistemas multiprocesador con memoria compartida:
- Su programación era más sencilla gracias al uso de variables compartidas (cerrojos, semáforos y monitores)
- Pero su implementación era más costosa y la escalabilidad del hardware era limitada ya que había un cuello de botella en el acceso a la memoria común.

Los sistemas distribuidos son un conjunto de procesos (en uno o varios ordenadores) que no comparten memoria pero se intercambian datos a través de una red. Ello hace que :
- La distribución de datos y recursos sea más fácil.
- Soluciona el problema de la escalabilidad y el elevado coste.
- La programación sea más compleja ya que no hay direcciones de memoria comunes y mecanismos como los monitores son inviables.

Así una vista lógica de la arquitectura serían N procesos, cada uno con su espacio de direcciones y memoria propia. Los procesos se comunican mediante envío y recepción de mensajes.
- En un mismo procesador pueden residir físicamente varios procesos.
- Por motivos de eficiencia, frecuentemente se adopta la política de alojar un único proceso en cada procesador disponible.
- Cada interacción requiere cooperación entre 2 procesos: el propietario de los datos (emisor) debe intervenir aunque no haya conexión lógica con el evento tratado en el receptor.

Diseñar un código diferente para cada proceso puede ser complejo.
- Una solución es el estilo SPMD (Single Program Multiple Data). Donde todos los procesos ejecutan el mismo código pero cada proceso procesa datos distintos y/o flujos de control distintos.
- Otra opción es usar el estilo MPMD (Multiple Program Multiple Data). Cada proceso ejecuta el mismo o diferentes programas y cada proceso puede usar datos diferentes.

El paso o transferencia entre dos procesos constituye una transferencia de una secuencia finita de bytes:
- Se leen de una variable del proceso emisor (var_orig)
- Se transfieren a través de alguna red de interconexión.
- Se escriben en una variable del proceso receptor (var_dest)
- Implica sincronización: los bytes acaban de recibirse después de iniciado el envío.
- Ambas variables son del mismo tipo.
- El efecto neto final es equivalente a una asignación var_dest = var_orig.

**Primitivas básicas de paso de mensajes:**

El proceso emisor realiza un envío invocando a *send*, y el proceso receptor realiza la recepción invocando a *receive*. Las sintaxis son:
- send (variable_origen, identificador_proceso_destino)
- receive (variable_destino, identificador_proceso_origen)

**Esquemas de identificación de la comunicación:**

¿Cómo identifica el emisor al receptor y viceversa? Existen dos opciones:
- Denominación directa estática.
  - El emisor identifica explícitamente al receptor y viceversa usando identificadores de procesos. Cada identificador es un valor (entero) biunívocamente asociado a un proceso en tiempo de compilación (estáticamente).
  - Sólo permite la comunicación uno-a-uno.
- Denominación directa con identificación asimétrica : El emisor identifica al receptor pero el receptor no indica un emisor específico.
  - El receptor inicia una recepción, pero indica que acepta recibir el mensaje de cualquier proceso emisor.
  - Una vez recibido el mensaje, el receptor puede conocer que proceso lo ha enviado gracias al identificador de proceso
    - que puede estar incluido en los metadatos del mensaje
    - o ser un parámetro de salida de receive.
- Denominación indirecta.
  - Los mensajes se depositan en almacenes intermedios que son accesibles desde todos los procesos (buzones).
  - El emisor nombra a un buzón al que envía y el receptor nombra un buzón desde el que quiere recibir (típicamente el mismo).
  - El uso de buzones da mayor flexibilidad ya que permite comunicaciones de tres tipos:
    - uno-a-uno : con denominación directa estática.
    - muchos-a-muchos : send de cualquier proceso, receive de cualquier proceso, aunque tiene una implementación complicada (enviar y transmisir a todos los lugares, recibir y notificar la recepción a todos)
    - muchos-a-uno: send de un proceso, receive de cualquier proceso.
  - Un mensaje enviado a un buzón general permanece en dicho buzón hasta que haya sido leído por todos los procesos (broadcast).
- Declaración estática vs dinámica
  - Estáticamente:
    - Ventaja: es muy eficiente en tiempo.
    - Desventaja: cambios en la estructura del programa requieren adaptar el código fuente y recompilarlo.
  - Dinámicamente:
    - Ventaja: el código puede seguir siendo válido aunque cambie el número de procesos de cada tipo (no hay que recompilar)
    - Desventaja: es menos eficiente en tiempo y más complejo.

**Comportamiento de las operaciones de paso de mensajes**

- Si el comportamiento de la operación *send* es el esperado hablamos de comportamiento seguro.
- En caso contrario sería no seguro.

Para poder transmitir un mensaje en el sistema de paso de mensajes (SPM), en el lado del emisor se deben dar estos pasos.
- Solicitud de Envío (SE): después de llamar a *send*, el SPM registra los identificadores de ambos procesos, la dirección y tamaño de la variable origen.
- Inicio de lectura (IL): el SPM lee el primer byte de todos los que forman el valor de la variable origen.
- Fin de lectura (FL): el SPM lee el último byte de todos los que forman el valor de la variable de origen.

En el lado del receptor, el SPM debe dar estos pasos:
- Solicitud de recepción (SR): después de iniciar *receive*, el SPM registra los identificadores de procesos, la dirección y tamaño de la variable destino.
- Fin del emparejamiento (EM): el SPM espera hasta que se haya registrado una solicitud de envío que case con la de recepción anterior y las emparejan.
- Inicio de escritura (IE): el SPM escribe en la variable destino el primer byte recibido.
- Fin de escritura (FE): el SPM escribe en la variable de destino el último byte recibido.

La transmisión de un mensaje supone una sincronización:
- SE < EM
- IL < IE
- FL < FE
- Por tanto, IL < FE

Sin embargo, no hay orden para estas acciones:
- SE y SR
- EM y IL (ni FL)

Por tanto, podemos ver que se puede iniciar la lectura en el lado del emisor (IL) antes de que ocurra el emparejamiento en el lado del receptor (EM), sin embargo para que esto ocurra el SPM deberá almacenar temporalmente esos datos en alguna zona de memoria en el lado del emisor, esa zona se llama almacén temporal.

Además, por la hipótesis de progreso finito, el intervalo de tiempo entre la solicitud del envío (SE) y el fin de la escritura (FE) tiene una duración no predecible. En este intervalo de tiempo se dice que el mensaje está en tránsito.
- Por tanto, el SPM necesita usar una memoria temporal para todos los mensajes en tránsito.
- Dicha memoria puede estar ubicada tanto en el nodo emisor, como en el receptor como en alguno intermedio si los hubiera.
- Si el SPM detecta que no tiene suficiente memoria para el almacenamiento temporal retrasa la lectura del emisor hasta que se libere memoria.

Como hemos comentado antes, las operaciones podrían no ser seguras: el valor que el emisor pretendía enviar podría no ser el mismo que el receptor recibe.
- Operación de envío-recepción segura: se puede garantizar a priori que el valor de *var_orig* antes del envío (SE) coincidirá con el valor de *var_dest* tras la recepción (FE).
- Operación de envío-recepción insegura. Hay dos casos:
  - Envío inseguro: ocurre cuando es posible modificar el valor de *var_orig* entre SE y FL.
  - Recepción insegura: ocurre cuando se puede acceder a *var_dest* entre SR y FE, si se lee antes de recibirlo totalmente o se modifica después de haberse ya recibido parcialmente.


**Tipos de operaciones de paso de mensaje**

- Operaciones seguras
  - Devuelven el control cuando se garantiza la seguridad: send no espera a la recepción, receive sí espera.
  - Existen dos mecanismos de paso de mensajes seguro:
    - Envío y recepción síncronos
    - Envío asíncrono seguro
- Operaciones inseguras
  - Devuelven el control inmediatamente tras hacerse la solicitud de envío o recepción, sin garantizar la seguridad.
  - El programador debe asegurar que no se alteran las variables mientras el mensaje está en tránsito.
  - Existen sentencias adicionales para comprobar el estado de la operación.
- Operaciones síncronas
  - *s_send (var_orig, ident_proceso_receptor);*
    - Realiza el envío de los datos y espera bloqueado hasta que los datos hayan terminado de leerse en el emisor y se haya iniciado y emparejado un receive en el receptor.
    - Es decir, *s_send* no termina antes de que ocurran FL y EM.
  - *receive (var_dest, ident_proceso_emisor)*
    - Espera bloqueado hasta que el emisor emita un mensaje con destino al proceso receptor y hasta que hayan terminado de escribirse los datos en la zona de memoria designada en la variable destino.
    - Es decir, *receive* no termina antes de que ocurra FE.
  - Por tanto, las operaciones síncronas exigen una cita entre el emisor y receptor. La operación *s_send* no devuelve el control hasta que el receive correspondiente sea alcanzado en el receptor.
    - El intercambio de mensaje constituye un punto de sincronización entre emisor y receptor.
  - Desventajas
    - Fácil de implementar pero poco flexible.
    - Sobrecarga por espera ociosa: sólo es adecuado cuando send/receive se inician aprox. al mismo tiempo.
    - Interbloqueo: es necesario alternar llamadas en intercambios.
- Envío asíncrono seguro
  - *send (variable, id_proceso_receptor);*
    - Inicia el envío de los datos y espera bloqueado hasta que hayan terminado de copiarse todos los datos de variable a un lugar seguro. Tras la copia de los datos, devuelve el control sin que tengan que haberse recibido los datos en el receptor.
    - Por tanto, devuelve el control después de FL.
    - Se suele usar junto con la recepción síncrona (*receive*).
  - El fin de *send* no depende de la actividad del receptor.
  - Al igual que ocurre con *s_send*, el fin de *receive* ocurre después del inicio de *send*.
  - Ventajas
    - El uso de *send* lleva en general a menos tiempos de espera bloqueada que *s_send*, ya que no es necesario esperar al emparejamiento.
    - Por tanto, usar *send* es generalmente más eficiente.
  - Inconvenientes
    - *send* requiere memoria para el almacenamiento temporal, el cual, en algunos casos, puede crecer muchho o indefinidamente.
    - Por tanto, el SPM puede retrasar el inicio de lectura (IL) en el lado del emisor, cuando detecta que no dispone de memoria suficiente.
- Aunque se hagan los envíos con *send* que no es síncrono, *receive* sí lo es y por tanto se bloquea por lo que sigue existiendo la posibilidad de interbloqueo.
- Operaciones inseguras:
  - Las operaciones seguras son menos eficientes tanto en tiempo (esperas bloqueadas) como en memoria (almacenamiento temporal).
  - La alternativa son las operaciones de inicio de envío o recepción
    - Las operaciones devuelven el control antes de que sea seguro modificar (caso de envío) o leer los datos (caso de recepción).
    - Deben existir sentencias de chequeo de estado para ver si los datos pueden alterarse o leerse sin comprometer la seguridad.
    - Una vez iniciada la operación, el usuario puede realizar cualquier cómputo que no depende de la finalización de la operación, y cuando sea necesario, chequeará su estado.
  - *i_send( var_orig, id_proceso_receptor, var_resguardo);*
    - Se registra la solicitud de envío (SE) y acaba.
    - No espera a FL ni ninguna acción del receptor.
    - *var_resguardo* permite consultar después el estado del envío.
  - *i_receive( var_dest, id_proceso_emisor, var_resguardo);*
    - Se registra la solicitud de recepción (SR) y acaba.
    - No espera a FE ni ninguna acción del emisor.
    - *var_resguardo* permite consultar después el estado de la recepción.
  - Cuando realizamos cualquiera de esas dos operaciones podemos continuar trabajando hasta que tengamos que esperar su finalización, para ello disponemos de:
    - *wait_send (var_resguardo);*
      - Se invoca por el proceso emisor y lo bloquea hasta que la operación asociada a *var_resguardo* ha llegado al instante FL.
    - *wait_recv(var_resguardo);*
      - Se invoca por el proceso receptor y lo bloquea hasta que la operación asociada a *var_resguardo* ha llegado al instante FE:.
  - Por tanto, las operaciones inseguras nos permiten obtener una mejora en el tiempo de espera pero suponen un coste de reestructuración del programa (más trabajo para el programador).
- Consultas de estado de operaciones asíncronas
  - *test_send(var_resguardo);*
    - Función lógica que se invoca por el emisor. Si el envío asociado a *var_resguardo* ha llegado al fin de la lectura (FL), devuelve true, sino devuelve false.
  - *test_recv(var_resguardo);*
    - Función lógica que se invoca por el receptor. Si el envío asociado a *var_resguardo* ha llegado al fin de la escritura (FE) devuelve true, sino devuelve false.

**Espera selectiva**

La espera selectiva es una operación que permite espera bloqueada de múltiples emisores. Se usan las palabras clave *select* y *when*.

    select
      when condicion1 receive (variable1, proceso1) do
        sentencias1
      when condicioni receive (variablei, procesoi) do
        sentenciasi
    end

- Cada bloque que comienza en *when* se llama una alternativa.
- El texto entre *when* y *do* se llama la guarda de dicha alternativa, incluye una expresión lógica (*condicioni*)

Una guarda es ejecutable en un momento de la ejecución de un proceso P cuando se dan estas dos condiciones:
- La condición de la guarda se evalúa en ese momento a true.
- Si tiene sentencia de entrada, entonces el proceso origen nombrado ya ha iniciado en ese momento una sentencia *send* con destino al proceso P, que casa con el receive.

Una guarda será potencialmente ejecutable si se dan estas dos condiciones:
- La condición de la guarda se evalúa a true.
- Tiene una sentencia de entrada, que nombra a un proceso que no ha iniciado aún un *send* hacia P.

Una guarda será no ejecutable en el resto de los casos, en los que forzosamente la condición de la guarda se evalúa a false.

Para ejecutar select, al inicio se selecciona una alternativa:
- Si hay guardas ejecutables con sentencia de entrada se selecciona aquella cuyo sendo se inició antes (equidad).
- Si hay guardas ejecutables pero ninguna tiene una sentencia de entrada, se selecciona aleatoriamente cualquiera.
- Si no hay ninguna guarda ejecutable, pero sí hay guardas potencialmente ejecutables, se espera bloqueado a que alguno de los procesos nombrados en las guardas inicie un send.
- Si no hay guardas ejecutables ni potencialmente ejecutables no se selecciona nada.

## Paradigmas de interacción de procesos en programas distribuidos.

Un paradigma de interacción define un esquema de interacción entre procesos y una estructura de control que aparece en  múltiples programas.
  - Maestro-Esclavo
  - Iteración síncrona
  - Encauzamiento (pipelining)
  - Cliente-Servidor

Se usan principalmente en programació paralela excepto el último que es más general (sistemas distribuidos).

**Maestro-esclavo**

El proceso maestro descompone el problema en pequeñas subtareas (que guarda en una colección), las distribuye entre los procesos esclavos y va recibiendo los resultados parciales de estos, de cara a producir el resultado final.
Los procesos esclavos ejecutan un ciclo muy simple hasta que el maestro informa del final del cómputo: reciben un mensaje con la tarea, procesan la tarea y envían el resultado al maestro.

**Iteración síncrona**

Iteración: En múltiples problemas numéricos, un cálculo se repite y cada vez se obtiene un resultado que se utiliza en el siguiente cálculo. El proceso se repite hasta obtener los resultados deseados.

Paradigma de iteración síncrona:
- En un bucle diversos procesos comienzan juntos en el inicio de cada iteración.
- La siguiente iteración no puede comenzar hasta que todos los procesos hayan acabado la previa.
- Los procesos suelen intercambiar información en cada iteración.

**Encauzamiento (pipelining)**

El problema se divide en una serie de tareas que se han de completar una después de otra. Cada tarea se ejecuta por un proceso separado. Los procesos se organizan en un cauce (pipeline) donde cada proceso se corresponde con una etapa del cauce y es responsable de una tarea particular. Cada etapa contribuirá al problema global y devuelve información que es necesaria para etapas posteriores.

## Mecanismos de alto nivel en sistemas distribuidos.

Los mecanismos vistos hasta ahora presentan un bajo nivel de abstracción. Vamos a los siguientes mecanismos:
- Llamada a procedimiento remoto (RPC)
- Invocación remota de métodos (RMI)

Ambos están basados en el método habitual por el cual un proceso llamador hace una llamada a procedimiento como sigue:
- El lamador indica el nombre del procedimiento y los valores de los parámetros.
- El proceso llamador ejecuta el código del procedimiento.
- Cuando el procedimiento termina, el llamador obtiene los resultados y continúa ejecutando el código tras la llamada.

**Llamada a procedimientos remotos (RPC)**

En el modelo de invocación remota o llamada a procedimiento remoto (RPC), se dan los mismos pasos, pero es otro proceso (el proceso llamado) el que ejecuta el código del procedimiento:
- El llamador indica el nombre del procedimiento y los valores de los parámetros.
- El proceso llamador se queda bloqueado. El proceso llamado ejecuta el código del procedimiento.
- Cuando el procedimiento termina, el llamador obtiene los resultados y continúa ejecutando el código tras la llamada.

RPC presenta estas características:
- El flujo de comunicación es bidireccional(peticion-respuesta)
- Se permite que varios procesos invoquen un procedimiento gestionado por otro procesos (esquema muchos-a-uno).

**Paradigma Cliente-Servidor**

- Proceso servidor: Gestiona un recurso (ej: base de datos) y ofrece un servicio a otros procesos (clientes) para permitir que puedan acceder al recurso. Pueden estar ejecutándose durante u largo periodo de tiempo, pero no hace nada útil mientras espera peticiones de los clientes.
- Proceso cliente: envía un mensaje de petición al servidor solicitando algo asociado al servicio proporcionado por el servidor (ej: una consulta sobre la base de datos).

No obstante, se plantean estos problemas usando este paradigma:
- Si el servidor falla, el cliente se queda esperando una respuesta que nunca llegará.
- Si un cliente no invoca el *receive* y el servidor realiza *s_send* síncrono, el servidor quedará bloqueado.

Para resolver estos problemas:
- El par (recepción de petición, envío de respuesta) se debe considerar como una única operación de comunicación bidireccional en el servidor y no como dos operaciones separadas.
- El mecanismo de llamada a procedimiento remoto (RPC) proporciona una solución en esta línea.

**Llamada a Procedimiento remoto (RPC)** (dentro de cliente-servidor)

Mecanismos de comunicación entre procesos que sigue el esquema cliente-servidor y que permite realizar las comunicaciones como llamadas a procedimientos convencionales.

La diferencia principal respecto a una llamada a procedimiento local es que el programa que invoca el procedimiento (cliente) y el procedimiento invocado (en el proceso servidor) pueden pertenecer a máquinas diferentes del sistema distribuido.

Un representante o delegado (stub) es un procedimiento local que gestiona la comunicación en el lado del cliente o del servidor. Los procesos cliente y servidor no se comunican directamente, sino a través de representantes.

La comunicación entre cliente y servidor usando RCP por tanto, sigue estos siguientes pasos:
1. En el nodo cliente se invoca un procedimiento remoto como si de un procedimiento local se tratase. Esta llamada se traduce en una llamada al representante del cliente.
2. El representante empaqueta todos los datos de la llamada usando un determinado formato (XDR). Este proceso suele denominarse marshalling o serialización.
3. El representante en el cliente envía el mensaje con la petición de servicio al nodo servidor usando la comunicación ofrecida por el SO.
4. El programa del cliente se quedará bloqueado esperando la respuesta.
5. En el nodo servidor, el SO desbloquea el proceso servidor para que se haga cargo de la petición y el mensaje es pasado al representante del servidor.
6. El representante del servidor desempaqueta (unmarshalling) los datos del mensaje de petición (identificación del procedimiento y parámetros) y ejecuta una llamada al procedimiento local identificado usando los parámetros obtenidos del mensaje.
7. Una vez finalizada la llamada, el representante del servidor empaqueta los resultados y lo envía al cliente.
8. El SO del nodo cliente desbloquea al proceso que hizo la llamada para recibir el resultado que es pasado al representante del cliente.
9. El representante del cliente desempaqueta el mensaje y pasa los resultados al invocador del procedimiento.

**Java Remote Method Invocation (RMI)**

En programación orientada a objetos para invocar un método de un objeto hay que dar una referencia al objeto, el método, los parámetros y el proceso o nodo en el que reside.

Interfaz remota: especifica los métodos del objeto remoto que están accesibles para los demás objetos.

Remote Method Invocation (RMI): acción de invocar un método de la interfaz remota de un objeto remoto. La invocación de un método de una interfaz remota sigue la misma sintaxis que un objeto local.

El cliente y el servidor deben conocer ambos la interfaz de la clase del objeto remoto. Además:
- En el cliente el proceso llamador usa un objeto llamado stub que es responsable de implementar la comunicación con el servidor.
- En el servidor se usa un objeto llamado skeleton, que es responsable de esperar la llamada, recibir los parámetros, invocar la implementación del método, obtener los resultados y enviarlos de vuelta.

El stub y el skeleton permiten al programador ignorar los detalles de la comunicación y empaquetamiento de datos.

- Los objetos remotos residen en el nodo servidor y son gestionados por el mismo. Los procesos clientes manejan referencias remotas a esos objetos:
  - Una referencia remota permite al cliente localizar el objeto remoto dentro del sistema distribuido. Para ello, la referencia remota incluye: la dirección IP del servidor, el puerto de escucha y un identificador de objeto.
- Enlazador: servicio de un sistema distribuido que registra las asignaciones de nombres a referencias remotas.

**Servicios Web**

En la actualidad gran parte de la comunicación en Internet ocurre vía los llamados servicios web.
- Se usan los protocolos HTTP en la capa de aplicación sobre TCP/IP en la capa de transporte.
- Se usa codificación basada en XML o JSON.
- Lo más frecuente es usar el método REST que se caracteriza por:
  - Los clientes solicitan un recurso especificando su URL.
  - El servidor responde enviando el recurso.
  - Cada petición es independiente de otras (es stateless).

Las peticiones de recursos pueden hacerse desde una aplicación cualquiera ejecutándose en el cliente aunque lo más frecuente es usar un programa Javascript ejecutándose en un navegador en el nodo cliente.

Las peticiones pueden gestionarse de forma
- Síncrona: el proceso cliente espera bloqueado la llegada de la respuesta.
- Asíncrona: el proceso cliente envía la petición y continua. Cuando se recibe la respuesta, se ejecuta una función designada por el cliente al hacer la petición.
