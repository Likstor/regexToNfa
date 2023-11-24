#include <iostream>
#include <string>
#include "regex2nfa.h"
#include "nfa2dfa.h"
#include "printFA.h"

using namespace std;

int main() {
	// Ввод регулярного выражения
	string regex;
	cout << "Enter RegExp: ";
	cin >> regex;
	cout << endl;

	// RegexpToNFA
	cout << "NFA" << endl;

	LA NFA;
	regexToNFA(regex, NFA);
	printStartAndFinishNFA(NFA);
	printFA(NFA);

	// NFAtoDFA
	cout << "DFA" << endl;

	ECM eClosureMap = NFAtoPreDFA(NFA);
	printStartAndFinishDFA(NFA, eClosureMap);
	LA DFA;
	buildDFA(DFA, eClosureMap);
	printFA(DFA);
}