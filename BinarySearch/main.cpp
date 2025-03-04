#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath> 
#include "address.h"
using namespace std; 

//Function declarations 
void printVector(vector<Address> &address);
void readFile(string filename, vector<Address> &address);
void searchAddressCall(vector<Address> & address, int number, string street);
void searchLocationCall(vector<Address> & location, double lat, double lon, double D);
string searchAddress(int houseNumber, string streetName, int min, int max, vector<Address> &address); 
void searchLocation(double lat, double lon, double D, int min, int max, vector<Address> &location); 
string trim(const string str); 

int main()
{
    bool continuing = true; 
    int number = 0;
    string street = "";
    vector<Address> address; 
    vector<Address> location;
    
    while (continuing)
    {
        cout<<"MENU\n"
            <<"1) Search by address\n"
            <<"2) Search by location\n"
            <<"3) Exit program"<<endl;     
        int selection = 0;
        cout<<"Enter selection: ";
        cin>>selection;
        
        while (selection!=1 && selection!=2 && selection!=3)
        {
            cout<<"Invalid selection. Try again.\n\n"
                <<"1) Search by address\n"
                <<"2) Search by location\n"
                <<"3) Exit program"<<endl;  
            cin>>selection; 
        }
        
        if (selection==1)
        {
            cout<<"Enter street number: ";
            cin>>number;
            cout<<"Enter street name: ";
            string empty = "";
            getline(cin, empty);
            getline(cin, street);
            searchAddressCall(address, number, street);
            cout<<endl;
        }
        
        else if (selection==2)
        {
            double Latitude = 0.0;
            double Longitude = 0.0;
            double deltaDistance = 0.0;
            cout<<"Enter latitude: ";
            cin>>Latitude;
            cout<<"Enter longitude: ";
            cin>>Longitude;
            cout<<"Enter distance you want to search: ";
            cin>>deltaDistance;
            searchLocationCall(location, Latitude, Longitude, deltaDistance);
            cout<<endl; 
        }
        else
        {
            cout<<"Exiting program."<<endl; 
            continuing = false;
        }
    }
    return 0;
}

void readFile(string filename, vector<Address> &address)
{
    ifstream fin; //Declare file input object
    fin.open(filename); //Open the text file of addresses 
    
    //If file open is unsuccessful 
    if (fin.fail())
    {
        cout<<"File opening failed. Check that text files exist in the root directory. "<<endl; 
        main(); 
    }
    
    //Proceed otherwise 
    else 
    {
        while (!fin.eof())
        {
            //Read one line of the file 
            double latitude;
            fin>>latitude; 
            double longitude;
            fin>>longitude; 
            int number;
            fin>>number;
            string name;
            getline(fin, name);
            
            //Add the parameters to the vector's first index
            //Trim the preceeding space off name using trim() function before adding to vector 
            if (!fin.eof())
                address.push_back(Address(latitude, longitude, number, trim(name)));
        }
    }
    //Close the file when reading is complete 
    fin.close(); 
}

void searchAddressCall(vector<Address> & address, int number, string street)
{
    //Store the data from the addresses.txt into an address object vector
    readFile("addresses.txt", address); //Call to read the addresses.txt  
    int min=0;
    int max=address.size()-1;
    cout<<"Searching for "<<number<<" "<<street<<endl; 
    cout<<searchAddress(number, street, min, max, address)<<endl;
}

void searchLocationCall(vector<Address> & location, double lat, double lon, double D)
{
    //Store the data from location.txt into a location object vector 
    readFile("location.txt", location);
    cout<<"\nSearching for addresses +/- " 
        <<D<< " from coordinates "
        <<lat<<", "<<lon<<endl;
    
    searchLocation(lat, lon, D, 0, location.size()-1, location);
}

string searchAddress(int houseNumber, string streetName, int min, int max, vector<Address> &address)
{
    //Create min, mid, and max variables
    int mid=(min+max)/2;
    
    //Create a concatenated string containing street name + street number 
    string query = streetName + to_string(houseNumber);
    
    //Create a concatenated string containing street name + street number at [mid] 
    string addressAtIndex = address[mid].getName() + to_string(address[mid].getHouseNumber());
    
    //Terminating condition 
    if(max<min)
        return ("No match found"); 
        
    else if (query==addressAtIndex)
    {
        string lat = to_string(address[mid].getLatitude());
        string lon = to_string(address[mid].getLongitude());
        //trim geographic coordinates to have 4 decimal places 
        if (lat[0] == '-')
            lat.resize(8);
        else
            lat.resize(7); 
        if (lon[0] == '-')
            lon.resize(8);
        else
            lon.resize(7);
        return ("Match found at latitude " + lat + ", longitude " + lon);
    }
    
    else if (addressAtIndex<query)
        return (searchAddress(houseNumber, streetName, mid+1, max, address)); 
    
    else 
        return (searchAddress(houseNumber, streetName, min, mid-1, address)); 
}

void searchLocation(double lat, double lon, double D, int min, int max, vector<Address> &location)
{
    float dLat;
    float dLon;
    bool matchFound = false;
    
    //Loop over entire vector
    for (int i = min; i<max; i++)
    {
        //Calculate the delta latitude 
        dLat = location[i].getLatitude()-lat;
        //Calculate the delta longitude 
        dLon = location[i].getLongitude()-lon;
        
        //If the found latitude and longitude are within the desired range, print the address 
        if (fabs(dLat)<D && fabs(dLon)<D)
        {
            location[i].printAddress(); 
            matchFound = true; 
        }
    }
    if (matchFound == false)
        cout<<"No matches were found."<<endl; 
}

//-----------------------------------------------------------
// Remove white space from front and back of string
// Author: John Gauch 
//-----------------------------------------------------------
string trim(const string str)
{
    int start = 0;
    int end = str.length()-1;
    while ((start < int(str.length())) && (isspace(str[start]))) 
        start++;
    while ((end > start) && (isspace(str[end]))) 
        end--;
    return str.substr(start, (end-start+1));
}
