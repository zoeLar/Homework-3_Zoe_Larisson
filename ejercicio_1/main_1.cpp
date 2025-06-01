#include "ej_1.h"

int main(){
    Posicion pos1(-34.6f, -58.4f, 950.0f, 5.3f), pos2;
    Presion pres1(101.3f, 5.8f, 6.1f),pres2;

    ofstream out("test_ej1.txt",ios::binary);
    cout<<"Primero se serializan pos1 y pres1 con los valores dados por la consigna"<<endl;
    pos1.imprimir();
    pres1.imprimir();

    if(out.is_open()){
        pos1.serializar(out);
        pres1.serializar(out);
         out.close();
    }

   
    //------------------------
    ifstream in("test_ej1.txt",ios::binary);

    cout<<"Luego de ello se desserealizan los valores en pos2 y pres2"<<endl<<
    "Primero se muestran los valores antes de la des serealizacion (se decidio usar valores default en vez de otro constructor sin parametros)"<<endl;
    pos2.imprimir();
    pres2.imprimir();

    if(in.is_open()){
        pos2.desserializar(in);
        pres2.desserializar(in);
        in.close();
    }
    cout<<"Ahora se ve el resultado final de la des serealizacion:"<<endl<<"Pos2: "<<endl;
    pos2.imprimir();
    cout<<"pres2"<<endl;
    pres2.imprimir();
    
    cout<<"Ahora se probaran las funciones de save flight data"<<endl<<
    "1)Se crea utilizando a pos2 y pres2. Y se serializa"<<endl;

    SaveFlightData FlightD1(pos2,pres2),FlightD2;
    FlightD1.imprimir();

    //------------------------

    ofstream out2("test_ej1.txt",ios::binary);

    if(out2.is_open())
       FlightD1.serializar(out2);
    
    out2.close();

    //------------------------
    cout<<"2) Se deserealiza"<<endl;

    ifstream in2("test_ej1.txt",ios::binary);


    if(in2.is_open())
        FlightD2.desserializar(in2);

    FlightD2.imprimir();
    in2.close();

    return 0;
}
