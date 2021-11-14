#include <bits/stdc++.h>
using namespace std;

vector<int> runIntcodePart1(vector<unsigned int> intcode)
{
    vector<int> output;

    unsigned int ip = 0;
    while(true){
        unsigned int op = intcode[ip];
        string opStr = to_string(op);

        unsigned int    de =(opStr.size() >= 2)?( stoul(opStr.substr(opStr.size() - 2, 2)) ):( stoul(opStr.substr(opStr.size() - 1, 1)) ),
                        c = (opStr.size() >= 3)?( stoul(opStr.substr(opStr.size() - 3, 1)) ):(0),
                        b = (opStr.size() >= 4)?( stoul(opStr.substr(opStr.size() - 4, 1)) ):(0),
                        a = (opStr.size() >= 5)?( stoul(opStr.substr(opStr.size() - 5, 1)) ):(0);

        // Parameters point to either the immediate value or value at address depending on the three modes
        unsigned int& firstParameter = (c)?(intcode[ip + 1]):(intcode[intcode[ip + 1]]);
        unsigned int& secondParameter = (b)?(intcode[ip + 2]):(intcode[intcode[ip + 2]]);
        unsigned int& thirdParameter = (a)?(intcode[ip + 3]):(intcode[intcode[ip + 3]]);

        // Execute OP
        if(de == 1)         // Add
            thirdParameter = firstParameter + secondParameter;
        else if(de == 2)    // Multiply
            thirdParameter = firstParameter * secondParameter;
        else if(de == 3)    // Input integer
            cin >> firstParameter;
        else if(de == 4)    // Output integer
            output.push_back(firstParameter);
        else if(de == 99)   // Terminate
            return output;

        // Advance instruction pointer
        if(de == 1) ip += 4;
        else if(de == 2) ip += 4;
        else if(de == 3) ip += 2;
        else if(de == 4) ip += 2;
        else if(de == 99) ip += 1;
    }
}

vector<int> runIntcodePart2(vector<unsigned int> intcode){
    vector<int> output;

    unsigned int ip = 0; // Instruction pointer
    while(true){
        unsigned int op = intcode[ip];
        string opStr = to_string(op);

        unsigned int    de =(opStr.size() >= 2)?( stoul(opStr.substr(opStr.size() - 2, 2)) ):( stoul(opStr.substr(opStr.size() - 1, 1)) ),   // Operation
                        c = (opStr.size() >= 3)?( stoul(opStr.substr(opStr.size() - 3, 1)) ):(0),  // Mode first parameter
                        b = (opStr.size() >= 4)?( stoul(opStr.substr(opStr.size() - 4, 1)) ):(0),  // Mode second parameter
                        a = (opStr.size() >= 5)?( stoul(opStr.substr(opStr.size() - 5, 1)) ):(0);  // Mode third parameter

        // Parameters point to either the immediate value or value at address depending on the three modes
        unsigned int& firstParameter = (c)?(intcode[ip + 1]):(intcode[intcode[ip + 1]]);
        unsigned int& secondParameter = (b)?(intcode[ip + 2]):(intcode[intcode[ip + 2]]);
        unsigned int& thirdParameter = (a)?(intcode[ip + 3]):(intcode[intcode[ip + 3]]);

        // Execute OP
        if(de == 1)         // Add
        {
            thirdParameter = firstParameter + secondParameter;
            ip += 4;
        } 
        else if(de == 2)  // Multiply
        {
            thirdParameter = firstParameter * secondParameter;
            ip += 4;
        } 
        else if(de == 3)  // Input integer
        {
            cin >> firstParameter;
            ip += 2;
        } 
        else if(de == 4)  // Output integer
        {
            output.push_back(firstParameter);
            ip += 2;
        } 
        else if(de == 5)  // Jump-if-true
        {
            if(firstParameter)
                ip = secondParameter;
            else
                ip += 3;
        } 
        else if(de == 6)  // Jump-if-false
        {
            if(!firstParameter)
                ip = secondParameter;
            else
                ip += 3;
        } 
        else if(de == 7)  // Less than
        {
            if(firstParameter < secondParameter)
                thirdParameter = 1;
            else
                thirdParameter = 0;
            ip += 4;
        } 
        else if(de == 8)  // Equals
        {
            if(firstParameter == secondParameter)
                thirdParameter = 1;
            else
                thirdParameter = 0;
            ip += 4;
        }
        else if(de == 99)  // Terminate
            return output;
    }
}

int main(){
    // Variables
    vector<unsigned int> intcode;

    // Open file
    ifstream input("input.txt");

    // Read integers delimited by comma from file to vector
    string numberStr;
    while(getline(input, numberStr, ','))
        intcode.push_back(stoi(numberStr)); // Convert string to int

    // Close file
    input.close();

    // Part 1
    {
        cout << "Input '1' to run tests: ";
        vector<int> output = runIntcodePart1(intcode);

        for(size_t i = 0; i < output.size(); i++)
            if(i != output.size() - 1)
                cout << "Test " << i << ": " << ((output[i])?("Failed!"):("Succeeded!")) << endl;
            else
                cout << "Diagnostic code: " << output[i] << endl;
    }

    // Part 2
    {
        cout << "Input '5' to diagnose the ships thermal radiator controller: ";
        vector<int> output = runIntcodePart2(intcode);

        cout << "Diagnostic code: " << output.at(0) << endl;
    }
}