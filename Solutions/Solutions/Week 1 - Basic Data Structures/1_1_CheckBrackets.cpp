#include <iostream>
#include <string>

#include <vector>

using namespace std;

class Stack {

public:
	vector<char> charStack;

	void push(char character) {
		charStack.push_back(character);
	}
	void pop() {
		charStack.pop_back();
	}
	char top() {
		return charStack.back();
	}
	int size() {
		return charStack.size();
	}

};

using namespace std;


void checkBrackets(string input) {

	Stack charStack = Stack();
	vector<int> stringPosition = vector<int>(0);


	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '{' || input[i] == '(' || input[i] == '[') {
			charStack.push(input[i]);
			stringPosition.push_back(i);
		}
		else if (input[i] == ')') {
			if (charStack.size() == 0 || charStack.top() != '(') {
				cout << i + 1;
				return;
			}
			else {
				charStack.pop();
				stringPosition.pop_back();
			}
		}
		else if (input[i] == '}') {
			if (charStack.size() == 0 || charStack.top() != '{') {
				cout << i + 1;
				return;
			}
			else {
				charStack.pop();
				stringPosition.pop_back();

			}
		}
		else if (input[i] == ']') {
			if (charStack.size() == 0 || charStack.top() != '[') {
				cout << i + 1;
				return;
			}
			else {
				charStack.pop();
				stringPosition.pop_back();
			}
		}
	}

	if (charStack.size() != 0) {
		cout << stringPosition.back() + 1;
	}
	else {
		cout << "Success";
	}
}


int main(int argv, int* argc) {

	string input;
	getline(cin, input);

	checkBrackets(input);

	return 0;
}