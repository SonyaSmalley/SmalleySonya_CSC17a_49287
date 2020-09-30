/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 24, 2020, 2:35 PM
 * Purpose: Sort and reverse a dynamic array
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int *getData(int &);            //Fill the array
int *sort(const int *,int);     //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order
void prntDat(const int *,int);  //Print the array

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    int sizeA,  //The size of an array
        *array=nullptr, //Dynamic array
        *aCopy=nullptr; //Copy of the array - copy is to be sorted and reversed
    
    //Fill an integer array
    array=getData(sizeA);
    
    //Fill an index array and sort the data lowest to highest
    aCopy=sort(array,sizeA);
    
    //Display Outputs
    prntDat(aCopy,sizeA);
    
    //Reverse copy array
    aCopy=reverse(aCopy,sizeA);
    
    //Display Outputs
    cout<<endl;
    prntDat(aCopy,sizeA);
    
    //Delete allocated memory
    delete []array;
    array=nullptr;
    delete []aCopy;
    aCopy=nullptr;
    
    //Exit stage right!
    return 0;
}


int *getData(int &size)             //Fill the array
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


int *sort(const int *a,int size)      //Sort smallest to largest
{
    //Copy the array
    int *arr=new int[size];
    for (int i=0;i<size;i++)
        *(arr+i)=*(a+i);
    
    //Sort the array
    for (int last=size-1;last>0;last--)
    {
        for (int i=0;i<last;i++) //Go through the array...
        {
            if (*(arr+i)>*(arr+i+1)) //and if the lower position is greater..
            {
                int temp=*(arr+i); //swap the values in the two elements
                *(arr+i)=*(arr+i+1);
                *(arr+i+1)=temp;
            }
        }
    }
    
    //Exit function
    return arr;
}


int *reverse(const int *a,int size)   //Sort in reverse order
{
    //Copy the array
    int *arr=new int[size];
    for (int i=0;i<size;i++)
        *(arr+i)=*(a+i);
    
    //Sort the array
    for (int last=size-1;last>0;last--)
    {
        for (int i=0;i<last;i++) //Go through the array...
        {
            if (*(arr+i)<*(arr+i+1))//and if the lower position is smaller...
            {
                int temp=*(arr+i);//swap the values in the two elements
                *(arr+i)=*(arr+i+1);
                *(arr+i+1)=temp;
            }
        }
    }
    
    //Exit function
    return arr;
}


void prntDat(const int *arr,int size)   //Print the array
{
    //Print the array
    for (int i=0;i<size;i++)
    {
        cout<<arr[i];
        if (i!=size-1)
            cout<<" ";
    }
}