#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Vertex {
public:
    int id;
    int degree;
    int color;
    
    Vertex(int id, int degree) : id(id), degree(degree), color(-1) {}
    
    bool operator<(const Vertex &other) const {
        return degree > other.degree;
    }
};

class Graph {
private:
    vector<vector<int>> adjacencyMatrix;
    vector<Vertex> vertices;
    
public:
    Graph(const vector<vector<int>> &matrix) : adjacencyMatrix(matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            int degree = count(matrix[i].begin(), matrix[i].end(), 1);
            vertices.push_back(Vertex(i, degree));
        }
    }
    
    void colorGraph() {
        sort(vertices.begin(), vertices.end());
        
        for (auto &v : vertices) {
            vector<bool> available(vertices.size(), true);
            
            for (int j = 0; j < adjacencyMatrix.size(); j++) {
                if (adjacencyMatrix[v.id][j] == 1) {
                    for (auto &neighbor : vertices) {
                        if (neighbor.id == j && neighbor.color != -1) {
                            available[neighbor.color] = false;
                        }
                    }
                }
            }
            
            for (int c = 0; c < available.size(); c++) {
                if (available[c]) {
                    v.color = c;
                    break;
                }
            }
        }
    }
    
    void displayGraph() {
        for (const auto &v : vertices) {
            cout << "Vertex " << v.id << " (Degree: " << v.degree << ") -> Color " << v.color << endl;
        }
    }
};

int main() {
    vector<vector<int>> v = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };
    
    Graph g(v);
    g.colorGraph();
    g.displayGraph();
    
    return 0;
}
