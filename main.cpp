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
    
    printMap(readMapFile("SampleMap.txt"));

}