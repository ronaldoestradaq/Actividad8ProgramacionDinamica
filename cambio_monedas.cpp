#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// valor grande para representar que un monto todavia no se puede formar
const int INF = 1e9;

int main() {
    int k, monto;

    cout << "Ingresa la cantidad de denominaciones de monedas: ";
    cin >> k;

    if (k <= 0) {
        cout << "Error: debe ingresar al menos una moneda.\n";
        return 1;
    }

    // leemos las monedas y validamos que sean positivas
    vector<int> monedas(k);
    cout << "Ingrese las " << k << " denominaciones separadas por espacio: ";
    for (int i = 0; i < k; i++) {
        cin >> monedas[i];
        if (monedas[i] <= 0) {
            cout << "Error: las denominaciones deben ser mayores a 0.\n";
            return 1;
        }
    }

    cout << "Ingresa la cantidad objetivo: ";
    cin >> monto;

    if (monto < 0) {
        cout << "Error: la cantidad objetivo no puede ser negativa.\n";
        return 1;
    }

    return 0;
}