#include <iostream>
using namespace std;



void combine(int a[], int s, int m, int e)
{
    int* buffer = new int [e+1];
    int k = s;
    while(k<=e)
    {
        buffer[k] = a[k];
        k = k+1;
    }

    //combining the two parts
    int i = s;
    int j = m+1;
    k = s;
    while(i<=m && j<=e)
    {
        if(buffer[i] <= buffer[j])
        {
            a[k] = buffer[i];
            i++;
        }
        else
        {
            a[k] = buffer[j];
            j++;
        }
        k++;
    } 

    while(i<=m)
    {
        a[k] = buffer[i];
        i++;
        k++;
    }
    while(j<=e)
    {
        a[k] = buffer[j];
        j++;
        k++;
    }

    delete [] buffer;
}



void mrgSort(int a[], int s, int e)
{
    if(s>=e)
    {
        return;
    }
    int m = (s+e)/2;
    mrgSort(a, s, m);   //recursively sorting the first half
    mrgSort(a, m+1, e);   //recursively sorting the second half
    combine(a, s, m, e);  //combining the first and second half
}


void mrgSort(int a[], int n)
{
    mrgSort(a, 0, n-1);
}


void show(int a[], int n)
{
    int i = 0;
    while(i<n)
    {
        cout<<a[i]<<", ";
        i++;
    }
    cout<<endl;
}

int main()
{

    int arr[] = {139, 193, 2934, 2832, 11, 343, 55};
    int size = sizeof(arr)/sizeof(int);


    show(arr, size);
    mrgSort(arr, size);
    show(arr, size);
    return 0;
}