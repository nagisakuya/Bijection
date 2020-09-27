#include "Bijection.h"
#include <string>
#include <iostream>
using namespace nagisakuya::Bijection;
using namespace std;

int main(void) {
	bijection<int, string> test = { {1, "one"} };
	cout << test.at_ftos(1) << endl;
}