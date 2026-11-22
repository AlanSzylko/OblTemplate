#include <iostream>

using namespace std;

// Conteo con dos punteros propuesto por Claude: reemplaza un ciclo interno que
// hacia el algoritmo cuadratico. Aprovecha que las dos mitades estan ordenadas,
// por lo que el puntero sobre la izquierda nunca retrocede.
void contar(int* arr1, int l1, int* arr2, int l2, long long& cont) {
  int x = 0;
  for (int j = 0; j < l2; j++) {
    while (x < l1 && arr1[x] <= arr2[j] * 2) {
      x++;
    }
    cont += l1 - x;
  }
}

int* intercalar(int* arr1, int l1, int* arr2, int l2) {
  int* ret = new int[l1 + l2];
  int i = 0, j = 0, k = 0;
  while (i < l1 && j < l2) {
    if (arr1[i] < arr2[j]) {
      ret[k] = arr1[i];
      k++;
      i++;
    } else {
      ret[k] = arr2[j];
      k++;
      j++;
    }
  }
  while (i < l1) {
    ret[k++] = arr1[i++];
  }
  while (j < l2) {
    ret[k++] = arr2[j++];
  }
  return ret;
}

int* mergeSort(int* corredores, int inicio, int fin, long long& cont) {
  if (inicio == fin) {
    int* ret = new int[1];
    ret[0] = corredores[inicio];
    return ret;
  }
  int mitad = (inicio + fin) / 2;

  int* ord1 = mergeSort(corredores, inicio, mitad, cont);
  int* ord2 = mergeSort(corredores, mitad + 1, fin, cont);

  int l1 = mitad - inicio + 1;
  int l2 = fin - mitad;

  contar(ord1, l1, ord2, l2, cont);

  int* ret = intercalar(ord1, l1, ord2, l2);

  delete[] ord1;
  delete[] ord2;

  return ret;
}

int main() {
  int n;
  cin >> n;
  int* corr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> corr[i];
  }

  long long cont = 0;
  int* ordenados = mergeSort(corr, 0, n - 1, cont);
  cout << cont;

  delete[] ordenados;
  delete[] corr;

  return 0;
}