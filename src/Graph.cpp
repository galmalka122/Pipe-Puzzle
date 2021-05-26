#include "Graph.h"

//=============================================================================
void Graph<type_position>::removeEdge(type_position s, type_position v) {
    if (std::find(m_neighborsList[s].begin(), m_neighborsList[s].end(), v) != m_neighborsList[s].end()) {
        m_neighborsList[s].remove(v);
        m_neighborsList[v].remove(s);
    }
}
//=============================================================================
void Graph<type_position>::addEdge(type_position s, type_position v) {
    if (std::find(m_neighborsList[s].begin(), m_neighborsList[s].end(), v) == m_neighborsList[s].end()) {
        m_neighborsList[s].push_back(v);
        m_neighborsList[v].push_back(s);
    }
}
//=============================================================================
std::set<std::pair<int, int>> Graph<type_position>::bfs(type_position src){

    std::map<type_position, bool> visited;
    std::queue<type_position> queue;

    queue.push(src);

    visited[src] = true;
    std::set<std::pair<int, int>> visited_nodes;

    while (!queue.empty()) {
        type_position node = queue.front();
        queue.pop();

        for (auto& nbr : m_neighborsList[node]) {
            if (!visited[nbr]) {
                queue.push(nbr);
                visited[nbr] = true;
                visited_nodes.insert(nbr.second);
            }
        }
    }
    return visited_nodes;
}
//=============================================================================