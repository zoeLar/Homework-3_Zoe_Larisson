#pragma once 

#include <iostream>
#include <memory>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class class_1{
    public:
        vector<vector<string>> matriz_int;
        vector<string> vec_doubles;
        vector<string> vec_string;
        
        class_1(vector<vector<string>> matriz={{}}, vector<string> vector_d={}, vector<string> vec_s={});
        
        template<typename T>
        void añadir_datos(const vector<T>& data){
            if constexpr (is_same_v<T, double>) {
                for( int i=0; i<data.size(); i++){
                    vec_doubles.push_back(to_string(data[i]));
                }
            }

            else if constexpr (is_same_v<T, vector<int>>) {
                for (int i=0; i<data.size(); i++){
                    vector<string> temp_vec;
                    temp_vec.push_back(to_string(data[i][0]));
                    temp_vec.push_back(to_string(data[i][1]));
                    matriz_int.push_back(temp_vec);
                }
            }

            else if constexpr (is_same_v<T, string>) {
                for (const auto& str : data) {  // Recorre cada string en el vector
                    vec_string.push_back(str);  // Añade cada string individualmente
                }
        }
    }
};
class class_2{
    private:
        string str;
        class_1 data;
    public:
        class_2(class_1 & obj);
        void formatea_datos();
        void genera_json();
        void imprime_datos();
};

//Para clasificar los datos se considero que la manera mas directa era
//utilizar un objeto de la clase 1, y en la clase 2 se ponen los datos en el formato correcto
//y se imprimen y muestran en el json
