#include "parse.h"


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
