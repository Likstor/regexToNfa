#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

using Edges = std::vector<std::pair<int, char>>;

typedef std::vector<Edges> LA; // List adjacency / Список смежности
typedef std::map<std::set<int>, std::set<std::pair<std::set<int>, char>>> ECM;

    std::vector<bool> _visited; // Multi threading break
void epsilonClosure(std::set<int> &eClosure, const LA &NFA)
{ // Эпсилон замыкание / Обходим граф по эпсилон стрелкам / Итеративный DFS
    std::stack<int> s;
    _visited.assign(NFA.size(), false);

    for (int vertex : eClosure)
    {
        s.push(vertex);
    }

    while (!s.empty())
    {
        int v = s.top();
        s.pop();

        if (_visited[v] == true)
        {
            continue;
        }

        _visited[v] = true;

        for (auto edge : NFA[v])
        {
            if (edge.second == '_' && !_visited[edge.first])
            {
                s.push(edge.first);
                eClosure.insert(edge.first);
            }
        }
    }
}

std::map<char, std::set<int>> collect(std::set<int> &key, const LA &g)
{
    std::map<char, std::set<int>> mp;
    for (auto &v : key)
    {
        for (auto &&[u, b] : g[v])
        {
            mp[b].insert(u);
        }
    }

    mp.erase('_');

    for (auto &&[_, encl] : mp)
    {
        epsilonClosure(encl, g);
    }

    return mp;
}

ECM NFAtoPreDFA(const LA &NFA)
{ // Детерминизация НКА
    ECM eClosureMap;
    std::queue<std::set<int>> keys;

    std::set<int> eClosure = {0};
    epsilonClosure(eClosure, NFA);

    keys.push(eClosure);

    while (!keys.empty())
    {
        std::set<int> key = keys.front();
        keys.pop();

        if (eClosureMap.contains(key))
        {
            continue;
        }

        eClosureMap[key] = {};

        auto mp = collect(key, NFA);

        for (auto &&[lexem, closure] : mp)
        {
            eClosureMap[key].insert({closure, lexem});
            keys.push(closure);
        }
    }

    return eClosureMap;
}


void buildDFA(LA& DFA, ECM& eClosureMap) {
    // Нумеруем ДКА
    int state = 0;
    std::map<std::set<int>, int> number;

    for (auto x : eClosureMap)
    { // Создаем вершины ДКА
        DFA.push_back({});
        number[x.first] = state;
        state++;
    }

    state = 0;

    for (auto &&[key, edges] : eClosureMap)
    {
        for (auto &edge : edges)
        {
            DFA[state].push_back({number[edge.first], edge.second});
        }
        state++;
    }
}

