/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on 9/12/2020 at 16:25
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

//Function to read in an array of characters and determine its actual size.
//Output the size.
int  read(char a[])
{
    int actSize=0;   //will hold the array's actual size
    
    while (cin>>a[actSize])    //read the array one character at a time
        actSize++; //count the characters
        
    return actSize;
}

//Function to sort a char array.
void sort(char a[],int size)
{
    for (int max=size-1;max>0;max--)
    {
        for (int i=0;i<max;i++)
        {
            if (a[i]>a[i+1])
            {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
}

//Function to display the array. Input array and array size.
void print(const char a[],int size)
{
    for (int i=0;i<size;i++)
        cout<<a[i];
    cout<<endl;
}