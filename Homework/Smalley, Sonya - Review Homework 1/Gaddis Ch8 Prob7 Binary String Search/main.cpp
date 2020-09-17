/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on August 30, 2020, 6:09 PM
 * Purpose: Modify the book's binary search function to search an array of
 *          strings instead of an array of ints.
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void selSort(string[],int); //Selection sort an array
int binSrch(const string[],int,string); //Binary search an array
void print(const string[],int); //Print an array

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    const int NUM_NAMES=20;
    string names[NUM_NAMES]={"Collins, Bill","Smith, Bart","Allen, Jim",
                             "Griffin, Jim","Stamey, Marty","Rose, Geri",
                             "Taylor, Terri","Johnson, Jill","Allison, Jeff",
                             "Looney, Joe","Wolfe, Bill","James, Jean",
                             "Weaver, Jim","Pore, Bob","Rutherford, Greg",
                             "Javens, Renee","Harrison, Rose","Setzer, Cathy",
                             "Pike, Gordon","Holland, Beth"};
    string srchNme; //name user enters to search
    
    //Initialize Variables
    cout<<"Search for a name. Enter LastName, FirstName: ";
    getline(cin,srchNme);
    selSort(names,NUM_NAMES);
    
    //Display Outputs
    cout<<"The name "<<srchNme<<" was found in element "
        <<binSrch(names,NUM_NAMES,srchNme)<<".\n";
    cout<<"If -1 was returned, then the name was not found.\n"<<endl;
    print(names,NUM_NAMES);

    //Exit stage right!
    return 0;
}

//Function to sort a string array via selection sort
void selSort(string a[],int size)
{
    string min;
    int index;
    
    for (int pos=0;pos<size-1;pos++)
    {
        index=pos;
        min=a[pos];
        for (int i=pos+1;i<size;i++)
        {
            if (a[i]<min)   //find the smallest value
            {
                min=a[i];
                index=i;
            }
        }
        a[index]=a[pos];
        a[pos]=min;
    }
}

//Function to search a string array for a name using a binary search
int binSrch(const string a[],int size,string name)
{
    int first=0,last=size-1;
    int middle;
    
    do
    {
        middle=(first+last)/2; //find the middle of the area to search
        if (a[middle]==name) //if the name is in the middle position
            return middle;
        else if (a[middle]>name) //if the name is somewhere in the lower area
            last=middle-1;
        else //if the name is somewhere in the upper area
            first=middle+1;
    }
    while (first<=last);
    
    //if the name is not found
    return -1;
}

//Function to print a string array
void print(const string a[],int size)
{
    cout<<"List of Available Names:\n";
    for (int i=0;i<size;i++)
        cout<<a[i]<<endl;
}