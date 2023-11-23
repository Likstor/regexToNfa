#include <iostream>
#include <vector>

using Edges = std::vector<std::pair<int, char>>;

typedef std::vector<Edges> LA; // List adjacency / Список смежности

void printFA(LA &listAdjancency)
{ // Печать КА
    int state = 0;

    for (Edges subList : listAdjancency)
    {
        for (std::pair<int, char> edge : subList)
        {
            //	std::cout << state << ' ' << edge.second << ' ' << edge.first << std::endl; // Печать по заданию
            std::cout << state << "((" << state << "))"
                      << " -->|" << edge.second << "| " << edge.first << "((" << edge.first << "))" << std::endl; // Печать для mermaid
        }
        state++;
    }
}