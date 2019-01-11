#include "dTriesNode.h"
#include <cstddef>
#include <cstring>
#include <cstdint>

/*ASCII code's maximum character number is 127, so in order to make an array,
 *set array size as 128
 */
#define CHARACTER_SIZE 128

/* TriesNode() : Constructor 
 * Description : initialize the node, only used when root node get created
 * put empty string that represent the root node
 */
TriesNode::TriesNode()
{
	parent = nullptr;
	for (int i = 0; i < CHARACTER_SIZE; ++i)
		child[i] = nullptr;
	parseNum = 0;
	str[0] = '\0';
}

/* TriesNode(TriesNode, int, char)
 * Description : cases which node is not root, parent pointer points parent
 * node, node number will be assigned as _num, and, _ch denotes the node's
 * parent's string, so concatenate _ch to original string of parent. 
 */
TriesNode::TriesNode(TriesNode *_parent, int _num, char _ch)
{
	parent = _parent;
	for (int i = 0; i < CHARACTER_SIZE; ++i)
		child[i] = NULL;
	
	parseNum = _num;
	int len = strlen(parent->str);
	strncpy(str, parent->str, len);
	str[len] = _ch;
	str[len + 1] = '\0';
}


/* getChild(char)
 * Description : return the pointer of child node in edge with _c
 */
TriesNode* TriesNode::getChild(char _c)
{
	return child[(uint8_t)_c];
}

/* getParseNum()
 * Description : return the parse number of node
 */
int TriesNode::getParseNum()
{
	return parseNum;
}

/* getStr()
 * Description: return the string of node
 *
 */
char* TriesNode::getStr()
{
	return str;
}

/* setChild(int, char)
 * Description : makes child node when there is no node for representing the
 * longest match, use _num as parse number , _c will be used as concatenating
 * character to parent's node's string. 
 *
 */
TriesNode* TriesNode::setChild(int _num, char _c)
{
	child[(uint8_t)_c] = new TriesNode(this, _num, _c);
	return child[(uint8_t)_c];
}
