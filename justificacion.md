# Justificación de órdenes — Obligatorio 2

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 6
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 7
- La letra exige dividir y conquistar, O(N log N) en tiempo y O(N) en espacio.
- Justificación: se usa un merge sort sobre los dorsales en orden de llegada. El árbol de
  recursión tiene log N niveles y en cada nivel el intercalar recorre los N elementos, y el
  conteo de remontadas épicas se hace dentro de ese mismo intercalar, aprovechando que
  ambas mitades ya están ordenadas.

## Ejercicio 8
- La letra exige programación dinámica con tabulación, tiempo y espacio
  O(N · W · L₀ · L₁ · L₂ · L₃).
- Justificación: el estado del problema son seis datos (el producto que se está mirando, el peso libre de la heladera y los cuatro cupos restantes), así que la tabla tiene una dimensión por cada uno, de tamaños N+1, W+1 y Lₖ+1. Eso da el orden espacial pedido. Se llena con seis ciclos anidados, una celda por estado, y cada celda se resuelve en tiempo constante: lee dos celdas ya calculadas de la fila i+1 (saltear el producto o comprarlo) y se queda con el máximo. Una celda por estado y trabajo constante en cada una da el orden temporal pedido.

## Ejercicio 9
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 10
- Sin restricciones de órdenes. / Justificación: ...

