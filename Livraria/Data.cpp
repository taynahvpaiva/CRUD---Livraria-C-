#include "Data.h"
#include <string>
using namespace std;

Data::Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {
    int dia = dia;
    int mes = mes;
    int ano = ano;
}

int Data::getDia() const {
    return dia;
}
int Data::getMes() const{
    return mes;
}
int Data::gestAno() const {
    return ano;
}

string Data::toString() const {
    string diaTexto = to_string(dia);
    string mesTexto = to_string(mes);
    string anoTexto = to_string(ano);

    if (dia < 10) {
        diaTexto = "0" + diaTexto;
    }

    if (mes < 10) {
        mesTexto = "0" + mesTexto;
    }

    return diaTexto + "/" + mesTexto + "/" + anoTexto;
}
    