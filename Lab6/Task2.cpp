# include <iostream>
# include <cctype>
# include <cstdlib> 
# include <cstring>
# include "StackDouble.h"
# include "StackDouble.cpp"
# include <fstream>
using namespace std;
bool evaluatePostfixinputression ( char* input, ofstream& fout ) {
    StackDouble s(100);
    int i = 0;
    const char space[2] = " ";
    char* token = strtok((input+i),space);
    while (token != nullptr)
    {
        cout<<token<<endl;
        if (isdigit(token[0]))
        {   
            double val = atof(token);
            s.push(val);
        }
        else
        {
            if (token[0] == '+')
            {
                double a, b;
                if(s.isEmpty()){
                    fout<<"Too few operands for operator: "<<token[0]<<endl;
                    return 0;
                }
                s.pop(b);
                if(s.isEmpty()){
                    fout<<"Too few operands for operator: "<<token[0]<<endl;
                    return 0;
                }
                s.pop(a);
                s.push(a+b);
            }
            else if (token[0] == '-')
            {
                double a, b;
                if(s.isEmpty()){
                    fout<<"Too few operands for operator: "<<token[0]<<endl;
                    return 0;
                }
                s.pop(b);
                if(s.isEmpty()){
                    fout<<"Too few operands for operator: "<<token[0]<<endl;
                    return 0;
                }
                s.pop(a);
                s.push(a - b);
            }
            else if (token[0] == '*')
            {
                double a, b;
                if(s.isEmpty()){
                    fout<<"Too few operands for operator: "<<token[0]<<endl;
                    return 0;
                }
                s.pop(b);
                if(s.isEmpty()){
                    fout<<"Too few operands for operator: "<<token[0]<<endl;
                    return 0;
                }
                s.pop(a);
                s.push(a * b);
            }
            else if (token[0] == '/')
            {
                double a, b;
                if(s.isEmpty()){
                    fout<<"Too few operands for operator: "<<token[0]<<endl;
                    return 0;
                }
                s.pop(b);
                if(s.isEmpty()){
                    fout<<"Too few operands for operator: "<<token[0]<<endl;
                    return 0;
                }
                s.pop(a);
                s.push(a / b);
            }
            else if(token[0] == '~'){
                double a;
                if(s.isEmpty()){
                    fout<<"Too few operands for operator: "<<token[0]<<endl;
                    return 0;
                }
                s.pop(a);
                s.push(-a);
            }
            else{
                fout<<"Invalid operator: "<<token[0]<<endl;
                return 0;
            }
        }
        token = strtok(nullptr,space);
    }
    double result;
    s.pop(result);
    if(!s.isEmpty()){
        fout<<"Too few Operators"<<endl;
        return 0;
    }
    fout<<result<<endl;
    return true;
}
int main(){
    ifstream infile("input.txt");
    if (!infile) {
        cout << "Error: Could not open input.txt" << endl;
        return 1;
    }
    int size = 0;
    infile>>size;
    infile.ignore();
    char** inputs = new char*[size];
    for(int i = 0; i < size; i++){
        inputs[i] = new char[200];
        infile.getline(inputs[i], 200);
        cout<<inputs[i]<<endl;
    }
    ofstream fout("output.txt");
    for(int i = 0;i<size;i++){
        bool ans = evaluatePostfixinputression(inputs[i],fout);
    }
    for(int i = 0;i<size;i++){
        delete[] inputs[i];
    }
    delete[] inputs;
    inputs = nullptr;
}