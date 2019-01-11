#ifndef __DTRIESNODE_H__

#define CHARACTER_SIZE 128
/* class TriesNode
 * member : each node has it's own string, and the maximum length is 1000
 * also has parent pointer, and child node, and their own parse number
 * function description : refer to dTriesNode.cpp
 */
class TriesNode
{
private:
	TriesNode* parent;
	TriesNode* child[CHARACTER_SIZE];
	int parseNum;
	char str[1000];

public:
	TriesNode();
	TriesNode(TriesNode *_parent, int _num, char _ch);
	TriesNode* getChild(char _c);
	int getParseNum();
	char* getStr();
	TriesNode* setChild(int _num, char _c);
};

#endif 
