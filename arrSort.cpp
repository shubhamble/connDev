#include <iostream>

using namespace std;

class arrSort {
    int* list; // Pointer to dynamically allocated array
    int size;  // To store the size of the array
public:
    arrSort(int[], int); // Constructor with an parameter for array and size
    void sortedArr(); // Method to print the sorted array
    void getSortedArr();    // getter function to get the sorted array
    ~arrSort(); // Destructor to free dynamically allocated memory
};

arrSort::arrSort(int arr[], int n)
{
    size = n;
    list = new int[size];
    cout << "Integers that are passed:" << endl;
    for(int i = 0 ; i<size; i++)
    {
        list[i] = arr[i];
        cout << "\t" << arr[i];
    }
}

void arrSort::sortedArr(){
    int temp;
    cout << endl;
    for(int i =0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(list[j] > list[j+1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

void arrSort::getSortedArr(){
    cout << endl;
    cout << "size: " << size << endl;
    for(int i=0; i<size; i++){
        cout << "\t" << list[i];
    }
    cout << endl;
}

arrSort::~arrSort(){
    delete[] list;
}

// int main() {
//     int arr[] = {2,52,1,4,9,35,31,21};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     cout << "size: " << size << endl;
//     arrSort l(arr, size);
//     l.sortedArr();
//     l.getSortedArr();

//     return 0;
// }