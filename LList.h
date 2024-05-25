

class LList {

private :

	int rule;
	int binaryRule[3];
	int index;

public:

	int ReturnRule();
	int ReturnBinaryRule(int index);



	LList(int in_1, int in_2, int in_3, int rule_input);
	virtual ~LList();
};
