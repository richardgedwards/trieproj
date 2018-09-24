#include <iostream>
#include "trie.h"


int main(int argc, char* argv[])
{
    Trie t0;
    t0.addWord("abc");

    Trie t1 = t0;
    t1.addWord("abcd");
    Trie t2;
    t2 = t1;

    std::string example("abcd");
    std::cout << t0.isWord(example) << std::endl;
    std::cout << t1.isWord(example) << std::endl;
    std::cout << t2.isWord(example) << std::endl;
    
    return 0;
}