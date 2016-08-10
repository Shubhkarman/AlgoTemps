#include <iostream>

using namespace std;

int main()
{
    //fstream in;
    //in.open("input.txt");
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[n+1][n+1];
        for(int i=1;i<n+1;i++)
            for(int j=1;j<n+1;j++)
            arr[i][j]=-1;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
//            x--;y--;//to change the values for starting frm 0
            arr[x][y]=arr[y][x]=6;
        }
        int s;
        cin>>s;
        arr[s][s]=0;
//        s--;//to change the values for starting frm 0


/***************
    This Bitch ain't BFC nigga
                ****************/
//bcuz their is no check back for changes made... like if 2 were initially not connected to 1, but 3 is connected to both
// it would also make 2 connected and thus opening the possibilities for every one connected to 2 as well

/*        for(int i=1;i<n+1;i++)
        {
            if(i!=s) // valle
            if(arr[s][i]!=-1)
            {
                for(int j=1;j<n+1;j++)
                {
                    if(j!=s) // to prevent confusion... :P
                    if(arr[s][j]==-1&&arr[i][j]!=-1)
                    {
                        arr[s][j]=arr[s][i] + 6;
                    }
                }
            }
        }
*/



        for(int i=0;i<n;i++)
        {
            if(i!=s)
            {
                if(arr[s][i]==0)
                    cout<<-1<<" ";
                else
                    cout<<arr[s][i]<<" ";
            }

        }
    }
    cout<<endl;
    //in.close();
}
