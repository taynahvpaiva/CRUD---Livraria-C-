#include <string> 
#include "EBook.h"
#include <iostream>
using namespace std;

EBook::EBook(int id, string titulo, string autor, string genero, int ano, bool lido, Data dataCadastro, string formato, double tamanhoArquivo)
    : Livro(id, titulo, autor, genero, ano, lido, dataCadastro), formato(formato), tamanhoArquivo(tamanhoArquivo) {}

string EBook::getFormato() const {
    return formato;
}

double EBook::getTamanhoArquivo() const {
    return tamanhoArquivo;
}

void EBook::setFormato(string formato) {
    this->formato = formato;
}

void EBook::setTamanhoArquivo(double tamanhoArquivo) {
    this->tamanhoArquivo = tamanhoArquivo;
}

void EBook::exibirInfo() const {
    Livro::exibirInfo();
    cout << "Formato: " << formato << std::endl;
    cout << "Tamanho do Arquivo: " << tamanhoArquivo << " MB" << std::endl;
}

string EBook::salvarEmLinha() const {
    ostringstream linha;

    linha << "EBOOK; "
          << getId() << "; "
          << getTitulo() << "; "
          << getAutor() << "; "
          << getGenero() << "; "
          << getAno() << "; "
          << isLido() << "; "
          << getDataCadastro().getDia() << "; "
          << getDataCadastro().getMes() << "; "
          << getDataCadastro().getAno() << "; "
          << formato << "; "
          << tamanhoArquivo;

    return linha.str();
}

string EBook::getTipo() const {
    return "EBOOK";
}


