/**
 *  \mainpage Keno Game
 *  \author Gustavo Araújo Carvalho e Yuri Alessandro Martins
 *  \date 2016
 *  \version 1.0
 *
 *  \file keno_main.cpp
 *  \brief Contém a função principal do programa, que gerencia a classe e as demais funcionalidades.
 */

#include <iostream>
#include <vector>
#include "classes.h"
#include "functions.h"

/** Define o arquivo de execução padrão como bets.txt */
#define _FILENAME "bets.txt"

/** Tabela de prêmios */
static std::vector< std::vector<double> > prizes
{
{0},
{0, 3},
{0, 1, 9},
{0, 1, 2, 16},
{0, 0.5, 2, 6, 12},
{0, 0.5, 1, 3, 15, 50},
{0, 0.5, 1, 2, 3, 30, 75},
{0, 0.5, 0.5, 1, 6, 12, 36, 100},
{0, 0.5, 0.5, 1, 3, 6, 19, 90, 720},
{0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200},
{0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800},
{0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000},
{0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000},
{0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000},
{0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500},
{0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}
}; 


/**
 * Função principal do programa:\n
 * Executa passos importantes para a leitura do arquivo e chama as funções que irão tratá-lo. */
int main(int argc, char const *argv[])
{
	/* Nome do arquivo de apostas. */
	std::string fileName;
	
	/* Instância do KenoBet */
	KenoBet player;
	
	
	/* Recebe o nome do arquivo por parâmetro, roda o caso
	 * padrão caso não seja inserido. */
	if (argc > 1){
		fileName = argv[1];
	}else{
		std::cout << ">>> WARNING: Filename not set, running default case.\n";
		fileName = _FILENAME;
	}
	
	/* Se houver falha na leitura do arquivo, o programa encerra. */
	if( !player.readFile( fileName ) ){
		std::cout << ">>> ERROR: An error was found while reading the file.\n"
		<< "Either it doesn't exist or it's incomplete.\n";
		return EXIT_SUCCESS;
	}
	
	/* Exibe a primeira parte da interface textual do jogo. */
	interface( player, prizes );

	/* Parte final da interface textual do jogo: \n
	 * Confere todos os resultados, mostra para o usuário e encerra o programa. */
	game( player, prizes );


	
	return EXIT_SUCCESS;
}