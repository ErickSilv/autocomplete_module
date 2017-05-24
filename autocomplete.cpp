#include <iostream> //cout, cin
#include <string>	//std::string, strtok, stol
#include <cstring>	//strtok, strtoul, stol
#include <fstream>	//open, is_open, eof
#include <sstream>	//necessary to token (std::getline)
#include <vector>	//push_back

int main ( int argc, char *argv[] )
{
	/* IF has being detected one argument, than read it. 
	 *	OTHERWISE, ends the execetution.
	 */
	if ( argc > 1 )
	{
		//Open the wiktionary archive
		std::fstream wiktionary;
		wiktionary.open( argv[1] );

		//Receive the word to search.
		std::string palavra;
		std::cin >> palavra;

		//Declaration of a vector with the ponderosity of each word in wiktionary.
		std::vector < long int > ponderosity_list;

		//Declaration of a vector of words in wiktionary
		std::vector < std::string > wiktionary_list;

		//IF the archive has been succesfully open.
		if ( wiktionary.is_open() )
		{
			//declarates count to differenciate the first of archive.
			int count = 0; 

			// Will receive the first line of the archive with the size of wiktionary.
			size_t size_wiktionary = 0;

			// Reads the archive content.
			while ( ! wiktionary.eof() )
			{
				//guards the content of each line.
				std::string line;
				std::getline( wiktionary, line );

				/* IF count == 0, than the reader is in the first line of the wiktionary.
				 *		OTHERWISE, the line has a word and his ponderosity as content.
				 */
				if ( count == 0 )
				{
					//Guards the content of the first line in the archive as 'long int' value.
					size_wiktionary = std::stoull( line );
				}
				else 
				{
					std::istringstream string_to_tokenizer( line );
					// Tokenizing the read line.
					std::string token;

					//A count to help in indentify the half is actual in analysis.
					size_t token_count = 0;
					
					/* WHILE  has content in line separated by '\t', cross under the line.
				 	 *		IF the first half is actually crossed, than save the ponderosity in ponderosity_list.
				 	 *		 OTHERWISE, the second half now is crossed, than save the word content in wiktionary_list.
					 */
					while( std::getline( string_to_tokenizer, token, '\t' ) ) 
					{

						if ( token_count == 0 )
						{
							ponderosity_list.push_back ( std::stoull( token ) );
						} 
						else
						{
							wiktionary_list.push_back ( token );
						} 

						//Increments the token_count of the line.
						token_count++;
					}
				}

				//Increments the count of the archive.
				count++; 

			}

			for ( auto i(0ul); i < size_wiktionary; i++ )
			{
				std::cout << ponderosity_list[i] << "\t" << wiktionary_list[i] << "\n";  
			}
		}


	}
	else 
	{
		std::cout << "Invalid wiktionary\n";
		std::cout << "Please re-execute with a valid wiktionary\n";
	}

	return EXIT_SUCCESS;
}