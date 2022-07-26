#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstring>

using namespace std;


///function prototype for the creation of the testArrays
int testArray(int&, int&, char[][1672], int, int);
void deleteOldPath(int, int, char[][1672]);


int main()
{
    int arraySize = 0;
    int integerArray[2];


    cout << "Welcome To the charArray!" << endl;


    int rows = 0;
    int columns = 0;
    int finalValue;
    string fileName;
    int begining = 0;
    int placehold = begining;






    cout << "Please Enter a File Name For the charArray: " << endl;
    cin >> fileName;
    ifstream myfile (fileName.c_str());

    myfile >> integerArray[0];
    rows = integerArray[0];

    myfile >> integerArray[1];
    columns= integerArray[1];
    arraySize = ((rows * columns));
    char charArray[arraySize][1672];


     if (myfile.is_open());
    {

     int counter = 0;




      while (!myfile.eof() && (counter < sizeof(charArray)))
        {
            myfile.getline(charArray[counter],(1672));

            counter++;
        }


        for (int i = 0; i < counter; i++)
        {

            cout << charArray[i] << endl;
        }

    }

        int row=1;
        int col=1;

///finds begining
   while(charArray[row][col] != ' ')
   {
       col+=1;
   }



    charArray[row][col] = '@';

     finalValue= testArray(row, col, charArray, finalValue, columns);
     deleteOldPath(rows, columns, charArray);


    for(int i = 0; i <= columns; i++)
    {
        cout << endl;
      for (int j = 0; j <= rows; j++)
        {

            cout << charArray[i][j];
        }

    }

    myfile.close();
     return 0;
}


int testArray(int& row, int& col, char charArray[][1672], int finalValue, int columns)
{

///checks for begining
    if (row < 1)
    {
        return 0;
    }


///checks end
    if ((row) >= (columns))
    {
        cout<< "You finished the Maze!!!"<< endl;
        return 1;
    }


///checks below
    if (charArray[row+1][col] == ' ')
    {
        charArray[row+1][col] = '@';
        row+= 1;
        finalValue= testArray(row, col, charArray, finalValue, columns);

        return 1;
    }

///checks right
    else if (charArray[row][col+1] == ' ')
    {
        charArray[row][col+1] = '@';
        col+=1;
        finalValue= testArray(row, col, charArray, finalValue, columns);

        return 1;
    }

///checks left
    else if (charArray[row][col-1] == ' ')
    {
        charArray[row][col-1] = '@';
        col-=1;
        finalValue= testArray(row, col, charArray, finalValue, columns);


        return 1;
    }


///checks above
    else if (charArray[row-1][col] == ' ')
    {
        charArray[row-1][col] = '@';
        row-=1;
        finalValue= testArray(row, col, charArray, finalValue, columns);


        return 1;
    }


///
///backtracking:
///

///rewrites values up
   else if(charArray[row-1][col] == '@')
    {
        charArray[row][col]= '$';
        row-=1;
        finalValue= testArray(row, col, charArray, finalValue, columns);
        return 0;
    }

///rewrites values left
    else if(charArray[row][col-1] == '@')
    {
        charArray[row][col]= '$';
        col-=1;
        finalValue= testArray(row, col, charArray, finalValue, columns);
        return 0;
    }

///rewrite values right
    else if(charArray[row][col+1] == '@')
    {
        charArray[row][col]= '$';
        col+=1;
        finalValue= testArray(row, col, charArray, finalValue, columns);
        return 0;
    }

///rewrite values down
    else if(charArray[row+1][col] == '@')
    {
        charArray[row+1][col]= '$';
        row+=1;
        finalValue= testArray(row, col, charArray, finalValue, columns);
        return 0;
    }

    return 0;

}

void deleteOldPath(int rows, int columns, char charArray[][1672])
{

    for( int i=0; i< columns; i++)
    {
        for(int j=0; j<rows; j++)
        {
            if(charArray[i][j]== '$')
            {
                charArray[i][j]= ' ';
            }
        }
    }
}







