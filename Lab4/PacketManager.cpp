/*Name :Ali Haider
Roll Number : BITF24M004
Section : Morning*/
# include "PacketManager.h"
# include <iostream>
using namespace std;
PacketManager::PacketManager(ifstream& fin){
    fin>>numPackets;
    packets = new Packet[numPackets];
    for(int i=0;i<numPackets;i++){
        fin>>packets[i].position;
        fin.ignore();
        fin.getline(packets[i].body,6);
    }
    message = nullptr;
    msgLength = 0;
}
PacketManager::~PacketManager(){
    if(numPackets!=0){
        delete[] packets;
    }
}
void PacketManager::displayPackets()const{
    for(int i=0;i<numPackets;i++){
        cout<<packets[i].position<<" ";
        cout<<packets[i].body<<endl;
    }
}
void PacketManager::sortPacketsBubbleSort(){
    for (int i = numPackets - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (packets[j].position > packets[j + 1].position)
            {
                Packet temp = packets[j];
                packets[j]= packets[j+1];
                packets[j+1] = temp;
            }
        }
    }
}
void PacketManager::sortPacketsSelectionSort(){
    for(int i=0;i<numPackets-1;i++){
        int min = i;
        for(int j=i+1;j<numPackets;j++){
            if(packets[j].position<packets[min].position){
                min = j;
            }
        }
        Packet temp = packets[i];
        packets[i]= packets[min];
        packets[min] = temp;
    }
}
void PacketManager::extractMessage(){
    char choiceOfAlgo;
    cout<<"Which sorting algorithm do you want to use?"<<endl<<"Enter 'B' or 'b' for Bubble sort"<<endl<<"Enter 'S' or 's' for Selection sort"<<endl;
    cin>>choiceOfAlgo;
    if(choiceOfAlgo == 'b'|| choiceOfAlgo=='B'){
        sortPacketsBubbleSort();
    }
    else if(choiceOfAlgo == 's'|| choiceOfAlgo=='S'){
        sortPacketsSelectionSort();
    }
    else{
        return;
    }
    msgLength = numPackets*5;
    cout<<"The order of packets after extracting the message:"<<endl;
    message = new char[msgLength+1];
    int size =0;
    for(int i=0;i<numPackets;i++){
        for(int j=0;j<5;j++){
            message[size] = packets[i].body[j];
            size++;
        }
    }
    message[size] = '\0';
    displayPackets();
}
void PacketManager::displayMessage()const{
    if(msgLength == 0){
        cout<<"Extract message has not been called!"<<endl;
        return;
    }
    cout<<"The extracted message is:"<<endl;
    cout<<message<<endl;
}