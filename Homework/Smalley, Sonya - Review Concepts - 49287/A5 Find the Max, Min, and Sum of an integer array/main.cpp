/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on 9/8/2020 @ 17:56
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);  //Read in an integer array
int  stat(const int [],int,int &,int &); //Determine sum, min, and max
void print(const int [],int,int,int,int); //Display array values, min, max, and sum

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}

//Read in an array of integers using user specifications for initialized array length
void read(int a[],int size)
{
    for (int i=0;i<size;i++) //Read in values
        cin>>a[i];
}

//Determine the max and min values in the array, and sum all the values of the array
int  stat(const int a[],int size, int &max,int &min)
{
    int sum=0; //sum will be used to hold the summation of all the integers in the array
    max=min=a[0]; //set max and min to the value in the first element, values to be tested against values in remaining elements
    
    for (int i=0;i<size;i++) //Find min, max, and sum
    {
        sum+=a[i]; //sum the values in the array
        if (a[i]>=max) //find the max value
            max=a[i];
        if (a[i]<=min) //find the min value
            min=a[i];
    }
    
    return sum; //return the value of the summed toatl
}

//Display the values in an array of integers, as well as their sum, max, and min values
void print(const int a[],int size,int sum,int max,int min)
{
    for (int i=0;i<size;i++) //display the values of the array in format a[i]=x
        cout<<"a["<<i<<"] = "<<a[i]<<endl;
    
    //display min, max, and sum
    cout<<"Min  = "<<min<<endl; 
    cout<<"Max  = "<<max<<endl;
    cout<<"Sum  = "<<sum<<endl;
}