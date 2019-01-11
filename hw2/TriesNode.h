#ifndef __TRIESNODES_H__

#define CHARACTER_SIZE 128


/* class TriesNode
 * member : parseNum(the parse number of the node in dictionary), child array
 * which size is 128, and parent ptr.
 * function : refer to TriesNode.cpp
 */
class TriesNode
{
private:
	int parseNum;
	TriesNode *child[CHARACTER_SIZE];
	TriesNode *parent;

public:
	TriesNode();
	TriesNode(int _num, TriesNode *_parent);
	TriesNode* setChild(char _c, int _parseNum);
	TriesNode* getSpecificNumChild(char _c);
	int getParseNum();
};

#endif
