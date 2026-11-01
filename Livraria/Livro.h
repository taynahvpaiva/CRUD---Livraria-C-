#pragma once
#include <string> 
#include "Data.h"
using namespace std;

// classe base para os diferentes tipos de livros
class Livro {

    private:
        int id, ano;
        string titulo, autor, genero;
        bool lido;
        Data dataCadastro;

    public:
        Livro(int id, string titulo, string autor, string genero, int ano, bool lido, Data dataCadastro);

        // destrutor virtual para permitir a destruição correta de objetos derivados
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

        // metodo virtual para exibir informações do livro, que pode ser sobrescrito por classes derivadas
        virtual void exibirInfo() const;

        // metodos virtuais puros para salvar os dados do livro em uma linha e obter o tipo do livro, que devem ser implementados por classes derivadas
        virtual string salvarEmLinha() const = 0;
        virtual string getTipo() const = 0;

};