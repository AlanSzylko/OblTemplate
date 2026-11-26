# Declaración de autoría — Obligatorio 2

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
- Merge sort basado en la implementación vista y discutida en clase, adaptado para contar las 
  remontadas épicas.
- IA generativa: Claude. Primera consulta (Tiago): errores de compilación con `cin`/`cout`;
nos indicó que faltaba `using namespace std`.
- IA generativa: Claude. Segunda consulta (Alan): revisión del ejercicio contra las restricciones 
  de órdenes de la letra. Detectó que el conteo dentro del `intercalar` era cuadrático y que el 
  contador en`int` se podia desbordar, y propuso la función de conteo con dos punteros que reemplaza 
  ese ciclo.

## Ejercicio 8
- Diseño de la solución propio: el modelo del estado (producto, peso libre y los cuatro
  cupos) y la recurrencia los razonamos nosotros.
- IA generativa: Claude. Consultas: interpretación de la letra, qué datos forman el estado
  del problema, sintaxis de `cin >>`  y revisión de errores sobre código propio ya escrito. 
  Uso: explicaciones y detección de bugs en arreglos de tamaño 4 en lugar de N, las correcciones
  las aplicamos nosotros.

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
- Estructura de la función `backtracking` basada en el template de backtracking visto en
  clase. El enfoque columna por columna desde las unidades se razonó por cuenta propia.
- IA generativa: Claude. Consultas: estrategia para modelar el problema con backtracking
  (le pedimos que guiara el razonamiento en vez de dar la solución; de ahí salió deducir la
  letra del resultado con (suma + acarreo) % 10 para podar apenas una columna no cierra);
  casos que faltaban en `puedoAplicarMovimiento`; generación de tests contra fuerza bruta
  (no se entregan); y ayuda para redactar la justificación del orden. 
