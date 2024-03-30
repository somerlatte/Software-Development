#include <iostream>
using namespace std;
#define SIZE 5

int main (){
    long value1 = 200000;
    long value2;
    long *long_ptr; //1

    long_ptr = &value1; //2
    cout << *long_ptr << " "; //3
    value2 = *long_ptr; //4
    cout << value2 << " "; //5
    cout << &value1 << " "; //6
    cout << long_ptr << " "; //7
    if (&value1 == long_ptr)
    {
        cout << "1" << " "; //8
    }

    unsigned int values [SIZE]; //9
    for (int i = 0; i < SIZE; i++)
    {
        values [i] = (i*2) + 2;
    }
    
    unsigned int *v_ptr; //10
    int i;
    for (i = 0; i < SIZE; i++)
    {
    cout << values [i] << " "; //11
    }

    v_ptr = values; 
    v_ptr = &values [0]; //12

    for (i = 0; i < SIZE; i++)
    {
    cout << values [i] << " "; //13
    }

    for (i = 0; i < SIZE; i++)
    {
    cout << *(values + i)  << " "; //14
    }

    for (i = 0; i < SIZE; i++)
    {
    cout << v_ptr [i] << " "; //15
    }

    cout << values [4] << " ";
    cout << *(values + 4) << " ";
    cout << v_ptr [4] << " ";
    cout << *(v_ptr + 4) << " "; //16

    cout << v_ptr + 3 << " ";
    cout << *(v_ptr + 3) << " "; //17

    cout << v_ptr - 4 << " ";
    cout << *(v_ptr - 4) << " ";


    return 0;
}
