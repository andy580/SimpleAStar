#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "display.h"

using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;


vector<state> parseRow(string row);
vector<vector<state>> readMapFile(string filename);

#endif