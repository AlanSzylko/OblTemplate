# Bitácora — Obligatorio 2

**Integrantes:** Nombre Apellido (Nº estudiante), Nombre Apellido (Nº estudiante)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## AAAA-MM-DD — Nombre
- Ejemplo: Leí la letra del ejercicio 6. Primera idea: ... pero la restricción de
  complejidad pide ..., así que ...

## AAAA-MM-DD — En conjunto
- Ejemplo: Implementamos ... Bug: ... Lo corregimos ...
- Pasan los casos de prueba 1 a 4 del ejercicio 6.

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

