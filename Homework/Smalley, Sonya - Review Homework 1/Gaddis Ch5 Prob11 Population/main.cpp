/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on August 29, 2020, 11:33 AM
 * Purpose: Predict the size of a population of organisms based on the starting
 *      number of organism, their average daily population increase, and the
 *      number of days they will multiply.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    int start,end, //starting and ending population sizes
        days; //number of days of population growth
    float gRate; //growth rate (daily)
    
    //Initialize Variables
    cout<<"Predict a Future Population Size\n"<<endl;
    
    //Get the starting number
    cout<<"Enter the starting number of organisms: ";
    cin>>start;
    while (start<2) //Validate the entry
    {
        cout<<"A starting number of at least 2 organisms must be entered.\n";
        cout<<"Enter the starting number of organisms: ";
        cin>>start;
    }
    end=start;
    
    //Get the daily increase
    cout<<"Enter the average daily increase in the population as a percentage: ";
    cin>>gRate;
    while (gRate<0) //Validate the entry
    {
        cout<<"This program only predicts future population growth, not decline.\n";
        cout<<"Enter the average daily increase in the population as a percentage: ";
        cin>>gRate;
    }
    gRate/=100.0;
    
    //Get the number of days they will multiply
    cout<<"Enter the number of days the population will be increasing: ";
    cin>>days;
    while (days<1) //Validate the entry
    {
        cout<<"This program only predicts future population growth, not decline.\n";
        cout<<"Enter the number of days the population will be increasing: ";
        cin>>days;
    }

    //Display Outputs
    for (int count=0;count<days;count++) //Determine the final population size
        end+=(gRate*end); //do not allow for fractional organisms - round down
    cout<<endl<<"The final population size after "<<days<<" days will likely be "
        <<end<<" organisms.\n";

    //Exit stage right!
    return 0;
}

