#include <iostream>
#include "Livro.h"
using namespace std;

// inicializa os atributos da classe Livro
Livro::Livro(int id, string titulo, string autor, string genero, int ano, bool lido, Data dataCadastro)
    : id(id), titulo(titulo), autor(autor), genero(genero), ano(ano), lido(lido), dataCadastro(dataCadastro) {
}

// destrutor da classe 
Livro::~Livro() {
}

// métodos para acessar os atributos da classe Livro
int Livro::getId() const {
    return id;
}

string Livro::getTitulo() const {
    return titulo;
}

string Livro::getAutor() const {
    return autor;
}

string Livro::getGenero() const {
    return genero;
}

int Livro::getAno() const {
    return ano;
}

bool Livro::isLido() const {
    return lido;
}

Data Livro::getDataCadastro() const {
    return dataCadastro;
}

// metodos para modificar os atributos da classe Livro
void Livro::setId(int id) {
    this->id = id;
}

void Livro::setTitulo(string titulo) {
    this->titulo = titulo;
}

void Livro::setAutor(string autor) {
    this->autor = autor;
}

void Livro::setGenero(string genero) {
    this->genero = genero;
}

void Livro::setAno(int ano) {
    this->ano = ano;
}

void Livro::setLido(bool lido) {
    this->lido = lido;
}

void Livro::setDataCadastro(Data dataCadastro) {
    this->dataCadastro = dataCadastro;
}

// exibe as informações do livro no console
void Livro::exibirInfo() const {
    cout << "ID: " << id << endl;
    cout << "Título: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Gênero: " << genero << endl;
    cout << "Ano: " << ano << endl;
    cout << "Lido: " << (lido ? "Sim" : "Não") << endl;
    cout << "Data de Cadastro: " << dataCadastro.toString() << endl;
}   