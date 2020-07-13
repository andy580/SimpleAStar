#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using std::cout;
using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;

enum class state {grass, tree, visited};
// Forward declarations
void printMap(vector<vector<state>> &map); 
vector<state> parseRow(string row);
vector<vector<state>> readMapFile(string filename);
string VisualizeMap (state state);
vector<vector<state>> Search (vector<vector<state>> &map, int start[2], int end[2]);
int heuristic (int x1, int x2, int y1, int y2);
void addToOpenNodes(int x,int y,int costValue, int heuristicValue, vector<vector<int>> &openNodes, vector<vector<state>> &map);


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