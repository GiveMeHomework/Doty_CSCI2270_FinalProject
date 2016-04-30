#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

//verticies are individual dogs
//edges are the distance between teh dogs
//"packs" are connected groups of dogs


struct vertex{
    string name;
    int pack;
    int cost;
    int distance; 
    bool solved;
    bool visited; 
    vertex* parent;
    string par;
    vector<adjVertex> adj;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2, int weight); //1
        void addVertex(std::string name); //2
        void displayEdges(); //3
        void findPacks(); //4
        void setPacks(vertex * vert,int dist); //5
        void search(string dog1, string dog2); //6
        void searchrecursion(vertex * vert, int cost); //7
        void Dijkstra(string start, string end);//8
        void print(string dog1, string dog2); //9
        bool sameDist(string n1, string n2);//10
        vertex * searchDogs(string n1);//11
        
    protected:
    private:
    vector<vertex> vertices;
};

#endif 
