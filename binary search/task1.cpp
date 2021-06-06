#include <iostream>
#include <fstream>
#include <utility>

using namespace std;

const char FD[]="list.txt";

void read(const char FD[],int & n,int B[])
{
    ifstream fd(FD);

    fd>>n;

    for(int i=0;i<n;i++)
    {
        fd>>B[i];
        //cout <<B[i]<<endl;
    }
    fd.close();
}

void Ssort(int n,int B[])
{
    for(int i=0;i<n-1;i++)
    {
        int m=i;
        for(int j=i+1;j<n;j++)
        {
            if(B[j]<B[m]) m=j;
        }
        swap(B[i],B[m]);
    }
}

int search(int n,int I,int B[])
{
    int high=n-1;
    int low=0;
    int mid=(low+high)/2;

    while(low<=high)
    {
        int mid=(low+high)/2;
        int guess=B[mid];
        if(guess==I) return B[mid];
        else if (guess >I) high=mid-1;
        else low=mid+1;
        //cout <<B[mid]<<" ";
    }
}

int main()
{
    int n,I;

    cout <<"Choose a number from 0 to 10"<<endl;
    cin>>I;
    ifstream fd(FD);
    fd>>n;
    int B[n];

    read(FD,n,B);
    int newB[n];
    Ssort(n,B);
    /*for(int j=0;j<n;j++)
    {
        cout<<B[j];
    }*/

   /* for(int i=0;i<n;i++)
    {
        fd>>B[i];
    }*/
    int z=search(n,I,B);
    cout<<"Your number is "<<z;
    //----------------------------------- b.s.

    /*int high=n-1;
    int low=0;
    int mid=(low+high)/2;

    while(low<=high)
    {
        int mid=(low+high)/2;
        int guess=B[mid];
        if(guess==I) return B[mid];
        else if (guess >I) high=mid-1;
        else low=mid+1;
    }*/

    return 0;
}
