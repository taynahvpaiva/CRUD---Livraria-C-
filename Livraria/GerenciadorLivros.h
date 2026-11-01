#pragma once
#include "Livro.h"
#include <string>
using namespace std;

class GerenciadorLivros {
private:
    Livro* livros[100];
    int totalLivros;
    int proximoId;
    string nomeArquivo;

public:
    GerenciadorLivros();

    int Pesquisar(string nome);

    void cadastrarLivro();
    void listarLivros();
    void exibirLivro();
    void atualizarLivro();
    void deletarLivro();
    void exibirResumo();
    void salvarEmArquivo();
    void carregarDoArquivo();
    void exibirMenu();
    bool processarMenu();

    ~GerenciadorLivros();
};