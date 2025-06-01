#include "ej_2.h"

int main() {
    Punto punto(1.0, 1.0);
    Circulo circulo(punto, 3.0);
    Elipse elipse(punto, 4.0, 2.0);
    Rectangulo rect(punto, 5.0, 3.0);

    cout << "Area del punto: " << ProcesadorFigura<Punto>::calcularArea(punto) <<endl<<
    "Area del circulo: " << ProcesadorFigura<Circulo>::calcularArea(circulo) << endl<<
    "Area de la elipse: " << ProcesadorFigura<Elipse>::calcularArea(elipse) << endl<<
    "Area del rectangulo: " << ProcesadorFigura<Rectangulo>::calcularArea(rect) <<endl;

    return 0;
}