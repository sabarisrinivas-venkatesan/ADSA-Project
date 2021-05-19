// Merkle Tree Array Implementation

#include<bits/stdc++.h>
using namespace std;
#define k 3

typedef vector<vector<int>> node;

int hashs(int n)
{
    return n%10;
}


int main ()
{
    vector <int> a;

    a.push_back (21);
    a.push_back (32);
    a.push_back (32);
    a.push_back (32);
    a.push_back (28);
    a.push_back (98);

    int n = 6;

    node result;

    cout << "Given Data is" << endl; 
    for (auto x:a) cout << x << " " ;

    cout << endl;   

    result.push_back(a);

    int r = 0;

    while (result[r].size() > 1)
    {
        vector<int> temp;

        for (int i = 0;i<result[r].size();i+=k)
        {
            int tempi = 0;
            for  (int j = i;j<i+k;j++)
            {
                //cout << result[r][j] << " "; 
                tempi += hashs(result[r][j]);
            }

            temp.push_back(tempi);
            tempi = 0;
            //cout << endl;
        }

        result.push_back(temp); 
        r++;

    }


   cout << "The Constructed tree is" << endl; 
     for (int i = 0; i < result.size(); i++) {
        for (
            auto it = result[i].begin();
            it != result[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
   
}