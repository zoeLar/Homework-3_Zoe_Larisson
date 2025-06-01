#pragma once 

#include <iostream>
#include <memory>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

class Punto {
    private:
        float X;
        float Y;

    public:
        Punto(float x, float y);

        void setter_X(float nuevoX);
        void setter_Y(float nuevoY);

        float get_X() const;
        float get_Y() const;
};
class Circulo {
    private:
        Punto centro;
        float radio;

    public:
        Circulo(const Punto& centro, float radio );

        void setter_Centro(const Punto& nuevoCentro);
        void setter_Radio(float nuevoRadio);

        
        Punto get_Centro() const;
        float get_Radio() const;
};

class Elipse {
    private:
        Punto centro;
        float semiejeMayor;
        float semiejeMenor;

    public:
        Elipse(const Punto& Centro, float mayor, float menor);

        void set_Centro(const Punto& nuevoCentro);
        void set_SemiejeMay(float SemiejeMayor);
        void set_SemiejeMen(float SemiejeMenor);

        Punto get_Centro() const;
        float get_SemiejeMay() const;
        float get_SemiejeMen() const;
};
class Rectangulo {
    private:
        Punto verInfIzquierdo;
        float ancho;
        float largo;

    public:
        Rectangulo(const Punto& vertice, float Ancho, float Largo);

        
        void set_Vertice(const Punto& nuevoVertice);
        void set_Ancho(float nuevoAncho);
        void set_Largo(float nuevoLargo);

        Punto get_Vertice() const;
        float get_Ancho() const;
        float get_Largo() const;
};

template<typename T>
class ProcesadorFigura;

//especializo la clase para punto:
template<>
class ProcesadorFigura<Punto> {
    public:
        static float calcularArea(const Punto& punto) ;
};

//especializo la clase para circulo
template<>
class ProcesadorFigura<Circulo> {
    public:
        static float calcularArea(const Circulo& circulo);
};

//especializo la clase para elipse
template<>
class ProcesadorFigura<Elipse> {
    public:
        static float calcularArea(const Elipse& elipse);
};

//especializo la clase para rectangulo
template<>
class ProcesadorFigura<Rectangulo> {
    public:
        static float calcularArea(const Rectangulo& rectangulo);
};



