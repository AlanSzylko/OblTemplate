# Bitácora — Obligatorio 2

**Integrantes:** Alan Szylkowski (290025), Tiago Fuhrman (290103)

## 2026-10-28 — Tiago
- Hice el ejercicio 7 completo con el merge sort que se habló en clase. Lo modifiqué para
  que lleve un contador por referencia que se va actualizando (cantidad de *remontadas
  épicas*). Modifiqué el intercalar original del mergeSort para que detecte una remontada
  épica. En las compilaciones iniciales contaba mal las remontadas porque me faltaba la
  condición `arr1[r] > arr2[j]*2` dentro del while.
- Usé Claude para resolver errores de compilación del cin y el cout; me ayudó a darme
  cuenta de que faltaba el `using namespace std`.

## 2026-11-02 — Alan
- Leí la letra del ejercicio 8. Al principio confundí las 4 categorías con la cantidad de
  productos: hice los arrays de peso y satisfacción de tamaño 4 e indexados por categoría,
  y me di cuenta de que con varios productos de la misma categoría
  se pisaban entre ellos y perdía datos. Lo rehice con tres arrays de tamaño N
  (peso, satisfacción, categoría) indexados por número de producto.
- Dibujé el árbol de decisiones sobre el input 3 para entender el estado: en cada nodo hay
  que llevar el producto actual, el peso libre y los cuatro cupos restantes. La satisfacción no es
  parte del estado, es lo que devuelve cada nodo.
  Quedo terminado el ej 8.

## 2026-11-10 - Tiago
- Hice el ejercicio 6 completo. Lo encontré bastante intuitivo. Me di cuenta bastante rápido que
  la forma de respetar el O(n) era con un array de largo 1001. También que la forma de imprimir el 
  numero capicúa podía hacerlo con un array de largo n el cual guardaba en orden decreciente los numeros
  de cantidad par. De esta forma podía recorrerlo para un lado y para el otro, y formar el output capícua.
- En la primera pasada de ejecución de test se me colgaba por un loop infinito. Le pedi a claude ayuda para
  encontrarlo, resultó ser que como copié y pegue los for, el que va decrementando me quedo incrementando (i++).
  Otra simplificación que me sugerió Claude y decidí implementarla fue, en vez de crear un string
  retorno e ir concatenando todos los números con un to_string, simplemente ir haciendo cout de los números.


## 2026-11-15 — Alan
- Pasé el ejercicio 8 de la versión recursiva (que era fuerza bruta, O(2^N)) a programación
  dinámica con tabulación. Los seis parámetros de la recursión pasaron a ser las seis
  dimensiones de la tabla, y las llamadas recursivas a `i+1` pasaron a ser lecturas de
  celdas de la fila i+1.
- Decisión: la tabla se recorre con el ciclo de productos hacia atrás (de cantProd-1 a 0),
  porque cada celda depende de celdas con i+1. La fila i == cantProd queda en 0 y es el caso
  base; inicializar el arreglo con `new int[...]()` ya la deja resuelta.
- La guardé en un arreglo plano con una función `pos()` que calcula la posición a partir del
  estado, porque en C++ no se puede declarar un arreglo de 6 dimensiones con tamaños que se
  conocen recién al leer la entrada.
- Verificación: da los 4 ejemplos de la letra (16, 14, 9, 0) y además lo comparamos contra
  la versión recursiva anterior en 3000 casos chicos generados al azar; coinciden en todos.

## 2026-11-22 — Alan
- Revisé el ejercicio 7, que ya estaba hecho por Tiago y pasaba los ejemplos perfecto, contra las
  restricciones de la letra, y encontré dos incumplimientos. El `while` que estaba dentro del
  `intercalar` recorría todo lo que quedaba de la mitad izquierda por cada elemento tomado de
  la derecha, lo que hace el algoritmo cuadrático y no el O(N log N) pedido. Y el contador era
  `int`, cuando la letra avisa que la cantidad de remontadas se pasa de 32 bits.
- Saqué el conteo del `intercalar` a una función aparte con dos punteros.
  Como la mitad izquierda está ordenada, si un elemento supera el doble todos los siguientes
  también, así que la cantidad sale de una resta. Y como la mitad derecha también está
  ordenada, el umbral solo crece y el puntero nunca vuelve para atrás: el conteo queda lineal.
- Cambié el contador a `long long` en la declaración y en los dos parámetros por referencia, y
  agregué los `delete[]` de los arreglos intermedios del mergeSort para cumplir el O(N) espacial.
- Pruebas: pasa los 5 ejemplos de la letra y el caso de un solo corredor.
- Usé Claude para esta revisión: le pedí que chequeara el ejercicio contra las restricciones de
  la letra, me señaló los dos problemas.


## 2026-11-22 — Alan(tanda 2)
- Leí la letra del ejercicio 9. Lo que hay que arrastrar es la ronda, la
  ventaja de goles de A sobre B, y si el Pato bailó en el tiro anterior. En cada ronda primero
  patea A (la ventaja sube según a[i]) y después se decide: bailar suma likes pero B convierte
  y la ventaja baja uno, o no bailar y la ventaja queda igual. Bailar solo es legal si después
  la ventaja no queda negativa, o sea si ventaja + a[i] >= 1, que es la regla del DT.
- Verifiqué el modelo a mano con el Input 4 reconstruyendo el marcador ronda por ronda.
- Problema con la restricción de órdenes: la letra pide O(K) pero el estado necesita la ventaja,
  que tiene rango 0..K, así que quedan K*(K+1)*2 estados, O(K²). Probé si la ventaja se podía
  acotar a una constante chica y no: construí casos con m goles al principio y m tiros caros al
  final, donde el Pato tiene que ahorrar ventaja, y el tope necesario crece con K (con K=40
  hace falta 11). Queda la duda abierta para preguntarle al docente; mientras tanto
  implementamos la versión O(K²), que con K=1000 corre en 160 ms.
- Implementación con memoización: función recursiva sobre (ronda, ventaja, bailó antes) y un
  arreglo de memo inicializado en -1 como marca de "sin calcular", que sirve porque los likes
  son siempre >= 1 y ningún resultado legítimo es negativo.
- Pruebas: pasa los 5 ejemplos de la letra, dos casos borde con K=1, y 800 casos random
  contrastados contra la fuerza bruta.
- Usé Claude en esta sesión: para interpretar la letra, para verificar si la ventaja se podía
  acotar (hizo los experimentos con los contraejemplos).

## 2026-11-24 — Tiago
- Lei la letra del ejercicio 10. Me fue muy dificil poder modelar el ejercicio con backtracking solo. 
  Discuti con claude la estrategia, pidiendole que me guie a pensarlo yo, en vez de que me de la solucion.
  La forma que terminamos utilizando es: resolver la suma columna por columna desde las unidades, como a 
  mano, probando dígitos para las letras de los sumandos y deduciendo la letra del resultado con 
  (suma + acarreo) % 10. Así podemos podar apenas una columna no cierra, en vez de llenar todas las 
  letras y verificar al final. Inclui el template de backtracking visto en clase.

## 2026-11-25 — Alan
- Repasé la devolución del obligatorio 1 y las consignas del 2 punto por punto contra lo que
  tenemos entregable.
- Revisión de formato de salida: encontré que el ejercicio 6 imprimía un espacio sobrante al
  final del cartel, porque el separador iba después de cada número en lugar de antes. La letra
  pide un espacio únicamente entre número y número, así que lo reescribí con un bool que
  saltea el separador en el primero. Ahora la salida coincide byte a byte con los cuatro
  ejemplos de la letra; antes solo coincidía si se recortaban los espacios finales.
- Limpieza de la entrega: saqué los includes que venían en el template y no usamos  
  de los ejercicios 6, 8 y 9, porque en el obligatorio 1
  nos marcaron un include sin usar. Borré los bloques de instrucciones de los tres .md.
- Verificación completa: recompilé los cuatro ejercicios hechos sin warnings y volví a correr
  los 18 ejemplos de la letra, los 18 pasan. También los tamaños máximos.
- Queda pendiente el ejercicio 10 y su justificación de órdenes.

## 2026-11-25 — Tiago
- Terminé con el ejercicio 10. La idea es la que decidimos en la entrada anterior, columna
  por columna, de derecha a izquierda, probando números para las letras y volviendo
  atrás cuando algo no cierra.
- Para el puedoAplicarMovimiento le pedí ayuda a Claude ya que me estaban faltando casos, 
  y quedaba mal el backtracking. Después faltaba elegir cuál solución imprimir, porque 
  puede haber varias. Pasamos las letras a números y nos quedamos con la menor. 
- Por último lo adapté para leer varias veces y lo imprimí con el formato de la letra.
- Claude generó tests para comprobar que el backtracking coincide con los resultados de fuerza bruta.
  También me ayudó para explicar el Orden del ejercicio, ya que no estaba seguro si poniendo peor caso
  O(10!/(10−L)!) era suficiente.

