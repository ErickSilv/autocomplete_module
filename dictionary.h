#ifndef _DICTIONARY_
#define _DICTIONARY_

typedef struct {
    std::string name;
    size_t strength;
} word;

struct Comparator {
    bool operator() ( word w1, word w2 ) { 
        if ( w1.strength > w2.strength )
            return true;
        else if ( w1.strength < w2.strength )
            return false;

        return true;
    }
};

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

    private:
        std::vector<word> m_palavras;
        size_t m_size;
};

#endif