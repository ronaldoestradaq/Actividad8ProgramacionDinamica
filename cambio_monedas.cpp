#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// valor grande para representar que un monto todavia no se puede formar
const int INF = 1e9;

// busca el minimo de monedas para llegar al monto usando DP
void cambioMinimoMonedas(const vector<int>& monedas, int monto) {
    // dp[i] guarda el minimo de monedas para el monto i; arranca en INF
    vector<int> dp(monto + 1, INF);

    // caso base: para monto 0 no hace falta ninguna moneda
    dp[0] = 0;

    // vamos resolviendo monto por monto desde 1 hasta llegar al objetivo
    for (int i = 1; i <= monto; i++) {
        for (int c : monedas) {
            // solo probamos la moneda si no se pasa del monto actual y el resto tiene solucion
            if (i >= c && dp[i - c] != INF) {
                // si usar esta moneda mejora lo que ya teniamos, actualizamos
                if (dp[i - c] + 1 < dp[i]) {
                    dp[i] = dp[i - c] + 1;
                }
            }
        }
    }

    // si quedo en INF significa que no hubo forma de armar ese monto
    if (dp[monto] == INF) {
        cout << "\nNo es posible formar la cantidad " << monto << " con las monedas dadas.\n";
    } else {
        cout << "\nCantidad minima de monedas: " << dp[monto] << "\n";
    }

    // mostramos la tabla DP completa
    cout << "Tabla DP:\n[";
    for (int i = 0; i <= monto; i++) {
        if (dp[i] == INF) {
            cout << "INF";
        } else {
            cout << dp[i];
        }
        if (i < monto) cout << ", ";
    }
    cout << "]\n";
}

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

    cambioMinimoMonedas(monedas, monto);
    return 0;
}