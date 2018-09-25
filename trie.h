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
	std::vector<std::string> findAllWordsStartingWithPrefix(const std::string&);

private:
	Node* findPrefixNode(const std::string& word);
	void findWords(Node* node);
	void copy(Node*, Node*);
	Node* remove(Node*);
	Node* _root;

    std::vector<std::string> _words;
	std::string _word;
	std::string _prefix;
};

#endif
