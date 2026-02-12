# include <iostream>
using namespace std;
int main(){
    int n ;
    cin>>n;
    for(int i = 1;i<=n ;i++){
        int temp =0;
        for(int j=1;j<i;j*=2){
            temp++;
        }
        cout<<i<<" "<<temp<<endl;
    }
    return 0;
}