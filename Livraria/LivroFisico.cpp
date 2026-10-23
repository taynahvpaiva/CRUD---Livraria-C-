#include "LivroFisico.h""
#include <iostream>
#include <string>
using namespace std;

LivroFisico::LivroFisico(int id, string titulo, string autor, string genero, int ano, bool lido, Data dataCadastro, int numPaginas, string editora)
    : Livro(id, titulo, autor, genero, ano, lido, dataCadastro), numPaginas(numPaginas), editora(editora) {}
    numPaginas(numPaginas), editora(editora) {}

int LivroFisico::getNumPaginas() const {
    return numPaginas;
}

void LivroFisico::setNumPaginas(int numPaginas) {
    this->numPaginas = numPaginas;
}

void LivroFisico::exibirInfo() const {
    Livro::exibirInfo();
    std::cout << "Número de Páginas: " << numPaginas << std::endl;
    std::cout << "Editora: " << editora << std::endl;
}

string LivroFisico::salvarEmLinha() const {
    ostringstream linha;

    linha << "FISICO; "
          << getId() << "; "
          << getTitulo() << "; "
          << getAutor() << "; "
          << getGenero() << "; "
          << getAno() << "; "
          << isLido() << "; "
          << getDataCadastro().getDia() << "; "
          << getDataCadastro().getMes() << "; "
          << getDataCadastro().getAno() << "; "
          << numPaginas;

    return linha.str();
}

string LivroFisico::getTipo() const {
    return "FISICO";
}
