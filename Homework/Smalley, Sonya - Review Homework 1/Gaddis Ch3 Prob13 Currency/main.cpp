/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on August 29, 2020, 7:47 AM
 * Purpose: Convert dollars to euros
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const float YEN_PER_DOLLAR=105.36; //Conversion factor for dollars to yen
const float EUROS_PER_DOLLAR=0.84; //Conversion factor for dollars to euros

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    float dollars,yen,euros; //money

    //Initialize Variables
    cout<<"Enter a dollar amount to be converted into euros "
        <<"and the Japanese yen.\n";
    cin>>dollars;
    
    yen=dollars*YEN_PER_DOLLAR; //Convert dollars to yen
    euros=dollars*EUROS_PER_DOLLAR; //Convert dollars to euros

    //Display Outputs
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<endl<<dollars<<" dollars converts to "<<yen<<" yen or "
        <<euros<<" euros.\n";

    //Exit stage right!
    return 0;
}

