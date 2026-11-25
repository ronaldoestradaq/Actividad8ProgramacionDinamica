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

    // aca guardo que moneda funciono mejor en cada monto para armar la combinacion al final
    vector<int> monedaUsada(monto + 1, -1);

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
                    monedaUsada[i] = c;
                }
            }
        }
    }

    // si quedo en INF significa que no hubo forma de armar ese monto
    if (dp[monto] == INF) {
        cout << "\nNo es posible formar la cantidad " << monto << " con las monedas dadas.\n";
    } else {
        cout << "\nCantidad minima de monedas: " << dp[monto] << "\n";

        // retrocedemos desde el monto objetivo hasta 0 para ver que monedas se usaron
        vector<int> combinacion;
        int actual = monto;
        while (actual > 0) {
            int c = monedaUsada[actual];
            combinacion.push_back(c);
            actual -= c;
        }

        // ordeno de mayor a menor para que la salida se vea mas limpia
        sort(combinacion.rbegin(), combinacion.rend());

        cout << "combinacion: ";
        for (size_t i = 0; i < combinacion.size(); i++) {
            cout << combinacion[i];
            if (i + 1 < combinacion.size()) cout << " + ";
        }
        cout << "\n";
    }

    // Mostramos la tabla DP completa
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
    cout << "Ingresa las " << k << " denominaciones separadas por espacio: ";
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