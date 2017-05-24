#ifndef _DICTIONARY_
#define _DICTIONARY_

#include <iostream> //cout, cin
#include <string>   //std::string, strtok, stol, strtoul, stol
#include <cstring>  //strtok
#include <fstream>  //open, is_open, eof
#include <sstream>  //necessary to token (std::getline)
#include <vector>   //push_back
#include <cstdlib>  //qsort

typedef struct {
    std::string name;
    size_t strength;
} word;

class Dictionary 
{
    public:
        // Carrega as palavras em um dicionário a partir de um arquivo na criação do objeto
        Dictionary(std::string filename);

        // Retorna um vetor ordenado por peso de todas as palavras que pertencem ao dicionário e começam com w1
        std::vector<word> getWords(std::string w1);

        // Imprime as palavras de um vetor de palavras
        void printWords (std::vector<word> words);

        // Retorna o tamanho do dicionário
        size_t getSize();

        // Compara duas palavras e retorna 1 se a primeira tiver maior peso que a segunda. 0 caso contrário.
        int getStronger(const void* w1_, const void* w2_);

    private:
        std::vector<word> m_palavras;
        size_t m_size;
};

#endif