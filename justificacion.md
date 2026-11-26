# Justificación de órdenes — Obligatorio 2

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
- La letra exige programación dinámica con memoización, tiempo y espacio O(K²).
- Justificación: el estado es (ronda, ventaja de goles de A sobre B, si bailó en el tiro
  anterior). La ventaja es necesaria porque la regla de que A nunca quede abajo no es
  local, el Pato puede ahorrar ventaja en rondas tempranas para gastarla bailando más
  adelante. Como la ventaja va de 0 a K, quedan K·(K+1)·2 estados, cada uno resuelto en
  tiempo constante (bailar o no bailar): O(K²) en tiempo, y la tabla de memo ocupa O(K²).
- En la práctica, con K = 1000 la solución corre en unos 150 ms.

## Ejercicio 10
- La letra exige backtracking y que la solución realice las podas posibles. No fija un
  orden temporal, pero pide que cada test se resuelva en el orden de los segundos, y avisa
  que con 10 cifras un número puede superar el rango de un entero de 32 bits.
- Justificación: se resuelve la suma columna por columna desde las unidades, asignando un
  dígito a cada letra y volviendo atrás cuando algo no cierra. Podas: la letra del resultado
  no se prueba sino que se deduce de (suma + acarreo) % 10, y si no coincide se corta la rama
  en esa columna; no se repiten dígitos; no se prueba 0 en letras iniciales de palabras
  largas; si un sumando es más largo que el resultado, o si el resultado tiene más cifras
  que el sumando más largo más una (con a lo sumo 5 sumandos la suma no llega), se responde
  "imposible" sin buscar; y si se terminan las columnas con acarreo sobrante no quedan
  movimientos válidos.
- Poda por mejor solución: no se corta en la primera solución porque hay que imprimir la
  menor, así que se guarda la mejor encontrada (por resultado y después por sumandos en
  orden). En cada llamada se calcula el menor resultado que todavía puede salir de la rama:
  las letras del resultado ya asignadas mantienen su dígito y las demás toman el menor
  dígito libre. Si esa cota ya es mayor que el resultado de la mejor solución, la rama no
  puede ganar y se corta. La cota se vuelve más precisa a medida que se asignan letras; en
  acertijos con muchas soluciones baja el tiempo a menos de un tercio.
- En el peor caso se exploran asignaciones de hasta 10 letras a 10 dígitos (como mucho 10!
  por acertijo), pero con las podas cada acertijo se resuelve en milisegundos. Los valores
  se calculan en long long.
- Espacio O(1): arreglos de tamaño fijo (26 letras, 10 dígitos, tabla de 5 x 10), más la pila
  de recursión, que tiene como mucho una llamada por letra de cada columna.
- En la práctica, 100 acertijos de 5 sumandos de 10 letras tardan entre 1 y 2 segundos.
