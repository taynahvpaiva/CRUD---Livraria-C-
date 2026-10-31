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

//listar os livros cadastrados
void GerenciadorLivros::listarLivros() {
    if (totalLivros == 0) {
        cout <<endl << "Nenhum livro cadastrado!" << endl;
        return;
    }

    for (int i = 0; i < totalLivros; i++) {
        cout << "Livro " << i + 1 << ": " << endl;
        livros[i]->exibirInfo();
    }
}

//atualização dos livros
void GerenciadorLivros::atualizarLivro() {
    string nome;
    cout << "Atualizacao do Livro: " << endl;
    cout << "Digite o titulo: ";
    cin.ignore();
    getline(cin, nome);

    int posicao = Pesquisar(nome);
    if (posicao == -1) {
        return;
    }

    int opcao;
    cout << endl<<"O que deseja atualizar? " << endl;
    cout << "1 - Titulo" << endl;
    cout << "2 - Autor" << endl;
    cout << "3 - Genero" << endl;
    cout << "4 - Ano" << endl;
    cout << "5 - Situacao de leitura" << endl;
    cout << "Escolha uma opcao: ";

    cin >> opcao;
    string texto;
    int numero;

    switch (opcao) {
        case 1:
            cout << "Novo titulo: ";
            cin.ignore();
            getline(cin, texto);
            livros[posicao]->setTitulo(texto);
            break;

        case 2:
            cout << "Novo autor: ";
            cin.ignore();
            getline(cin, texto);
            livros[posicao]->setAutor(texto);
            break;

        case 3:
            cout << "Novo genero: ";
            cin.ignore();
            getline(cin, texto);
            livros[posicao]->setGenero(texto);
            break;

        case 4:
            cout << "Novo ano: ";
            cin >> numero;
            livros[posicao]->setAno(numero);
            break;

        case 5:
            cout << "O livro ja foi lido? (sim/nao): ";
            cin >> texto;
            for (int i = 0; i < texto.length(); i++) {
                texto[i] = tolower(texto[i]);
            }
            livros[posicao]->setLido(texto == "sim");
            break;

        default:
            cout << "Opcao invalida!" << endl;
            return;
    }

    cout << endl<<"Livro atualizado!" << endl;
}

//deletar um livro
void GerenciadorLivros::deletarLivro() {
    string nome;
    cout << endl<<"Deletar um Livro: " << endl;
    cout << "Digite o titulo ou inicio do titulo: ";

    cin.ignore();
    getline(cin, nome);

    int posicao = Pesquisar(nome);
    if (posicao == -1) {
        return;
    }
    delete livros[posicao];

    for (int i = posicao; i < totalLivros - 1; i++) {
        livros[i] = livros[i + 1];
    }

    totalLivros--;
    livros[totalLivros] = NULL;
    cout << endl<<"Livro excluido!" << endl;
}

//resumo da biblioteca
void GerenciadorLivros::exibirResumo() {
    int lidos = 0;
    int pendentes = 0;
    int fisicos = 0;
    int ebooks = 0;

    for (int i = 0; i < totalLivros; i++) {
        if (livros[i]->isLido()) {
            lidos++;
        }
        else {
            pendentes++;
        }

        if (livros[i]->getTipo() == "FISICO") {
            fisicos++;
        }
        else if (livros[i]->getTipo() == "EBOOK") {
            ebooks++;
        }
    }

    double percentual = 0;
    if (totalLivros > 0) {
        percentual = (100.0 * lidos) / totalLivros;
    }

    cout <<endl<< "Resumo da biblioteca: " << endl;
    cout << "Total de livros: " << totalLivros << endl;
    cout << "Livros lidos: " << lidos << endl;
    cout << "Livros pendentes: " << pendentes << endl;
    cout << "Leitura concluida: " << percentual << "%" << endl;
    cout << "Livros fisicos: " << fisicos << endl;
    cout << "EBooks: " << ebooks << endl;
}

