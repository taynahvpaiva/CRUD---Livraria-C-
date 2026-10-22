#pragma once 
#include <string> 
using namespace std;

class Data {
    
    private: 
        int dia, mes, ano;

    public:
        Data(int dia = 1, int mes = 1, int ano = 2026);

        getDia() const;
        getMes() const;
        getAno() const;

        string toString() const;

};