#ifndef CLASSES_H
#define CLASSES_H

/**
 * \file classes.h
 * \brief Contém a classe KenoBet, responsável pela mecânica do jogo.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

// Mudar isso para um .h //Deixa pra depois que terminar tudo
// Separar um somente com declaração

class KenoBet{

public:

	/**
     * Construtor da classe
     * @param _maxNumSpots número a ser armazenado no variável m_maxSpots.
     */
	explicit KenoBet ( unsigned int _maxNumSpots = 0 ) : m_maxSpots(_maxNumSpots)
	{}

    /** 
     * Recupera a quantidade de números que o jogador está apostando. \n
     * @return Quantidade de apostas.
     */
    std::size_t numChosen() const;
    
    /**
     * Recupera o vetor com as apostas do jogador.\n
     * @return Vetor de apostas.
     */
    std::vector<int> getSpots() const;
    
    /**
     * Recupera o valor atual de dinheiro do jogador.\n
     * @return O valor de dinheiro.
     */
    float getWage() const;
    	
    /**
     * Recupera quantas rodadas o jogador deseja realizar com a aposta definida.\n
     * @return Total de rodadas.
     */
    int getRounds() const;
    
    /**
     * Determina quantos números sorteados são iguais aos apostados pelo jogador.\n
     * @param _hits Vetor com os valores sorteados pelo jogo.\n
     * @return Números que coincidiram.
     */
    std::vector<int> getHits( std::vector<int> & _hits ) const;
    
    /**
     * Adiciona um número a aposta somente se ele não já foi adicionado.\n
     * @param _spot O número que desejamos incluir na aposta.\n
     * @return True Se o número for inserido com sucesso ; False caso contrário.
     */
    bool addNumber ( int _spot );
    
    /**
     * Define a quantidade de dinheiro que o jogador está apostando.\n
     * @param _wage O dinheiro.\n
     * @return True se o valor for maior que 0 ; false caso contrário.
     */
    bool setWage ( float _wage );
    
    /*	
    void reset();
    */
    
    /**
     * Lê o arquivo de apostas do usuário.\n
     * @param fileName Nome do arquivo.\n
     * return True se o arquivo foi lido corretamente, False caso contrário.
     */
    bool readFile( std::string fileName );

private:
	unsigned int m_maxSpots;	/**< Armazena a quantidade de números apostados.*/
	std::vector<int> m_spots 	/**< Armazena os números escolhidos pelo jogador.*/
	float m_wage			/**< Armazena o dinheiro apostado pelo jogador.*/
	int m_rounds;			/**< Armazena o número de rodadas a serem executadas.*/

};

#endif
