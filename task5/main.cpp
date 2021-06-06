#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string LCS(string s1,string s2,int i1,int i2, string memo[][100])
{
    if(i1 == s1.size() || i2 == s2.size())
            return "";

        if (memo[i1][i2] != "")
            return memo[i1][i2];

        if (s1[i1] == s2[i2])
            {
            memo[i1][i2] = s1[i1] + LCS(s1,s2,i1+1,i2+1,memo);
            return memo[i1][i2];
            }

        string result;
        string resultA = LCS(s1,s2,i1+1,i2,memo);
        string resultB = LCS(s1,s2,i1,i2+1,memo);
        if(resultA.size() > resultB.size())
        {
            result = resultA;
        }
        else
        {
            result = resultB;
        }
        memo[i1][i2] = result;
        return memo[i1][i2];
}
/*
string compare (string w1,string w2[],int n)
{
    for(int i = 0;i <= n1; i++)
    {

    }

}*/

void removeDupWord(string str, string w[])
{
    int i = 0;
    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            w[i] = word;
            cout << w[i] << endl;
            word = "";
        }
        else {
            word = word + x;
        }
    }
    w[i] = word;
    cout << w[i] << endl;
}

int main()
{

    string s1 = "I am waiting for snow.";
    string s2 = "I've been waiting for snow.";
    cout<<"Original text: I am waiting for snow."<< endl;
    cout<<"Edited text: I've been waiting for snow."<< endl;
    cout<<"Expected result: I waiting for snow."<< endl;

    string memo [100][100];

    string s3 = LCS(s1,s2,0,0, memo);

    cout<<"Actual result: "<<LCS(s1,s2,0,0, memo)<< endl;

    return 0;
}
