#include "TriesNode.h"
#include <cstddef>
#include <cstdint>


/* TriesNode()
 * Description : used only for making root node
 */
TriesNode::TriesNode()
{
	parent = nullptr;
	parseNum = 0;
	for (int i = 0; i < CHARACTER_SIZE; ++i)
		child[i] = nullptr;
}


/* TriesNode(int, TriesNode*)
 * Description : used for making node except root node. 
 */
TriesNode::TriesNode(int _num, TriesNode* _parent)
{
	parent = _parent;
	parseNum = _num;
	for (int i = 0; i < CHARACTER_SIZE; ++i)
		child[i] = nullptr;
}


/* setChild(char, int)
 * Description: make a child node with edge _c, and that child node's node
 * number is _parseNum
 */
TriesNode* TriesNode::setChild(char _c, int _parseNum)
{
	child[(uint8_t)_c] = new TriesNode(_parseNum, this);
	return child[(uint8_t)_c];
}

/* getSpecificNumChild(char)
 * Description : return the node's child node with edge _c
 */
TriesNode* TriesNode::getSpecificNumChild(char _c)
{
	return child[(uint8_t)_c];
}


/* getParseNum()
 * Description : return a parse number of the node
 *
 */
int TriesNode::getParseNum()
{
	return parseNum;
}
