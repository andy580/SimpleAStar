#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <vector>

#include "display.h"

using std::string;
using std::vector;


vector<state> parseRow(string row);
vector<vector<state>> readMapFile(string filename);

#endif