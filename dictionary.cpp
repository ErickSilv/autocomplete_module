#include <iostream> //cout, cin
#include <string>	//std::string, strtok, stol
#include <cstring>	//strtok, strtoul, stol
#include <fstream>	//open, is_open, eof
#include <sstream>	//necessary to token (std::getline)
#include <vector>	//push_back
#include <algorithm>//sort
#include <cstdlib>  //qsort

#include "dictionary.h"

// Carrega as palavras em um dicionário a partir de um arquivo na criação do objeto
Dictionary::Dictionary(std::string filename) {
    // Abre o arquivo que contém as palavras
    std::fstream file;
    file.open( filename );

    // Caso a abertura do arquivo seja bem sucedida
    if ( file.is_open() ) 
    {
        int cont = 0; // Contador usado para percorrer o arquivo lido

        // A variável que contém cada linha lida do arquivo
        std::string line;

        while ( ! file.eof() )
        {
            std::getline( file , line );

            // Determina o tamanho do dicionário
            if ( cont == 0 )
                m_size = std::stoull( line );

            // Lê todas as palavras do arquivo
            std::istringstream string_to_tokenizer( line );
            std::string token;

            size_t token_count = 0;

            while( std::getline( string_to_tokenizer, token, '\t' ) ) 
            {
                word w;

                if ( token_count == 0 )
                    w.strength = ( std::stoull( token ) );
                else
                    w.name = token;

                m_palavras.push_back(w);

                //Increments the token_count of the line.
                token_count++;
            }

            // Incrementa o contador
            cont++;
        }
    } else {
        std::cout << ">> Falha na abertura do arquivo... " << std::endl;
    }

};

// Retorna um vetor ordenado por peso de todas as palavras que pertencem ao dicionário e começam com w1
std::vector<word> Dictionary::getWords(std::string w1) {

    std::vector<word> chosenOnes;

    for ( size_t i = 0; i < m_size; i++ )
    {
        std::string s = m_palavras[i].name;

        if (s.find(w1) == 0)
            chosenOnes.push_back(m_palavras[i]);
    }

    Comparator comparar_palavras;

    /* Utilizando std::sort com a uma função do tipo Comparator, definido
     *  no arquivo 'dictionary.h'.
     */
    sort( chosenOnes.begin(), chosenOnes.end(), comparar_palavras );
    
    return chosenOnes;
};

// Imprime as palavras de um vetor de palavras
void Dictionary::printWords (std::vector<word> words) {
    if ( words.size() == 0 )
        std::cout << ">>> Nenhuma palavra foi encontrada... " << std::endl;
    
    for ( size_t i = 0; i < words.size(); i++ )
    {
        std::cout << words[i].name << std::endl;
    }

};

// Retorna o tamanho do dicionário
size_t Dictionary::getSize() {
    return m_size;
}
