#include "ElementaryCA.h"

bool ElementaryCA::BinaryRule(int left, int middle, int right, int index) {

	//Checking state of (from position) top left, top center, and top right to see what rule must be invoked.
	return left == binaryRule[index][0] &&
		middle == binaryRule[index][1] &&
		right == binaryRule[index][2];
}
int ElementaryCA::Rules(int left, int middle, int right) {

	//Looping through all 8 rules.
	for (int i = 0; i < 8; ++i) {

		//If the binarRule is true (1), set to 1 otherwise set to false (0).
		if (BinaryRule(left, middle, right, i)) {

			return rule[i];
		}
	}
	return 0;
}

void ElementaryCA::Game() {

	std::ofstream outFS;

	std::string fileName = "WolframCAout.txt";

	outFS.open(fileName);

	unsigned int whileSize = BOARD_SIZE * 0x18;

	//Setting up board.
	for (unsigned int i = 0; i < BOARD_SIZE; ++i) {

		//Setting random number between 0 and 1 (this is all that is needed since this is all in binary).
		board[i] = rand() % 2;
		board2[i] = board[i];
	}

	while (counter <= whileSize) {

		for (int i = 0; i < BOARD_SIZE; ++i) {

			//Making sure there is no error when on the leftmost and rightmost sides.
			int left = i == 0 ? board[BOARD_SIZE - 1] : board[i - 1];
			int middle = board[i];
			int right = i == BOARD_SIZE - 1 ? board[0] : board[i + 1];

			//Checking rules and storing the result in board2 so there is no conflict between readings.
			board2[i] = Rules(left, middle, right);
		}

		//Looping through the board again to display and set the first board equal to the second board.
		for (int i = 0; i < BOARD_SIZE; ++i) {

			//Setting board 1 to board 2.
			board[i] = board2[i];

			textLine.push_back(board[i]);

			//If board at i is 0 then display nothing, otherwise set it to a visible character.
			if (board[i] == 0) {

				std::cout << ' ';
			}
			else {

				std::cout << 'O';
			}
		}
		//At the end of a line go to next line visibly.
		std::cout << "\n";

		++counter;
	}

	for (int i = 0; i <= whileSize; ++i) {

		if (i % BOARD_SIZE == 0) {

			outFS << std::endl;
			continue;
		}

		if (textLine.at(i) == 0) {

			outFS << ' ';
			continue;
		}
		outFS << 'O';
	}
}
ElementaryCA::ElementaryCA() {

	magicNum = 0xFAC688;
	ruleNum = 0b00011110;

	counter = 0;

	board = new unsigned int[BOARD_SIZE];
	board2 = new unsigned int[BOARD_SIZE];

	GenList();
}
ElementaryCA::~ElementaryCA() {

	//Deleting boards.
	delete[] board;
	delete[] board2;
}
