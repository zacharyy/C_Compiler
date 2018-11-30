#ifndef EMPTY_NODE
#define EMPTY_NODE 

#include "tree.h"


class EmptyNode: public TreeNode
{
public:
	EmptyNode(string TreeNodeProductionName);
	~EmptyNode();
	void traverse_to_file(FILE*);
	nodeDataType getDataType(char *);
protected:
	nodeDataType dType;
};
#endif