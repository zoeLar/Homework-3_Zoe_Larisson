
#include"ej_1.h"

MedicionBase::MedicionBase(const MedicionBase& MedB){
    if (MedB.tiempoMedicion){ //si el puntero no es nullptr
        tiempoMedicion = make_unique<float>(*MedB.tiempoMedicion);
    }
}

float MedicionBase::getTiempo(){
    return *tiempoMedicion;
}

void MedicionBase::serializar(ofstream & out){
    out.write(reinterpret_cast<const char*>(& (*tiempoMedicion)),sizeof(getTiempo())); 
}

void MedicionBase::desserializar(ifstream & in){
    float tiempoM;
    in.read(reinterpret_cast<char *>(&tiempoM),sizeof(tiempoM));

    if(!in.good()){
        cout<< "Ha fallado la deserealizacion"<<endl;
        return;
    }

    tiempoMedicion=make_unique<float>(tiempoM);
}

//--------------------------------------------------------

Presion::Presion(float p, float q,float t): presionEstatica(p),presionDinamica(q){
    tiempoMedicion=make_unique<float>(t);
}

Presion::Presion(const Presion & p):
MedicionBase(p),presionDinamica(p.presionDinamica),presionEstatica(p.presionEstatica){} 

void Presion::serializar(ofstream & out){
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(& (presionEstatica)),sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(& (presionDinamica)),sizeof(presionDinamica));

}

void Presion::desserializar(ifstream & in){
    MedicionBase::desserializar(in);
    in.read(reinterpret_cast<char*>(& (presionEstatica)),sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(& (presionDinamica)),sizeof(presionDinamica));
}

void Presion::imprimir(){
    cout<< "-----------------------------------------"<<endl<<
    "Presion estatica: "<<presionEstatica<<endl<<
    "Presion dinamica: "<<presionDinamica <<endl<<
    "Tiempo de la medicion: "<< getTiempo() <<endl<<
    "-----------------------------------------"<<endl;
}

//---------------------------------------------------------


Posicion::Posicion(float lat, float lon,float alt, float t): 
    latitud(lat),longitud(lon),altitud(alt) { tiempoMedicion=make_unique<float>(t);
}

Posicion::Posicion(const Posicion & p):
MedicionBase(p),latitud(p.latitud),longitud(p.longitud),altitud(p.altitud){} 

void Posicion::serializar(ofstream & out){
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(& (latitud)),sizeof(latitud));
    out.write(reinterpret_cast<const char*>(& (longitud)),sizeof(longitud));
    out.write(reinterpret_cast<const char*>(& (altitud)),sizeof(altitud));
}

void Posicion::desserializar(ifstream & in){
    MedicionBase::desserializar(in);
    in.read(reinterpret_cast<char*>(& (latitud)),sizeof(latitud));
    in.read(reinterpret_cast<char*>(& (longitud)),sizeof(longitud));
    in.read(reinterpret_cast<char*>(& (altitud)),sizeof(altitud));
}

void Posicion::imprimir(){
    cout<< "-----------------------------------------"<<endl<<
    "latitud: "<<latitud<<endl<<
    "longitud: "<<longitud <<endl<<
    "Altitud: "<<altitud<<endl<<
    "Tiempo de la medicion: "<< getTiempo() <<endl<<
    "-----------------------------------------"<<endl;
}



//----------------------------------------------------------

SaveFlightData::SaveFlightData(const Posicion& p, const Presion & q): 
posicion(Posicion(p)), presion(Presion(q)){}

void SaveFlightData::serializar(ofstream & out){
 posicion.serializar(out);
 presion.serializar(out);
}

void SaveFlightData::desserializar(ifstream & in){
 posicion.desserializar(in);
 presion.desserializar(in);
}

void SaveFlightData::imprimir(){
    cout<<"Posicion: "<<endl;
    posicion.imprimir();
    cout<<"Presion: "<<endl;
    presion.imprimir();
}


//-------------------------------------------------------------