#pragma once
#include <vector>

using Edges = std::vector<std::pair<int, char>>;

typedef std::vector<Edges> LA; // List adjacency / Список смежности
typedef std::map<std::set<int>, std::set<std::pair<std::set<int>, char>>> ECM;

void printFA(LA &listAdjancency);

void printStartAndFinishNFA(LA &NFA);

void printStartAndFinishDFA(LA &NFA, const ECM &eClosureMap);