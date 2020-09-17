/* 
 * File:   main.cpp
 * Author: Sonya Smalley
 * Created on 9/13/2020 @ 19:48
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}

//Function tests if the char array is within the integer size range of an
//unsigned short (0 to 65,535) and assigns the value in the array to the 
//unsigned short. Returns true if it's within range, false if it's not.
bool  inRange(const char a[],unsigned short &unS)//Output true,unsigned or false
{
    unS=0;
    
    for (int i=0;a[i]!='\0';i++) //check the array until you hit null zero
    {
        if (a[i]-48>=0&&a[i]-48<10) //if the element contains a digit greater than 0 but less than 10...
            //add the digit to the unsigned short variable, but first move any digits already there over one place
            //and then convert the digit to be added to an integer
            unS=(unS*10)+(a[i]-48);
        else if (a[i]>32&&a[i]<48||a[i]>57&&a[i]<127) //if the element contains something other than 1 to 9
            return false;
    }
    
    if (unS<0||unS>65535) //if the value in the array is not within the range of an unsigned short
        return false;
    else //if the value in the array is within the range of an unsigned short
        return true;
}

//Function reverses the value in the unsigned short and places the reversed
//value into the signed short, adding 0s to the end until there are five digits in the signed short.
bool  reverse(unsigned short unS,signed short &snS)//Output true,short or false
{
    short digit,count; //digit holds the digits and count counts the digits
    
    count=0;
    snS=0;
    
    while (unS!=0&&snS<32767&&snS>=0) //as long as the number is in the range of a signed short and the unsigned short isn't 0
    {
        digit=unS%10; //copy the ones place digit from the unsigned short
        snS=(snS*10)+digit; //add it to the ones place in signed short while moving signed short's other digits over
        if (snS<0) //it can't be negative
            return false;
        unS/=10; //remove the ones place digit from unsigned short (it's all used up and you don't need it anymore)
        count++; //count the number of digits added to the signed short
    }
    
    while (count<5&&snS<32767&&snS>=0) //as long as the number is in the range of a signed short
    {
        snS=snS*10; //if the signed short doesn't have all five possible digits filled, then add 0s to the end until it does
        if (snS<0) //it can't be negative
            return false;
        count++; //count the digits added to the signed short until it has five digits
    }
    
    return true;
}

//Function will subtract a number from the signed short
short subtrct(signed short snS,int n)
{
    if (snS>n) //as long as the signed short is bigger than the number to be subtracted from it
    {
        snS-=n; //subtract the number from the signed short
        return snS;
    }
    else //if the signed short is not as big as the number to subtract, don't do anything to the signed short
        return snS;
}