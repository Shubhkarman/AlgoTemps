#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
int key;
int GSA(int* arr,int low,int high,int d)
{
    int i,j,x;


    if(low == high)
    {
        if(arr[low] == key)
            return 1;
        else
            return 0;
    }
    if(low==(high-1))
    {
        if(arr[low] == key)
            return 1;
        else if (arr[high]==key)
            return 1;
        else
            return 0;

    }
    else if(low<high)
    {
        for(j=0;j<d;j++)
        {
            x = (j+1)*(low+high)/d;
            if(arr[x]==key)
            {
                return 1;
            }

            else if(arr[x]>key)
            {
                return GSA(arr,low +(j*((high-low)/d)) ,low +((j+1)*((high-low)/d)),d );
            }
            else if(arr[x]<key)
            {

                continue;

            }

        }

//        for(i =0; i<d; i++)
//        {
//            return GSA(arr,i*(low+high)/d,(i+1)*((low+high)/d),d);
//        }
    }



}
//GSA and qsort check
/*int main()
{
    int arr[5]={3,7,2,4,8}; int n =5;
//    for (int i=1;i<n;i++) {
//        arr[i]= rand();
//        cout << arr[i]<<endl;
//
//     }
//     key = arr[(rand())%n];
     key = 3;
//     key = arr[(rand())%n];
//     cout<<key;
     qsort(arr,n,sizeof(int),compare);
     int ans = GSA(arr,0,n-1,2);
    for (int i=0;i<n;i++) {
        cout << arr[i]<<endl;

     }
     cout<<key <<" "<< ans;



}
*/


int main()
{   double sum=0.0;  double avg,avg1,sum1=0.0;    //sum frm long to double
//     plotdata x(6.0, 7.0);
//     plotdata y = x;
//     plot(x, y);
    ofstream fout("a8.txt");
    for (int d=2;d<11;d++)
    {   sum =0;

        for (int n=50;n<2000;n=n+50)
        {   int arr[n];
            for (int k=1;k<10000;k++)
            {

                for (int i=1;i<n;i++) {
                   arr[i]= rand();

                }
                key = arr[(rand())%n];     //giving index instead of any randon number so that it definetly finds it
                //key = rand();
                qsort(arr,n,sizeof(int),compare);
                clock_t startTime = clock();    //clock =start();
                GSA(arr,0,n,d);
                //cout<<"hi";
                clock_t endTime = clock();      //clock stop
                clock_t clockTicksTaken = endTime - startTime;  //time
                //cout<<d << "   "<< n<<  "   "<<k<< "   "<<clockTicksTaken<<endl;//double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;

                sum = sum +clockTicksTaken;
                //cout<< sum<<endl;                    // sum +=time;
                //sum1 = sum1+timeInSeconds;
            }
            avg=sum/(double)10;
           cout<<avg<<endl;
           fout<<avg<<"  ";
           // addMark(x,y,n,avg);   //cout <<  "  avg:  "<<avg<< "  n:  "<<n << "  d: "<< d <<endl;
        }
        fout<<"\n";
    }
    return 0;
}


