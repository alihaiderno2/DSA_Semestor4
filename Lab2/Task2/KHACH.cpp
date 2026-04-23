#include<iostream>
using namespace std;
int countEvenDigits(int * a,int m,int n){
  if (m<=n)
  {  int temp=countEvenDigits(a,m+1,n);
    if (a[m]%2==1)
    {
        return temp;
        }
        else
        {
        return 1+temp;
    }
    
  }
  else
  {
    return 0;
  }
  
}
int main(){
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int *a=new int[n];
    cout<<"Enter the elements of array:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"The number of even digits in the array is: "<<countEvenDigits(a,0,n-1)<<endl;
    delete [] a;
}