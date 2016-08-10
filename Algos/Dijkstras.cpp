#include <bits/stdc++.h>


using namespace std;

int arr[3000][3000];

int main()
{
    ifstream in;ofstream out;
    in.open("in.txt");
    out.open("out.txt");
    int t;
    in>>t;
    while(t--)
    {
        int n,m;
        in>>n>>m;
//        int arr[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    arr[i][j]=0;
                else
                    arr[i][j]=10000;
            }
        for(int i=0;i<m;i++)
        {
            int z=0,y=0,r=0;
            in >>z>>y>>r;
            z--;y--;//to change the values for starting frm 0
            if(arr[z][y]==10000)
            arr[z][y]=arr[y][z]=r;
            else
            {
                if(r<arr[z][y])
                    arr[z][y]=arr[y][z]=r;
            }
        }
        int s;//starting pt
        in>>s;
        s--;//to change the values for starting frm 0
//        arr[s][s]=0;
/*        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            if(arr[i][j]==-1)
                arr[i][j]=351;// 351= max val
*/





        int x,mini=0,seta[n],flag;
        for(int i=0;i<n;i++)
            seta[i]=0;
        seta[s]=1;   // initialized everything

        while(true)
        {
            mini=0;// <-- to confirm
            flag=0;
            for(int i=0;i<n;i++)
                if(seta[i]==0)
                {
                    flag=1;// seta includes all that have been included
                    break;
                }

            if(flag==0)  // still nodes remaining
                break;

            for(int i=0;i<n;i++) // to find the smallest in set
            {

                if(seta[i]==0) // valle
                {
                    if(mini==0)
                     {
                         mini=arr[s][i];
                         x=i;
                     }
                    else
                    if(arr[s][i]<mini)
                    {
                        mini=arr[s][i];
                        x=i;
                    }
                }
            }
            seta[x]=1;
            for(int i=0;i<n;i++)
            {
                if(arr[s][x]+arr[x][i] <arr[s][i])
                     arr[s][i]=arr[s][x]+arr[x][i];
            }

        }



        for(int i=0;i<n;i++)
        {
            if(i!=s)
            {
                if(arr[s][i]==10000)
                    out<<-1<<" ";
                else
                out<<arr[s][i]<<" ";
            }


        }
        out<<endl;
    }
     in.close();
    out.close();
    //in.close();
}
