/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on August 29, 2020, 10:55 AM
 * Purpose: Tell a user how many days are in any month of a year.
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
    int days, month, year;  //month and year to be entered by user, days to be determined

    //Initialize Variables
    cout<<"Enter a month (1-12): ";
    cin>>month;
    cout<<"Enter a year: ";
    cin>>year;
    
    //Display Outputs
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: 
            days=31;
            cout<<days<<" days"<<endl;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days=30;
            cout<<days<<" days"<<endl;
            break;
        case 2:
            if (year%100==0&&year%400==0)
                days=29;
            else if (year%100!=100&&year%4==0)
                days=29;
            else
                days=28;
            cout<<days<<" days"<<endl;
            break;
        default: cout<<"\nThe month you entered is not a real month."<<endl;
    }
    
    //Exit stage right!
    return 0;
}

