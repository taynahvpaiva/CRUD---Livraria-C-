#pragma once 
#include <string> 
using namespace std;

class Data {
    
    private: 
        // atributos da classe Data
        int dia, mes, ano;

    public:
        // construtor da classe Data com valores padrão para dia, mês e ano
        Data(int dia = 1, int mes = 1, int ano = 2026);

        // metodos para acessar os atributos da classe Data
        int getDia() const;
        int getMes() const;
        int getAno() const;

        // retorna a data no formato de texto 
        string toString() const;

        // verifica se a data é valida 
        bool validarData() const;

};