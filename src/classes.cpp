/**
 * \file classes.cpp 
 * \brief Contém as funções da classe KenoBet.
 */

#include "classes.h"
#include "functions.h"

/*!
 * Recupera a quantidade de números que o jogador está apostando. \n
 * @return Quantidade de apostas.
 */
std::size_t KenoBet::numChosen() const{
	return m_maxSpots;
}

/**
 * Recupera o vetor com as apostas do jogador.\n
 * @return Vetor de apostas.
 */
std::vector<int> KenoBet::getSpots() const{
	return m_spots;
}

/**
 * Recupera o valor atual de dinheiro do jogador.\n
 * @return O valor de dinheiro.
 */
float KenoBet::getWage() const{
	return m_wage;

}
	
/**
 * Recupera quantas rodadas o jogador deseja realizar com a aposta definida.\n
 * @return Total de rodadas.
 */
int KenoBet::getRounds() const{
	return m_rounds;
}



/** 
 * Adiciona um número a aposta somente se ele não já foi adicionado.\n
 * @param _spot O número que desejamos incluir na aposta.\n
 * @return T Se o número for inserido com sucesso ; F caso contrário.
 */
bool KenoBet::addNumber ( int _spot ){
	/* Testa se o elemento a ser inserido já não está presente.*/
	if( _spot >= 1 && _spot <= 80 &&
	std::find( m_spots.begin(), m_spots.end(), _spot ) != m_spots.end() ){
		return false;
	}
	else{
		m_spots.push_back( _spot );	// Adiciona o elemento no fim do vetor
		return true;
	}
}

/** Define a quantidade de dinheiro que o jogador está apostando.\n
 * @param _wage O dinheiro.\n
 * @return True se o valor for maior que 0 ; false caso contrário.
 */
bool KenoBet::setWage ( float _wage ){
	m_wage = _wage;
	return (m_wage > 0)? true : false;
}


/*
void reset(){
	m_maxSpots; = 0
	m_spots.resize(0);
	m_wage = 0;
	m_rounds = 0;
}
*/


/**
 * Determina quantos números sorteados são iguais aos apostados pelo jogador.\n
 * @param _hits Vetor com os valores sorteados pelo jogo.\n
 * @return Números que coincidiram.
 */
std::vector<int> KenoBet::getHits( std::vector<int> & _hits ) const{
	std::vector<int> hits;
	for( unsigned int i = 0; i < m_maxSpots; i++ )
		for( unsigned int j = 0; j < 20; j++ )
			if( m_spots[i] == _hits[j])
				hits.push_back( m_spots[i] );
	
	return hits;			
	
}

/**
 * Lê o arquivo de apostas do usuário.\n
 * @param fileName Nome do arquivo.\n
 * return T se o arquivo foi lido, F caso contrário.
 */
bool KenoBet::readFile( std::string fileName ){
	
	/* String temporária que lerá os arquivos. */
	std::string temp;
	
	fileName = "data/" + fileName;
	
	/* Avisa para o usuário que o arquivo será lido.*/
	std::cout << ">>> Preparing to read bet file [" << fileName << "], please wait...\n"; 
	
	/* Abre o arquivo como somente leitura. */
	std::ifstream file( fileName );
	
	/* Retorna falso se o arquivo não for encontrado. */
	if( !file.is_open() )
		return false;
	
	/* O Laço que procura pelo valor 'Wage' */
	while ( !file.eof() ){
		file >> temp;
		if( areAllNumbers( temp ) ){
			m_wage = atof( temp.c_str() );
			break;
		}
	}
	
	/* O Laço que procura o número de rodadas. */
	while( !file.eof() ){
		file >> temp;
		if( areAllNumbers( temp ) ){
			m_rounds = atoi( temp.c_str() );
			break;
		}
	}		
	
	/* O laço que recebe as apostas.*/
	while( !file.eof() && m_maxSpots < 15){
		file >> temp;
		if( areAllNumbers( temp ) )
			if( this->addNumber( atoi( temp.c_str() ) ) )
				m_maxSpots++;
	}
	
	/* Se não houver apostas o programa é encerrado */
	if( m_maxSpots < 1 )
		return false;
		
	/* Ordena o vetor de apostas do jogador. */
	quicksort( m_spots, 0, m_maxSpots-1 );
	
	/* Fecha a leitura do arquivo. */
	file.close();
	
	return true;
}
