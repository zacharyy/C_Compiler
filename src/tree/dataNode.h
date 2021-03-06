#ifndef DATA_NODE
#define DATA_NODE

#include "tree.h"
#include "castNode.h"
//error: array subscript is not an integer
union Data
{
	int dint;
	char dchar;
	char *dstr;
	double ddoub;
};

class DataNode : public TreeNode {
public:	
	DataNode(string nodeName);
	~DataNode();

	void traverse_to_file(FILE*);
	void ast_to_3ac(FILE*);

	int returnTicket();

	void storeInt(int i);
	void storeDouble(double d);
	void storeString(char *s);
	void storeChar(char c);
	void setTypeSpecifier(nodeDataType typeSpec);
	void setOperator(OperatorType typeSpec);
	nodeDataType getDataType(char * representation);//representation returned uses max buffer 500 characters.
	void notData();
	void setNumberChildren(int);
	void errorCheck();
	void implicitCastWarning(nodeDataType t1, nodeDataType t2);
	void setidDataTypes(vector<nodeDataType>);
	nodeDataType getidDataType();
	void setArrayOffset(int i);
	int getArrayOffset();
	void setTicketNumber(int);
	int getTicketNumber();
	void setArraySizes(int size);
	void addParamDataTypes(nodeDataType t);
	void addParamTickets(int t);
	vector<nodeDataType> getParamDataTypes();
	vector<int> getParamTickets();
protected:

	//int ticketNumber;
	nodeDataType dType;
	OperatorType oType;
	Data data;
	bool isData;
	bool isOperatorNode;
	bool isArray;
	vector<nodeDataType> idDataTypes;
	int arrayOffset;
	vector<int> arraySizes;
	vector<int> paramTicketNumbers;
	vector<nodeDataType> paramDataTypes;
};

#endif
