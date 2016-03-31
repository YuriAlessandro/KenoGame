#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/**
 * \file functions.h
 * \brief Funcionalidades gerais para o jogo.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cctype>
#include "classes.h"


/**
 * Gera uma semente aleátoria.
 * @param i chave aleatória.
 */
int seed ( int i );

/**
 * Informa se todos os elementos de uma string são dígitos ou não.
 * @param str String que será analisada.
 * @return True se todos forem números, False se não.
 */
bool areAllNumbers ( std::string str );

/**
 * Ordena um vetor de números.\n
 * @param V Vetor a ser ordenado
 * @param left Limite inicial do vetor
 * @param right Limite final do vetor.
 */
void quicksort( std::vector<int>& V, int left, int right );

/**
 * Parte inicial da interface textual do jogo.\n
 * @param player KenoBet com as informações de aposta do jogador
 * @param prizes Tabela de pagamentos por acerto.
 */
void interface( KenoBet player, std::vector< std::vector< double > > prizes );

/**
 * Parte final da interface textual do programa.\n
 * @param player KenoBet com as informações de aposta do jogador
 * @param prizes Tabela de pagamentos por acerto.
 */
void game( KenoBet player, std::vector< std::vector< double > >& prizes );
			 
#endif