//Connor Humiston
//Godley 310
//Data Structures
//Communication Network

//This file is where the methods are implemented

#include "CommunicationNetwork.hpp" //including the the other declarations
#include <iostream>
#include <fstream>
using namespace std;

//constructor & destructor w/ :: telling the compiler that I am defining addCity which is part of communicationNetwork class
CommunicationNetwork::CommunicationNetwork()
{
	head = NULL;
}
CommunicationNetwork::~CommunicationNetwork()
{
	deleteNetwork();
}

// Insert a new city into the linked list after the previousCityName. The name of the new city is in the argument newCityName.
void CommunicationNetwork::addCity(string newCityName, string previousCityName)
{
	//instantiating a new City
	City* newcity = new City;
	newcity->name = newCityName;
	newcity->message = "";
	newcity->next = NULL;
	newcity->prev = NULL;

	//searching for the previous city name & determining if it's valid
	City* temp = head;
	City* leftcity = NULL;
	City* tailcity = NULL;
	bool isValidName = false;
	if(previousCityName.compare("First") == 0)
	{
		isValidName = true;
	}
	else //not inserting at the head so we must search for the previous city name
	{
		while(temp != NULL)
		{
			if(temp->name.compare(previousCityName) == 0)
			{
				leftcity = temp;
				isValidName = true;
				break;
			}
			else
			{
				if((temp->next == NULL) && !(previousCityName.compare("\"\"") == 0))
				{
					isValidName = false;
					break;
				}
				else if((temp->next == NULL) && (previousCityName.compare("\"\"") == 0)) 
				{
					tailcity = temp;
					isValidName = true;
					break;
				}
				temp = temp->next;
			}
		}
	}
	
	//if the previousCityName entered is valid
	if(isValidName) 
	{
		//inserting the city at the head
		if(previousCityName.compare("First") == 0 /*|| leftcity == NULL*/)  
		{
			//head->prev = newcity;
			newcity->next = head;
			head = newcity;
			if(head->next != NULL)
				head->next->prev = head;
		}
		else if(previousCityName.compare("\"\"") == 0) //inserting at user
		{
			tailcity->next = newcity;
			newcity->prev = tailcity;
		}
		else if(leftcity->next == NULL) //inserting a new city at the tail node
		{
			leftcity->next = newcity;
			newcity->prev = leftcity;
		}
		else //middle of the list
		{		
			leftcity->next->prev = newcity;
			newcity->prev = leftcity;
			newcity->next = leftcity->next;
			leftcity->next = newcity;
		} 
	}
	else //the previousCityName is not valid
	{
		cout << "\nThe previous city name you entered is invalid. Please try again." << endl;
	}
}


// Open the file and transmit the message between all cities in the network word by word. A word needs 
// to be received at the beginning of the network after being sent to the end of the network before 
// sending the next word (coast to coast to coast). Only one city can hold the message at a time; as soon as 
// it is passed to the next city, it needs to be deleted from the sender city. 
void CommunicationNetwork::transmitMsg(char* filename)
{
	//reading the message
    ifstream in(filename);
    if (!in)
    {
        cout << "File can't be opened! " << endl;
        exit(1);
    }
    string currentMessageWord;
    while (!in.eof()) //while not at the end of file marker
    {
        in >> currentMessageWord;

        City* currentCity = head;
        if(head == NULL)
   		{
        	cout << "The network is empty." << endl;
        	break;
    	}
   		else
   		{
       		while(currentCity != NULL)
       		{
       			currentCity->message = currentMessageWord;
       			cout << currentCity->name << " recieved " << currentCity->message << endl;

       			currentCity->message = ""; //deleting the message before we move on
       			currentCity = currentCity->next;

       			if(currentCity->next == NULL) //if we are at the end of the network we need to go backward
       			{
	       			while(currentCity != NULL)
	       			{
	       				currentCity->message = currentMessageWord;
	       				cout << currentCity->name << " recieved " << currentCity->message << endl;

	       				currentCity->message = "";
	       				currentCity = currentCity->prev;
	       			}
	       		}
       		}
       	} 
    }
}


// Start at the head of the linked list and print the name of each city in order to the end of the list.
void CommunicationNetwork::printNetwork()
{
	City *temp = head;
	cout << "\nNULL <-> ";
	while(temp != NULL)
	{
		cout << temp->name << " <-> ";
		//if(tmp->next != NULL) cout << ", ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}


// Build the initial network from the cities given in the writeup. The cities can be fixed in the function, 
// you do not need to write the function to work with any list of cities.
void CommunicationNetwork::buildNetwork()
{
	deleteNetwork();
	addCity("Los Angeles", "First");
	addCity("Phoenix", "Los Angeles");
	addCity("Denver", "Phoenix");
	addCity("Dallas", "Denver");
	addCity("St. Louis", "Dallas");
	addCity("Chicago", "St. Louis");
	addCity("Atlanta", "Chicago");
	addCity("Washington, D.C.", "Atlanta");
	addCity("New York", "Washington, D.C.");
	addCity("Boston", "New York");
}


// Find the city in the network where city name matches removeCity. Change the next and previous 
// pointers for the surrounding cities and free the memory.
void CommunicationNetwork::deleteCity(string removeCity)
{
	City* cityDelete;
	City* temp = head; 
	City* toDelete;
	if(temp == NULL) //if head is NULL (nothing in the list)
	{
		cout << removeCity << " not found" << endl;
	}
	else if(head->name.compare(removeCity) == 0) //we are trying to delete the head
	{
		toDelete = head;
		cout << "deleting " << toDelete->name << endl;
		if(head->next != NULL)
			head->next->prev = NULL;
		head = head->next; 
		delete toDelete;
	}
	else //not deleting at the head
	{
		while(temp != NULL)
		{
			if(temp->next == NULL) //if the next is NULL (end of the list)
			{
				cout << removeCity << " not found" << endl;
				break;
			}
			else if(temp->next->name.compare(removeCity) == 0) //if the next node has the value we are looking for, temp is leftnode and next is toDelete
			{
				toDelete = temp->next; 
				if(toDelete->next == NULL) //if we are at tail
				{
					temp->next = NULL;
					cout << "deleting " << toDelete->name << endl;
					delete toDelete;
					break;
				}
				else //if we are not at tail
				{
					temp->next = toDelete->next;
					toDelete->next->prev = temp;
					cout << "deleting " << toDelete->name << endl;
					delete toDelete;
					break;
				}
			}
			temp = temp->next; //keeps going along the list
		}
	}
}


// Delete all cities in the network, starting at the head city.
void CommunicationNetwork::deleteNetwork()
{
	City* temp = head; 
	while(temp != NULL)
	{
		if(temp->next != NULL)
		{
			deleteCity(temp->name);
			temp = temp->next;
		}
		else //if you are at the end of the list we only delete the last element, not move on
		{
			deleteCity(temp->name);
			break;
		}
	}
}


