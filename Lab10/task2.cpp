#include <iostream>
using namespace std;

class JosephusList; 
class PersonNode { 
    friend class JosephusList; 
    private: 
    int id; 
    PersonNode *next; 
};
class JosephusList { 
private: 
PersonNode *first; 
public: 
    JosephusList (int N){
        first = new PersonNode;
        first->id = 1;
        PersonNode* nextNode = first;
        for(int i = 2;i<=N;i++){
            nextNode->next = new PersonNode;
            nextNode->next->id = i;
            nextNode = nextNode->next;
        }
        nextNode->next = first;
    }
    ~JosephusList (){
        PersonNode* curr = first->next;
        first->next = nullptr;
        while(curr != nullptr){
            PersonNode* temp = curr->next;
            delete curr;
            curr = temp;
        }
        first = nullptr;
    }
    int getWinner (int M){
        PersonNode* prev = first;
        PersonNode* curr = first->next;
        int total = 1;
        while(curr != first){
            total++;
            prev = curr;
            curr = curr->next;
        }
        curr = first;
        while(total != 1){
            for(int i = 0;i<M%total;i++){
                prev = curr;
                curr = curr->next;
            }
            PersonNode* temp = curr->next;
            prev->next = temp;
            cout<<curr->id<<" ";
            delete curr;
            curr = temp;
            total--;
        }
        first = curr;
        cout<<curr->id;
        return curr->id;
    }
}; 
int main(){
    JosephusList list(5);
    list.getWinner(2);

}
