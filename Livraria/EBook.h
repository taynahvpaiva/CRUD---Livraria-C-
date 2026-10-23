#pragma once 
#include "Livro.h"
#include <string>
using namespace std;

class EBook: public Livro {

    private:
        string formato;
        double tamanhoArquivo;

    public:
        EBook(int id, string titulo, string autor, string genero, int ano, bool lido, Data dataCadastro, string formato, double tamanhoArquivo);

        string getFormato() const;
        double getTamanhoArquivo() const;

        void setFormato(string formato);
        void setTamanhoArquivo(double tamanhoArquivo);

        void exibirInfo() const override;

        string salvarEmLinha() const override;
        string getTipo() const override;

};


