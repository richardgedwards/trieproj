#include <iostream>
#include <fstream>
#include "trie.h"

int main(int argc, char* argv[])
{
    if (argc !=3) {
        std::cout << "usage: " << argv[0] << " wordfile outfile" << std::endl;
        std::cout << "where wordfile is text file that contains lowercase words on separte lines" << std::endl;
        std::cout << "and outfile is a textfile where the output will be stored." << std::endl;
    }

    std::ifstream is;
    is.open(argv[1]);

    std::ofstream os;
    os.open(argv[2]);
    os << "writing to file\n";
    os.close();
    // Trie t0;
    // t0.addWord("bad");
    // t0.addWord("dac");
    // t0.addWord("dab");
    // t0.addWord("dabb");
    // t0.addWord("rdaaa");
    // std::vector<std::string> words;
    // words = t0.findAllWordsStartingWithPrefix("da");
    // for (unsigned int i=0; i<words.size(); i++) {
    //     std::cout << words[i] << std::endl;
    // }
    
    return 0;
}