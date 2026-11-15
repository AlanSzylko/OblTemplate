#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int cantProd, pesoMax;
int* peso;
int* satisfaccion;
int* categoria;
int cupos[4];
int D1, D2, D3, D4, D5;

int pos(int i, int w, int r0, int r1, int r2, int r3)
{
    return ((((i * D1 + w) * D2 + r0) * D3 + r1) * D4 + r2) * D5 + r3;
}

int main()
{
    cin >> cantProd >> pesoMax;
    cin >> cupos[0] >> cupos[1] >> cupos[2] >> cupos[3];

    peso = new int[cantProd];
    satisfaccion = new int[cantProd];
    categoria = new int[cantProd];

    for (int i = 0; i < cantProd; i++)
    {
        cin >> peso[i] >> satisfaccion[i] >> categoria[i];
    }

    D1 = pesoMax + 1;
    D2 = cupos[0] + 1;
    D3 = cupos[1] + 1;
    D4 = cupos[2] + 1;
    D5 = cupos[3] + 1;


    int* tabla = new int[(cantProd + 1) * D1 * D2 * D3 * D4 * D5]();

    for (int i = cantProd - 1; i >= 0; i--)
    {
        int cat = categoria[i];
        int p = peso[i];
        int s = satisfaccion[i];

        for (int w = 0; w <= pesoMax; w++)
        for (int r0 = 0; r0 <= cupos[0]; r0++)
        for (int r1 = 0; r1 <= cupos[1]; r1++)
        for (int r2 = 0; r2 <= cupos[2]; r2++)
        for (int r3 = 0; r3 <= cupos[3]; r3++)
        {
            int restantes[4] = { r0, r1, r2, r3 };

            int noUso = tabla[pos(i + 1, w, r0, r1, r2, r3)];

            if (p > w || restantes[cat] == 0)
            {
                tabla[pos(i, w, r0, r1, r2, r3)] = noUso;
            }
            else
            {
                restantes[cat]--;
                int uso = s + tabla[pos(i + 1, w - p, restantes[0], restantes[1], restantes[2], restantes[3])];

                tabla[pos(i, w, r0, r1, r2, r3)] = max(uso, noUso);
            }
        }
    }

    cout << tabla[pos(0, pesoMax, cupos[0], cupos[1], cupos[2], cupos[3])];

    delete[] tabla;
    delete[] peso;
    delete[] satisfaccion;
    delete[] categoria;

    return 0;
}
