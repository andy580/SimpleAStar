#include "display.h"

string VisualizeMap (state state) {
    switch(state) {
        // grass, tree, visited, path
        case state::grass : return "0 ";
        case state::tree : return "1 ";
        case state::path : return "- ";
        case state::visited : return "o ";
        default: return "0 ";
    }
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