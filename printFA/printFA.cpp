#include <iostream>
#include <vector>
#include <set>
#include <map>

using Edges = std::vector<std::pair<int, char>>;

typedef std::vector<Edges> LA; // List adjacency / Список смежности
typedef std::map<std::set<int>, std::set<std::pair<std::set<int>, char>>> ECM;

void printFA(LA &listAdjancency)
{ // Печать КА
    int state = 0;

    for (Edges subList : listAdjancency)
    {
        for (std::pair<int, char> edge : subList)
        {
            //std::cout << state << ' ' << edge.second << ' ' << edge.first << std::endl; // Печать вида: (Vertex) (Transition symbol) (Vertex)
            std::cout << state << "((" << state << "))" << " -->|" << edge.second << "| " << edge.first << "((" << edge.first << "))" << std::endl; // Печать для mermaid
        }
        state++;
    }
}

void printStartAndFinishNFA(LA& NFA) {
    std::cout << "NFA start: " << 0 << ' ' << "NFA Finish: " << NFA.size() - 1 << std::endl;
}

void printStartAndFinishDFA(LA& NFA, const ECM& eClosureMap)
{
    int start = 0;
    int finishNFA = NFA.size() - 1;

    std::cout << "DFA start: " << start << ' ';

    std::cout << "DFA finish: ";
    int state = 0;
    for (auto [key, edges] : eClosureMap) {
        if (key.contains(finishNFA)) {
            std::cout << state << ' ';
        }
        state++;
    }
    std::cout << std::endl;
}
