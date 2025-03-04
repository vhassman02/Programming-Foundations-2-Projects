#include "address.h"
#include <iostream>

//Default constructor 
Address::Address()
{
    cout<<"default constructor was called"<<endl; 
    latitude = 0;
    longitude = 0;
    houseNumber = 0;
    streetName = "";
}

//Non-default constructor 
Address::Address(double Latitude, double Longitude, int Number, string Name) 
{
    latitude = Latitude;
    longitude = Longitude;
    houseNumber = Number;
    streetName = Name; 
}

//Copy constructor 
Address::Address(const Address & newAddress)
{
    //cout<<"copy constructor was called"<<endl;
    latitude = newAddress.latitude;
    longitude = newAddress.longitude;
    houseNumber = newAddress.houseNumber;
    streetName = newAddress.streetName; 
}

//Destructor 
Address::~Address()
{
    //empty    
}

//Getter methods 
double Address::getLatitude() const
{
    return latitude;
}

double Address::getLongitude() const
{
    return longitude; 
}

int Address::getHouseNumber() const
{
    return houseNumber; 
}

string Address::getName() const
{
    return streetName; 
}

//Setter methods 
void Address::setLatitude(double Latitude)
{
    latitude = Latitude;    
}

void Address::setLongitude(double Longitude)
{
    longitude = Longitude;
}
void Address::setHouseNumber(int hn)
{
    houseNumber = hn; 
}

void Address::setStreetName(int sn)
{
    streetName = sn; 
}

//Print methods
void Address::print() const
{
    cout<<"Latitude:     "<<latitude<<endl;
    cout<<"Longitude:    "<<longitude<<endl;
    cout<<"House number: "<<houseNumber<<endl;
    cout<<"Street name:  "<<streetName<<endl; 
    cout<<endl; 
}

void Address::printGeo() const
{
    cout<<"Latitude:     "<<latitude<<endl;
    cout<<"Longitude:    "<<longitude<<endl;
    cout<<endl; 
}

void Address::printAddress() const
{
    cout<<"Address: "<<houseNumber<<" "<<streetName<<endl; 
    cout<<endl;
}
