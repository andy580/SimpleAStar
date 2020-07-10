#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::vector;
using std::string;
using std::ifstream;

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
    // printMap(map);
    readMapFile("SampleMap.txt");

}