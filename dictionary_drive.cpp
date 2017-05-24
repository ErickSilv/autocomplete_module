
#include "dictionary.h"
// Compara duas palavras e retorna 1 se a primeira tiver maior peso que a segunda. 0 caso contrário.
int getStronger(const void* w1_, const void* w2_);


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

    qsort( &chosenOnes, chosenOnes.size(), sizeof( word ), getStronger );

    dictionary.printWords( chosenOnes );

    return EXIT_SUCCESS;
}