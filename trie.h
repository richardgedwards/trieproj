#ifndef TRIE_H_
#define TRIE_H_

#include "node.h"
#include <string>
#include <vector>

class Trie
{
public:
	Trie();
	~Trie();
	Trie(const Trie&);
	Trie& operator= (const Trie&);

	void addWord(const std::string&);
	bool isWord(const std::string&);
	std::vector<std::string> prefix(const std::string&);

private:
	void copy(Node*, Node*);
	Node* remove(Node*);
	Node* _root;
};


#endif /* !TRIE_H_ */
