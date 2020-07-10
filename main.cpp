#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void printMap(vector<vector<int>> &map) {
    for (auto i = map.begin(); i != map.end(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            cout << *j << " ";
        }
        cout << "\n";
    }
};

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
    printMap(map);

}