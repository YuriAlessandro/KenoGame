# Keno Game
Bem vindo ao Keno. 

O Keno é um jogo de azar composto por uma tabela com 80 valores, no qual
o jogador deve escolher até 15 números, entre 1 e 80. O jogo então sorteia 
20 valores da tabela. Dependendo da quantidade de acertos, o jogador pode
faturar um prêmio, ou perder o dinheiro apostado.

## Como jogar (Linux)
Para jogar a partir desse programa é simples: Você deverá criar um arquivo num
formato qualquer (exemplo: myfile.txt) dentro da pasta data com a seguinte estrutura:

```Shell
    DINHEIRO INICIAL
    RODADAS A SEREM JOGADAS
    VALORES APOSTADOS
```
Um exemplo:

```Shell
    1500
    3
    52 12 60
```

Após salvar o arquivo (na pasta data), você deverá executar o programa em seu
terminal da seguinte maneira:

```Shell
    ./[Nome do executável] [Nome do arquivo]
```

Um exemplo:

```Shell
    ./KenoGame myfile.txt
```

O jogo então será executado, e você poderá conferir como se saiu.

A pasta 'data' possui alguns arquivos exemplos.

#### Dúvidas?
Caso esteja com dúvidas, apenas execute o programa sem nenhum argumento no seu
terminal e um modo padrão será jogado, assim você pode se familiarizar com a interface
e a mecânica do jogo.

## Detalhes
Este jogo foi desenvolvido em C++11. Para compilar, faça:

```Shell
    g++ -Wall -std=c++11 -I include/ src/keno_main.cpp src/functions.cpp src/classes.cpp -o bin/[nome do arquivo]
``` 

## Autores
Jogo criador por:

```Shell    
    * Gustavo Araújo Carvalho
    * Yuri Alessandro Martins
```

Realizado como proposta da disciplina de Linguagem de Programação, do curso de
Bacharelado em Tecnologia da Informação da UFRN.
