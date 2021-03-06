/*
* @Author: ahpalmerUNR
* @Date:   2018-10-31 11:49:36
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-12-18 15:58:22
*/
#include "selectionNode.h"

SelectionNode::SelectionNode(string TreeNodeProductionName,bool isaSwitch):TreeNode(TreeNodeProductionName,3)
{
	jticket1 = Label_counter;
	++Label_counter;
	jticket2 = Label_counter;
	++Label_counter;
	jticket3 = Label_counter;
	++Label_counter;
	isSwitch = isaSwitch;
	ticket = Variable_counter;
	++Variable_counter;
}
SelectionNode::~SelectionNode()
{
	
}

void SelectionNode::traverse_to_file(FILE* fileout)
{
	if (isSwitch)
	{
		//code for switch
		fprintf(fileout, "\t%s [shape=hexagon,color=green,label=\"switch\"]\n", TreeNodeName.c_str());
		TreeNode::traverse_to_file(fileout);
	}
	else
	{
		if (jticket3<0)
		{
			fprintf(fileout, "\t%s [shape=diamond,color=green,label=\"if\"]\n", TreeNodeName.c_str());
		TreeNode::traverse_to_file(fileout);
		}
		else
		{
			fprintf(fileout, "\t%s [shape=diamond,color=green,label=\"if else\"]\n", TreeNodeName.c_str());
			TreeNode::traverse_to_file(fileout);
		}
	}
}
void SelectionNode::ast_to_3ac(FILE* fileout)
{
	char tmp[500];
	if (currentCodeLine != forErrors[0].source[0].lineNum )
	{
		fprintf(fileout, "# %s",TreeNode::coldLine().c_str() );
		currentCodeLine = forErrors[0].source[0].lineNum;
	}
	char temp[500];
	if (isSwitch)
	{
		//code for switch
	}
	else
	{
		if (children[2]->getDataType(temp)==EMPTY_TYPE_NODE)
		{
			//no else
			children[0]->ast_to_3ac(fileout);
			fprintf(fileout, "ASSIGN\t(1)\t_\t%s\n", rep_3ac_ticket(children[0]->getDataType(tmp),ticket).c_str());
			fprintf(fileout, "BREQ\t%s\t%s\tl%d\n", rep_3ac_ticket(children[0]->getDataType(tmp), children[0]->returnTicket()).c_str(),rep_3ac_ticket(children[0]->getDataType(tmp),ticket).c_str(),jticket1);
			fprintf(fileout, "BR\t_\t_\tl%d\n", jticket2);
			fprintf(fileout, "LABEL\tl%d\t_\t_\n",jticket1);
			children[1]->ast_to_3ac(fileout);
			fprintf(fileout, "LABEL\tl%d\t_\t_\n", jticket2);
		}
		else
		{
			//else
			children[0]->ast_to_3ac(fileout);
			// fprintf(fileout, "BREQ\t%s\t(1)\tl%d\n", rep_3ac_ticket(children[0]->getDataType(tmp), children[0]->returnTicket()).c_str(),jticket1);
			fprintf(fileout, "ASSIGN\t(1)\t_\t%s\n", rep_3ac_ticket(children[0]->getDataType(tmp),ticket).c_str());
			fprintf(fileout, "BREQ\t%s\t%s\tl%d\n", rep_3ac_ticket(children[0]->getDataType(tmp), children[0]->returnTicket()).c_str(),rep_3ac_ticket(children[0]->getDataType(tmp),ticket).c_str(),jticket1);

			fprintf(fileout, "BR\t_\t_\tl%d\n", jticket2);
			fprintf(fileout, "LABEL\tl%d\t_\t_\n",jticket1);
			children[1]->ast_to_3ac(fileout);
			fprintf(fileout, "BR\t_\t_\tl%d\n", jticket3);
			fprintf(fileout, "LABEL\tl%d\t_\t_\n", jticket2);
			children[2]->ast_to_3ac(fileout);
			fprintf(fileout, "LABEL\tl%d\t_\t_\n", jticket3);
		}
	}
}

void SelectionNode::errorCheck(const char * str)
{
	//if if statement
	//
		//expression must have arithmetic or pointer type
		// this gets evaluated including side effects 
			
	//if switch statement
	//
		//expression must have integral type
		//
		//**expression undergoes integral promotion
		//case statements converted to promoted type
		//
		//cases must be unique
		//
		//only one default case
		//
		//nested switch statements ignore cases of inner switch statements
		//
		//expression is compared against all cases and only executes a default 
		//if no match occurs. If no default then the switch does not perform
		//anything. expressions side effects are executed
		//
		//from ** and below, these require evalutation of statement where cases are added to switch symbol table.
}