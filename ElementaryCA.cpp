#include "LList.h"

int LList::ReturnRule(){

	return rule;
}
int LList::ReturnBinaryRule(int index){

	return binaryRule[index];
}
LList::LList(){

	rule = -1;

	binaryRule[0] = -1;
	binaryRule[1] = -1;
	binaryRule[2] = -1;

	head = nullptr;
}
LList::LList(unsigned int rule_in, unsigned int bin_in[3]) {

	rule = rule_in;

	binaryRule[0] = bin_in[0];
	binaryRule[1] = bin_in[1];
	binaryRule[2] = bin_in[2];

	head = nullptr;

	//std::cout << "rule: " << rule << "\n";
	//std::cout << "binaryRule[0]: " << binaryRule[0] << "\n";
	//std::cout << "binaryRule[1]: " << binaryRule[1] << "\n";
	//std::cout << "binaryRule[2]: " << binaryRule[2] << "\n";
}
LList::~LList(){


}
