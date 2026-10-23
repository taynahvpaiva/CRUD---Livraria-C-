#pragma once 
#include "Livro.h"

class LivroFisico: public Livro{

    private:
        int numPaginas;
        string editora;

    public:
        LivroFisico(int id, string titulo, string autor, string genero, int ano, bool lido, Data dataCadastro, int numPaginas, string editora);

        int getNumPaginas() const;
        string getEditora() const;

        void setNumPaginas(int numPaginas);
        void setEditora(string editora);

        void exibirInfo() const override;

        string salvarEmLinha() const override;
        string getTipo() const override;
}