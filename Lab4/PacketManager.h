# pragma once
# include <fstream>
using namespace std;
const int PACKET_SIZE = 5;
struct Packet{
    int position;
    char body[PACKET_SIZE+1];
};
class PacketManager { 
    private:
    void sortPacketsBubbleSort ();
    void sortPacketsSelectionSort ();
    void swapPackets(Packet* ,Packet* );
    Packet* packets;
    int numPackets;
    char* message;
    int msgLength;
    public:
    PacketManager(ifstream& fin);
    ~PacketManager();
    void displayPackets () const;
    void extractMessage();
    void displayMessage () const;
}; 