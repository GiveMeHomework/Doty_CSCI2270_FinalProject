//Daniel Doty
//Assignment10
//Hoenigman


#include "Graph.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>


using namespace std;


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
