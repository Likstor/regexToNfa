#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>

using Edges = std::vector<std::pair<int, char>>;

typedef std::vector<Edges> LA; // List adjacency / Список смежности
typedef std::map<std::set<int>, std::set<std::pair<std::set<int>, char>>> ECM;

void epsilonClosure(std::set<int> &eClosure, const LA &NFA);

std::map<char, std::set<int>> collect(std::set<int> &key, const LA &g);

ECM NFAtoPreDFA(const LA &NFA);

void buildDFA(LA &DFA, ECM &eClosureMap);