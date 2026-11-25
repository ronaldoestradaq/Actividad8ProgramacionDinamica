#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cout << "Ingresa el numero de escalones (N >= 0): ";
    cin >> n;

    // Evitamos que el usuario meta numeros negativos
    if (n < 0) {
        cout << "Error: el numero de escalones no puede ser negativo.\n";
        return 1;
    }

    return 0;
}