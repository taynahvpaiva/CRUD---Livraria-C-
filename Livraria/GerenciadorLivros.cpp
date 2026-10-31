#include "GerenciadorLivros.h"
#include "Livro.h"
#include "LivroFisico.h"
#include "EBook.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

//construtor
GerenciadorLivros::GerenciadorLivros() {
    totalLivros = 0;
    proximoId = 1;
    nomeArquivo = "biblioteca.txt";

    for (int i = 0; i < 100; i++) {
        livros[i] = NULL; //permite as posições do vetor começarem vazias
    }

    carregarDoArquivo();
}

//destrutor
GerenciadorLivros::~GerenciadorLivros() {
    salvarEmArquivo();

    for (int i = 0; i < totalLivros; i++) {
        delete livros[i];
    }
}

//pesquisar
int GerenciadorLivros::Pesquisar(string nome) {

    int encontrados = 0;
    int posicoes[100];

    for (int i = 0; i < totalLivros; i++) {
        string titulo = livros[i]->getTitulo();

        if (titulo.find(nome) == 0) {
            posicoes[encontrados] = i;
            encontrados++;
        }
    }

    if (encontrados == 0) {
        cout << "Nenhum livro encontrado!" << endl;
        return -1;
    }

    if (encontrados == 1) {
        return posicoes[0];
    }

    cout << endl << "Livros encontrados:" << endl;

    for (int i = 0; i < encontrados; i++) {
        int posicao = posicoes[i];

        cout << i + 1 << " - "
             << livros[posicao]->getTitulo() << endl;
    }

    int escolha;

    cout << "Escolha o livro: ";
    cin >> escolha;

    if (escolha < 1 || escolha > encontrados) {
        cout << "Opcao invalida!" << endl;
        return -1;
    }

    return posicoes[escolha - 1];
}

//cadastro livro fisico ou ebook
void GerenciadorLivros::cadastrarLivro() {

    int tipo;

    cout << endl << "Cadastrar Livro:" << endl;
    cout << "1 - Livro fisico" << endl;
    cout << "2 - EBook" << endl;
    cout << "Escolha o tipo de livro: ";
    cin >> tipo;

    if (tipo != 1 && tipo != 2) {
        cout << "Tipo invalido!" << endl;
        return;
    }

    string titulo, autor, genero;
    int ano;
    cin.ignore();

    cout << "Titulo: ";
    getline(cin, titulo);

    cout << "Autor: ";
    getline(cin, autor);

    cout << "Genero: ";
    getline(cin, genero);

    cout << "Ano de publicacao: ";
    cin >> ano;

    string resposta;
    cout << "O livro ja foi lido? (sim/nao): ";
    cin >> resposta;
    for (int i = 0; i < resposta.length(); i++) {
        resposta[i] = tolower(resposta[i]);
    }
    bool lido = (resposta == "sim");

}

