# include <iostream>
# include <string>
using namespace std;
class StudentBST;
class StudentNode {
    friend class StudentBST;
    private:
    int rollNo; 
    string name; // Student’s name
    double cgpa; // Student’s CGPA
    StudentNode *left; // Pointer to the left subtree of a node
    StudentNode *right; // Pointer to the right subtree of a node
    };
class StudentBST {
    private:
    StudentNode *root; // Pointer to the root node of the BST
    public:
    StudentBST(){
        root  = nullptr;
    } // Default constructor
    bool insert (int rn, string n, double c){
        StudentNode *newNode = new StudentNode;
        newNode->rollNo = rn;
        newNode->name = n;
        newNode->cgpa = c;
        newNode->left = nullptr;
        newNode->right = nullptr;
        StudentNode *curr = root;
        StudentNode *prnt = nullptr;

        while (curr != nullptr)
        {
            prnt = curr;
            if (rn == curr->rollNo)
            {
                delete newNode;
                return false;
            }
            else if (rn < curr->rollNo)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        // When tree is empty
        if (prnt == nullptr)
        {
            cout<<"Yes"<<endl;
            cout<<newNode->cgpa;
            root = newNode;
            return true;
        }
        if (rn > prnt->rollNo)
        {
            prnt->right = newNode;
        }
        else
        {
            prnt->left = newNode;
        }
        cout<<newNode->cgpa;
        return true;
    }
    bool search (int rn){
        StudentNode *temp = root;
        while (temp != nullptr)
        {
            if (temp->rollNo == rn)
            {
                return true;
            }
            else if (temp->rollNo > rn)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return false;
    }
    void inOrder(StudentNode *curr)
    {
        if (curr == nullptr)
        {
            return;
        }
        inOrder(curr->left);
        cout<<curr->rollNo<< " "<<curr->name<< " "<<curr->cgpa<<endl;
        inOrder(curr->right);
    }
    void inOrder(){
        inOrder(root);
    }
    ~StudentBST(){

    }
    void destroy (StudentNode* s){
        if (s == nullptr)
        {
            return;
        }
        destroy(s->left);
        destroy(s->right);
        delete s;
        s = nullptr;
    }
    bool remove (int rn){
        StudentNode *curr = root;
    StudentNode *prnt = nullptr;

    while (curr != nullptr && curr->rollNo != rn)
    {
        prnt = curr;
        if (rn < curr->rollNo)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (curr == nullptr)
    {
        return false;
    }
    // Conversion of Degree 2 to Degree 1
    if (curr->left != nullptr && curr->right != nullptr)
    {
        StudentNode *successor = curr->right;
        StudentNode *prntSuc = curr;
        while (successor->left != nullptr)
        {
            prntSuc = successor;
            successor = successor->left;
        }

        curr->rollNo = successor->rollNo;
        curr = successor;
        prnt = prntSuc;
        }
        // Deletion of Degree 1 or 0
        StudentNode *child;
        if (curr->left != nullptr)
        {
            child = curr->left;
        }
        else
        {
            child = curr->right;
        }
        if (prnt == nullptr)
        {
            root = child;
        }
        else if (curr == prnt->left)
        {
            prnt->left = child;
        }
        else
        {
            prnt->right = child;
        }

        delete curr;
        curr = nullptr;

        return true;
    }
};
int main(){
    StudentBST bst;
    int choice, val;
    cout<<"1. Insert "<<endl;
        cout<<"2. Search "<<endl;
        cout<<"3. Remove "<<endl;
        cout<<"4. Display InOrder "<<endl;
        cout<<"5. EXit "<<endl;
    do{
        cin>>choice;
        if(choice == 1){
            cout<<"Insert a new Student";
            int rn;
            double cgpa;
            string name;
            cout<<"Enter the rollNo"<<endl;
            cin>>rn;
            cout<<"Enter the name"<<endl;
            cin>>name;
            cout<<"Enter the CGPA"<<endl;
            cin>>cgpa;
            bool result = bst.insert(rn,name,cgpa);
            if(result){
                cout<<"Value inserted"<<endl;
            }
        }
        else if(choice == 2){
            cout<<"Search for a student"<<endl;
            cin>>val;
            if(bst.search(val)){
                cout<<"Value found in the BST."<<endl;
            }
            else{
                cout<<"Value not found in the BST."<<endl;
            }
        }
        else if(choice == 3){
            cout<<"Enter the rollno to be removed ";
            cin>>val;
            if(bst.remove(val)){
                cout<<"Value removed from the BST."<<endl;
            }
            else{
                cout<<"Value not found in the BST."<<endl;
            }
        }
        else if(choice == 4){
            cout<<"InOrder Traversal: ";
            bst.inOrder();
        }
        else if(choice == 5){
            cout<<" Exiting......"<<endl;
        }
        else{
            cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    while(choice >= 1 && choice <=4);
}