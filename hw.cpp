//************************************************************
// Rayane EL YASTI
// Program 5
// due 3/18/2025
// Graph coloring using the largest firsst algorithm
//************************************************************

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Vtx {
private:
    int id;          // node id
    int col;         // color value
    vector<int> nbrs;  // neighbors
    char lbl;        // letter label (A, B, C...)

public:
    // Constructor
    Vtx(int vid) : id(vid), col(-1) {
        // Make label A, B, C, etc.
        lbl = 'A' + vid;
    }

    // Basic getters
    int getId() const { return id; }
    char getLbl() const { return lbl; }
    int getCol() const { return col; }
    void setCol(int c) { col = c; }
    
    const vector<int>& getNbrs() const { return nbrs; }
    
    // Add a connected node
    void addNbr(int nid) {
        // Check if already exists
        if (find(nbrs.begin(), nbrs.end(), nid) == nbrs.end()) {
            nbrs.push_back(nid);
        }
    }
    
    // How many connections
    int getDeg() const {
        return nbrs.size();
    }
    
    // Compare nodes by connections count
    bool operator<(const Vtx& other) const {
        // Higher degree first
        if (getDeg() != other.getDeg()) {
            return getDeg() > other.getDeg();
        }
        // Tie breaker
        return id < other.id;
    }
    
    // Print node info
    void print() const {
        string cstr = col == -1 ? "None" : "C" + to_string(col + 1);
        cout << lbl << " (color " << cstr << ")";
        cout << " connected to: ";
        for (size_t i = 0; i < nbrs.size(); ++i) {
            cout << static_cast<char>('A' + nbrs[i]);
            if (i < nbrs.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
};

class Graph {
private:
    vector<Vtx> nodes;      // all nodes
    vector<vector<int>> mat;  // connection matrix
    vector<int> order;      // processing order
    
public:
    // Setup graph with n nodes
    Graph(int n) {
        // Make nodes
        for (int i = 0; i < n; ++i) {
            nodes.push_back(Vtx(i));
        }
        
        // Empty connection matrix
        mat.resize(n, vector<int>(n, 0));
    }
    
    // Connect two nodes
    void addEdge(int v1, int v2) {
        if (v1 >= 0 && v1 < nodes.size() && v2 >= 0 && v2 < nodes.size()) {
            // Mark connection in matrix
            mat[v1][v2] = 1;
            mat[v2][v1] = 1;
            
            // Update node connections
            nodes[v1].addNbr(v2);
            nodes[v2].addNbr(v1);
        }
    }
    
    // Load connections from matrix
    void loadMat(const vector<vector<int>>& m) {
        if (m.size() != nodes.size()) {
            cout << "The matrix size wrong" << endl;
            return;
        }
        
        mat = m;
        
        // Build connections from matrix
        for (size_t i = 0; i < m.size(); ++i) {
            for (size_t j = 0; j < m[i].size(); ++j) {
                if (m[i][j] == 1) {
                    nodes[i].addNbr(j);
                }
            }
        }
    }
    
    // Main coloring algorithm
    void colorGraph() {
        // List nodes by id
        vector<int> srt;
        for (size_t i = 0; i < nodes.size(); ++i) {
            srt.push_back(i);
        }
        
        // Sort by most connections first
        sort(srt.begin(), srt.end(), 
            [this](int a, int b) { return nodes[a] < nodes[b]; });
        
        // Save order for display
        order = srt;
        
        // Color each node in order
        for (int nid : srt) {
            vector<bool> used(nodes.size(), false);
            
            // Check colors of neighbors
            for (int nbr : nodes[nid].getNbrs()) {
                int nc = nodes[nbr].getCol();
                if (nc != -1) {
                    used[nc] = true;
                }
            }
            
            // Find first free color
            int c = 0;
            while (c < used.size() && used[c]) {
                c++;
            }
            
            // Set the color
            nodes[nid].setCol(c);
        }
    }
    
    // Print graph info
    void print() const {
        cout << "Graph:" << endl;
        
        // Print nodes and connections
        for (const Vtx& v : nodes) {
            v.print();
        }
        
        // Print matrix with labels
        cout << "\nConnection Matrix:" << endl;
        cout << "  ";
        for (size_t i = 0; i < nodes.size(); i++) {
            cout << nodes[i].getLbl() << " ";
        }
        cout << endl;
        
        for (size_t i = 0; i < mat.size(); i++) {
            cout << nodes[i].getLbl() << " ";
            for (int val : mat[i]) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    
    // Print color results
    void printColors() const {
        cout << "Color Assignment:" << endl;
        for (const Vtx& v : nodes) {
            cout << v.getLbl() << ": C" << (v.getCol() + 1) << endl;
        }
        
        // Count colors used
        int max_col = -1;
        for (const Vtx& v : nodes) {
            max_col = max(max_col, v.getCol());
        }
        
        cout << "Total colors used: " << max_col + 1 << endl;
        
        // Show processing sequence
        cout << "\nProcessing Order:" << endl;
        for (size_t i = 0; i < order.size(); i++) {
            int nid = order[i];
            cout << (i + 1) << ". " << nodes[nid].getLbl() 
                 << " (" << nodes[nid].getDeg() << " connections)" << endl;
        }
    }
};

int main() {
    // Make graph with 6 nodes
    Graph g(6);
    
    // Setup connections from example
    vector<vector<int>> m = {
        {0, 0, 0, 1, 1, 0},
        {0, 0, 1, 1, 1, 1},
        {0, 1, 0, 0, 1, 1},
        {1, 1, 0, 0, 1, 0},
        {1, 1, 1, 1, 0, 1},
        {0, 1, 1, 0, 1, 0}
    };
    
    g.loadMat(m);
    
    // Show graph
    g.print();
    
    // Run coloring
    g.colorGraph();
    
    // Show results
    g.printColors();
    
    return 0;
}