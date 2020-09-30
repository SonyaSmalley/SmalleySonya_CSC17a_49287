/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 27, 2020, 4:35 PM
 * Purpose: Given an array, create a parallel array that represents the successive
 * sum of preceding members in the array.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int *getData(int &); //Return the array size and the array from the inputs
int *sumAry(const int *,int);//Return the array with successive sums
void prntAry(const int *,int);//Print the array

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    int *array=nullptr, //integer array
        *sumsAry=nullptr; //parallel array that represents the successive sum of preceding members in the array
    int sizeA; //size of the array (dynamic)
    
    //Fill an integer array
    array=getData(sizeA);
    
    //Display origianl array
    prntAry(array,sizeA);
    
    //Reverse copy array
    sumsAry=sumAry(array,sizeA);
    
    //Display parallel array of successive sums
    cout<<endl;
    prntAry(sumsAry,sizeA);
    
    //Delete allocated memory
    delete []array;
    array=nullptr;
    delete []sumsAry;
    sumsAry=nullptr;

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

//Function input 
int *sumAry(const int *arr,int size)  //Return the array with successive sums
{
    int *a=new int[size]; //parallel array will hold the succesive sums of the original array
    
    //Fill the parallel array
    for (int i=0;i<size;i++)
    {
        if (i==0) //Element zero in the parallel array is equal to the value in the original array element 0
            *(a+i)=*(arr+i);
        //The rest of the elements in the parallel array equal the value in the original array corresponding
        //element plus the value in the parallel array previous element
        else 
            *(a+i)=*(arr+i)+(*(a+i-1));
    }
    
    //Exit function
    return a;
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