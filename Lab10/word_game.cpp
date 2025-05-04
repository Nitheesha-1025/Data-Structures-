#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<unordered_map>

using namespace std;

//Function to solve the problem 
void solve()
{
    int n;
    scanf("%d",&n);

    vector<vector<string>>words(3, vector<string>(n));
    unordered_map<string,int> freq;

    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cin >> words[i][j];
            freq[words[i][j]]++;
        }
    }

    vector<int>points(3,0);
    for(int i=0;i<3;i++)
    {
        for(const string& word:words[i])
        {
            switch(freq[word])
            {
                case 1:
                       points[i]+=3;
                       break;
                case 2:
                       points[i]+=1;
                       break;
                case 3:
                       break;
                       
            }
        }
    }
    for(int i=0;i<3;i++)
    printf("%d ",points[i]);

}

//Main function to implement the solution 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
        printf("\n");
    }
}