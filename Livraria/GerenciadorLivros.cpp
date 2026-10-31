
#include "GerenciadorLivros.h"
#include "Livro.h"
#include "LivroFisico.h"
#include "EBook.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//construtor
GerenciadorLivros::GerenciadorLivros() {
    totalLivros =0;
    proximoId =1;
    nomeArquivo ="biblioteca.txt";

    for (int i=0; i<100; i++) {
        livros[i]=NULL;//permite as posições do vetor começarem vazias
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
