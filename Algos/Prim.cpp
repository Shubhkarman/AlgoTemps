#include<algorithm>
#include <iostream>
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;

long int arr[3000][3000];

int main()
{
  long int n,m;
  cin>>n>>m;
//  int arr[n][n];
  f(i,0,n)
  f(j,0,n)
  {
     // if(i==j)
        arr[i][j]=100001;// in prim cant go to self... and 10^5 is max
   //   else arr[i][j]=-1;
  }
  f(i,0,m) //cost adjacency matrix
  {
      long int a,b,c;
      cin>>a>>b>>c;
      a--;b--;
      if(arr[a][b]==100001)
      arr[a][b]=arr[b][a]=c;
      else if(arr[a][b]>c)
        arr[a][b]=arr[b][a]=c;
  }
/*  f(i,0,n)
  f(j,0,n)
      if(arr[i][j]==-1)
        arr[i][j]=100001;// so that -1 weights dont get picked up.... can be simplified but na !
  */
  long int s;
  cin>>s;
  s--;
  int seta[n];
  f(i,0,n) seta[i]=0;
  long int cost=0,mini=-1;// mini for new min fucn
  int indx,indx2,j,flag;
  indx=min_element(arr[s],arr[s]+n)-arr[s];
  seta[indx]=1;seta[s]=1;
  cost=arr[s][indx];
  arr[s][indx]=arr[indx][s]=100001; //so that it doesnt repeat... special for prim not kruskal

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
          if(seta[i]==1) //changed frm kruskal... if seta=1 then find smallest. but make sure it doesnt repeat
          {
              if(indx==-1)
              {
                  j=i;
                  //indx=min_element(arr[i],arr[i]+n)-arr[i];
                  mini=-1;
                  f(u,0,n) //new min fucn.. to include no cycle argument
                  {
                      if(seta[u]==0) // the cycle argument... no repeat
                      if(mini==-1)
                      {
                          mini=u;
                      }
                      else
                      {
                          if(arr[u]<arr[mini])
                            mini=u;
                      }
                  }
                  indx=mini;
              }
              else
              {
                  //indx2=min_element(arr[i],arr[i]+n)-arr[i];
                  mini=-1;
                  f(u,0,n) //new min fucn.. to include no cycle argument
                  {
                      if(seta[u]==0) // the cycle argument... no repeat
                      if(mini==-1)
                      {
                          mini=u;
                      }
                      else
                      {
                          if(arr[u]<arr[mini])
                            mini=u;
                      }
                  }
                  indx2=mini;
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
//      no need for the below step if new min is used
//      arr[j][indx]=arr[indx][j]=100001; //so that it dont repeat... special for prim not in kruskal

  }

cout<<cost;
}
