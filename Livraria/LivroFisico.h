#pragma once 
#include "Livro.h"
#include <string>
using namespace std;

// classe que representa um livro físico, derivada da classe Livro
class LivroFisico: public Livro{

    private:
        int numPaginas;
        string editora;

    public:
        // construtor da classe LivroFisico, que chama o construtor da classe base Livro e inicializa os atributos específicos de LivroFisico
        LivroFisico(int id, string titulo, string autor, string genero, int ano, bool lido, Data dataCadastro, int numPaginas, string editora);

        int getNumPaginas() const;
        string getEditora() const;

        void setNumPaginas(int numPaginas);
        void setEditora(string editora);

        // metodos sobrescritos da classe base Livro
        void exibirInfo() const override;

        string salvarEmLinha() const override;
        string getTipo() const override;
};