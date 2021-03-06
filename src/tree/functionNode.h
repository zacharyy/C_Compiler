#ifndef FUNCTION_NODE
#define FUNCTION_NODE 

#include "tree.h"

class FunctionNode:public TreeNode
{
public:
	FunctionNode( string TreeNodeProductionName);
	~FunctionNode();
	
	void traverse_to_file(FILE* fileout);
	void ast_to_3ac(FILE* fileout);
	nodeDataType getDataType(char*);
	int returnTicket();
	void errorCheck(const char * str);
	vector<nodeDataType> getTypes();
	
protected:
	// vector<nodeDataType> freturnType;
	vector<nodeDataType> freturnType;
	int variableTick;
	vector<vector<nodeDataType>> functionArgs;
	string functName;
	int sizeOfParams;
	int sizeOfLocals;
};

class ParamListNode:public TreeNode
{
public:
	ParamListNode(string TreeNodeProductionName,bool isIDList);
	~ParamListNode();
	bool isIDList();
	
protected:
	bool isID;//if false, is param-list
};

#endif