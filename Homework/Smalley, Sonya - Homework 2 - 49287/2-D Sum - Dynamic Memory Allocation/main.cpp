/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 27, 2020, 6:30 PM
 * Purpose: Total the elements in a 2d array
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    int **array=nullptr; //2d integer array
    int rows, //number of rows in the 2d array
        cols, //number of columns in the 2d array
        total; //sum of the values in the 2d array
    
    //Initialize Variables
    array=getData(rows,cols);
    
    //Display array
    prntDat(array,rows,cols);
    
    //Sum the array and display the Sum
    total=sum(array,rows,cols);
    cout<<total;
       
    //Deallocate memory
    destroy(array,rows,cols);
    
    //Exit stage right!
    return 0;
}

//Function input is the row and column variables for the 2d array.
//Returns the array.
int **getData(int &row,int &col)        //Return the 2-D array and its size.
{
    //Get row and col size from the user
    cin>>row>>col;
    
    //Allocate memory to the row pointers
    int **a=new int*[row];
    
    //Allocate memory to the column width for each row
    for (int r=0;r<row;r++)
        a[r]=new int[col];
    
    //Fill the array with user input
    for (int r=0;r<row;r++)
    {
        for (int c=0;c<col;c++)
        {
            cin>>a[r][c];
        }
    }
    
    //Exit function
    return a;
}

//Function input is pointer to a 2d array, rows, and columns.
//Displays the array.
void prntDat(const int* const *a,int row,int col)//Print the 2-D Array
{
    for (int r=0;r<row;r++)
    {
        for (int c=0;c<col;c++)
        {
            cout<<a[r][c];
            if (c!=col-1)
                cout<<" ";
        }
        cout<<endl;
    }
}

//Function input is the array, rows, and columns.
//Function will deallocate the memory allocated to the array.
void destroy(int **a,int row,int col)       //Deallocate memory
{
    //Delete allocated memory one row at a time
    for (int i=0;i<row;i++)
    {
        delete []a[row];
        a[row]=nullptr;
    }
    
    //Delete the row pointers
    delete []a;
    a=nullptr;
}

//Function input is a pointer to a 2d array, rows, and columns.
//Returns the sum of the values in the array.
int sum(const int * const *a, int row,int col)    //Return the Sum
{
    int total=0; //sum of values in the integer array
    
    //Sum the values of the array
    for (int r=0;r<row;r++)
    {
        for (int c=0;c<col;c++)
            total+=a[r][c];
    }
    
    //Exit function
    return total;
}