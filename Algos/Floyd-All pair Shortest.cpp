#include <bits/stdc++.h>

using namespace std;
int arr[400][400];
int main()
{
    ios::sync_with_stdio(0);
    fstream in,out;
    in.open("in.txt");
    out.open("out.txt");

    int n,m;
    in>>n>>m;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=-1;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        in>>x>>y>>z;
        x--;y--;
        arr[x][y]=z;
    }

    /// all pair short paths
    /// we have i and j to traverse the matrix and then k for the nodes through which we can traverse
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][k]!=-1 && arr[k][j]!=-1)
                {
                    if(arr[i][j]==-1)
                    {
                        arr[i][j]=arr[i][k]+arr[k][j];

                    }
                    else
                    {
                        if(arr[i][k]+arr[k][j] < arr[i][j])
                        {
                            arr[i][j]=arr[i][k]+arr[k][j];
                        }

                    }
                }
            }
        }
    }

    int q;
    in>>q;
    for(int i=0;i<q;i++)
    {
        int x,y;
        in>>x>>y;
        x--;y--;
        if(x==y)
            out<<0<<endl;
        else
        out<<arr[x][y]<<endl;
    }
    in.close();
    out.close();
}
