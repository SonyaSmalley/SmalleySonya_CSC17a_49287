/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on 9/12/2020 @ 17:04
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

//Function takes 2d char array and row size integer.
//Returns the length of the columns in the array.
int  read(char a[][COLMAX],int &maxRow)//Outputs row and columns detected from input
{
    int row=0,col,maxCol;
    
    while (cin>>a[row])
    {
        col=strlen(a[row]);
        row++;
        if (col>maxCol)
            maxCol=col;
    }

    if (row!=maxRow)
        maxRow=row;
    
    return maxCol;
}

//Function takes 2d char array, and integers for row and column sizes.
//Compares the rows of an array and sorts them.
void sort(char a[][COLMAX],int row,int col)//Sort by row
{
    for (int last=row-1;last>0;last--)
    {
        for (int r=0;r<last;r++)
        {
            if (strcmp(a[r],a[r+1])>0)
            {
                char temp[col];
                strcpy (temp,a[r]);
                strcpy (a[r],a[r+1]);
                strcpy (a[r+1],temp);
            }
        }
    }
}

//Function takes 2d char array, and integers for row and column sizes.
//Displays the array.
void print(const char a[][COLMAX],int row,int col)//Print the sorted 2-D array
{
    for (int r=0;r<row;r++)
    {
        for (int c=0;c<col;c++)
        {
            cout<<a[r][c];
        }
        cout<<endl;
    }
}