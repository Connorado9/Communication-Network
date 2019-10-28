//Connor Humiston
//Godley 310
//Data Structures
//Communication Network

//The main file

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "CommunicationNetwork.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    //Reading the message file name from the terminal command line
    char* messageFileName = argv[1];

    CommunicationNetwork network;

    bool isRunning = true;
    while(isRunning)
    {
        //Program start
        //Printing the menu:
        cout << "\n";
        cout << "======Main Menu======" << endl;
        cout << "1. Build Network" << endl;
        cout << "2. Print Network Path" << endl;
        cout << "3. Transmit Message Coast-To-Coast-To-Coast" << endl;
        cout << "4. Add City" << endl;
        cout << "5. Delete City" << endl;
        cout << "6. Clear Network" << endl;
        cout << "7. Quit" << endl;

        int numIn;
        string stringIn;
        cin >> numIn;

        switch(numIn)
        {
            case 1: //build network
            {
                cout << "Build Network" << endl;
                network.buildNetwork();
                network.printNetwork();
                break;
            }

            case 2: //print network path
            {
                cout << "Print Network" << endl;
                network.printNetwork();
                break;
            }

            case 3: //transmitting message coast to coast
            {
                cout << "Transmit Message" << endl;
                cout << "\n";
                network.transmitMsg(messageFileName);
                break;
            }

            case 4: //adding city
            {
                cout << "Add City" << endl;
                cout << "\n";
                string newCityName = "";
                string previousCityName;

                cin.ignore();
                cout << "Enter a city name: " << endl;
                getline(cin, newCityName);

                cout << "Enter a previous city name (\"First\" for network start or \"\" for end): " << endl;
                getline(cin, previousCityName);

                network.addCity(newCityName, previousCityName);
                cout << "Here\'s the current network, " << endl;
                network.printNetwork();
                break;

            }

            case 5: //delete city
            {
                cout << "Delete City" << endl;
                cout << "\n";
                string deleteCityName;
                cin.ignore();
                cout << "Enter a city name: " << endl;
                getline(cin, deleteCityName);
                //cin.ignore();

                network.deleteCity(deleteCityName);
                cout << "Here\'s the current network, " << endl;
                network.printNetwork();
                break;
            }

            case 6: //clearing network
            {
                cout << "Clear Network" << endl;
                cout << "\n";
                network.deleteNetwork();
                break;
            }

            case 7:
            {
                cout << "Goodbye!\n" << endl;
                isRunning = false;
                network.~CommunicationNetwork();
                exit(0);
                break;
            }

            default:
            {
                cout << "Sorry that wasn't an option. Please reload the program and try again." << endl;
                isRunning = false;
            }
        }
    }
}


