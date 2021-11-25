#include <bits/stdc++.h>
using namespace std;

struct Operation {
    string name;
    uint8_t reg;
    int32_t val;
};

void P1(istream& input);
void P2(istream& input);
uint32_t run(istream& input, uint32_t initial = 0);

int main(void) {
    istringstream test1(R"(inc a
jio a, +2
tpl a
inc a)");

    ifstream infile("input.txt");

    P1(infile);

    infile.clear();
    infile.seekg(0);
    P2(infile);
}

void P1(istream& input) {
    cout << "Reg b: " << run(input) << "\n";
}

void P2(istream& input) {
    cout << "a=1 Reg b: " << run(input, 1) << "\n";
}

uint32_t run(istream& input, uint32_t initial /* = 0 */) {

    vector<Operation> program;

    string line;
    while (getline(input, line)) {

        istringstream ss(line);

        string op, para, parb;
        ss >> op >> para;

        if (op == "hlf" || op == "tpl" || op == "inc") {
            program.push_back(Operation{op, (para == "b"), 0});
        } else if (op == "jmp") {
            program.push_back(Operation{op, 0, stoi(para)});
        } else {
            ss >> parb;
            program.push_back(Operation{op, (para == "b,"), stoi(parb)});
        }
    }

    uint32_t regs[] = { initial, 0 };

    for (size_t i = 0; i < program.size(); i++) {

        auto op = &program[i];

        if (op->name == "hlf") {
            regs[op->reg] /= 2;
        } else if (op->name == "tpl") {
            regs[op->reg] *= 3;
        } else if (op->name == "inc") {
            regs[op->reg]++;
        } else if (op->name == "jmp") {
            i += op->val - 1;
        } else if (op->name == "jie") {
            if (regs[op->reg] % 2 == 0) {
                i += op->val - 1;
            }
        } else if (op->name == "jio") {
            if (regs[op->reg] == 1) {
                i += op->val - 1;
            }
        }

    }
    return regs[1];
}