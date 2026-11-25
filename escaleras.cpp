#include <iostream>
#include <vector>

using namespace std;

// calcula de cuantas formas se puede subir hasta el escalon n usando DP
void resolverEscaleras(int n) {
    // uso long long porque con numeros grandes de escalones un int se desborda rapido
    vector<long long> dp(n + 1, 0);

    //casos base: 1 forma de quedarse en el 0 y 1 forma de llegar al primer escalon
    dp[0] = 1;
    if (n >= 1) {
        dp[1] = 1;
    }

    // llenamos la tabla sumando las dos posiciones anteriores (paso de 1 o paso de 2)
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // imprimimos la respuesta final
    cout << "\nFormas posibles: " << dp[n] << "\n";
}

int main() {
    int n;

    cout << "Ingresa el numero de escalones (N >= 0): ";
    cin >> n;

    // evitamos que el usuario meta numeros negativos
    if (n < 0) {
        cout << "Error: el numero de escalones no puede ser negativo.\n";
        return 1;
    }

    resolverEscaleras(n);
    return 0;
}