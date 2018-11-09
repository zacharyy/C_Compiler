/*
* @Author: ahpalmerUNR
* @Date:   2018-11-05 15:44:49
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-11-09 03:09:36
*/
#include "functionNode.h"

using namespace std;

FunctionNode::FunctionNode(string TreeNodeProductionName):TreeNode(TreeNodeProductionName,4)
{
	variableTick = Variable_counter;
	++Variable_counter;
}

FunctionNode::~FunctionNode()
{

}

void FunctionNode::traverse_to_file(FILE* fileout)
{
	fprintf(fileout, "\t%s [shape=doubleoctagon,color=red,label=\"%s\"]\n", TreeNodeName.c_str(),functName.c_str());
	TreeNode::traverse_to_file(fileout);
}

void FunctionNode::ast_to_3ac(FILE* fileout)
{

}

int FunctionNode::getDataType(char* buffer)
{
	return -1;
}

vector<int> FunctionNode::getTypes()
{
	return freturnType;
}

int FunctionNode::returnTicket()
{
	return variableTick;
}

void FunctionNode::errorCheck()
{
	char temp[500];
	if (children[1]->getDataType(temp)==ID_TYPE_NODE)
	{
		functName.assign(temp);
	}
	else if(children[1]->getDataType(temp)==DIRECT_DECL_TYPE_NODE)
	{
		children[1]->children[0]->getDataType(temp);
		
		functName.assign(temp);
		
		//set param list
	}
	else
	{
		cout<<"Child type "<<children[1]->getDataType(temp)<<" "<<ID_TYPE_NODE<<endl;
		// children[1]->printNode();
		TreeNode::errorCheck("No function name.");
	}
	if (children[0]->getDataType(temp)==EMPTY_TYPE_NODE)
	{
		// TreeNode::printNode();
		TreeNode::errorCheck("Warning: No return type specified for function.");
	}
	else
	{
		freturnType = children[0]->getTypes();
	}
	if (children[2]->getDataType(temp)!=EMPTY_TYPE_NODE)
	{
		//set param types
	}
	
	
}
