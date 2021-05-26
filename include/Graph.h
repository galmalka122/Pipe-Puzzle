#pragma once

#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>

// A template class that implement a graph.

using type_position = std::pair<char, std::pair<int, int>>;
template <typename T>
class Graph {
public:
    void addEdge(T, T);
    void removeEdge(T, T);
    void bfs(T);
    void clear() { m_neighborsList.clear(); };

private:
    std::map<T,std::list<T>> m_neighborsList;
};

//--------------------------- Specialization Classes --------------------------
template<>
class Graph<std::pair<char, std::pair<int, int>>> {

private:
    std::map<type_position, std::list<type_position>> m_neighborsList;
public:
    void addEdge(type_position, type_position);
    void removeEdge(type_position, type_position);
    std::set<std::pair<int, int>> bfs(type_position);
    void clear() { m_neighborsList.clear(); }
};
//=============================================================================
template<typename T>
void Graph<T>::addEdge(T s, T v) {
    if(std::find(m_neighborsList[s].begin(), m_neighborsList[s].end(), v) == m_neighborsList[s].end()) {
        m_neighborsList[s].push_back(v);
        m_neighborsList[v].push_back(s);
    }
}
//=============================================================================
template<typename T>
void Graph<T>::removeEdge(T s, T v) {
    if(std::find(m_neighborsList[s].begin(), m_neighborsList[s].end(), v) != m_neighborsList[s].end()) {
        m_neighborsList[s].remove(v);
        m_neighborsList[v].remove(s);
    }
}
//=============================================================================
template<typename T>
void Graph<T>::bfs(T src) {
    std::map<T, bool> visited;
    std::queue<T> queue;
    queue.push(src);
    visited[src] = true;

    while (!queue.empty()) {
        T node = queue.front();
        queue.pop();

        for (auto & nbr : m_neighborsList[node]){
            if(!visited[nbr]){
                queue.push(nbr);
                visited[nbr] = true;
            }
        }
    }
   
}
