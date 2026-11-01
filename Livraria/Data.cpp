#include "Data.h"
#include <string>
#include <stdexcept>
using namespace std;

// inicializa os atributos da classe Data com os valores passados como parâmetros e verifica se a data é valida 
Data::Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {

    if (!validarData()) {
        throw invalid_argument("Data invalida!");
    }
}


// permitem acessar os atributos da classe Data
int Data::getDia() const {
    return dia;
}
int Data::getMes() const{
    return mes;
}
int Data::getAno() const {
    return ano;
}

// converte a data para uma string no formato "dd/mm/aaaa"
string Data::toString() const {
    string diaTexto = to_string(dia);
    string mesTexto = to_string(mes);
    string anoTexto = to_string(ano);

    // adiciona um zero à esquerda se o dia ou o mês for menor que 10
    if (dia < 10) {
        diaTexto = "0" + diaTexto;
    }

    if (mes < 10) {
        mesTexto = "0" + mesTexto;
    }

    return diaTexto + "/" + mesTexto + "/" + anoTexto;

}

// verifica se a data existe 
bool Data::validarData() const {

    // verifica se o mês e o ano são válidos
    if (mes < 1 || mes > 12 || ano < 1) {
        return false;
    }

    // quantidade de dias de cada mês
    int diasMes[] = {31, 28, 31, 30, 31, 30,
                     31, 31, 30, 31, 30, 31};

    // ajusta fevereiro quando o ano é bissexto
    if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)) {
        diasMes[1] = 29;
    }

    // verifica se o dia existe naquele mês
    if (dia < 1 || dia > diasMes[mes - 1]) {
        return false;
    }

    return true;


}
    