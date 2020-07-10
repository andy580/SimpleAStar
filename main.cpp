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

void printMap(vector<vector<int>> &map) {
    for (auto i = map.begin(); i != map.end(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            cout << *j << " ";
        }
        cout << "\n";
    }
}

void readMapFile(string filename) {
    ifstream mapFile;
    mapFile.open(filename);
    if(!mapFile)
        cout << "File not open";
    else {
        string row;
        while(std::getline(mapFile, row)) {
            cout << row << "\n";
        }
    }
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

    void printMap(vector<vector<int>> &map); 
    void readMapFile(string filename);
    vector<int> parseRow(string row);
    // printMap(map);
    // readMapFile("SampleMap.txt");
    parseRow("0,1,0,1,0,1,0,");

}