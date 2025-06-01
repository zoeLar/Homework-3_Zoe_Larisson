#include "ej_3.h"

int main(){
    class_1 datos({},{},{});
    vector<vector<int>> m_int={{1, 2}, {3,  4}};
    vector<double> v_double ={1.3, 2.1, 3.2};
    vector<string> v_string =  {"Hola", "Mundo"};           
    datos.añadir_datos(m_int);
    datos.añadir_datos(v_double);
    datos.añadir_datos(v_string);
    class_2 a(datos);
    a.formatea_datos();
    a.genera_json();
    a.imprime_datos();
    
    return 0;
}

