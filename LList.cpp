#include "LList.h"

int LList::ReturnRule(){

	return rule;
}
int LList::ReturnBinaryRule(int index){

	return binaryRule[index];
}
LList::LList(int in_1, int in_2, int in_3, int rule_input){

	binaryRule[0] = in_1;
	binaryRule[1] = in_2;
	binaryRule[2] = in_3;

	rule = rule_input;
}
LList::~LList(){


}
