#include"assignmentNode.h"

AssignmentNode::AssignmentNode(string nodeName, int numberOfChildren) : TreeNode(nodeName,numberOfChildren)
{
	ticketNumber = Variable_counter;
	++Variable_counter;
}
AssignmentNode::~AssignmentNode()
{

}

void AssignmentNode::traverse_to_file(FILE *fileout)
{
	char typePrint[500];
	char assignPrint[500];
		switch(dType)
		{
			case CHAR_TYPE_NODE:
				snprintf(typePrint, 500,"Char: ");
				break;
			case INT_TYPE_NODE:
				snprintf(typePrint, 500,"Int: ");
				break;
			case DOUBLE_TYPE_NODE:
				snprintf(typePrint, 500,"Float: ");
				break;
			
		}
		switch(aType)
		{
			case EQUAL_ASSIGN:
				snprintf(assignPrint, 500,"Left = Right");
				break;
			case ADD_ASSIGN:
				snprintf(assignPrint, 500,"Left += Right");
				break;
			case SUB_ASSIGN:
				snprintf(assignPrint, 500,"Left -= Right");
				break;
			case MULT_ASSIGN:
				snprintf(assignPrint, 500,"Left *= Right");
				break;
			case DIV_ASSIGN:
				snprintf(assignPrint, 500,"Left /= Right");
				break;
			case MOD_ASSIGN:
				snprintf(assignPrint, 500,"Left %%= Right");
				break;
			case LEFT_ASSIGN:
				snprintf(assignPrint, 500,"Left <<= Right");
				break;
			case RIGHT_ASSIGN:
				snprintf(assignPrint, 500,"Left >>= Right");
				break;
			case AND_ASSIGN:
				snprintf(assignPrint, 500,"Left &= Right");
				break;
			case XOR_ASSIGN:
				snprintf(assignPrint, 500,"Left ^= Right");
				break;
			case OR_ASSIGN:
				snprintf(assignPrint, 500,"Left |= Right");
				break;
		}

		fprintf(fileout, "\t%s [label=\"%s %s\"]\n", TreeNodeName.c_str(),typePrint, assignPrint);
	TreeNode::traverse_to_file(fileout);
	
}
void AssignmentNode::ast_to_3ac(FILE *fileout)
{

}

int AssignmentNode::returnTicket()
{
	return ticketNumber;
}

void AssignmentNode::setTypeSpecifier(nodeDataType typeSpec)
{
	dType = typeSpec;
}

void AssignmentNode::setAssignType(AssignType assignSpec)
{
	aType = assignSpec;
}

void AssignmentNode::errorCheck()
{
		char pointless[500];
		nodeDataType left, right;
		//Actually have to get the data type from the symbol table
		left = nodeDataType(children[0]->getDataType(pointless));
		right = nodeDataType(children[1]->getDataType(pointless));
		if(left != ID_TYPE_NODE)
			yyerror("Error: lvalue required as left operand of assignment");
		
		left = children[0]->getidDataType();
		if(right == ID_TYPE_NODE)
		{
			//Get rights actual type
			right = children[1]->getidDataType();
		}
		
		if(right != left)
		{
			CastNode *tmp = new CastNode("Implicit_Cast");
			tmp->setTypeSpecifier(left);
			tmp->assignChild(0,children[1]);
			assignChild(1,tmp);
			setTypeSpecifier(left);
		}
}


