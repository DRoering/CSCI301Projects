#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int quickSort(int[], int, int, int);
void swaps(int*, int*);
int partitions(int[], int, int);

void Merge(int*, int, int, int);
int MergeSort(int[], int, int);


int insertion_sort(int[], int);

int main()
{
    int sortingCount;
    int Seed, counter1, counter2, counter3;
    int counter;
    char choice;


    cout << "Welcome to the Sorting Program!" << endl;
    cout << "Please enter the number of values you wish to sort: "<< endl;
    cin >> sortingCount;
    int storearray1[sortingCount];
    int storearray2[sortingCount];
    int storearray3[sortingCount];
    cout << "Enter an integer seed value: " << endl;
    cin >> Seed;
    srand(Seed);
    for(int i = 0; i < sortingCount; i++)
    {
        int value;
        value = rand();
        storearray1[i] = value;
        storearray2[i] = value;
        storearray3[i] = value;
    }

    cout << "Do you wish to see the values?  Y/N " << endl;
    cin >> choice;

    if(choice == 'y' || choice == 'Y')
    {
        for(int i = 0; i < sortingCount; i++)
        {
            cout << storearray1[i] << ' ';
        }
    }
    cout << endl;

    ///
    ///Quick sort
    ///
    int n = sizeof(storearray1)/sizeof(storearray1[0]);
    counter1 = quickSort(storearray1, 0, n-1, counter);

    ///
    ///Merge Sort
    ///
    int nn = sizeof(storearray2)/sizeof(storearray2[0]);
    counter2 = MergeSort(storearray2, 0, nn-1);

    ///
    ///Insertion sort
    ///
    counter3 = insertion_sort(storearray3,10);

    ///
    ///Final Displays
    ///
    cout << "The values have been Sorted!" << endl;
    cout << "Would you like to view them? Y/N" << endl;
    cin >> choice;

     if(choice == 'y' || choice == 'Y')
    {

        cout << "Here is Array 1: " << endl;
        for(int i = 0; i < sortingCount; i++)
        {
            cout << storearray1[i] << ' ';
        }
        cout << endl;
        cout << "Here is Array 2: " << endl;
        for(int i = 0; i < sortingCount; i++)
        {
            cout << storearray2[i] << ' ';
        }
        cout << endl;
        cout << "Here is array 3: " << endl;
        for(int i = 0; i < sortingCount; i++)
        {
            cout << storearray3[i] << ' ';
        }
        cout << endl;

        cout << "Quick Sort Count: " << counter1 << endl;
        cout << "Merge Sort Count: " << counter2 << endl;
        cout << "Insertion Sort Count: " << counter3 << endl;

    }


    return 0;
}

///
///Code for the Quick Sort
///
void swaps(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partitions (int storearray1[], int low, int high)
{
    int pivot = storearray1[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (storearray1[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swaps(&storearray1[i], &storearray1[j]);
        }
    }
    swaps(&storearray1[i + 1], &storearray1[high]);
    return (i + 1);
}

int quickSort(int storearray1[], int low, int high, int counter)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partitions(storearray1, low, high);


        // Separately sort elements before
        // partition and after partition
        quickSort(storearray1, low, pi - 1, counter);
        counter++;
        quickSort(storearray1, pi + 1, high, counter);

        return counter;
    }
}

///
///Code for the merge sort
///
void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

// A function to split array into two parts.
int MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		int counter = 1;
        counter++;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
		return counter;
	}
}

///
///Insertion sort code
///

int insertion_sort(int storearray3[], int length)
{
    int i,j,tmp;
    int counter = 1;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && storearray3[j - 1] > storearray3[j]) {
            tmp = storearray3[j];
            storearray3[j] = storearray3[j - 1];
            storearray3[j - 1] = tmp;
            j--;

            counter++;
        }
    }
    return counter;
}

