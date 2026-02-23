#include <iostream>
#include <fstream>
#include <string>
# include "PacketManager.h"
# include "PacketManager.cpp"
using namespace std;
int ceiling(float f){
    return int(f)+1;
}
int main(){
    string messageFromUser ;
    cout<<"Enter the message to make packets of:"<<endl;
    getline(cin,messageFromUser);
    cout<<messageFromUser<<endl;
    int sizeOfMessage = messageFromUser.size();
    ofstream fout("input2.txt");
    cout<<sizeOfMessage<<endl;
    fout<<ceiling(float(sizeOfMessage/5))<<endl;
    for(int i=0;i<sizeOfMessage;i+=5){
        Packet temp;
        temp.position = i/5 + 1;
        cout<<temp.position<<endl;
        int j = 0;
        while(i+j<sizeOfMessage && j<5){
            temp.body[j] = messageFromUser[i+j];
            j++;
        }
        temp.body[j] = '\0';
        fout<<temp.position<<" "<<temp.body<<endl;
    }
    fout.close();
}