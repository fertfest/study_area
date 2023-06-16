#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Car {
public:
    // TODO: Fill in method signatures!
    string getMake() { return make;}
    string getModel() { return model;}
    int getYear() { return year;}
    int getMileage() { return mileage;}
    void drive(int dis) { mileage += dis; }
    void displayInfo() { cout << "make: " << make << " model: " << model 
        << " year: " << year << " mileage: " << mileage << endl; }
    Car(string make, string model, int year, int mileage) : 
        make(make), model(model), year(year), mileage(mileage){}

private:
    // TODO: Fill in private member variables
    string make;
    string model;
    int year;
    int mileage;
};
