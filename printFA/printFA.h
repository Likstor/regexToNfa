#pragma once
#include <vector>

using Edges = std::vector<std::pair<int, char>>;

typedef std::vector<Edges> LA; // List adjacency / Список смежности

void printFA(LA &listAdjancency);