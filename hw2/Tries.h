#ifndef __TRIES_H__

#include "TriesNode.h"

/* class Tries
 * member : root, ptr(used for searching longest match, idx(number of nodes in trie)
 * function : refer TriesNode.cpp
 */
class Tries
{
private:
	TriesNode *root;
	TriesNode *ptr;
	int idx;
public:
	Tries();
	bool isExist(char _c);
	int makeNode(char _target_character);
	TriesNode* getCurrentPtr();
	int getCurrentParseNum();
	int getNodeNum();
};

#endif
