#include "trie.h"


Trie::Trie() {
// default constructor
    _root = new Node;
}


Trie::~Trie() {
// destructor
    delete remove(_root);
}


Trie::Trie(const Trie& trie) {
// copy constructor
    _root = new Node;
    copy(_root, trie._root);
}


Trie& Trie::operator= (const Trie& trie) {
// overloaded assignment operator
    remove(_root);
    copy(_root, trie._root);
    return *this;
}


void Trie::copy(Node* local, Node* node) {
// copy nodes into the local empty Trie
    for(unsigned int i=0; i<Node::ALPHABETSIZE; i++){
        if(node->_children[i] != nullptr) {
            local->_children[i] = new Node;
            copy(local->_children[i], node->_children[i]);
        }
    }
    local->_isWord = node->_isWord;
}


Node* Trie::remove(Node* node) {
// remove and deallocate memory to all nodes below node
    for(unsigned int i=0; i<Node::ALPHABETSIZE; i++){
        if(node->_children[i] != nullptr) {
            delete remove(node->_children[i]);
            node->_children[i] = nullptr;
        }
    }
    return node;
}


void Trie::addWord(const std::string& word)
{
// add a word to the local Trie
    unsigned int indx;
    Node* local = _root;
    for (unsigned int i=0; i<word.length(); i++){
        indx = word[i]-'a';
        if(local->_children[indx] == nullptr)
            local->_children[indx] = new Node;
        local = local->_children[indx];
    }
    local->_isWord = true;
}


bool Trie::isWord(const std::string& word)
{
// return a true if word is in the Trie
    unsigned int indx;
    Node* local = _root;
    for (unsigned int i=0; i<word.length(); i++){
        indx = word[i]-'a';
        if(local->_children[indx] == nullptr)
            return false;
        local = local->_children[indx];
    }
    return local->_isWord;
}


std::vector<std::string> Trie::prefix(const std::string&)
{
    return std::vector<std::string>();
}
