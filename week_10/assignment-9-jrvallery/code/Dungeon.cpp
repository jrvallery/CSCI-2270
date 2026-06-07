#include "Dungeon.hpp"
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

Dungeon::Dungeon(int size){
    //Given - This functions initializes the matrix in the heap
    n = size;

    dungeon = new cell_type* [n];
    for(int i=0; i<n; i++){
        dungeon[i] = new cell_type[n];   
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dungeon[i][j] = END;
        }
    }
}

/**
 * @brief This function should add a new vertex to the graph 
 * 
 * @param x x-cordinate of the cell
 * @param y y-cordinate of the cell
 * @param typeOfCell the type of the cell
 */
void Dungeon::addVertex(int x, int y, cell_type typeOfCell){
    // TODO
    int vertNum = findVertexNumFromPosition(x, y);
    vertex *vert = new vertex;
    vert->vertexNum = vertNum;
    vert->x = x;
    vert->y = y;
    vert->c = typeOfCell;
    vert->visited = false;

    vertices.push_back(vert);
}

/**
 * @brief Finds the vertex number from the position of the open path in the maze
 * 
 * @param x the x-cordinate of the cell
 * @param y the y-codinate of the cell
 * @return int the vertex number of the cell
 */
int Dungeon::findVertexNumFromPosition(int x, int y){
    //TODO
    return (y + (n * x)); //n is the size of the given dungeon
}

/**
 * @brief Given the x,y cordinates of a cell, find the vertex no.s of the cells that are adjacent and possible to visit.
 * 
 * @param x 
 * @param y 
 * @return vector<int> 
 */
vector<int> Dungeon::findOpenAdjacentPaths(int x, int y){
    //TODO
    vector<int> openSpaces;
    int directions[8][2] = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}}; //repersents all 8 possible travel directions and the change in x and y
    for(int i = 0; i < 8; i++){
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) { //n is the size of the dungeon
            continue;
        }

        cell_type nCell = dungeon[nx][ny];
        if(nCell == start || isContaminated(nx, ny) || nCell == wall){
            continue;
        }

        int num = findVertexNumFromPosition(nx, ny);
        openSpaces.push_back(num);
    }

    return openSpaces;
}


vertex* Dungeon::findVertexByNum(int num){
    for(auto& v : vertices){
        if(v->vertexNum == num){
            return v;
        }
    }
    return nullptr;
}
/**
 * @brief For each cell, find and store it's neighbors, essentially converting the matrix to an adjacency list representation. 
 * 
 */
void Dungeon::convertDungeonToAdjacencyListGraph(){
    //TODO
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cell_type cell = dungeon[i][j];
            if(isContaminated(i, j) || cell == wall){
                continue;
            }
            addVertex(i, j, cell);
        }
    }

    for(auto& v : vertices){
        vector<int> nNums = findOpenAdjacentPaths(v->x, v->y);
        for(int nNum : nNums){
            adjVertex adj;
            vertex* neighbor = findVertexByNum(nNum);
            adj.v = neighbor;
            v->adj.push_back(adj);
        }
    }
}


/**
 * @brief Determine whether a cell is contaminated 
 */
bool Dungeon::isContaminated(int x, int y){
	// TODO
    // First, check if the tile itself is radioactive.
    if(dungeon[x][y] == radioactive)
        return true;

    // Define the 8 possible directions (all adjacent neighbors).
    int directions[8][2] = {{-1, -1}, {0, -1}, {1, -1},{-1,  0},{1,  0},{-1,  1},{0,  1},{1,  1}};

    for (int i = 0; i < 8; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];

        // Check bounds.
        if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
            if (dungeon[nx][ny] == radioactive)
                return true;
        }
    }

    // No contamination detected.
    return false;
}


/**
 * This function is supposed to return true if the Dungeon is traversal is possible and false if not.
 */
vertex* dfsHelper(vertex* vert){
    vert->visited = true;
    if(vert->c == END){
        return vert;
    }
    vector<adjVertex> neighbors = vert->adj;
    int size = neighbors.size();
    for(int i = 0; i < size; i++){
        if(!neighbors[i].v->visited){
            vertex* result = dfsHelper(neighbors[i].v);
            if(result != nullptr){
                return result;
            }
        }
    }
    return nullptr;
}


bool Dungeon::isDungeonTraversable(){
    //TODO
    for(auto& v : vertices){
        if(v->c == start){
            return dfsHelper(v);
        }
    }
    return false;
}




/**
 * @brief Destroy the Dungeon:: Dungeon object
 * 
 */
Dungeon::~Dungeon(){
    //TODO
    for(auto v : vertices){
        delete v;
    }
    vertices.clear();


    for(int i = 0; i < n; i++){
        delete[] dungeon[i];
    }
    delete[] dungeon;
}
