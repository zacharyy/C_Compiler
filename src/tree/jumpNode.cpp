/*
* @Author: ahpalmerUNR
* @Date:   2018-10-31 11:34:10
* @Last Modified by:   ahpalmerUNR
* @Last Modified time: 2018-12-18 00:59:12
*/
#include "jumpNode.h"

JumpNode::JumpNode(string TreeNodeProductionName,int jumpType):TreeNode(TreeNodeProductionName,1)
{
	jumpCounter = Label_counter;
	maybeTicket = Variable_counter;
	++Variable_counter;
	++Label_counter;
	jtype = jumpType;
}

JumpNode::~JumpNode()
{
	
}

void JumpNode::traverse_to_file(FILE* fileout)
{
	switch(jtype)
	{
		case 0:
			fprintf(fileout, "\t%s [shape = triangle,color=purple,label=\"goto id\"]\n", TreeNodeName.c_str());
			TreeNode::traverse_to_file(fileout);
			break;
		case 1:
			fprintf(fileout, "\t%s [shape = triangle,color=purple,label=\"continue\"]\n", TreeNodeName.c_str());
			break;
		case 2:
			fprintf(fileout, "\t%s [shape = triangle,color=purple,label=\"break\"]\n", TreeNodeName.c_str());
			break;
		case 3:
			fprintf(fileout, "\t%s [shape = triangle,color=purple,label=\"return\"]\n", TreeNodeName.c_str());
			break;
		case 4:
			fprintf(fileout, "\t%s [shape = triangle,color=purple,label=\"return expr\"]\n", TreeNodeName.c_str());
			TreeNode::traverse_to_file(fileout);
			break;
	}
}
void JumpNode::ast_to_3ac(FILE* fileout)
{
	string key;
	char const_exprRepr[500];
	int a = 0;
	int isID;
	nodeDataType ttype;
	Node* ch1;
	if (currentCodeLine != forErrors[0].source[0].lineNum )
	{
		fprintf(fileout, "# %s",TreeNode::coldLine().c_str() );
		currentCodeLine = forErrors[0].source[0].lineNum;
	}
	switch(jtype)
	{
		case 0:
			
			
			isID=children[0]->getDataType(const_exprRepr);
			if (isID == ID_TYPE_NODE)
			{
				ch1 = astTable.searchAll(const_exprRepr,&a);
				if (ch1 ==NULL)
				{
					ch1 = astTable.insert(const_exprRepr,jumpCounter,0,INT_TYPE,&a);
				}
				if (a >= 1)
				{
					jumpCounter = ch1->lineNumber;
				}
			}
			else
			{
				printf("Warning: jump goto node does not have id node child.\n");
			}

			fprintf(fileout, "BR\t_\t_\tl%d\n", jumpCounter);
			break;
		case 1:
			key = "continue";
			ch1 = astTable.searchAll(key.c_str(),&a);
			if (ch1 ==NULL)
			{
				printf("Warning: jump continue node does not have reference in symbolTable.\n");
			}
			else
			{
				jumpCounter = ch1->lineNumber;
			}

			fprintf(fileout, "BR\t_\t_\tl%d\n", jumpCounter);
			break;
		case 2:
			key = "break";
			ch1 = astTable.searchAll(key.c_str(),&a);
			if (ch1 ==NULL)
			{
				printf("Warning: jump break node does not have reference in symbolTable.\n");
			}
			else
			{
				if (ch1->lineNumber==-1)
				{
					printf("Error: break statement not in loop or switch.");
				}
				else
				{
					jumpCounter = ch1->lineNumber;
					fprintf(fileout, "BR\t_\t_\tl%d\n", jumpCounter);
				}
			}
			break;
		case 3:
			key = "return";
			ch1 = astTable.searchAll(key.c_str(),&a);
			if (ch1 ==NULL)
			{
				printf("Warning: jump return node does not have reference in symbolTable.\n");
			}
			else
			{
				// jumpCounter = ch1->lineNumber;
			}

			fprintf(fileout, "RETURN\t_\t_\t_\n");
			break;
		case 4:
			key = "return";
			ch1 = astTable.searchAll(key.c_str(),&a);
			if (ch1 ==NULL)
			{
				printf("Warning: jump return node does not have reference in symbolTable.\n");
			}
			else
			{
				// jumpCounter = ch1->colNumber;
				ticketNumber = ch1->lineNumber;
				ttype = nodeDataType(ch1->lineNumber);
			}
			children[0]->ast_to_3ac(fileout);
			if (children[0]->getidDataType()!=ttype)
			{
				fprintf(fileout, "CAST\t%s\t_\t%s\n", rep_3ac_ticket(children[0]->getidDataType(),children[0]->returnTicket()).c_str(),rep_3ac_ticket(ttype,maybeTicket).c_str());
				fprintf(fileout, "ASSIGN\t%s\t_\tret\n", rep_3ac_ticket(ttype,maybeTicket).c_str());
			}
			else
			{
				fprintf(fileout, "ASSIGN\t%s\t_\tret\n", rep_3ac_ticket(children[0]->getidDataType(),children[0]->returnTicket()).c_str());
			}
			fprintf(fileout, "RETURN\t_\t_\t_\n");
			break;
	}
}
