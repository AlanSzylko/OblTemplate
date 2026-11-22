#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

int K;
int* a;
int* likes;
int* memo;

// Indexado del arreglo de memo propuesto por Claude: la tabla es conceptualmente
// de 3 dimensiones (ronda, ventaja, bailo antes) y se guarda en un arreglo plano.
int pos(int i, int d, int prev) {
  return (i * (K + 1) + d) * 2 + prev;
}

int mejor(int i, int d, int prev) {
  if (i == K) return 0;

  int p = pos(i, d, prev);
  if (memo[p] != -1) return memo[p];

  int ventaja = d + a[i];

  int r = mejor(i + 1, ventaja, 0);

  if (ventaja >= 1) {
    int g;
    if (prev == 1) {
      g = likes[i] / 2;
    } else {
      g = likes[i];
    }
    int conBaile = g + mejor(i + 1, ventaja - 1, 1);
    if (conBaile > r) {
      r = conBaile;
    }
  }

  memo[p] = r;
  return r;
}

int main() {
  cin >> K;

  a = new int[K];
  likes = new int[K];

  for (int i = 0; i < K; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < K; i++) {
    cin >> likes[i];
  }

  int total = K * (K + 1) * 2;
  memo = new int[total];
  for (int i = 0; i < total; i++) {
    memo[i] = -1;
  }

  cout << mejor(0, 0, 0);

  delete[] memo;
  delete[] a;
  delete[] likes;

  return 0;
}