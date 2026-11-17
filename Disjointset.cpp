#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// class DisjointSet {
// private:
//     vector<int> parent;
//     vector<int> rankValue;
// public:
//     // Initializes one independent set for every node.
//     DisjointSet(int n) {
//         parent.resize(n + 1);
//         rankValue.assign(n + 1, 0);
 
//         // Make every node its own parent.
//         for (int node = 1; node <= n; node++) {
//             parent[node] = node;
//         }
//     }
 
//     // Returns the representative using path compression.
//     int findParent(int node) {
//         // Base case: node is its own representative.
//         if (parent[node] == node) {
//             return node;
//         }
 
//         // Compress the path while finding the representative.
//         parent[node] = findParent(parent[node]);
 
//         return parent[node];
//     }
 
//     // Merges two sets using rank balancing.
//     void unionByRank(int u, int v) {
//         int rootU = findParent(u);
//         int rootV = findParent(v);
 
//         // Same representative means both nodes are already connected.
//         if (rootU == rootV) {
//             return;
//         }

//         // Keep the higher-rank root as the parent.
//         if (rankValue[rootU] < rankValue[rootV]) {
//             swap(rootU, rootV);
//         }
 
//         // Attach the lower-rank root to the higher-rank root.
//         parent[rootV] = rootU;
 
//         // Increase rank only when both ranks are equal.
//         if (rankValue[rootU] == rankValue[rootV]) {
//             rankValue[rootU]++;
//         }
//     }
 
//     // Checks whether two nodes share one set.
//     bool find(int u, int v) {
//         return findParent(u) == findParent(v);
//     }
// };





class DisjointSet {
private:
    vector<int> parent;
    vector<int> componentSize;
 
public:
    // Initializes one independent set for every node.
    DisjointSet(int n) {
        parent.resize(n + 1);
        componentSize.assign(n + 1, 1);
 
        // Make every node its own parent.
        for (int node = 1; node <= n; node++) {
            parent[node] = node;
        }
    }
 
    // Returns the representative using path compression.
    int findParent(int node) {
        // Base case: node is its own representative.
        if (parent[node] == node) {
            return node;
        }
 
        // Compress the path while finding the representative.
        parent[node] = findParent(parent[node]);
 
        return parent[node];
    }
 
    // Merges two sets using component-size balancing.
    void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
 
        // Same representative means both nodes are already connected.
        if (rootU == rootV) {
            return;
        }
 
        // Keep the larger component as the main parent.
        if (componentSize[rootU] < componentSize[rootV]) {
            swap(rootU, rootV);
        }
 
        // Attach the smaller component to the larger component.
        parent[rootV] = rootU;
 
        // Update the size of the merged component.
        componentSize[rootU] += componentSize[rootV];
    }
 
    // Checks whether two nodes share one set.
    bool find(int u, int v) {
        return findParent(u) == findParent(v);
    }
 
    // Returns the number of nodes in one set.
    int componentSizeOf(int node) {
        return componentSize[findParent(node)];
    }
};


//  Number of Operations to Make Network Connected.
int makeConnected(int n, vector<vector<int>>& connections) {
    DisjointSet dsu(n);
    int extra_edge = 0;
    for(int i = 0 ; i < connections.size();i++){
        if(dsu.find(connections[i][0],connections[i][1]) == true){
            extra_edge++;
        }
        else { 
            dsu.unionBySize(connections[i][0],connections[i][1]);
        }

    }
    int edges_used = 0;

    for(int i = 0 ; i < n - 1;i++){
        if(dsu.find(i,i + 1) == false){
            if(edges_used == extra_edge)     return -1;    
            edges_used++;
            dsu.unionBySize(i,i+1);

        }
        
    }

    return edges_used ;
}


// Driver code.
int main() {
    DisjointSet dsu(5);
 
    dsu.unionBySize(1, 2);
    dsu.unionBySize(4, 5);
    dsu.unionBySize(2, 4);
 
    cout << boolalpha << dsu.find(1, 5) << "\n";
    cout << dsu.componentSizeOf(3) << "\n";
 
    return 0;
}