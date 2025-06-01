#include "ej_3.h"

class_1::class_1(vector<vector<string>> matriz, vector<string> vector_d, vector<string> vec_s):
matriz_int(matriz),vec_doubles(vector_d), vec_string(vec_s){};



class_2::class_2(class_1 & obj): data(obj),str(""){}

void class_2::formatea_datos() {
        string resultado = "{";
        
        resultado+= " \"vec_doubles\": [";
        for (size_t i= 0; i < data.vec_doubles.size(); ++i) {
            if (i > 0) 
                resultado+= ", ";
            resultado+= data.vec_doubles[i];  
        }
        resultado+= "],\n";
        
       
        resultado+= "  \"palabras\":[";
        for (size_t i= 0; i < data.vec_string.size(); ++i) {
            if (i > 0) resultado+= ", ";
            resultado+= "\"" + data.vec_string[i] + "\""; 
        }
        resultado+= "],\n";
        
        resultado+= "   \"listas\":[\n";
        for (size_t i= 0; i < data.matriz_int.size(); ++i) {
            resultado+= "   [";
            for (size_t j = 0; j < data.matriz_int[i].size(); ++j) {
                if (j > 0) resultado+= ", ";
                resultado+= data.matriz_int[i][j];  // Sin comillas
            }
            resultado+= "]";
            if (i < data.matriz_int.size() - 1) resultado += ",";
            resultado+= "\n";
        }
        resultado+= "  ]\n}";
        
        str = resultado;  
}
void class_2::genera_json() {
        ofstream archivo("datos.json"); 
        if (archivo.is_open()) {
            archivo<< str;  
            archivo.close();
        } else {
            cerr << "Error al abrir el archivo." << endl;
        }
}
void class_2::imprime_datos(){
    cout<< str;
}

