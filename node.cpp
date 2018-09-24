#include "node.h"

Node::Node() : _isWord(false)
{
    _children = new Node*[ALPHABETSIZE];
    for (unsigned int i=0; i<ALPHABETSIZE; i++)
        _children[i] = nullptr;
}


Node::~Node()
{
    delete [] _children;
}


Node::Node(Node& node)
{
    _isWord = node._isWord;
    _children = new Node*[ALPHABETSIZE];
    for (unsigned int i=0; i<ALPHABETSIZE; i++)
        _children[i] = node._children[i];
}


Node& Node::operator= (Node& node)
{
    _isWord = node._isWord;
    for (unsigned int i=0; i<ALPHABETSIZE; i++)
        _children[i] = node._children[i];
    return *this;
}
