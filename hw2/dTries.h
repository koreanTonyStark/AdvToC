#ifndef __DTRIES_H__

#include "dTriesNode.h"
#include <vector>
#include <iostream>


/* Class Tries 
 * member : root, ptr, idx(number of nodes), list(each iterator points the
 * node's string
 * function : refer Tries.cpp
 */
class Tries
{
private:
	TriesNode *root;
	TriesNode *ptr;
	int idx;
	std::vector<TriesNode*> list;
public:
	Tries();
	TriesNode* getRoot();
	void makeNode(TriesNode *_node, char _ch);
	TriesNode* getTriesNode(int _num);

};

#endif
