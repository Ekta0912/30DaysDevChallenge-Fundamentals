#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

struct Edge {
    char to;
    int weight;
};

unordered_map<char, vector<Edge>> graph = {
    {'A', {{'B', 2}, {'C', 5}}},
    {'B', {{'D', 8}, {'E', 3}}},
    {'C', {{'E', 4}, {'F', 6}}},
    {'D', {}},
    {'E', {{'F', 1}}},
    {'F', {}}
};

vector<char> bfs_shortest_path(char start, char end) {
    queue<vector<char>> q;
    unordered_map<char, bool> visited;

    q.push({start});
    visited[start] = true;

    while (!q.empty()) {
        vector<char> path = q.front();
        q.pop();
        char current = path.back();

        if (current == end)
            return path;

        for (auto neighbor : graph[current]) {
            if (!visited[neighbor.to]) {
                visited[neighbor.to] = true;
                vector<char> new_path = path;
                new_path.push_back(neighbor.to);
                q.push(new_path);
            }
        }
    }

    return {}; 

bool dfs_path(char current, char end, unordered_map<char, bool>& visited, vector<char>& path, int& total_weight, int current_weight) {
    visited[current] = true;
    path.push_back(current);

    if (current == end) {
        total_weight = current_weight;
        return true;
    }

    for (auto neighbor : graph[current]) {
        if (!visited[neighbor.to]) {
            if (dfs_path(neighbor.to, end, visited, path, total_weight, current_weight + neighbor.weight)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}


int main() {
    vector<char> bfs_result = bfs_shortest_path('A', 'F');

    cout << "Shortest path (BFS, by hops): ";
    for (char node : bfs_result) {
        cout << node;
        if (node != 'F') cout << " -> ";
    }
    cout << endl;


    vector<char> dfs_result;
    unordered_map<char, bool> visited;
    int total_weight = 0;

    dfs_path('A', 'F', visited, dfs_result, total_weight, 0);

    cout << "One path (DFS, total latency): ";
    for (char node : dfs_result) {
        cout << node;
        if (node != 'F') cout << " -> ";
    }
    cout << " | Total weight: " << total_weight << "ms" << endl;

    return 0;
}
