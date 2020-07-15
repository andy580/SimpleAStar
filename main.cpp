#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using std::cout;
using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;

enum class state {grass, tree, visited, path};
// Forward declarations
void printMap(vector<vector<state>> &map); 
vector<state> parseRow(string row);
vector<vector<state>> readMapFile(string filename);
string VisualizeMap (state state);
vector<vector<state>> Search (vector<vector<state>> &map, int start[2], int end[2]);
int heuristic (int x1, int x2, int y1, int y2);
void addToOpenNodes(int x,int y,int costValue, int heuristicValue, vector<vector<int>> &openNodes, vector<vector<state>> &map);
bool compare (vector<int> node1, vector<int> node2);
void cellSort (vector<vector<int>> &openNodes);


// Function to sort nodes in a list based on sum of cost and heuristic value
void cellSort (vector<vector<int>> &openNodes) {
    sort(openNodes.begin(), openNodes.end(), compare);
}

// Function takes the sum of the cost and heuristic value to compare
bool compare(vector<int> node1, vector<int> node2) {
    int sumValue1 = node1[2] + node1[3];
    int sumValue2 = node2[2] + node2[3];
    return sumValue1 > sumValue2;
}

void addToOpenNodes(int x,int y,int costValue, int heuristicValue, vector<vector<int>> &openNodes, vector<vector<state>> &map) {
    vector<int> node = {x,y,costValue, heuristicValue};
    openNodes.push_back(node);
    map[x][y] = state::visited;
}


int heuristic (int x1, int x2, int y1, int y2) {
    int manhatDist = abs(x2-x1) + abs(y2-y1); 
    return manhatDist;
}

vector<vector<state>> Search (vector<vector<state>> &map, int start[2], int end[2]){
    
    vector<vector<int>> openNodes;

    int x = start[0];
    int y = start[1];
    int costValue = 0;
    int heuristicValue = heuristic(x,y,end[0],end[1]);
    addToOpenNodes(x,y,costValue,heuristicValue,openNodes,map);

    while (openNodes.size() > 0) {
        cellSort(openNodes);
        auto currentNode = openNodes.back();
        openNodes.pop_back();
        x = currentNode[0];
        y = currentNode[1];
        map[x][y] = state::path;

        if (x == end[0] && y == end[1]) {
            return map;
        }

        // function to search adjacent nodes; 
    }
    
    cout << "No path found :(" << std::endl;
    vector<vector<state>> path;
    return path; 
}

string VisualizeMap (state state) {
    if (state == state::tree)
        // return "🌲 ";
        return "1 ";
    else  
        // return "🟩 ";
        return "0 ";
}

void printMap(vector<vector<state>> &map) {
    for (auto i = map.begin(); i != map.end(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            cout << VisualizeMap(*j) << " ";
        }
        cout << "\n";
    }
}
// Overloading function to accept R-Value 
void printMap(vector<vector<state>> &&map) {printMap(map);}

vector<vector<state>> readMapFile(string filename) {
    ifstream mapFile;
    vector<vector<state>> map;
    mapFile.open(filename);
    if(!mapFile)
        cout << "File not open";
    else {
        string row;
        while(std::getline(mapFile, row)) {
            map.push_back(parseRow(row));
        }
    }
    return map;
}

vector<state> parseRow(string row) {
    vector<state> mapRow;
    istringstream mapRowIn(row); 
    char c; 
    int n; 
    while (mapRowIn >> n >> c) {
        if (n==0)
            mapRow.push_back(state::grass);
        else
            mapRow.push_back(state::tree);
    }
    return mapRow;
}

int main () {
    
    auto map = readMapFile("SampleMap.txt");
    printMap(map);
    int start[2] = {0,0};
    int end[2] = {4,5};
    auto solution = Search(map, start, end);
    printMap(solution);

}