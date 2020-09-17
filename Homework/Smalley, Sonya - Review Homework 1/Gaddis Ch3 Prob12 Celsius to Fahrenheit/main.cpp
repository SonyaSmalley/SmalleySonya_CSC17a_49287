/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on August 29, 2020, 7:13 AM
 * Purpose: Convert Celsius temperature to Fahrenheit temperature.
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
    float cTemp,fTemp;
    char choice;

    do
    {
        //Initialize Variables
        cout<<"Enter a temperature in Celsius to convert it to Fahrenheit: \n";
        cin>>cTemp;
        fTemp=(9.0/5.0)*cTemp+32.0;

        //Display Outputs
        cout<<"The temperature is "<<fTemp<<" degrees Fahrenheit.\n"<<endl;
        
        cout<<"Would you like to convert another temperature? Y/N: "<<endl;
        cin>>choice;
    }
    while (choice=='Y'||choice=='y');
    
    //Exit stage right!
    return 0;
}

