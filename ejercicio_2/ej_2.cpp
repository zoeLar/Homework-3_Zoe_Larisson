#include "ej_2.h"

Punto::Punto(float x, float y) : X(x), Y(y) {}

void Punto::setter_X(float nuevoX) {X= nuevoX;}

void Punto::setter_Y(float nuevoY) {Y= nuevoY;}

float Punto::get_X() const {return X;}

float Punto::get_Y() const {return Y;}

//--------------------------------------
Circulo::Circulo(const Punto& centro, float radio) : centro(centro), radio(radio) {}

void Circulo::setter_Centro(const Punto& nuevoCentro) {centro= nuevoCentro;}

void Circulo::setter_Radio(float nuevoRadio) {radio= nuevoRadio;}

Punto Circulo::get_Centro() const {return centro;}

float Circulo::get_Radio() const {return radio;}

//--------------------------------------

Elipse::Elipse(const Punto& centro, float mayor, float menor) : centro(centro), semiejeMayor(mayor), semiejeMenor(menor) {}

void Elipse::set_Centro(const Punto& nuevoCentro) {centro= nuevoCentro;}

void Elipse::set_SemiejeMay(float SemiejeMayor) {semiejeMayor= SemiejeMayor;}

void Elipse::set_SemiejeMen(float SemiejeMenor) {semiejeMenor= SemiejeMenor;}

Punto Elipse::get_Centro() const {return centro;}

float Elipse::get_SemiejeMay() const {return semiejeMayor;}

float Elipse::get_SemiejeMen() const {return semiejeMenor;}

// --------------------------------------

Rectangulo::Rectangulo(const Punto& vertice, float Ancho, float Largo) : verInfIzquierdo(vertice), ancho(Ancho), largo(Largo) {}

void Rectangulo::set_Vertice(const Punto& nuevoVertice) {verInfIzquierdo= nuevoVertice;}

void Rectangulo::set_Ancho(float nuevoAncho) {ancho= nuevoAncho;}

void Rectangulo::set_Largo(float nuevoLargo) {largo= nuevoLargo;}

Punto Rectangulo::get_Vertice() const {return verInfIzquierdo;}

float Rectangulo::get_Ancho() const {return ancho;}

float Rectangulo::get_Largo() const {return largo;}


float ProcesadorFigura<Punto>::calcularArea(const Punto& punto) {
    return 0.0f;
}

float ProcesadorFigura<Circulo>::calcularArea(const Circulo& circulo) {
    return M_PI * circulo.get_Radio() * circulo.get_Radio();
}

float ProcesadorFigura<Elipse>::calcularArea(const Elipse& elipse) {
    return M_PI * elipse.get_SemiejeMay() * elipse.get_SemiejeMen();
}

float ProcesadorFigura<Rectangulo>::calcularArea(const Rectangulo& rectangulo) {
    return rectangulo.get_Ancho() * rectangulo.get_Largo();
}