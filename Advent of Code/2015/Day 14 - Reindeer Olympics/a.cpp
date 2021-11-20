#include <bits/stdc++.h>
using namespace std;

class reindeer {
private:
    int curtime;
    int stars;
    int cdist;
    int speed;
    int duration;
    int resttime;
public:
    reindeer(int s, int d, int r) : curtime(0), stars(0), cdist(0), speed(s), duration(d), resttime(r) {}

    int calculate_distance(int time) {
        int intervaltime = duration+resttime;
        int cycles = time / intervaltime;
        int rest   = time % intervaltime;
        int movingtime = cycles * duration;
        if (rest<duration) movingtime+=rest; else movingtime+=duration;
        return movingtime * speed;
    }

    int step() {
        ++curtime;
        return cdist = calculate_distance(curtime);
    }

    void addstar() { ++stars; }

    int  getstars() { return stars; } 

    int getdistance() { return cdist; } 
};

int simulate(int time, map<string,reindeer*> reindeers) {
    for (int t = 0; t < time; ++t) {
        int maxdist = INT_MIN;
        for (auto r: reindeers) {
            int d = r.second->step();
            if (d > maxdist) 
            	maxdist = d;
        }

        for (auto r: reindeers)
            if (r.second->getdistance() == maxdist) 
            	r.second->addstar();
    }

    int s, maxstars = INT_MIN;
    for (auto r: reindeers) 
        if ((s = r.second->getstars()) > maxstars) 
        	maxstars = s;
    return maxstars;
}

int main() {
	
    map<string,reindeer*> reindeers;
    string line;
    string name;
    string temp;
    int s;
    int d;
    int r;

    ifstream iss("input.txt");
    while (getline(iss,line)) {
        istringstream ss(line);
        ss >> name >> temp >> temp >> s >> temp >> temp >> d >> temp >> temp >> temp >> temp >> temp >> temp >> r;
        reindeers[name] = new reindeer(s,d,r);
    }

    int t = 2503;
    int maxdist = INT_MIN;
    for (auto r: reindeers) {
        int d = r.second->calculate_distance(t);
        if (d>maxdist) maxdist=d;
    }

    cout << "Part 1: " << maxdist << endl;
    cout << "Part 2: " << simulate(t, reindeers) << endl;

    return 0;
}