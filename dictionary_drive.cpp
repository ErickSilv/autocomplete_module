#include <iostream> //cout, cin
#include <string>	//std::string, strtok, stol
#include <cstring>	//strtok, strtoul, stol
#include <fstream>	//open, is_open, eof
#include <sstream>	//necessary to token (std::getline)
#include <vector>	//push_back

#include "dictionary.h"

// Drive Application
int main( int argc, char * argv[] ) 
{

    // Verificar palavra lida via terminal
    std::string selectedWord;

    if ( argc == 2 ) {
        selectedWord = argv[1];
    } else {
        std::cout << ">>> Insira uma palavra válida para procurar... " << std::endl;
        return 1;
    }

    // Criar novo dicionário a partir do arquivo indicado
    Dictionary dictionary( "wiktionary.txt" );

    // Verifica quais palavras no dicionário começam com a string lida
    std::vector<word> chosenOnes = dictionary.getWords( selectedWord );

    // Imprime as palavras selecionadas
    dictionary.printWords( chosenOnes );

    return 0;
}