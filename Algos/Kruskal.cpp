#include<algorithm>
#include <iostream>
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  int arr[n][n];
  f(i,0,n)
  f(j,0,n)
  {
      if(i==j)
        arr[i][j]=100001;// in kruskal cant go to self... and 10^5 is max
      else arr[i][j]=-1;
  }
  f(i,0,m) //cost adjacency matrix
  {
      int a,b,c;
      cin>>a>>b>>c;
      a--;b--;
      if(arr[a][b]==-1)
      arr[a][b]=arr[b][a]=c;
      else if(arr[a][b]>c)
        arr[a][b]=arr[b][a]=c;
  }
  f(i,0,n)
  f(j,0,n)
      if(arr[i][j]==-1)
        arr[i][j]=100001;// so that -1 weights dont get picked up.... can be simplified but na !

  int s;
  cin>>s;
  s--;
  int seta[n];
  f(i,0,n) seta[i]=0;
  int cost=0,indx,indx2,j,flag;
  indx=min_element(arr[s],arr[s]+n)-arr[s];
  seta[indx]=1;seta[s]=1;
  cost=arr[s][indx];
  //cout<<endl<<indx;

  while(true)
  {
      indx=-1,indx2=-1,flag=1;
      f(a,0,n)
        if(seta[a]==0)
         {
             flag=0;
             break;
         }
      if(flag==1)
        break;
      f(i,0,n)
      {
          if(seta[i]==0)
          {
              if(indx==-1)
              {
                  j=i;
                  indx=min_element(arr[i],arr[i]+n)-arr[i];
              }

              else
              {
                  indx2=min_element(arr[i],arr[i]+n)-arr[i];
                  if(arr[j][indx]>arr[i][indx2])
                  {
                      indx=indx2;j=i;
                  }
              }
          }
      }
      seta[indx]=1;
      seta[j]=1;
      cost=cost+arr[j][indx];

  }

cout<<cost;
}
