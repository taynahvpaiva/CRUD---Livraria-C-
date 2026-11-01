#include <string> 
#include "EBook.h"
#include <iostream>
#include <sstream>
using namespace std;

// inicializa os atributos da classe EBook chamando o construtor da classe base Livro e inicializando os atributos específicos de EBook
EBook::EBook(int id, string titulo, string autor, string genero, int ano, bool lido, Data dataCadastro, string formato, double tamanhoArquivo)
    : Livro(id, titulo, autor, genero, ano, lido, dataCadastro), formato(formato), tamanhoArquivo(tamanhoArquivo) {}

// permitem acessar os atributos da classe EBook
string EBook::getFormato() const {
    return formato;
}

double EBook::getTamanhoArquivo() const {
    return tamanhoArquivo;
}

// permitem modificar os atributos da classe EBook
void EBook::setFormato(string formato) {
    this->formato = formato;
}

void EBook::setTamanhoArquivo(double tamanhoArquivo) {
    this->tamanhoArquivo = tamanhoArquivo;
}

// sobrescreve o método exibirInfo da classe base Livro para exibir informações específicas de EBook
void EBook::exibirInfo() const {
    Livro::exibirInfo();
    cout << "Formato: " << formato << std::endl;
    cout << "Tamanho do Arquivo: " << tamanhoArquivo << " MB" << std::endl;
}

// convertem os dados do objeto EBook em uma string no formato de linha para salvar em arquivo
string EBook::salvarEmLinha() const {
    ostringstream linha;

    linha << "EBOOK; "
          << getId() << ";"
          << getTitulo() << ";"
          << getAutor() << ";"
          << getGenero() << ";"
          << getAno() << ";"
          << isLido() << ";"
          << getDataCadastro().getDia() << ";"
          << getDataCadastro().getMes() << ";"
          << getDataCadastro().getAno() << ";"
          << formato << "; "
          << tamanhoArquivo;

    return linha.str();
}

// retorna o tipo do livro como uma string
string EBook::getTipo() const {
    return "EBOOK";
}


