Communication Between Towers
By Connor Humiston
6/30/19
Data Structures

Files: 
"CommunicationNetwork.hpp" (struct, class, and method definitions)
"CommunicationNetwork.cpp" (implementations)
"Assignment3.cpp"	   (main method)

Purpose: The purpose of this program is to simulate a communication network using a linked list. Each node in the linked list represents a city and that a message can be sent through as it travels across the country. The network of cities can be updated by adding or deleting cities along the route as the underlying linked list is changed.

Description: This C++ program built in Sublime and run through the command line is passed a file with a message that is to be sent across a network. After running the program, a main menu will be displayed with a list of options. Typing a 1 and then pressing enter builds a basic network of 10 cities across the country. To add or delete a city on the network, enter a 4 or 5 respectively. Though the current network is usually displayed after any changes are made, entering a 2 will print the current network. Entering a 3 will transmit the message from the first city to the last city and back again one message word at a time. Finally, 6 will clear the network and 7 will exit the program.

Running: The program can be compiled by typing g++ -std=c++11 followed by the file with the implementations in it followed by the main method file and then saved with -o
	For example:
		g++ -std=c++11 CommunicationNetwork.cpp Assignment3.cpp -o Assignment3
	
Next, the program would be run by typing ./Assignment3 followed by the name of the file with the message in it.
	For example:
		./Assignment3 messageIn.txt

