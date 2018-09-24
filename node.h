#ifndef NODE_H_
#define NODE_H_

class Node
{
public:
    Node();
    ~Node();
    Node(Node&);
    Node& operator=(Node&);

public:
    bool _isWord;
    Node** _children;
    static const unsigned int ALPHABETSIZE = 4U;    
};

#endif
