#include<iostream>
using namespace std;

struct cab{

    int cabId;
    string driverName;
    string cabType;
    float pricePerKm;

};

int main() {
    int x;
    float distance;

    
     cab cabs[6] = {
        {101, "Mukesh", "Auto", 10.0},
        {102, "Suresh", "Motorcycle", 15.0},
        {103, "Sonu", "Economy", 20.0},
        {104, "Ramesh", "Sedan", 30.0},
        {105, "Anil", "SUV", 40.0}, 
        {106, "Kabeer", "Luxury", 45.0}
    };


    cout << "Welcome to the Cab Booking System!" << endl;
    cout << "Available Cabs:" << endl;
    cout << "[1] Auto " << endl << "[2] Motorcycle " << endl
         << "[3] Economy " << endl << "[4] Sedan " << endl
         << "[5] SUV " << endl << "[6] Luxury " << endl;


    do {
        cout << "Please select a cab type by entering the corresponding number: "; 
        cin >> x;
        if(x < 1 || x > 6){
            cout << "Invalid choice. Please try again." << endl;
        } 
    }while (x < 1 || x > 6);


    do {
        cout << "Enter the distance to be traveled (in km): ";
        cin >> distance;
        if(distance <= 0) {
            cout << "Distance must be greater than zero. Please try again." << endl;
        }
    } while (distance <= 0);


    float totalCost = cabs[x - 1].pricePerKm * distance;
    cout << "Booking Details:" << endl;
    cout << "Cab Type: " << cabs[x - 1].cabType << endl;
    cout << "Cab ID: " << cabs[x - 1].cabId << endl;
    cout << "Driver Name: " << cabs[x - 1].driverName << endl;
    cout << "Total Distance: " << distance << " km" << endl;
    cout << "Price per km: Rs" << cabs[x - 1].pricePerKm << endl;
    cout << "Total Cost: Rs" << totalCost << endl;
    return 0;
}