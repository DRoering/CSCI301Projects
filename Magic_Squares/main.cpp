#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void readArray(int[]);
int horArray(int[],int,int,int,int,int);
int diagArray(int[], int);
int vertArray(int[], int, int, int, int, int, int);


int main()
{
    //This list of integers is essential because we need variables that have a value that
    //does not change during the recursion in the functions.
    int num = 0;
    int cubeArray[101];
    int total;
    int counter=1;
    int horTrue;
    int diagTrue;
    int vertTrue;

    readArray(cubeArray);

//This code sets the num variable to the number that needs to be squared
//and total is the magic square equation.
    num= cubeArray[0];
    total= num*((num*num)+1)/2;

    cout<< "total:"<< total<< endl;
//This is the value setting process before the tests are run
    int amount= num*num +1;
    int numStatic= num;
    int place = 1;
    int placehold = num;

   horTrue = horArray(cubeArray,num,total,counter,amount,numStatic);

   diagTrue = diagArray(cubeArray, total);

   vertTrue = vertArray(cubeArray, num, total, counter, amount, placehold, place);
//The functions return 1 if they equal the equations and 0 if they dont,
//meaning if they all return 1, its a magic square.
   if(horTrue == 1 && diagTrue == 1 && vertTrue == 1)
   {
       cout << " The Array Makes A Magic Square" << endl;
   }
   else
   {
       cout << "The Array Does Not Make A Magic Square" << endl;
   }
    return 0;
}

void readArray(int cubeArray[])
{
    //read in file name and load the array.
    int amount =0;
    string fileName;
    cout << "Please Enter a File Name: " << endl;
    cin >> fileName;
    ifstream myfile (fileName.c_str());

    myfile >> cubeArray[0];
    amount= cubeArray[0];
    amount= amount*amount +1;


    if (myfile.is_open());
    {
     cout << "This is the Array You Opened: " << endl;
     int i = 1;
     while (i < amount)
      {
             myfile >> cubeArray[i];
             cout<< cubeArray[i]<< endl;
             i++;
      }
    myfile.close();
    }
}

int horArray(int cubeArray[],int num, int total, int counter, int amount,int numStatic)
{
    int finalNum = 0;


    while (counter<=num)
    {
        finalNum+= cubeArray[counter];
        counter++;
    }

 // cout<< counter<< endl;
 // cout<< "amount:"<< amount<< endl;
 // cout<< "finalNum:"<< finalNum<< endl;
 // cout<< "total:"<< total<< endl;

 //recursion to add up every row
    if (finalNum== total)
    {
    if (counter== amount)
    {
        return 1;
    }

    else
    {
        num+=numStatic;
        horArray(cubeArray, num, total, counter,amount,numStatic);
    }
    }
    else
    {
        cout<< "It is not a magic cube."<< endl;
        return 0;
    }
}

int diagArray(int cubeArray[], int total)
{
    int amount = cubeArray[0];
    int arraysize = (amount * amount) +1;
    int arraysize2 = amount;
    int arraysize3 = amount - 1;
    int arraysize4 = amount + 1;
    int numtotald = 0;
    int numtotald2 = 0;
    int i = 1;
    int x = arraysize2;
    int g = 0;
    //loop that adds up the forwards diagnal
    while(i < arraysize)
    {
        numtotald += cubeArray[i];
        i = i + arraysize4;

    }
//loop that adds up the numbers in the backwards diagnal.
    while(g < amount)
    {
        numtotald2 += cubeArray[x];
    //    cout << cubeArray[x] << endl;
              x += arraysize3;
              g++;

    }
   // cout << "numtotal: " << numtotald << endl;
  //  cout << "numtotal2: " << numtotald2 << endl;

    if(numtotald == total)
    {
     if(numtotald2 == total)
     {
         return 1;
     }
    }
    else return 0;
    return 0;
}

int vertArray(int cubeArray[],int amount, int total, int counter, int num,int placehold,int place)
{
    int numTotal = 0;
    counter=place;
    int i=0;

    while (i<placehold)
    {
        numTotal+= cubeArray[counter];
        counter+=placehold;
        i++;
    }

    place++;

    cout<< counter<< endl;
//cout<< "amount:"<< amount<< endl;
//cout<< "numtotal:"<< numTotal<< endl;
//cout<< "total:"<< total<< endl;

//recursion functions to add up every column
    if (numTotal== total)
    {
        if (place== placehold)
        {
            return 1;
        }

        else
        {
            num+=1;
            vertArray(cubeArray, amount, total, counter,num,placehold,place);
        }
    }
    else
    {
        cout<< "It is not a magic cube."<< endl;
        return 0;
    }
}


