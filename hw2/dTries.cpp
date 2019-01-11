#include "dTries.h"

/* Tries() : constructor
 * Description : for initial state, we have to make a one node with no edges,
 * and mark 0 to that node.
 */
Tries::Tries()
{
	root = new TriesNode();
	ptr = NULL;
	idx = 0;
	list.push_back(root);
}

/* getRoot()
 * Description : return root pointer
 */

TriesNode* Tries::getRoot()
{
	return root;
}

/* makeNode(TriesNode, char)
 * Description : first, check whether _ch child node exists, if not then make
 * new node and set it's parent, parse number , and pushes to vector that
 * represents the node's string
 *
 */
void Tries::makeNode(TriesNode *_node, char _ch)
{
	if (_node->getChild(_ch) == NULL)
	{
		TriesNode *tempNode = _node->setChild(++idx, _ch);
		list.push_back(tempNode);
	}
}


/* getTriesNode(int)
 * Description : return list(vector type)'s a element which index is _num
 */
TriesNode* Tries::getTriesNode(int _num)
{
	return list[_num];
}
