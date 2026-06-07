#include "LinkedInNetwork.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void LinkedInNetwork::addProfessional(string name){
    //TODO
    for(auto&p : professionals){
        if(p->name == name){
            cout<<name<<" found."<<endl;
            return;
        }
    }
    Professional* pro = new Professional;
    pro->name = name;
    professionals.push_back(pro);
}

void LinkedInNetwork::addConnection(string v1, string v2){
    //TODO
    Professional* p1;
    Professional* p2;

    //Traverse professionals vector to find matching professions
    for(Professional* p : professionals){
        if (p->name == v1)
        {
            p1 = p;
        }
        if (p->name == v2)
        {
            p2 = p;
        }
    }
    //Check both professions exsist
    if (!p1 || !p2){
        cout << "One or both professionals do not exist." << endl;
        return;
    }

    //Add connection between two professions
    neighbor n1 = {p1};
    neighbor n2 = {p2};

    p1->neighbors.push_back(n2);
    p2->neighbors.push_back(n1);
}

void LinkedInNetwork::displayConnections(){
    //TODO
    for (Professional* p : professionals){
        cout << p->name << " -->";
        for (auto & n : p->neighbors){
            cout << " " << n.v->name;
        }
        cout << " " << endl;
    }
}

void LinkedInNetwork::breadthFirstTraverse(string sourceProfessional){
    //TODO
    Professional* pro = nullptr;
    for (auto&p : professionals){
        if(p->name == sourceProfessional){
            pro = p;
            break;
        }
    }
    if (!pro){
        cout << "Could not find source professional." << endl;
        return;
    }

    queue<pair<Professional*, int>>que;
    que.push({pro, 0});
    pro->visited = true;
    cout << "Starting Professional (root): " << sourceProfessional << "-> ";
    
    while (!que.empty()){
        auto front = que.front();

        Professional* pro = front.first;
        int currentLevel = front.second;
        que.pop();

        for (neighbor p : pro->neighbors){
            if (!p.v->visited){
                p.v->visited = true;
                p.v->connectionOrder = currentLevel + 1;
                que.push({p.v, p.v->connectionOrder});
                cout << p.v->name <<"("<< p.v->connectionOrder <<")"<< " ";
            }
        }
    }
}

void bfs_helper(string source, vector<Professional*> &professionals) {
    Professional* pro = nullptr;
    for (auto&p : professionals){
        if(p->name == source){
            pro = p;
            break;
        }
    }
    if (!pro){
        cout << "Could not find source professional." << endl;
        return;
    }

    queue<pair<Professional*, int>>que;
    que.push({pro, 0});
    pro->visited = true;
    
    while (!que.empty()){
        auto front = que.front();

        Professional* pro = front.first;
        int currentLevel = front.second;
        que.pop();

        for (neighbor p : pro->neighbors){
            if (!p.v->visited){
                p.v->visited = true;
                p.v->connectionOrder = currentLevel + 1;
                que.push({p.v, p.v->connectionOrder});
            }
        }
    }
}

vector<string> LinkedInNetwork::suggestProfessionalsWithinKthOrder(string professionalName, int k){
    bfs_helper(professionalName, professionals);
    vector<string> professionalsWithinK;

    for (auto& p : professionals){
        if (p->connectionOrder > 0 && p->connectionOrder <= k){
            professionalsWithinK.push_back(p->name);
        }
    }
    return professionalsWithinK;
}