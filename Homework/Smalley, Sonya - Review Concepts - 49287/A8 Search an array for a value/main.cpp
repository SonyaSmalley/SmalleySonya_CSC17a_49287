/* 
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}

//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
int  srch1(const char sent[],const char pat[],int pos)//Search for 1 occurrence
{
    int patL,index=0;
    
    patL=strlen(pat);
    
    for (int i=pos,p=0;i<pos+patL,p<patL;i++,p++)
    {
        if (sent[i]==pat[p])
            index++;
        else
            return 0;
    }
    if (index==patL)
        return 1;
    else
        return 0;
}

//srchAll Input->sentence, pattern Output->position array
void srchAll(const char sent[],const char pat[],int pos[])//Search for all occurrences
{
    int sentL; //holds the max length of the sentence
    
    sentL=strlen(sent);
    
    for (int i=0;i<sentL;i++)
        pos[i]=srch1(sent,pat,i);
    
    pos[sentL]=-1;
}

//Function displays the contents of a char array
void print(const char a[])//Print the character arrays
{
    cout<<a<<endl;
}

void print(const int a[]) //Print the array of indexes where the pattern was found
{
    int count=0;
    
    for (int i=0;a[i]!=-1;i++)
    {
        if (a[i]!=0)
        {
            cout<<i<<endl;
            count++;
        }
    }
    
    if (count==0)
        cout<<"None"<<endl;
}