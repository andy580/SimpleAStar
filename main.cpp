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

enum class graphics {grass, tree};
// Forward declarations
void printMap(vector<vector<graphics>> &map); 
vector<graphics> parseRow(string row);
vector<vector<graphics>> readMapFile(string filename);
string VisualizeMap (graphics state);
vector<vector<graphics>> Search (vector<vector<graphics>> &map, int start[2], int end[2]);
int heuristic (int x1, int x2, int y1, int y2);
void addToOpenNodes(int x,int y,int costValue, int heuristicValue, vector<vector<int>> &openNodes, vector<vector<graphics>> &map);


void addToOpenNodes(int x,int y,int costValue, int heuristicValue, vector<vector<int>> &openNodes, vector<vector<graphics>> &map) {
    vector<int> node = {x,y,costValue, heuristicValue};
    openNodes.push_back(node);
    
}


int heuristic (int x1, int x2, int y1, int y2) {
    int manhatDist = abs(x2-x1) + abs(y2-y1); 
    return manhatDist;
}

vector<vector<graphics>> Search (vector<vector<graphics>> &map, int start[2], int end[2]){
    cout << "No path found :(" << std::endl;
    vector<vector<graphics>> path;
    return path; 
}

string VisualizeMap (graphics state) {
    if (state == graphics::tree)
        // return "🌲 ";
        return "1 ";
    else  
        // return "🟩 ";
        return "0 ";
}

void printMap(vector<vector<graphics>> &map) {
    for (auto i = map.begin(); i != map.end(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            cout << VisualizeMap(*j) << " ";
        }
        cout << "\n";
    }
}
// Overloading function to accept R-Value 
void printMap(vector<vector<graphics>> &&map) {printMap(map);}

vector<vector<graphics>> readMapFile(string filename) {
    ifstream mapFile;
    vector<vector<graphics>> map;
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

vector<graphics> parseRow(string row) {
    vector<graphics> mapRow;
    istringstream mapRowIn(row); 
    char c; 
    int n; 
    while (mapRowIn >> n >> c) {
        if (n==0)
            mapRow.push_back(graphics::grass);
        else
            mapRow.push_back(graphics::tree);
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