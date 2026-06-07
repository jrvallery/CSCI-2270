#include "enemy_graph.hpp"
#include <iostream>

EnemyGraph::EnemyGraph() {
	return;
}

EnemyGraph::~EnemyGraph() {
    for (auto entry : vertices) {
        delete entry.second;
    }
    vertices.clear();
}

Vertex* EnemyGraph::addVertex(string id) {
    // Check for unique ID
    if (vertices.count(id) > 0) {
        cout << "ID already exists: " << id << endl;
        return nullptr;
    }
    Vertex* v = new Vertex();
    v->id = id;
	v->distance = 0;
	v->solved = false;
    vertices.insert({id, v});
    return v;
}

Vertex* EnemyGraph::searchVertex(string id) {
	Vertex* toReturn = nullptr;
	for (auto entry : vertices) {
		if (entry.first == id)
			return entry.second;
	}
	return toReturn;
}

/**
 * Adds an undirected edge between two vertices with specified IDs.
 */
void EnemyGraph::addEdge(string v1_id, string v2_id, string enemy_id) {
    // Verify that the IDs exist and are unique
    if (v1_id == v2_id) {
        cout << "v1_id and v2_id must be different!" << endl;
        return;
    }
    if (vertices.count(v1_id) == 0) {
        cout << "No Vertex with ID: " << v1_id << endl;
        return;
    }
    if (vertices.count(v2_id) == 0) {
        cout << "No Vertex with ID: " << v2_id << endl;
        return;
    }

    Vertex* v1 = vertices.at(v1_id);
    Vertex* v2 = vertices.at(v2_id);

    // Verify that edge doesn't already exist
    for (const auto &v : v1->adjacent) {
        if (v.v->id == v2_id) {
            cout << "There is already an edge between " << v1_id << " and " << v2_id << endl;
            return;
        }
    }
    for (const auto &v : v2->adjacent) {
        if (v.v->id == v1_id) {
            cout << "There is already an edge between " << v1_id << " and " << v2_id << endl;
            return;
        }
    }

    AdjacentVertex adj_v2;
    adj_v2.v = v2;
    adj_v2.enemy_id = enemy_id;
    v1->adjacent.push_back(adj_v2);

    AdjacentVertex adj_v1;
    adj_v1.v = v1;
    adj_v1.enemy_id = enemy_id;
    v2->adjacent.push_back(adj_v1);
}

/**
 *
 */
bool EnemyGraph::buildGraphFromFile(string fname) 
{
    
    ifstream ifile;
    ifile.open(fname.c_str());
    if( !ifile.is_open())
    {
        cout<<"wrong file name or path"<<endl;
        return false;
    }
    string line;
    while(getline(ifile,line))
    {
        stringstream s(line);
        string type; // vertex or edge
		string vertex_ID; // data for vertex
		string vertex1, vertex2, charName; // data for edges
        getline(s,type,';'); //cout<<movieName<<endl;
		if (type == "vertex") {
        	getline(s,vertex_ID,';'); 
			addVertex(vertex_ID);
		} else if (type == "edge") {
        	getline(s,vertex1,';');
        	getline(s,vertex2,';'); 
        	getline(s,charName,';'); 
			addEdge(vertex1, vertex2, charName);
		} else {
			cout << "line read error..." << endl;
		}
    }
    return true;
}

/**
 *  Your implmentation should run a Dijkstra's search from the start vertext to the end
 *   - Edges are labeled with character names, 
 *   - Edge weights will be the character's highest damage item
 */

int EnemyGraph::findEasiestPath(HashTable& ht) {
	//TODO
    Vertex* start = searchVertex("start");
    Vertex* end = searchVertex("end");

    start->distance = 0;
    vector <Vertex*> solved;
    solved.push_back(start);

    while(!end->solved){
        int minDistance = INT_MAX; //Shortest distance from all adjacent nodes of solved verticies
        Vertex* solvedV = nullptr; //Solved vertex for this iteration

        for(int i = 0; i < solved.size(); i++){ //Iterates through every solved vertex
            Vertex* vert = solved[i];
            int size = vert->adjacent.size(); //Size of adjacency list

            for(int j = 0; j < size; j++){ //Iterates through given adjacency
                Vertex* adj = vert->adjacent[j].v;

                if(!adj->solved){
                    string enemyId = vert->adjacent[j].enemy_id; //Finds enemy id for given edge
                    node* enemy = ht.searchCharacter(enemyId); //Finds character based on id
                    if (!enemy || enemy->pq.isEmpty()) continue; //checks that enemy exsits and pq isnt empty

                    int weight = enemy->pq.peek()->damage; //sets weight to top of enemy pq
                    int distance = vert->distance + weight; //calculates distance to given vertice

                    if(distance < minDistance){
                        solvedV = adj;
                        minDistance = distance;
                    }
                }
            }
        }
        if (!solvedV) {
            cout << "No valid path to end found.\n";
            return -1;
        }
        
        /*
        We have now found the node with the shortest path within all solved nodes adjaceny list
        Now we update its values and add it to the list of solved nodes
         */
        solvedV->distance = minDistance;
        solvedV->solved = true;
        solved.push_back(solvedV);
    }
    return end->distance;
}
