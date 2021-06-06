#include <iostream>

using namespace std;

void numbers()
{
    int B [10]={9,3,8,6,7,4,1,5,2,0};

    for(int i=0;i<10;i++)
    {
        int m=i;
        for(int j=i+1;j<10;j++)
        {
            if(B[j]<B[m]) m=j;
        }
        swap(B[i],B[m]);
    }
    cout<<"sorted numbers:"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;
}

void heapify(char arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(char arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i = n - 1; i >= 0; i--) {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
    cout<<"sorted char:"<<endl;
    for (int i=0; i <10; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void alfWord(string arr[], int n)
{
    int i, j;
    string key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position*/
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout<<endl<<"sorted countries:"<<endl;
    for (int i=0; i <10; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    numbers();
    char A[10]={'q','w','e','r','t','Q','W','E','R','T'};
    heapSort(A,10);
    string countries [10] =  {"Nauru", "Vietnam", "Samoa", "Montenegro", "Georgia", "Kenya", "Austria", "Israel", "Singapore", "Sweden"};
    alfWord(countries,10);
    return 0;
}
