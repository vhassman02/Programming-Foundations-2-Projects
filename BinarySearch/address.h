#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std; 

class Address
{
    public:
        Address(); //default constructor 
        Address(double Latitude, double Longitude, int Number, string Name); //non-default constructor 
        Address(const Address & newAddress);//copy constructor 
        ~Address(); //destructor 
        
        //Getter methods
        double getLatitude() const;
        double getLongitude() const;
        int getHouseNumber() const;
        string getName() const; 
        
        //Setter methods
        void setLatitude(double Latitude);
        void setLongitude(double Longitude);
        void setHouseNumber(int hn);
        void setStreetName(int sn); 
        
        //Print method 
        void print() const;
        void printGeo() const; 
        void printAddress() const;
    
    private:
        double latitude;
        double longitude;
        int houseNumber;
        string streetName; 
};
#endif 
