/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on 9/12/2020 @ 17:46
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

//Function to read in values and place even integers into one vector array and
//odd numbers into another vector array.
void read(vector<int> &evenV, vector<int> &oddV)
{
    int size, //total number of integers
        num; //to hold the values entered by user
    
    cout<<"Input the number of integers to input.\n";
    cin>>size; //get the number of integers that will be input
    cout<<"Input each number.\n";
    for (int i=0;i<size;i++)
    {
        cin>>num; //get each number one by one
        if (num%2==0) //if the number is even put it in the even vector
            evenV.push_back(num);
        else //if the number is odd put it in the odd vector
            oddV.push_back(num);
    }
}

//Function to copy the contents of two vectors into a 2d array.
//Input even, odd, then array.
void copy(vector<int> evenV,vector<int>oddV,int a[][COLMAX])
{
    for (int c=0;c<COLMAX;c++)
    {
        if (c!=0) //if we're looking at the odd numbers vector
        {
            for (int r=0;r<oddV.size();r++) //fill the array wih all the odd numbers
                a[r][c]=oddV[r];
        }
        else if (c==0) //if we're looking at the even numbers vector
        {
            for (int r=0;r<evenV.size();r++) //fill the array with all the even numbers
                a[r][c]=evenV[r];
        }
    }
}

//Function to display the contents of two vector arrays, one array per column.
//Input even vector and odd vector, as well as the number of spaces to display
//between each column of numbers.
void prntVec(vector<int> evenV, vector<int> oddV,int n)//int n is the format setw(n)
{
    //Display the header for the vector
    cout<<setw(n)<<"Vector"<<setw(n)<<"Even"<<setw(n)<<"Odd"<<endl;
    
    //Display the table of values: even in left column, odd in right column
    if (oddV.size()>evenV.size()) //if the odd vector is bigger...
    {
        for (int i=0;i<oddV.size();i++)
        {
            if (i<evenV.size()) //if there is still a number left in the even vector, display it
                cout<<setw(n)<<" "<<setw(n)<<evenV[i];
            else //if there are no more letters left in the even vector, but more in the odd, display spaces only
                cout<<setw(n)<<" "<<setw(n)<<" ";
            cout<<setw(n)<<oddV[i]<<endl; //display the odd number
        }
    }
    else //if the even vector is bigger
    {
        for (int i=0;i<evenV.size();i++)
        {
            cout<<setw(n)<<" "<<setw(n)<<evenV[i]; //display the even number
            if (i<oddV.size()) //if there is still a number left in the odd vector, display it
                cout<<setw(n)<<oddV[i]<<endl;
            else //if there are no more letters left in the odd vector, display spaces only
                cout<<setw(n)<<" "<<endl;
        }
    }
}

//Function to display the contents of a 2d array.
//Input integer array, the size of the even column, the size of the odd column,
//and the number of spaces to display between each column of numbers.
void prntAry(const int a[][COLMAX],int eSize,int oSize,int n)
{
    //Display the header for the array
    cout<<setw(n)<<"Array"<<setw(n)<<"Even"<<setw(n)<<"Odd"<<endl;
    
    if (oSize>eSize) //if the odd column is longer than the even column, then ....
    {
        for (int i=0;i<oSize;i++)
        {
            if (i<eSize) //if there is still a number left in the even column, then display it
                cout<<setw(n)<<" "<<setw(n)<<a[i][0];
            else //if there are no more numbers left in the even column, then display a space instead of a number
                cout<<setw(n)<<" "<<setw(n)<<" ";
            cout<<setw(n)<<a[i][1]<<endl; //display the next number in the odd column
        }
    }
    else //if the even column is the longer one, then...
    {
        for (int i=0;i<eSize;i++)
        {
            cout<<setw(n)<<" "<<setw(n)<<a[i][0]; //display the next number in the even column
            if (i<oSize) //if there is a number left in the odd column, then display it
                cout<<setw(n)<<a[i][1]<<endl;
            else //if there are no more numbers left in the odd column, then display a space instead of a number
                cout<<setw(n)<<" "<<endl;
        }
    }
}