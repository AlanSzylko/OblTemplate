# Justificación de órdenes — Obligatorio 2

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 6
- La letra exige una estrategia greedy, O(N) en tiempo y O(N) en espacio.
- Justificación: se cuentan las placas en un arreglo indexado por el número grabado, de tamaño
  fijo 1001 porque la letra acota los números a 0..1000. Eso evita ordenar, que sería
  O(N log N). Después se recorre ese arreglo una sola vez desde 1000 hacia 0, que es la
  decisión greedy: los números más grandes se colocan primero y por eso quedan hacia los
  extremos del cartel, que es lo que pide la regla 2. De cada número se toman todos los pares
  posibles, y el mayor número que queda suelto se guarda para el centro.
- Tiempo: una pasada para leer las N placas, una pasada de 1001 posiciones y una pasada para
  imprimir, todas lineales o constantes, de donde sale el O(N). El `while` interno que saca
  pares no agrega un factor, porque cada vuelta consume dos placas y en total hay N.
- Espacio: el arreglo de conteo es de tamaño constante y el de salida es O(N).

## Ejercicio 7
- La letra exige dividir y conquistar, O(N log N) en tiempo y O(N) en espacio, y avisa que el
  resultado puede superar el rango de un entero de 32 bits.
- Justificación del tiempo: se usa un merge sort sobre los dorsales en orden de llegada. El
  árbol de recursión tiene log N niveles y en cada nivel se recorren los N elementos. El
  conteo de remontadas se hace en una pasada aparte sobre las dos mitades ya ordenadas, con
  dos punteros: para cada elemento de la mitad derecha, el puntero sobre la izquierda avanza
  hasta el primero que supera el doble, y la cantidad sale de una resta. Como la mitad derecha
  también está ordenada, el umbral solo crece y ese puntero nunca retrocede, así que el conteo
  es lineal por nivel y no agrega un factor.
- Justificación del espacio: cada llamada libera con `delete[]` los dos arreglos de sus
  mitades después de intercalarlos, así que en todo momento vive una cantidad de memoria
  proporcional a N y no O(N log N).
- El contador es `long long`: con N = 10⁶ el peor caso da 249.999.500.000, unas 116 veces el
  máximo de un `int`.

## Ejercicio 8
- La letra exige programación dinámica con tabulación, tiempo y espacio
  O(N · W · L₀ · L₁ · L₂ · L₃).
- Justificación: el estado del problema son seis datos (el producto que se está mirando, el peso libre de la heladera y los cuatro cupos restantes), así que la tabla tiene una dimensión por cada uno, de tamaños N+1, W+1 y Lₖ+1. Eso da el orden espacial pedido. Se llena con seis ciclos anidados, una celda por estado, y cada celda se resuelve en tiempo constante: lee dos celdas ya calculadas de la fila i+1 (saltear el producto o comprarlo) y se queda con el máximo. Una celda por estado y trabajo constante en cada una da el orden temporal pedido.

## Ejercicio 9
- La letra exige programación dinámica con memoización, tiempo y espacio O(K).
- Nuestra solución es O(K²) en tiempo y espacio, y lo declaramos explícitamente.
  Justificación del orden alcanzado: el estado es (ronda, ventaja de goles de A sobre B, si
  bailó en el tiro anterior). La ventaja es necesaria porque la regla de que A nunca quede
  abajo no es local: el Pato puede ahorrar goles de ventaja en rondas tempranas para gastarlos
  bailando en rondas donde A erra. Como la ventaja tiene rango 0..K, quedan K·(K+1)·2 estados,
  cada uno resuelto en tiempo constante (dos opciones: bailar o no), de donde sale el O(K²).
- Verificamos que la ventaja no se puede acotar a una constante: con m goles al principio y m
  tiros de likes altos al final, el tope de ventaja necesario para alcanzar el óptimo crece
  linealmente con K (con K = 40 hace falta un tope de 11). Por eso no encontramos cómo sacarla
  del estado y llegar a O(K).
- En la práctica, con K = 1000 la solución corre en unos 150 ms.

## Ejercicio 10
- Sin restricciones de órdenes. / Justificación: ...

