// COMSC-210 | Lab 3A | Quang Ngo
// IDE used: Visual Studio Code
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// building the structure for restaurant
struct Restaurant {
    string name;
    string address;
    string cuisine;
    int numEmployees;
    double rating;
};

Restaurant populateRest();
void diplayRest(const Restaurant &);

// main function
int main() {
    vector<Restaurant> restaurants;
    int numRest;
    cout << "How many restaurants would you like to enter? ";
    cin >> numRest;
    cin.ignore();
    for(int i = 0; i < numRest; i++) {
        cout << "\nEntering information for restaurant " << i+1 << endl;
        restaurants.push_back(populateRest());
        cin.ignore();
    };
    cout << "\nHere is the information you have entered:\n";
    for(int i = 0; i < restaurants.size(); i++) {
        cout << "\nRestaurant " << i+1 << ":\n";
        diplayRest(restaurants[i]);
    }
    return 0;
}

// populateRest() gets user input to populate the structure
// returns: a Restaurant structure
Restaurant populateRest() {
    Restaurant temp;
    cout << "Enter the name: ";
    cin >> temp.name;
    cin.ignore();
    cout << "Enter the address: ";
    getline(cin, temp.address);
    cout << "Enter the cuisine: ";
    cin >> temp.cuisine;
    cout << "Enter the number of employees: ";
    cin >> temp.numEmployees;
    cout << "Enter the rating from 0 to 5: ";
    cin >> temp.rating;
    while(temp.rating < 0.0 || temp.rating > 5.0) {
        cout << "Invalid rating. Please enter a rating from 0 to 5: ";
        cin >> temp.rating;
    }
    return temp;
}

// diplayRest() displays the information of a Restaurant structure in a formatted manner
// parameters: a Restaurant structure
void diplayRest(const Restaurant &r) {
    cout << "Restaurant Name: " << r.name << endl;
    cout << "IRL Address: " << r.address << endl;
    cout << "Type Of Cuisine: " << r.cuisine << endl;
    cout << "Rating: " << r.rating << endl;
    cout << "Number of Employees: " << r.numEmployees << endl;
}