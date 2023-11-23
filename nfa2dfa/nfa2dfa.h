#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>

using Edges = std::vector<std::pair<int, char>>;

typedef std::vector<Edges> LA; // List adjacency / Список смежности

void epsilonClosure(std::set<int> &eClosure, const LA &NFA);

std::map<char, std::set<int>> collect(std::set<int> &key, const LA &g);

LA NFAtoDFA(const LA &NFA);