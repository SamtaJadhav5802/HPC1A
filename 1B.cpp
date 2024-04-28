#include <iostream>
#include <vector>
#include <stack>
#include <omp.h>

using namespace std;

const int MAX = 100000;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int node) {
    stack<int> s;
    s.push(node);

    while (!s.empty()) {
        int curr_node = s.top();
        s.pop();

        if (!visited[curr_node]) {
            visited[curr_node] = true;
            cout << curr_node << " "; // Print the node only if it's visited for the first time

            #pragma omp parallel for
            for (int i = 0; i < graph[curr_node].size(); i++) {
                int adj_node = graph[curr_node][i];
                if (!visited[adj_node]) {
                    s.push(adj_node);
                }
            }
        }
    }
}

int main() {
    int n, m, start_node;
    cout << "Enter No of Node, Edges, and start node: ";
    cin >> n >> m >> start_node;

    cout << "Enter Pair of edges:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // Perform DFS from every node in parallel
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    return 0;
}

/*
OUTPUT
gescoe@gescoe-OptiPlex-3010:~/Desktop/SamtaHPC$ g++ -o gfg -fopenmp 1B.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop/SamtaHPC$ ./gfg
Enter No of Node, Edges, and start node: 5
4 
0
Enter Pair of edges:
0 2
0 3
0 1
2 4
0 1 3 2 4
8/
