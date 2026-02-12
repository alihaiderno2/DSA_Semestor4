# include <iostream>
using namespace std;
int main(){
    int n ;
    cin>>n;
    int temp =0;
    for(int i = 1;i<=n ;i++){
        for(int j=0;j<n;j+=i){
            cout<<temp<<" ";
            temp++;
        }
    }
    return 0;
}