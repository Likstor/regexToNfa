#pragma once
#include <vector>
#include <string>

using Edges = std::vector<std::pair<int, char>>;

typedef std::vector<Edges> LA; // List adjacency / Список смежности

void regexToNFA(std::string regex, LA &NFA);