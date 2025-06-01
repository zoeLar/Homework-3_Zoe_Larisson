#pragma once 

#include <iostream>
#include <memory>
#include <fstream>
#include <iostream>


using namespace std;


class mediciones{
    public:
        virtual void serializar(ofstream & out)=0;
        virtual void desserializar(ifstream & in)=0;
};

class MedicionBase: public mediciones{
    protected:
        unique_ptr<float> tiempoMedicion;
        MedicionBase(){};
        ~MedicionBase(){};
        MedicionBase(const MedicionBase& other);
    
    public:
        virtual void imprimir()=0; 
        float getTiempo(); 
        void serializar(ofstream & out) override;
        void desserializar(ifstream & in) override;  
};

class Presion: protected MedicionBase{
    public:
        float presionEstatica;
        float presionDinamica;

        void serializar(ofstream & out);
        void desserializar(ifstream & in);
        
        Presion(float p=0, float q=0,float t=0);
        //hace un deep copy de p (constructor de cpira)
        Presion(const Presion & p);
        ~Presion(){};
        
        void imprimir() override;
};
class Posicion: protected MedicionBase{
    public:
        float latitud;
        float longitud;
        float altitud;

        void serializar(ofstream & out);
        void desserializar(ifstream & in);

        Posicion(float lat=0, float lon=0,float alt=0, float t=0);
        Posicion(const Posicion & p);

        ~Posicion(){};


        void imprimir() override;
};

class SaveFlightData{
    public:
        Posicion posicion; 
        Presion presion;
            
        SaveFlightData(const Posicion& p, const Presion & q); 
        SaveFlightData(){};
        void serializar(ofstream & out);
        void desserializar(ifstream & in);
        void imprimir();
};

