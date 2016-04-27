//Daniel Doty
//Assignment10
//Hoenigman



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

////////////////////////////////////////////////////////////////////////


int main(){


/////////////////////////initialize variables////////////////////////

Graph dogs;
string temp;

int choice = 0;
int weight;
string c1;
string c2;

////////////////////////////////////////////////////////////////////

//////////////create inital network for testing/////////////////////
dogs.addVertex("Top Dog");
dogs.addVertex("Undercover Cat");
dogs.addVertex("L Dog");
dogs.addVertex("Service Dog");
dogs.addVertex("Pretentious Dog");
dogs.addVertex("Lost Dog");
dogs.addVertex("Dinosaur Dog");


dogs.addEdge("Top Dog","Undercover Cat",5);
dogs.addEdge("Top Dog","Lost Dog",3);
dogs.addEdge("Top Dog","L Dog",15);
dogs.addEdge("Top Dog","Dinosaur Dog",30);
dogs.addEdge("Top Dog","Pretentious Dog",200);


dogs.addEdge("Undercover Cat","Lost Dog",50);
dogs.addEdge("Undercover Cat","L Dog",13);
dogs.addEdge("Undercover Cat","Dinosaur Dog",15);
dogs.addEdge("Undercover Cat","Pretentious Dog",6);

dogs.addEdge("Lost Dog","L Dog",7);
dogs.addEdge("Lost Dog","Dinosaur Dog",30);
dogs.addEdge("Lost Dog","Pretentious Dog",457);

dogs.addEdge("L Dog","Dinosaur Dog",5);
dogs.addEdge("L Dog","Pretentious Dog",45);

dogs.addEdge("Dinosaur Dog","Pretentious Dog",55);



dogs.findPacks();

////////////////////////////////////////////////////////////////////



while(choice != 6)
{

cout << "======Main Menu======" << endl;
cout << "1. Add Dog" << endl;
cout << "2. Add Connection" << endl; 
cout << "3. Print vertices" << endl;
cout << "4. Dj shortest" << endl;
cout << "5. Find shortest path" << endl;
cout << "6. Quit" << endl; 

cin>>choice;

	if(choice==1)
	{
	cout<<"Enter name of new dog:"<<endl;
	cin.ignore();
	std::getline(std::cin,c1);

	dogs.addVertex(c1);
	dogs.findPacks();
	}

	if(choice==2)
	{
	cout<<"Enter Dog 1"<<endl;
	cin.ignore();
	std::getline(std::cin,c1);

	cout<<"Enter Dog 2"<<endl;
	std::getline(std::cin,c2);

	cout<<"Enter distance between dogs"<<endl;
	cin >> weight;

	dogs.addEdge(c1,c2,weight);
	dogs.findPacks();
	}

	if(choice == 3)
	{
	dogs.displayEdges();
	}
	if(choice == 4)
	{
	cout<<"Enter a starting Dog:"<<endl;
	cin.ignore();
	std::getline(std::cin,c1);
		
	cout<<"Enter an ending Dog:"<<endl;
	std::getline(std::cin,c2);
	
	
	if(dogs.sameDist(c1, c2)==true && dogs.searchDogs(c1) != NULL)
	dogs.Dijkstra(c1, c2);
	else
	cout<<"Those dogs are either not in the same pack, or do not exist"<<endl;
	}

	if(choice == 5)
	{
		cout<<"Enter a starting Dog:"<<endl;
		cin.ignore();
		std::getline(std::cin,c2);
		
		cout<<"Enter an ending Dog:"<<endl;
		std::getline(std::cin,c1);
		
	if(dogs.sameDist(c1, c2)==true && dogs.searchDogs(c1) != NULL)
	dogs.search(c1, c2);
	else
	cout<<"Those dogs are either not in the same pack, or do not exist"<<endl;


	}

}

cout<<"Goodbye!"<<endl;;

}
