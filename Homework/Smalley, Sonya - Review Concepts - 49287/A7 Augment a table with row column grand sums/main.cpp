/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on 9/8/2020 @ 21:05
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

//Function prompts users to input size of an array: first rows, then columns.
//Then function prompts user to input values into the array.
//Parameters are the 2d array, the  row size variable, and the column size variable.
void read(int a[][COLMAX],int &rows,int &cols)//Prompt for size, then table
{
    cout<<"Input a table and output the Augment row,col and total sums.\n";
    cout<<"First input the number of rows and cols. <20 for each\n";
    cin>>rows>>cols; //Get the size of the rows and columns
    
    cout<<"Now input the table.\n";
    for (int r=0;r<rows;r++) //Get the values of the array elements
    {
        for (int c=0;c<cols;c++)
        {
            cin>>a[r][c];
        }
    }
}

//Function to add the sum of each row to an additional column and to add the sum
//of each column to an additional row. The Grand sum is displayed in the 
//intersection of the additional row and column.
//Input parameters are the integer array, the row size, the column size,
//and the augmented array that will hold the additional row and column with the sums.
void sum(const int a[][COLMAX],int rows,int cols,int newA[][COLMAX])//Sum rows,col,grand total
{
    int sumR,sumC, //variables for the sum of each row and column
        sumAll=0; //variable to hold the grand total
    
    //Copy each row of the original array into the new array (aa)
    //Sum each row and put the sum into the element at the end of the row of the new array
    for (int r=0;r<rows;r++)
    {
        sumR=0; //start at 0 for the start of the count for each row
        
        for (int c=0;c<cols;c++)
        {
            newA[r][c]=a[r][c]; //copy from the old array in the new array
            sumR+=a[r][c]; //add the value in each element of this row to the total for the row
            sumAll+=a[r][c]; //add the value in each element to the grand total
        }
        newA[r][cols]=sumR; //put the row total into the new array
    }
    
    //Sum each column and put the sum into the element at the end of the column of the new array
    for (int c=0;c<cols;c++)
    {
        sumC=0; //start at 0 for the start of the count for each column
        
        for (int r=0;r<rows;r++)
            sumC+=a[r][c]; //start at 0 for the start of the count for each column
        newA[rows][c]=sumC;
    }
    
    //Put the grand total of all the values in the original array into the bottom right corner of the new array
    newA[rows][cols]=sumAll;
}

//Function to display a 2d array as a table.
//Input parameters are the integer array, the rows, the columns, and the spacing to include between values.
void print(const int a[][COLMAX],int rows,int cols,int spaces)//Either table can be printed
{
    for (int r=0;r<rows;r++) //Get the values of the array elements
    {
        for (int c=0;c<cols;c++)
        {
            cout<<setw(spaces)<<a[r][c];
        }
        cout<<endl;
    }
}