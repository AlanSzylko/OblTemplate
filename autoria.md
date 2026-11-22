# Declaración de autoría — Obligatorio 2

> **Instrucciones** (borrar esta sección antes de entregar): declarar para cada ejercicio
> las fuentes utilizadas: código discutido o desarrollado en clase, recursos web (con URL)
> y uso de herramientas de IA generativa (herramienta, consulta y uso dado, según los
> lineamientos de Uso de IA de la letra). Si no se usaron fuentes externas, indicarlo
> explícitamente. Los fragmentos de terceros o generados por IA deben además señalarse
> con comentarios en el código fuente. La omisión de fuentes puede considerarse plagio.

## Ejercicio 6
- Implementación propia: el conteo de placas en un arreglo indexado por número y el armado
  del cartel desde los números más grandes hacia los extremos los razonó Tiago.
- IA generativa: Claude. Primera consulta: ayuda para encontrar un loop infinito; resultó ser
  que al copiar y pegar un `for` quedó incrementando (`i++`) el que tenía que decrementar.
- IA generativa: Claude. Segunda consulta: revisión del armado de la salida. Sugirió imprimir
  los números directamente con `cout` en lugar de construir un string e ir concatenando con
  `to_string`.
- IA generativa: Claude. Tercera consulta (Alan): revisión del formato de salida contra la
  letra. Detectó que quedaba un espacio sobrante al final del cartel y reescribió la
  impresión poniendo el separador antes de cada número salvo el primero. Ese fragmento es de
  origen IA y está señalado con un comentario en el código.


## Ejercicio 7
- Merge sort basado en la implementación vista y discutida en clase, adaptado para contar las remontadas épicas.
- IA generativa: Claude. Primera consulta (Tiago): errores de compilación con `cin`/`cout`;
nos indicó que faltaba `using namespace std`.
- IA generativa: Claude. Segunda consulta (Alan): revisión del ejercicio contra las restricciones de órdenes de la
letra. Detectó que el conteo dentro del `intercalar` era cuadrático y que el contador en`int` se podia desbordar, y 
propuso la función de conteo con dos punteros que reemplaza ese ciclo.

## Ejercicio 8
- Diseño de la solución propio: el modelo del estado (producto, peso libre y los cuatro
  cupos) y la recurrencia los razonamos nosotros.
- IA generativa: Claude. Consultas: interpretación de la letra, qué datos forman el estado
  del problema, sintaxis de `cin >>`  y revisión de errores sobre código propio ya escrito. Uso: explicaciones y detección de bugs en arreglos de tamaño 4 en lugar de N, las correcciones las aplicamos nosotros.

## Ejercicio 9
- Modelo del estado (ronda, ventaja de goles, si bailó en el tiro anterior) razonado en
  conjunto con la IA; la verificación contra fuerza bruta y los casos de prueba son propios.
- IA generativa: Claude. Consultas: interpretación de la letra y de la regla de que A nunca
  quede abajo; si la ventaja de goles podía acotarse para bajar el orden a O(K) (hizo
  experimentos con contraejemplos construidos que mostraron que no); e implementación de la
  tabla de memoización. Uso: la función `pos()` y la estructura del arreglo de memo son de
  origen IA y están señaladas con un comentario en el código. El resto se escribió siguiendo
  el modelo discutido.

## Ejercicio 10
- Implementación íntegramente propia, sin fuentes externas.

