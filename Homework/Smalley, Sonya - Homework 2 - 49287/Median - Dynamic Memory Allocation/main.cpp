/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 24, 2020, 12:00 PM
 * Purpose: Calculate the Median
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *,int);     //Print the median Array

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    int aSize,           //Array size
        *array=nullptr;  //Array of integers
    float *medArr=nullptr;
    
    //Fill an integer array
    array=getData(aSize);
    
    //Fill the median array with the float array size, median of the integer array, and the integer array data
    medArr=median(array,aSize);
    
    //Display Outputs
    prntDat(array,aSize);
    prntMed(medArr,aSize);
    
    //Delete allocated memory
    delete []array;
    delete []medArr;
    array=nullptr;
    medArr=nullptr;
    
    //Exit stage right!
    return 0;
}

//Function input is the variable to hold the size of the array.
//Initializes the size of the array (input by user) and returns the filled array.
int *getData(int &size)         //Return the array size and the array
{
    //Initialize the size of the array
    cin>>size;
    
    //Allocate memory to the integer array
    int *a=new int[size];
    
    //Fill the array with user input (integers)
    for (int i=0;i<size;i++)
        cin>>*(a+i);
    
    //Exit Function
    return a;
}

//Function inputs are the pointer to an integer array and the size of the array.
//Outputs the array.
void prntDat(int *a,int size)    //Print the integer array
{
    //Print the integer array
    for (int i=0;i<size;i++)
    {
        cout<<*(a+i);
        if (i!=size-1)
            cout<<" ";
    }
    cout<<endl;
}

//Function inputs are the integer array and the size of the array
//Returns the median float array.
float *median(int *a,int size)  //Fill the median Array with the Float array size, the median, and the integer array data
{
    //Allocate memory for the median float array
    float *median=new float[size+2];
    
    //Fill the first element of the median array with the number of elements it holds
    //and the second element with the position of the median in the array
    median[0]=size+2.0; //The median array is 2 elements larger than than the integer array
    median[1]=size/2.0+0.5; //The median position is in the center of a sorted array
    
    //Fill the rest of the median array
    for (int i=2;i<size+2;i++)
        *(median+i)=*(a+(i-2));
    
    //Exit Function
    return median;
}


void prntMed(float *medianA, int size)     //Print the median Array
{
    //Print the first element (the size) of the array
    cout<<medianA[0];
    //Print the rest of the median array
    for (int i=1;i<size+2;i++)
    {
        cout<<setprecision(2)<<fixed<<showpoint;
        cout<<" "<<*(medianA+i);
    }
}