// InheritedCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <sstream>
#include <exception>

using namespace std;

class BadLengthException : public exception
{
private:
	const char* number;
public:
	BadLengthException(const int n) {

		switch (n) {
		case 1:
			number = "1";
			break;

		case 2:
			number = "2";
			break;

		case 3:
			number = "3";
			break;

		case 4:
			number = "4";
			break;

		case 5:
			number = "5";
			break;

		default:
			number = "0";
		}
	}
	const char* what() const throw() override
	{
		return number;
	}
};

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if (n < 5) {
		throw BadLengthException(n);
	}
	for (int i = 0; i < n - 1; i++) {
		if (username[i] == 'w' && username[i + 1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while (T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if (isValid) {
				cout << "Valid" << '\n';
			}
			else {
				cout << "Invalid" << '\n';
			}
		}
		catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
