#include "Graph.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;



/////////////////////////////////////////////////////////////////////////////////////////
vertex * Graph::searchDogs(string n1)
{
vertex * d1 = NULL;

	for(unsigned int i = 0; i<vertices.size();i++)
	{
		if(vertices[i].name == n1)
		{
		d1 = &vertices[i];
		}
	}
	
return d1;


}

/////////////////////////////////////////////////////////////////////////////////////////
bool Graph::sameDist(string n1, string n2)
{
vertex * d1;
vertex * d2;

	for(unsigned int i = 0; i<vertices.size();i++)
	{
		if(vertices[i].name == n1)
		{
		d1 = &vertices[i];
		}
		if(vertices[i].name == n2)
		{
		d2 = &vertices[i];
		}
	}
	
if(d1->pack == d2 -> pack)
{
	return true;
}
else
{
	return false;
}


}

///////////////////////////////////////////////////////////////////////////////////////////

void Graph::Dijkstra(string start, string end)
{
vertex* startv;
vertex* endv;

vertex* tempv;
vertex* tempPrev;
int tempDist;
//int temPath;

//bool cont;

for(unsigned int i = 0; i < vertices.size(); i++)
{
    vertices[i].distance = 100000;
    vertices[i].parent = NULL;
    vertices[i].visited = false;
    
    if(vertices[i].name == start)
    {
    endv = &vertices[i];
    }
    
    if(vertices[i].name == end)
    {
    startv = &vertices[i];
    }
}



startv -> visited = true;
startv -> distance = 0;

while(endv -> visited != true)

{
//search all verticies for solved
//search all solved vertex edges for smallest length of all
//continue with smallest length, and mark attached vertex as solved

//reset temp variables
tempDist = 100000;
//temPath = 100000;


//search all verticies
    for(unsigned int i = 0; i < vertices.size(); i++)
    {
        
    //////////////////////////////////////////////
        //vertices[i].visited = true; 
    //////////////////////////////////////////  
    
        if(vertices[i].visited == true)
        {
            //if solved, search adjacent
            for(unsigned int j = 0; j < vertices[i].adj.size(); j++)
            {
                //if weight is smaller than temp, reset to that new smallest
                //found vertex must also be unsolved
                
                
    /////////////////////////////////////////////////////////////////////////////////////
                if(vertices[i].adj[j].weight + vertices[i].distance < tempDist && vertices[i].adj[j].v->visited == false)
                {

                    //record new weight
                   tempDist = vertices[i].adj[j].weight + vertices[i].distance;
                   //cout<<vertices[i].name<<" "<<vertices[i].distance<<endl;
                    //tempv is pointer to currently specified vertex
                    tempv = vertices[i].adj[j].v;
                    //reset acting parent
                    tempPrev = &vertices[i];
                    
                }  
                    
    

            ///////////////////////////////////////////////////////////////
            }
     
        }
      
    
    
    }
 //exit loop with tempv as the new solved vertex pointer
 //tempDist is the associated weight with taht addition
 //tempPrev is acting parent
 
 //mark as solved, mark parent, sum pervious distance with weight to make adjusted dist.
 
 tempv -> visited = true;
 tempv -> parent = tempPrev;
 tempv -> distance = tempDist;
 
 
}

tempv = endv;

 cout<<"Shortest Path"<<endl;
 cout<<tempv -> name;
if(tempv -> parent != NULL)
 tempv = tempv -> parent;
 
    
    
    while(tempv != NULL)
    {
      cout<<" -> "<<tempv -> name;
      tempv = tempv -> parent;
    }

   cout<<endl<<"Minimum Distance: "<<endv -> distance<<endl;

}



///////////////////////////////////////////////////////////////////////////////////////////

void Graph::search(string dog1, string dog2)
{
	vertex start;
	vertex end;

	
	//////////////////////////find both vertices////////////////////
	//also set all cost values to a maximum, and clear parents
	//this needs to be done in case the search has been initiated before

	for(unsigned int i = 0;i<vertices.size();i++)
	{
		vertices[i].cost = 100000;
		vertices[i].parent = NULL;
		
		if(vertices[i].name==dog1)
		{
			start = vertices[i];
			vertices[i].cost = 0;
		}
		if(vertices[i].name==dog2)
		{
			end = vertices[i];
		}
	}


	/////////////////begin recursive routine/////////////////////////////////////
	

	searchrecursion(&start,0);
	string dogtemp = end.name;
	print(dog1,dog2);

	

}

////////////////////////////////////////////////////////////////////////

void Graph::searchrecursion(vertex *vert, int cost)
{
	
	
	
		for(unsigned int i = 0;i < vert -> adj.size();i++)
		{
			if(cost + vert -> adj[i].weight < vert -> adj[i].v->cost)
			{					
			
			vert -> adj[i].v -> parent = vert;
			vert -> adj[i].v->cost = cost + vert -> adj[i].weight;
			

			
		    searchrecursion(vert -> adj[i].v,cost + vert -> adj[i].weight);
		}
	}
	
	
}

////////////////////////////////////////////////////////////////////////////
void Graph::print(string dog1, string dog2)
{
vertex* temp;
vertex* temp2;
vertex* temp3;
vertex* temp4;
int traversalcost;

	for(unsigned int i = 0;i<vertices.size();i++)
	{
		if(vertices[i].name == dog2)
		{
		temp = &vertices[i];
		traversalcost = temp -> cost;
		}
		
	}
	
	
		string dogtemp = dog2;
		
		temp2 = temp;
		temp3 = temp2;
		temp4 = temp3;
		
		int counter = 0;
		while(temp4 != NULL)
		{
		counter++;
		temp3 = temp4;
		temp4 = temp4 -> parent;
		}
		
		temp3 = temp;
		cout<<"traversed: "<<counter-1<<" Dogs"<<endl;
		cout<<"path length of: "<<traversalcost<<endl;
		
		while(temp2 != NULL)
		{
		temp = temp2;
			if(temp -> name != dog1)
			{
			cout<< temp -> name<<",";
			}
			else
			{
			cout<< temp -> name<<endl;
			}
		temp2 = temp2 -> parent;
		}
		
	
}

///////////////////////////////////////////////////////////////////////////////


void Graph::findPacks()
{
	for(unsigned int i = 0;i<vertices.size();i++)
	{
	vertices[i].pack = 0;
	}
unsigned int counter = 0;
int distcounter = 1;
	while(vertices.size() > counter)
	{
	if(vertices[counter].pack==0){
		setPacks(&vertices[counter],distcounter);
		distcounter++;
		}
	counter ++;
	}

}

void Graph::setPacks(vertex * vert,int dist){
vert -> pack = dist;

for(unsigned int i = 0;i < vert->adj.size();i++)
{
	if(vert->adj[i].v->pack == 0)
	{
	vert -> adj[i].v->pack = dist;
	setPacks(vert->adj[i].v,dist);
	}
}
}

/////////////////////////////////////////////////////////////////////////////

 
Graph::Graph()
{

}

//////////////////////////////////////////////////////////////////////////////////

Graph::~Graph()
{
    //dtor
}

//////////////////////////////////////////////////////////////////////


void Graph::addEdge(string v1, string v2, int weight){

    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(unsigned int j = 0; j < vertices.size(); j++){
				
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                    
                }
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////


void Graph::addVertex(string n){
    bool found = false;
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" already found in current dog list"<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        vertices.push_back(v);

    }
}

/////////////////////////////////////////////////////////////////////////////

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<"Pack ID: "<<vertices[i].pack<<endl;
        cout<<"Dog Name: "<<vertices[i].name<<endl;
        cout<<"Connected to: ";
        for(unsigned int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name;
            
            if(j != vertices[i].adj.size()-1)
            {
            cout<<", ";
			}
        }
        cout<<endl<<endl;
    }

}
