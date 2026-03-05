# include <iostream>
# include <fstream>
using namespace std;
int main(){
    ofstream outFile("output.txt");
    if(outFile.is_open()){
        outFile << "Hello, World!" << endl;
        outFile << "This is a file handling example in C++." << endl;
        outFile.close();
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}
// file.get(buffer, size): Reads characters until it hits a newline (\n) or reaches the size - 1 limit. It automatically adds a null terminator (\0) at the end to make it a valid C-string.
// file.read(buffer, size): This is more "raw." It grabs exactly size characters, regardless of newlines, and does not add a null terminator.
// Function How it handles Newlines (\n)  Does it add a Null Terminator (\0)?
// .get(buffer, size) It stops at the newline but leaves it in the pipe. 🛑Yes ✅
// .getline(buffer, size)It stops at the newline and removes it from the pipe. 🧼Yes ✅
// .read(buffer, size)It ignores newlines and just grabs raw characters. 🤖No 