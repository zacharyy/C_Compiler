/*
* @Author: ahpalmerUNR
* @Date:   2018-10-30 22:43:27
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-11-30 10:30:19
*/
#include "iteration_statement.h"

Iter_statement::Iter_statement(string TreeNodeProductionName,bool doType):TreeNode(TreeNodeProductionName,4)
{
	jumpCounterOne = Label_counter;
	++Label_counter;
	jumpCounterTwo = Label_counter;
	++Label_counter;
	dotype = doType;
}
Iter_statement::~Iter_statement()
{
	
}
void Iter_statement::traverse_to_file(FILE* fileout)
{
	// cout<<"Iter_statement"<<endl;
	string doRep;
	if (dotype)
	{
		doRep = "shape=invhouse,label=\"do type\niteration\",color=firebrick1";
	}
	else
	{
		doRep = "shape=house,label=\"for type\niteration\",color=firebrick1";
	}
	fprintf(fileout, "%s [%s]\n",TreeNodeName.c_str(),doRep.c_str() );
	TreeNode::traverse_to_file(fileout);
}
void Iter_statement::ast_to_3ac(FILE* fileout)
{fprintf(fileout, "#%s",TreeNode::coldLine().c_str() );
	if (dotype)
	{
		fprintf(fileout, "LABEL\tl%d\n", jumpCounterOne);
		children[3]->ast_to_3ac(fileout);
		children[1]->ast_to_3ac(fileout);
		fprintf(fileout, "BREQ\t%d\t(0)\tl%d\n", children[1]->returnTicket(),jumpCounterOne);
		
	}
	else
	{
		children[0]->ast_to_3ac(fileout);
		fprintf(fileout, "LABEL\tl%d\n",jumpCounterOne);
		children[1]->ast_to_3ac(fileout);
		fprintf(fileout, "BRNE\t%d\t(0)\tl%d\n", children[1]->returnTicket(),jumpCounterTwo);
		children[3]->ast_to_3ac(fileout);
		children[2]->ast_to_3ac(fileout);
		fprintf(fileout, "BR\tl%d\n", jumpCounterOne);
		fprintf(fileout, "LABEL\tl%d\n", jumpCounterTwo);
	}
}