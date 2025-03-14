#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Vertex {
public:
    char id;
    int degree;
    int color;
    vector<int> neighbors;

    Vertex(char id) : id(id), degree(0), color(-1) {}
};

class Graph {
private:
    vector<Vertex> vertices;
    vector<vector<int>> adjacencyMatrix;
    // Map to keep track of original indices after sorting
    unordered_map<int, int> sortedToOriginalIndex;

public:
    Graph(vector<vector<int>> matrix, vector<char> names) {
        adjacencyMatrix = matrix;
        for (size_t i = 0; i < names.size(); i++) {
            vertices.push_back(Vertex(names[i]));
        }

        // Fill neighbors and degree
        for (size_t i = 0; i < vertices.size(); i++) {
            for (size_t j = 0; j < vertices.size(); j++) {
                if (adjacencyMatrix[i][j] == 1) {
                    vertices[i].neighbors.push_back(j);
                    vertices[i].degree++;
                }
            }
        }
    }

    void sortVerticesByDegree() {
        // Create a temporary vector of indices
        vector<pair<int, int>> degreeIndices; // pair<degree, original_index>
        for (size_t i = 0; i < vertices.size(); i++) {
            degreeIndices.push_back({vertices[i].degree, i});
        }

        // Sort by degree (descending)
        sort(degreeIndices.begin(), degreeIndices.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        // Create a new vertices array in the sorted order
        vector<Vertex> sortedVertices;
        cout << "Sorted vertices by degree (Largest First):\n";
        for (size_t i = 0; i < degreeIndices.size(); i++) {
            int originalIndex = degreeIndices[i].second;
            sortedVertices.push_back(vertices[originalIndex]);
            sortedToOriginalIndex[i] = originalIndex; // Keep track of mapping
            cout << vertices[originalIndex].id << " (Degree: " << degreeIndices[i].first << ") -> ";
        }
        cout << "\n\n";

        vertices = sortedVertices;
    }

    void colorGraph() {
        // Reset the adjacency information after sorting
        vector<vector<int>> newAdjacencyMatrix(vertices.size(), vector<int>(vertices.size(), 0));
        
        // Update neighbors based on the original adjacency matrix
        for (size_t i = 0; i < vertices.size(); i++) {
            vertices[i].neighbors.clear();
            int originalI = sortedToOriginalIndex[i];
            
            for (size_t j = 0; j < vertices.size(); j++) {
                int originalJ = sortedToOriginalIndex[j];
                if (adjacencyMatrix[originalI][originalJ] == 1) {
                    vertices[i].neighbors.push_back(j);
                    newAdjacencyMatrix[i][j] = 1;
                }
            }
        }

        // Now do the coloring with updated neighbor information
        for (size_t i = 0; i < vertices.size(); i++) {
            vector<bool> available(vertices.size(), true); // All colors initially available

            // Check neighbors' colors and mark them unavailable
            for (int neighborIdx : vertices[i].neighbors) {
                int neighborColor = vertices[neighborIdx].color;
                if (neighborColor != -1) {
                    available[neighborColor] = false; // Mark the color as taken
                }
            }

            // Assign the first available color
            for (int c = 0; c < (int)vertices.size(); c++) {
                if (available[c]) {
                    vertices[i].color = c;
                    break;
                }
            }
        }

        cout << "Vertex Colors:\n";
        for (size_t i = 0; i < vertices.size(); i++) {
            cout << vertices[i].id << " -> C" << vertices[i].color + 1 << "\n"; // Colors are 1-based
        }
    }

    void run() {
        sortVerticesByDegree();
        colorGraph();
    }
};

int main() {
    // Use the specific adjacency matrix you provided
    vector<vector<int>> matrix = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    vector<char> names = {'A', 'B', 'C', 'D', 'E'};

    Graph g(matrix, names);
    g.run();

    return 0;
}