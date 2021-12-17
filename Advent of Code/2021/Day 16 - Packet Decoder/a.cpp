#include <bits/stdc++.h>
using namespace std;

class Packet{
public:
    long long value = 0;
    int version, type_id;
    bool isOperator;
    vector<Packet> sub_packets;
    Packet (int version, int type_id){
        this->version = version;
        this->type_id = type_id;
        this->isOperator = (this->type_id != 4);
        this->value  = 0;
    }

    static pair<Packet,int> makePacket(string& binary, int pointer){
        int version = stoi(binary.substr(pointer,3), 0, 2);
        pointer += 3;

        int type_id = stoi(binary.substr(pointer,3), 0, 2);
        pointer += 3;

        Packet currentPacket(version,type_id);
        if(currentPacket.isOperator){
            int I = binary[pointer] == '0' ? 15 : 11;
            pointer += 1;

            int len = stoi(binary.substr(pointer,I), 0, 2);
            pointer += I;
            int cur = 0;

            while(cur < len){
                pair<Packet,int> sub_packet_pointer = makePacket(binary,pointer);
                currentPacket.sub_packets.push_back(sub_packet_pointer.first);

                int increment = I == 11 ? 1 : sub_packet_pointer.second-pointer;
                pointer = sub_packet_pointer.second;
                cur += increment;
            }

        }
        else{
            char prefix = '1';
            string binary_value = "";
            while(prefix == '1'){
                prefix = binary[pointer];
                pointer++;
                binary_value.append(binary.substr(pointer, 4));
                pointer += 4;
            }
            currentPacket.value = stoll(binary_value, 0, 2);
        }
        return {currentPacket, pointer};
    }
};

int getSumOFIDs(Packet packet){
    if(packet.sub_packets.size() == 0){
        return packet.version;
    }

    int total = packet.version;
    for(Packet sub_packet : packet.sub_packets){
        total += getSumOFIDs(sub_packet);
    }
    return total;
}

long long getValue(Packet packet){
    long long value = 0;
    if(packet.type_id == 0){
        value = 0;
        for(Packet sub_packet : packet.sub_packets){
            value += getValue(sub_packet);
        }
    }
    else if(packet.type_id == 1){
        value = 1;
        for(Packet sub_packet : packet.sub_packets){
            value *= getValue(sub_packet);
        }
    }
    else if(packet.type_id == 2){
        bool first = true;
        for(Packet sub_packet : packet.sub_packets){
            if( first== true){
                value = getValue(sub_packet);
                first = false;
            } 
            else{
                long long sub_val = getValue(sub_packet);
                value = value > sub_val ? sub_val : value;
            }

        }
    }
    else if(packet.type_id == 3){
        bool first = true;
        for(Packet sub_packet : packet.sub_packets){
            if( first == true){
                value = getValue(sub_packet);
                first = false;
            } 
            else{
                long long sub_val = getValue(sub_packet);
                value = value < sub_val ? sub_val : value;
            }

        }
    }
    else if(packet.type_id == 4){
        value = packet.value;
    }
    else if(packet.type_id == 5){
        value = getValue(packet.sub_packets[0]) > getValue(packet.sub_packets[1]) ? 1 : 0;
    }
    else if(packet.type_id == 6){
        value = getValue(packet.sub_packets[0]) < getValue(packet.sub_packets[1]) ? 1 : 0;
    }
    else if(packet.type_id == 7){
        value = getValue(packet.sub_packets[0]) == getValue(packet.sub_packets[1]) ? 1 : 0;
    }
    return value;
}

int part1(Packet packet){
    return getSumOFIDs(packet);
}

long long part2(Packet packet){
    long long p = getValue(packet);
    return p;
}

int main(void) {
    map<char,string> hex_binary =
            {
                    { '0' , "0000" },
                    { '1' , "0001" },
                    { '2' , "0010" },
                    { '3' , "0011" },
                    { '4' , "0100" },
                    { '5' , "0101" },
                    { '6' , "0110" },
                    { '7' , "0111" },
                    { '8' , "1000" },
                    { '9' , "1001" },
                    { 'A' , "1010" },
                    { 'B' , "1011" },
                    { 'C' , "1100" },
                    { 'D' , "1101" },
                    { 'E' , "1110" },
                    { 'F' , "1111" }
            };

    string binary_instruction;
    ifstream input("input.txt");

    if(input.fail()) cout << "Failed to open file";
    else {
            string inp;
            input >> inp;
            binary_instruction = hex_binary[inp[0]];
            for (int i = 1; i < inp.size() ; ++i){
                binary_instruction += hex_binary[inp[i]];
            }

        }

    int pointer = 0;
    pair<Packet, long long > packet_pointer = Packet::makePacket(binary_instruction, pointer);

    Packet packet = packet_pointer.first;
    cout << "Part 1 : " << part1(packet) << "\n";
    cout << "Part 2 : " << part2(packet) << "\n";
}