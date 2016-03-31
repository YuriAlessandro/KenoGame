/**
 * \file functions.cpp
 * \brief Funcionalidades gerais para o jogo.
 */

#include "functions.h"

/**
 * Gera uma semente aleátoria.
 * @param i chave aleatória.
 */
int seed ( int i ) { return std::rand()%i;}

/**
 * Informa se todos os elementos de uma string são dígitos ou não.
 * @param str String que será analisada.
 * @return True se todos forem números, False se não.
 */
bool areAllNumbers ( std::string str ){
	
	for ( unsigned int i = 0; i < str.length(); i++ ){
		if( isdigit( str[i] ) || str[i] == '.' )
			continue;
		else
			return false;
	}

	return true;
}

/**
 * Ordena um vetor de números.\n
 * @param V Vetor a ser ordenado
 * @param left Limite inicial do vetor
 * @param right Limite final do vetor.
 */
void quicksort( std::vector<int>& V, int left, int right ){
	int i, j, x;
    i = left;
    j = right;
    x = V.at( ( left + right ) / 2 );

    while( i <= j ){
        
        while( V.at( i ) < x && i < right ){
            i++;
        }
        
        while( V.at( j ) > x && j > left ){
            j--;
        }
        
        if( i <= j ){
            
            std::swap( V.at( i ), V.at( j ) );
            i++;
            j--;
            
        }
    }
    
    if( j > left ){
        quicksort( V, left, j );
    }
    
    if( i < right ){
        quicksort( V,  i, right );
    }
    
}

/**
 * Parte inicial da interface textual do jogo.\n
 * @param player KenoBet com as informações de aposta do jogador
 * @param prizes Tabela de pagamentos por acerto.
 */
void interface( KenoBet player, std::vector< std::vector< double > > prizes ){
    
    std::cout << "--------------------------------------------------\n" <<
				">>> Bet successfully read!\n" <<
				"\tYou are going to wage a total of $" << player.getWage() << 
				" dollars.\n" << 
				"\tGoing for a total of " << player.getRounds() <<
				" rounds, waging $" << player.getWage()/player.getRounds() <<" per round.\n\n" <<
				"\tYour bet has " << player.numChosen() << " numbers.";
	
	std::cout << " They are = [ ";
    for( const auto &e : player.getSpots() ) std::cout << e << " ";
    std::cout << "]\n";
    
    int numSpots = player.numChosen();
    
    // Imprime a tabela
    std::cout << "\t\t-------+---------\n" <<
    			"\t\t  Hits | Payout\n" <<
    			"\t\t-------+---------\n";
    
    for( int i = 0; i <= numSpots; i++){
        std::cout << "\t\t   " << std::setw(2) << i << "  | " << prizes.at(numSpots).at(i) << "\n";        
    }
    
    std::cout << "\n\n";
}

/**
 * Parte final da interface textual do programa.\n
 * @param player KenoBet com as informações de aposta do jogador
 * @param prizes Tabela de pagamentos por acerto.
 */
void game( KenoBet player, std::vector< std::vector< double > >& prizes){

	/* Tabelas contendo todos os valores e os valores que foram acertados. */
	std::vector<int> table;
	std::vector<int> hits;

	float endMoney = 0;
	float betPerRound = player.getWage()/player.getRounds();
	float payoutRate;
	float _payout = 0;

	/* Gera os números da tabela [1 - 80 ]. */
	for( int i = 1; i <= 80; i++ ) table.push_back( i );

	for( int i = 0; i < player.getRounds(); i++ ){
		
		/* Gera uma semente aleátoria para o programa. Dessa forma,
		 * os números sorteados serão realmente sempre aleátorios. */
		std::srand ( unsigned ( std::time(0) ) );
		std::random_shuffle( table.begin(), table.end(), seed);
		
		/* Analisa os acertos do jogador. */
		hits = player.getHits( table );	
		
		/* Ordena os 20 primeiros resultados da tabela para os imprimir depois. */
		quicksort( table, 0, 19 );
		
		payoutRate = prizes.at( player.numChosen() ).at( hits.size() );
		endMoney += betPerRound * payoutRate;
		_payout += ( payoutRate * betPerRound ) - betPerRound;
		
		std::cout << std::fixed << std::setprecision(2) << "\t\t--------------------------------------------------\n" <<
					"\t\tThis is round #" << i+1 << " of " << player.getRounds() <<
					", and your wage is $" << betPerRound <<". Good luck!\n";
	
		/* Imprime os 20 números sorteados. */
		std::cout << "\t\tThe drawn numbers are: [ ";
		for(int j = 0; j < 20; j++) std::cout << table.at(j) << " ";
		std::cout << "]\n";

		if (hits.size() > 0){
			std::cout << "\n\t\tYou hit the following number(s) correctly [ ";
			for( const auto &e : hits ) std::cout << e << " ";
			std::cout << "], a total of " << hits.size() << " hits out of "
			<< player.numChosen() << "\n";
		}else{
		 	std::cout << "\n\t\tNo hits in this round.\n";
		}
						
		std::cout << std::fixed << std::setprecision(2) << "\t\tPayout rate is "
				  << payoutRate << ", thus you came out with: $"
				  << betPerRound * payoutRate  << "\n"
				  << "\t\tYour net balance so far is: $" <<  _payout << " dollars.\n";
	
	}
	
	std::cout << "\n===== SUMMARY =====\n";
	std::cout << ">>> You spent in this game a total of $" << player.getWage() << " dollars.\n";
	
	if ( (endMoney - player.getWage() ) <= 0 ){
		std::cout << std::fixed << std::setprecision(2) << ">>> Sorry, you lost $" << player.getWage() - endMoney << " dollars. Better luck next time.\n";
	
	}
	
	else if ( endMoney - player.getWage() > -0.01 && endMoney - player.getWage() < 0.01 ){
		std::cout << "It was a fair game (no losses or gains)\n";
	}
	
	else{
		std::cout << std::fixed << std::setprecision(2) << ">>> Hooray, you won $" << endMoney - player.getWage() << " dollars. See you next time! ;-)\n";
	}
	
	std::cout << std::fixed << std::setprecision(2) << ">>> You are leaving the Keno table with $" << endMoney << " dollars.\n";
}