/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 27, 2020, 6:29 PM
 * Purpose: Augment a 1-D array by 1 Element, place 0 in the first element and copy the rest from the original shifted by 1 index
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    int *array=nullptr, //original integer array
        *augArr=nullptr; //augmented array is filled with a 0 in the first element, and the rest is a shifted copy of the original
    int sizeA; //size of the array (dynamic)

    //Fill an integer array
    array=getData(sizeA);
    
    //Fill the augmented array
    augArr=augment(array,sizeA);
    
    //Display origianl array
    prntAry(array,sizeA);
    
    //Display augmented array
    cout<<endl;
    prntAry(augArr,sizeA+1);
    
    //Delete allocated memory
    delete []array;
    array=nullptr;
    delete []augArr;
    augArr=nullptr;
    
    //Exit stage right!
    return 0;
}


//Function input is the variable to hold the size.
//Returns an integer array and the size.
int *getData(int &size)  //Fill the array
{
    //Get user input on the size of the array
    cin>>size;
    
    //Allocate memory to the array
    int *arr=new int[size];
    
    //Fill the array with user input
    for (int i=0;i<size;i++)
        cin>>*(arr+i);
    
    //Exit function
    return arr;
}

//Function input is a pointer to an integer array and its size.
//Function returns an augmented array, which holds zero in the first
//element and then the rest is the original array duplicated
int *augment(const int *a,int size)//Augment and copy the original array
{
    //Allocate memory to the augment array
    int *arr=new int[size+1];
    
    //The first element of the augmented array holds 0
    *arr=0;
    
    //Copy the original array into the rest of the augmented array
    for (int i=0;i<size;i++)
        *(arr+i+1)=*(a+i);
    
    //Exit function
    return arr;
}


//Function input is the pointer to the array and the size of the array.
//Function displays the array/
void prntAry(const int *arr,int size)   //Print the array
{
    //Print the array
    for (int i=0;i<size;i++)
    {
        cout<<arr[i];
        if (i!=size-1)
            cout<<" ";
    }
}