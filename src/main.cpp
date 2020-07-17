#include <iostream>

#include "display.h"
#include "parse.h"
#include "search.h"

using std::cout;
using std::vector;

int main () {
    
    auto map = readMapFile("C:/Users/Andy/Projects/SimpleAStar/src/SampleMap.txt");
    

    printMap(map);
    int start[2] = {0,0};
    int end[2] = {5,5};
    auto solution = Search(map, start, end);
    cout << ("---------------") << std::endl;
    printMap(solution);

}