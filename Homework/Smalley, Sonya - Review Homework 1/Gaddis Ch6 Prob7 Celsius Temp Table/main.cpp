/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on August 29, 2020, 12:13 PM
 * Purpose: Show a table of fahrenheit and celsius temperatures
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void celsius(float); //Function to convert Fahrenheit to Celsius

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    float fTemp; //Temperature in Fahrenheit

    //Initialize Variables
    cout<<"Enter a temperature in degrees Fahrenheit: \n";
    cin>>fTemp;
    
    //Display Outputs
    cout<<"Fahrenheit"<<setw(11)<<"Celsius\n";
    celsius(fTemp); //output the user's converted temperature
    cout<<"---------------------------------"<<endl;
    
    for (int count=0;count<=20;count++) //output a table of converted temperatures
    {
        fTemp=count;
        celsius(fTemp);
    }

    //Exit stage right!
    return 0;
}

//Function to convert a temperature from Fahrenheit to Celsius
void celsius(float fahr)
{
    //Initialize variable
    float cels; //Temperature in Celsius
    
    //Display output
    cels=(5.0/9.0)*(fahr-32);
    
    cout<<setprecision(1)<<fixed<<showpoint;
    cout<<setw(6)<<fahr<<setw(13)<<cels<<endl;
}