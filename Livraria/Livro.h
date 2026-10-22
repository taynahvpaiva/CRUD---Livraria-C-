#pragma once
#include <string> 
#include "Data.h"
using namespace std;

class Livro {

    private:
        int id, ano;
        string titulo, autor, genero;
        bool lido;
        Data dataCadastro;

    public:
        Livro(int id, string titulo, string autor, string genero, int ano, bool lido, Data dataCadastro);

        virtual ~Livro();

        int getId() const;
        string getTitulo() const;
        string getAutor() const;
        string getGenero() const;
        int getAno() const;
        bool isLido() const;
        Data getDataCadastro() const;

        void setId(int id);
        void setTitulo(string titulo);
        void setAutor(string autor);
        void setGenero(string genero);
        void setAno(int ano);
        void setLido(bool lido);
        void setDataCadastro(Data dataCadastro);


        virtual void exibirInfo() const;

        virtual string salvarEmLinha() const = 0;
        virtual string getTipo() const = 0;

};