/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on August 30, 2020, 1:56 PM
 * Purpose: Create a report that displays, for each month in June, July, and
 *          August and for all three months together, how many days were rainy,
 *          how many were cloudy, and how many were sunny. It will also report
 *          which of the three months had the largest number of rainy days.
 *          Data is read from the file RainOrShine.txt.
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const unsigned int DAYS=30; //weather was recorded for 30 days of each summer month
const unsigned int MONTHS=3; //weather was recorded for the summer (June, July, August)
const unsigned int SIZE=10;

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare Variable Data Types and Constants
    char wData[MONTHS][DAYS]; //to hold weather data read from RainOrShine file
    ofstream outFile; //create RainOrShine file
    ifstream inFile; //read data from the RainOrShine file
    char weather[SIZE+1]="SSSSSSCCCR"; //weather is sunny (S), cloudy (C), or rainy (R)
    string months[]={"June","July","August"}; //names of the months
    short rainy[]={0,0,0}; //to hold the number of rainy days for each month of summer
    short maxRain,maxMnth; //to hold the month with the max number of rainy days

    //Initialize Variables
    //Create the file to hold the weather data for the summer
    outFile.open("RainOrShine.txt");
    for (int month=0;month<MONTHS;month++)
    {
        for (int day=0;day<DAYS;day++)
            outFile<<weather[rand()%SIZE]; //randomly assign sunny (S), cloudy (C), and rainy (R) days
        outFile<<endl;
    }
    outFile.close();
    
    //Read and store the weather data in an array
    inFile.open("RainOrShine.txt");
    for (int month=0;month<MONTHS;month++)
    {
        for (int day=0;day<DAYS;day++)
            inFile>>wData[month][day]; //populate an array with the summer weather data
    }
    inFile.close();
    
    //Count the rainy days for each summer month
    maxRain=0;
    for (int month=0;month<MONTHS;month++)
    {
        for (int day=0;day<DAYS;day++)
        {
            if (wData[month][day]=='R')
                rainy[month]+=1;
        }
        if (rainy[month]>maxRain)
        {
            maxRain=rainy[month];
            maxMnth=month;
        }
    }
    
    //Display the Summer Weather Table
    cout<<"Weather Data for the Summer Months\n";
    cout<<"----------------------------------"<<endl;
    cout<<"      ";
    for (int day=1;day<=DAYS;day++)
        cout<<setw(3)<<day;
    cout<<endl;
    for (int month=0;month<MONTHS;month++)
    {
        cout<<left<<setw(8)<<months[month]<<right;
        for (int day=0;day<DAYS;day++)
            cout<<wData[month][day]<<"  ";
        cout<<endl;
    }
    
    //Display the rainy day stats
    cout<<endl<<"------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl<<"Rainy Day Statistics from the Summer Months\n";
    cout<<"-------------------------------------------"<<endl;
    cout<<"Month with the most rain: "<<months[maxMnth]<<"..."
        <<maxRain<<" rainy days\n"<<endl;
    cout<<setw(17)<<"Rainy Days"<<endl;
    for (int month=0;month<MONTHS;month++)
        cout<<left<<setw(8)<<months[month]<<right
            <<setw(5)<<rainy[month]<<endl; //display each month's rainy day numbers
    
    //Exit stage right!
    return 0;
}

