#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;


enum class state {grass, tree, visited, path};

string VisualizeMap (state state);
void printMap(vector<vector<state>> &map); 

#endif