#include <iostream>

struct NODE {

	NODE* next;
};
class LList {

private:

	int rule;
	int binaryRule[3];

public:

	LList* head;

	int ReturnRule();
	int ReturnBinaryRule(int index);

	LList();
	LList(unsigned int rule_in, unsigned int bin_in[3]);
	virtual ~LList();
};
