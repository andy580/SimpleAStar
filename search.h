#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include "display.h"

using std::vector;

const int directions[4][2]
{
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};

vector<vector<state>> Search (vector<vector<state>> &map, int start[2], int end[2]);
int heuristic (int x1, int x2, int y1, int y2);
void addToOpenNodes(int x,int y,int costValue, int heuristicValue, vector<vector<int>> &openNodes, vector<vector<state>> &map);
bool compare (vector<int> node1, vector<int> node2);
void cellSort (vector<vector<int>> &openNodes);
bool checkValidCell(int x, int y, vector<vector<state>> &map);
void expandAdjCells(vector<int> &currNode, vector<vector<int>> &openNodes, vector<vector<state>> &map, int end[2]);

#endif