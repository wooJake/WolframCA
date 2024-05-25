#include "ElementaryCA.h"

int main() {

	//Setting random seed from time, terrible way to go about this but it is simpler.
	srand(static_cast<unsigned int>(time(NULL)));

	ElementaryCA* cA = new ElementaryCA();

	cA->Game();

	delete cA;

	return 0;
}
