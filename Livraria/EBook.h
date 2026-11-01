#pragma once 
#include "Livro.h"
#include <string>
using namespace std;

// classe EBook que herda da classe Livro e adiciona atributos específicos de um livro digital
class EBook: public Livro {

    private:
        // atributos específicos da classe EBook
        string formato;
        double tamanhoArquivo;

    public:
        // construtor da classe EBook que chama o construtor da classe base Livro e inicializa os atributos específicos de EBook
        EBook(int id, string titulo, string autor, string genero, int ano, bool lido, Data dataCadastro, string formato, double tamanhoArquivo);

        // consulta os atributos específicos da classe EBook
        string getFormato() const;
        double getTamanhoArquivo() const;

        // modifica os atributos específicos da classe EBook
        void setFormato(string formato);
        void setTamanhoArquivo(double tamanhoArquivo);

        // sobrescreve o método exibirInfo da classe base Livro para exibir informações específicas de EBook
        void exibirInfo() const override;

        string salvarEmLinha() const override;
        string getTipo() const override;

};


