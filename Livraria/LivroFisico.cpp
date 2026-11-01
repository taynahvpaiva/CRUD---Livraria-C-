#include "LivroFisico.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// inicializa os atributos da classe LivroFisico chamando o construtor da classe base Livro e inicializando os atributos específicos de LivroFisico
LivroFisico::LivroFisico(int id, string titulo, string autor, string genero, int ano, bool lido, Data dataCadastro, int numPaginas, string editora)
    : Livro(id, titulo, autor, genero, ano, lido, dataCadastro), numPaginas(numPaginas), editora(editora) {}

// métodos getters e setters para os atributos específicos de LivroFisico
int LivroFisico::getNumPaginas() const {
    return numPaginas;
}

string LivroFisico::getEditora() const {
    return editora;
}

void LivroFisico::setNumPaginas(int numPaginas) {
    this->numPaginas = numPaginas;
}

void LivroFisico::setEditora(string editora) {
    this->editora = editora;
}

void LivroFisico::exibirInfo() const {
    Livro::exibirInfo();
    std::cout << "Número de Páginas: " << numPaginas << std::endl;
    std::cout << "Editora: " << editora << std::endl;
}

// organiza os atributos do livro físico em uma linha de texto para salvar em arquivo
string LivroFisico::salvarEmLinha() const {
    ostringstream linha;

    linha << "FISICO; "
          << getId() << ";"
          << getTitulo() << ";"
          << getAutor() << ";"
          << getGenero() << ";"
          << getAno() << ";"
          << isLido() << ";"
          << getDataCadastro().getDia() << ";"
          << getDataCadastro().getMes() << ";"
          << getDataCadastro().getAno() << ";"
          << numPaginas << ";"
          << editora;

    return linha.str();
}

// indentifica o tipo do livro como "FISICO" para diferenciar de outros tipos de livros
string LivroFisico::getTipo() const {
    return "FISICO";
}
