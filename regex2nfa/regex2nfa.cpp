#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <ctype.h>
#include <stack>
#include <queue>

using Edges = std::vector<std::pair<int, char>>;

typedef std::vector<Edges> LA; // List adjacency / Список смежности

void regexToNFA(std::string regex, LA &NFA)
{ // Построение НКА
    std::stack<int> counters;
    counters.push(0);
    counters.push(-1);

    std::vector<std::set<std::pair<int, char>>> g;

    bool orState = false;
    std::stack<int> orCounter;
    std::stack<int> orList;

    g.push_back({});
    orCounter.push(0);

    for (char lexem : regex)
    {
        if (std::islower(lexem))
        {
            counters.pop();

            if (!orState)
            {
                g.back().insert({1, '_'});
            }
            else
            {
                g[g.size() - 1 - counters.top()].insert({counters.top() + 1, '_'});
                orState = false;
            }
            g.push_back({});
            counters.top()++;
            g.back().insert({1, lexem});
            g.push_back({});
            counters.top()++;

            counters.push(1);
        }
        else if (lexem == '*')
        {
            int tmpCounter = counters.top();
            counters.pop();

            g.back().insert({-tmpCounter, '_'});
            g.back().insert({1, '_'});

            std::set<std::pair<int, char>> &tmp = g[g.size() - 2 - tmpCounter];
            tmp.insert({tmpCounter + 2, '_'});

            g.push_back({});

            counters.top()++;
            counters.push(-1);
        }
        else if (lexem == '+')
        {
            int tmpCounter = counters.top();
            counters.pop();

            g.back().insert({-tmpCounter, '_'});
            g.back().insert({1, '_'});

            g.push_back({});

            counters.top()++;
            counters.push(-1);
        }
        else if (lexem == '(')
        {
            counters.pop();

            if (!orState)
            {
                g.back().insert({1, '_'});
            }
            else
            {
                g[g.size() - 1 - counters.top()].insert({counters.top() + 1, '_'});
                orState = false;
            }
            counters.push(0);
            counters.push(-1);

            g.push_back({});

            orCounter.push(0);
        }
        else if (lexem == ')')
        {
            counters.pop();
            int tmp = counters.top();
            counters.pop();
            counters.top() += tmp + 2;
            counters.push(tmp);
            counters.top()++;
            g.back().insert({1, '_'});
            g.push_back({});

            int tmpCounter = orCounter.top();
            for (int i = 0; i < tmpCounter; i++)
            {
                int orPos = orList.top();
                orList.pop();

                std::set<std::pair<int, char>> &vertex = g[orPos];
                vertex.insert({g.size() - 1 - orPos, '_'});
            }
            orCounter.pop();
        }
        else if (lexem == '|')
        {
            orState = true;

            orList.push(g.size() - 1);
            orCounter.top()++;
        }
    }

    if (orCounter.top() != 0)
    {
        orList.push(g.size() - 1);
        orCounter.top()++;

        g.push_back({});
    }

    int tmpCounter = orCounter.top();
    for (int i = 0; i < tmpCounter; i++)
    {
        int orPos = orList.top();
        orList.pop();

        std::set<std::pair<int, char>> &vertex = g[orPos];
        vertex.insert({g.size() - 1 - orPos, '_'});
    }
    orCounter.pop();

    int stateNumber = 0;
    for (auto &&state : g)
    {
        NFA.push_back({});
        for (auto &&edge : state)
        {
            NFA[stateNumber].push_back({edge.first + stateNumber, edge.second});
        }
        stateNumber++;
    }
}