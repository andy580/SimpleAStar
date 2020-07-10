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

// Forward declarations
void printMap(vector<vector<int>> &map); 
vector<int> parseRow(string row);
vector<vector<int>> readMapFile(string filename);

void printMap(vector<vector<int>> &map) {
    for (auto i = map.begin(); i != map.end(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            cout << *j << " ";
        }
        cout << "\n";
    }
}
// Overloading function to accept R-Value 
void printMap(vector<vector<int>> &&map) {printMap(map);}

vector<vector<int>> readMapFile(string filename) {
    ifstream mapFile;
    vector<vector<int>> map;
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

vector<int> parseRow(string row) {
    vector<int> mapRow;
    istringstream mapRowIn(row); 
    char c; 
    int n; 
    while (mapRowIn >> n >> c)
        mapRow.push_back(n);
    return mapRow;
}

int main () {
    vector<vector<int>> map = {
        {0,1,0,0,0,0},
        {0,1,0,0,0,0},
        {0,1,0,0,0,0},
        {0,1,0,1,0,0},
        {0,0,0,1,0,0},
        {0,1,0,1,1,0}          
    };

    printMap(readMapFile("SampleMap.txt"));

}