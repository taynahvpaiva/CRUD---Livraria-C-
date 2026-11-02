# CRUD Livraria C++

Projeto desenvolvido em C++ para o gerenciamento de uma livraria. O sistema permite cadastrar, consultar, atualizar e remover livros, utilizando conceitos de Programação Orientada a Objetos.

## Funcionalidades

- Cadastro de livros;
- Listagem dos livros cadastrados;
- Busca de livros;
- Atualização de informações;
- Remoção de livros;
- Gerenciamento de diferentes tipos de livros, como livros físicos e e-books.

## Tecnologias utilizadas

- C++;
- G++;
- Git e GitHub;
- Visual Studio Code.

## Organização do projeto

O projeto está organizado em arquivos separados para cada classe, facilitando a manutenção e a organização do código.

Entre as classes implementadas estão:

- `Livro`: classe base;
- `LivroFisico`: representa os livros físicos;
- `EBook`: representa os livros digitais.

## Como executar

É necessário ter o compilador G++ instalado.

1. Clone o repositório:

```bash
git clone https://github.com/taynahvpaiva/CRUD---Livraria-C-.git
```

2. Acesse a pasta do projeto:

```bash
cd CRUD---Livraria-C-/Livraria
```

3. Compile os arquivos:

```bash
g++ -std=c++17 *.cpp -o livraria
```

4. Execute o programa:

```bash
.\livraria.exe
```

