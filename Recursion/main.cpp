#include <iostream>
#include <string>

using namespace std;

///These are the function calls for all three choices
int exponentiation(double, double, double);
bool integerValue(int, int[], int, int);
bool findPalidrome(char[], int, int);

int main()
{
///These are the initialized variables used in all three of the functions. They directly
///reference the project on the website, ex. realvalue is the part in the project where
///a real value is asked for, etc.
    double realvalue;
    double anInteger;
    int counter = 0;
    int posInteger[counter];
    int fdigit;

    double trueExponentiation;
    bool trueIntSearch;
    bool truePalidrome;
    int i = 0;


///
///Exponential Problem
///
///

///Make a choice, 1 2 or 3 and it will run the proper part of the code
    int choice;

    cout<< "Welcome to the recursion program, What function would you like to use. type in 1 for exponentiation, 2 for does digit appear, or 3 for palidrome"<< endl;
    cin>> choice;

    if (choice == 1)
       {
///These are the inputs for the values used in the functions
         cout<< "enter a real value."<< endl;
         cin>> realvalue;
         cout<< "enter an integer."<< endl;
         cin>> anInteger;
///runs the recursive function and sets the trueExponentiation variable to either true or false since it is a boolean
         trueExponentiation = realvalue;

         trueExponentiation=exponentiation(trueExponentiation, realvalue, anInteger);
         cout<<"your answer is: "<< trueExponentiation<<endl;
       }
///
///choice 2 has all the values for the array string inputted before they are used in the function below recursivly
///
    else if(choice == 2)
    {
 cout << "Now it is time to see if a Digit is in a String! " << endl;
    cout << "How long is the number you will enter? " << endl;
    cin >> counter;
///This is the input stage
       for(int i = 0; i < counter; i++)
        {
         cout << "Please enter a positive Integer: " << endl;
         cin >> posInteger[i];
         cout << endl;
        }
///This is where you input the digit you would like to find
    cout << "Now enter a digit to be found: " << endl;
    cin >> fdigit;
///function is then run in order to determine if they are there in the string or not
       trueIntSearch = integerValue(i, posInteger, fdigit, counter);
///The return values are put out and this code shows whether it was found or not
       if(trueIntSearch == true)
       {
           cout << "The Value of : " << fdigit << " Was found in the int: ";
           for(int i = 0; i < counter; i++)
           {
               cout << posInteger[i] << " ";
           }
           cout << endl;
       }


    }
///
///This is the code for choice number 3
///
    else if(choice == 3)
    {
        int size1 = 0;
            cout << "Enter the Size of the Palidrome: " << endl;
            cin >> size1;
            cout<<"Enter the String letter by letter, separated by a space: "<<endl;
        char String1[size1];

///ints and arrays are created and then numbers are inputted into them here:
		for(int a = 0; a < size1; a++)
        {
            cin >> String1[a];
        }
         cout<<"You entered :";

		for(int i = 0; i < size1; i++)
	     {

			cout << String1[i] << "  ";

         }
        cout << endl;
        size1--;
        int c = 0;
///here the function is run and the program determines if the letters each match there mirrors
        truePalidrome =  findPalidrome(String1, size1, c);
///here the values that were returned have their outputs
        if(truePalidrome == true)
            cout << " That Line is a Palidrome!";



    }

    else
        cout<< "you did not enter a valid choice"<< endl;

       return 0;

}

///Function for choice 1

int exponentiation(double trueExponentiation, double realvalue,double anInteger)
{
///the function's recursive aspect is in this choice option
    if (anInteger>1)
    {
        trueExponentiation= trueExponentiation*realvalue;
        anInteger--;
        cout<< "R:"<<anInteger<<endl;
        cout<< trueExponentiation<< endl;
        trueExponentiation = exponentiation(trueExponentiation, realvalue, anInteger);

    }
///This is the part of the program that tests the recursivity of the problem and helps decide if it is time to
///run it again or output a return value
    else if(trueExponentiation==0)
        return 1;

        return trueExponentiation;
}

///This is the function for choice 2

bool integerValue(int i, int posInteger[], int fdigit, int counter)
{
///this function tests if a digit can be found in a string of other digits. it is recursive
///because it will check a position and then increment to the next if the number is not found
///then the return becomes false after all values in the array are exhausted
   if(posInteger[i] == fdigit)
   {
       return true;
   }
    else if(posInteger[i] != fdigit && i < counter)
    {
        ++i;
        return integerValue(i, posInteger, fdigit, counter);
    }
    else
    {
        cout << "That Number Is Not Part Of The String" << endl;
        return false;
    }

}

///This is the function for choice 3

bool findPalidrome(char String1[], int size1, int c)
{
    ///The function checks each letter in the string and compares is with it's mirrored letter recursivly, calling
    ///itself if the letters match, and returning false if any of the letters do not.
    bool recursion;

    if(String1[c] == String1[size1-c])
    {
        c++;
        recursion = findPalidrome(String1, size1, c);

    }
    else if(c >= (size1-c))
    {
        return true;
    }
    else
    {
        cout << " That Line is NOT a Palidrome.";
        return false;
    }
return true;
}
