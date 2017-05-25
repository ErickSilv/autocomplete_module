# Introdução

Esse projeto de programação implementa um sistema de auto completar.

O objetivo principal é desenvolver um módulo de autocompletar para digitação, com base em um wiktionário.

O projeto se encontra GitHub com o link [Autocompletar](https://github.com/ErickSilv/autocomplete_module).

# O Wiktionário

O Wiktionário é uma base de dados que contém na primeira linha, o tamanho do wiktionário, o restante são as palavras que disponíveis e seus respectivos pesos*.
	*Peso é seu número de 'importância' em relação às outras.


# Compilando
Para compilar esse projeto acesse, via terminal, o repositório no qual o projeto se encontra.
Depois disso, digite o comando, via terminal : 
> g++ -Wall -std=c++11 dictionary_drive.cpp dictionary.cpp -o dictionary

# Executando
Para executar o projeto digite o seguinte comando no terminal :   
>  ./dictionary 'palavra'

OBS: A palavra não está envolta entre aspas simples, como no exemplo. 

# Limitações
Apenas palavras presentes no wiktionário serão mostradas na saída.

# Autoria

Programa desenvolvido por Daniel Miqueias do Nascimento(<danielmnscb@gmail.com>), Graduando de TI na UFRN; e Erick de Oliveira Silva (<erickoliveira.eos@gmail.com>), Graduando de TI na UFRN.

# Licença
Esse projeto está sob a MIT License.

