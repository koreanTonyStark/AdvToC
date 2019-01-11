#include "Tries.h"
#include <cstdlib>
#include <cstddef>

#define MAX_NODE 1<<30


/* Tries() : constructor
 * Description : for constructing trie, this constructor only be used in initial
 * state, meaning for making root node. 
 */
Tries::Tries()
{
	this->root = new TriesNode();
	ptr=root;
}

/* isExist(char)
 * Description : check whether there exist such child node with edge _c 
 */
bool Tries::isExist(char _c)
{
	if (ptr->getSpecificNumChild(_c) == nullptr)
		return false;
	else
		return true;
}


/* makeNode(char)
 * Description : makeNode for a _target_character 3 cases exist. one is that if
 * there exists a node with edge _target_character, just change the pointer to
 * that child, and return -1(means fail to make node), another one is that the
 * node number of a dictionary(trie) is already full(for compression ratio,
 * we can gurantee the number maximum with 2^30), this case make ptr points to
 * root node and return the node's number(which means 0), last one is there no
 * exists such node, then we make a node with edge _target_character and change
 * ptr points to root node (for searching longest match in next step)
 *
 */
int Tries::makeNode(char _target_character)
{
	if (isExist(_target_character))
	{
		ptr = ptr->getSpecificNumChild(_target_character);
		return -1;
	}
	else if (idx>=MAX_NODE)
	{
		
		this->ptr = root;
		return ptr->getParseNum();
	}
	else
	{
		int num = ptr->getParseNum();
		ptr->setChild(_target_character, ++idx);
		ptr = root;
		return num;
	}
}

/* getCurrentPtr()
 * Description : return pointer of trie
 */
TriesNode* Tries::getCurrentPtr()
{
	return ptr;
}

/* getCurrentParseNum()
 * Description : get the node number of node which ptr points 
 */
int Tries::getCurrentParseNum()
{
	return ptr->getParseNum();
}

/* getNodeNum()
 * Description: return the whole number of a trie
 */
int Tries::getNodeNum()
{
	return idx;
}
