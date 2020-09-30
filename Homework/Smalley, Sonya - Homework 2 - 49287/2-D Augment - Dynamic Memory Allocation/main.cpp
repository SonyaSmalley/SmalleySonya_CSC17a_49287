/* 
 * File: main.cpp
 * Author: Sonya Smalley
 * Created on September 27, 2020, 6:35 PM
 * Purpose: Create a 2-D array 1 row and 1 column larger than the array to copy with 0's
 * in the 1st row and column but filled with the other rows and columns using the original array.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

//Execution Begins Here

int main(int argc, char** argv) {
    //Set Random Number seed


    //Declare Variable Data Types and Constants
    int **array=nullptr, //original integer array
        **augArr=nullptr; //augmented array is filled with a 0 in the first element, and the rest is a shifted copy of the original
    int rows,cols; //size of the rows and columns of the array (dynamic)
    
    //Fill an integer array
    array=getData(rows,cols);
    
    //Display original array
    printDat(array,rows,cols);
    
    //Fill the augmented array (first row and column with 0s and the rest is a copy of the original array)
    augArr=augment(array,rows,cols);
    
    //Display augmented array
    
    printDat(augArr,rows+1,cols+1);
    
    //Deallocate memory
    destroy(array,rows);
    destroy(augArr,rows);
    
    //Exit stage right!
    return 0;
}

//Function input is the row and column variables for the 2d array.
//Returns the array and the values of row and col.
int **getData(int &row,int &col)//Get the Matrix Data
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
void printDat(const int * const *a,int row,int col)//Print the Matrix
{
    //Display array
    for (int r=0;r<row;r++)
    {
        for (int c=0;c<col;c++)
        {
            cout<<a[r][c];
            if (c!=col-1)
                cout<<" ";
        }
        //if(r!=(row-1))        //This line makes the last augment row disappear
            cout<<endl; //if I add if(r!=row-1) in line 94 above cout<<endl;, the for loop for that row doesn't get processed for the augment array. Why???
    }
}

//Function input is the pointer to a 2d dynamic array, number of rows, and number of columns.
//Function returns an augmented array. The array is 1 row and 1 column larger than the original
//array. Zeros fill the first column and first row. The rest of the array is a copy of the original.
int **augment(const int * const *a,int row,int col)//Augment the original array
{
    //Allocate memory to the augment array row pointers
    int **arr=new int*[row+1];
    
    //Allocate memory to the column width for each row
    for (int r=0;r<row+1;r++)
        arr[r]=new int[col+1];
    
    //Fill the first row of the augmented array with 0s
    for (int c=0;c<col+1;c++)
        arr[0][c]=0;
        
    //Fill the first column of the augmented array with 0s
    for (int r=0;r<row+1;r++)
        arr[r][0]=0;
    
    //Copy the original array into the augmented array
    for (int r=1;r<row+1;r++)
    {
        for (int c=1;c<col+1;c++)
        {
            arr[r][c]=a[r-1][c-1];
        }
    }
    
    //Exit function
    return arr;
}

//Function input is the array and rows.
//Function will deallocate the memory allocated to the array.
void destroy(int **a,int row)//Destroy the Matrix, i.e., reallocate memory
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