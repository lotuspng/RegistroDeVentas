// Este sistema recibe la cantidad resultante de cada semana, apunta a los dias que mas se gano y el promedio


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Constante global para el numero de dias de la semana
const int DIAS = 7;

int main() {
    // Arreglos unidimensionales para los dias y las ventas diarias
    string nombresDias[DIAS] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo" };
    double ventas[DIAS];

    double total = 0.0;
    double promedio = 0.0;
    int diasSobrePromedio = 0;

    for (int i = 0; i < DIAS; i++) {
        do {
            cout << "Ventas del " << nombresDias[i] << ": RD$ ";
            cin >> ventas[i];
            if (ventas[i] < 0) {
                cout << "Error: la venta no puede ser negativa. Intente de nuevo." << endl;
            }
        } while (ventas[i] < 0);

        total += ventas[i];
    }

    promedio = total / DIAS;

    // Buscar mayor y menor venta y contar dias que superan el promedio
    double mayorVenta = ventas[0];
    double menorVenta = ventas[0];
    int indiceMayor = 0;
    int indiceMenor = 0;

    for (int i = 0; i < DIAS; i++) {
        if (ventas[i] > mayorVenta) {
            mayorVenta = ventas[i];
            indiceMayor = i;
        }
        if (ventas[i] < menorVenta) {
            menorVenta = ventas[i];
            indiceMenor = i;
        }
        if (ventas[i] > promedio) {
            diasSobrePromedio++;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\n===== VENTAS DEL COLMADO DON PEPE =====" << endl;

    for (int i = 0; i < DIAS; i++) {
        cout << nombresDias[i] << ": RD$ " << ventas[i] << endl;
    }

    cout << "\nTotal semanal: RD$ " << total << endl;
    cout << "Promedio diario: RD$ " << promedio << endl;
    cout << "Mayor venta: " << nombresDias[indiceMayor] << " (RD$ " << mayorVenta << ")" << endl;
    cout << "Menor venta: " << nombresDias[indiceMenor] << " (RD$ " << menorVenta << ")" << endl;
    cout << "Dias sobre el promedio: " << diasSobrePromedio << " -> ";

    // Mostrar los nombres de los dias que superaron el promedio
    bool primero = true;
    for (int i = 0; i < DIAS; i++) {
        if (ventas[i] > promedio) {
            if (!primero) {
                cout << ", ";
            }
            cout << nombresDias[i];
            primero = false;
        }
    }
    if (primero) {
        cout << "Ninguno";
    }
    cout << endl;

    return 0;
}