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


void Trie::addWord(const std::string& word) {
// add a word to the local Trie
    unsigned int indx;
    Node* local = _root;
    for (unsigned int i=0; i<word.length(); i++){
        indx = word[i]-'a';
        if (indx>=0 && indx < Node::ALPHABETSIZE) {
            if(local->_children[indx] == nullptr)
                local->_children[indx] = new Node;
            local = local->_children[indx];
        }
    }
    local->_isWord = true;
}


bool Trie::isWord(const std::string& word) {
// return true if the word is in the Trie
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


Node* Trie::findPrefixNode(const std::string& prefix) {
// return the node at the end of the prefix
    unsigned int indx;
    Node* local = _root;
    for (unsigned int i=0; i<prefix.length(); i++){
        indx = prefix[i]-'a';
        if(local->_children[indx] == nullptr)
            return nullptr;
        local = local->_children[indx];
    }
    return local;
}


void Trie::findWords(Node* node) {
    for(unsigned int i=0; i<Node::ALPHABETSIZE; i++){
        if(node->_children[i] != nullptr) {
            char temp[2] = {char(i+'a'), '\0'};
            _word.append(temp);
            if(node->_children[i]->_isWord){
                _words.push_back(_word);
            }
            findWords(node->_children[i]);
        }
    }
    _word = _prefix;
}


std::vector<std::string> Trie::findAllWordsStartingWithPrefix(const std::string& prefix) {
// return a vector of strings that have the same prefix
    _word = prefix;
    _prefix = prefix;
    Node* node = findPrefixNode(prefix);
    findWords(node);
    return _words;
}
