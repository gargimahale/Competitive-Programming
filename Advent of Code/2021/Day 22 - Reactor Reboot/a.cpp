#include <bits/stdc++.h>
using namespace std;

struct point {
    int64_t x, y, z;
};

class cuboid {
  public:
    bool on;
    point low, high;
    uint64_t volume() const {
        return abs((high.x - low.x + 1) * (high.y - low.y + 1) * (high.z - low.z + 1));
    }
    bool is_overlapped(const cuboid& b) const { return overlap(b) || b.overlap(*this); }
    bool valid(void) const {
        return (high.x >= low.x) && (high.y >= low.y) && (high.z >= low.z);
    }

  private:
    bool overlap(const cuboid& c) const {
        return (low.x <= c.high.x && high.x >= c.low.x) &&
               (low.y <= c.high.y && high.y >= c.low.y) &&
               (low.z <= c.high.z && high.z >= c.low.z);
    }
};

list<cuboid> explode(const cuboid& c1, const cuboid& c2) {
    struct range {
        int64_t low, high;
    };
    typedef range slice[3];
    const range below_x = {c1.low.x, c2.low.x - 1}, above_x = {c2.high.x + 1, c1.high.x},
                below_y = {c1.low.y, c2.low.y - 1}, above_y = {c2.high.y + 1, c1.high.y},
                below_z = {c1.low.z, c2.low.z - 1}, above_z = {c2.high.z + 1, c1.high.z},
                middle_x = {max(c1.low.x, c2.low.x), min(c1.high.x, c2.high.x)},
                middle_y = {max(c1.low.y, c2.low.y), min(c1.high.y, c2.high.y)},
                middle_z = {max(c1.low.z, c2.low.z), min(c1.high.z, c2.high.z)};
    const slice x_slices = {below_x, above_x, middle_x},
                y_slices = {below_y, above_y, middle_y},
                z_slices = {below_z, above_z, middle_z};
    list<cuboid> l;
    for (auto& x : x_slices)
        for (auto& y : y_slices)
            for (auto& z : z_slices) {
                cuboid c3 = {false, {x.low, y.low, z.low}, {x.high, y.high, z.high}};
                if (c3.valid()) {
                    c3.on = !c3.is_overlapped(c1) || !c3.is_overlapped(c2);
                    l.push_back(c3);
                }
            }
    return l;
}

vector<cuboid> cube_rules;
list<cuboid> cubes, new_cubes;

void add_cube(const cuboid& c, bool add) {
    list<cuboid>::iterator it;
    for (auto& c2 : cubes) {
        if (c.is_overlapped(c2)) {
            list<cuboid> l = explode(c2, c);
            for (auto& c3 : l)
                if (c3.on)
                    new_cubes.push_back(c3);
        } else
            new_cubes.push_back(c2);
    }
    if (add)
        new_cubes.push_back(c);
}

uint64_t part(int part_n) {
    static const cuboid init_region = {false, {-50, -50, -50}, {50, 50, 50}};
    cubes.clear();
    for (auto& r : cube_rules) {
        new_cubes.clear();
        if (part_n == 1 && !r.is_overlapped(init_region))
            continue;
        add_cube(r, r.on);
        swap(cubes, new_cubes);
    }
    uint64_t volume = 0;
    for (auto& c : cubes)
        volume += c.volume();
    return volume;
}

int main(void) {
    ifstream f("input.txt");
    string l;
    while (getline(f, l)) {
        istringstream ss(l);
        string s;
        cuboid cube;
        ss >> s;
        cube.on = s == "on";
        char c;
        ss >> c >> c;
        ss >> cube.low.x;
        ss >> c >> c;
        ss >> cube.high.x;
        ss >> c >> c >> c;
        ss >> cube.low.y;
        ss >> c >> c;
        ss >> cube.high.y;
        ss >> c >> c >> c;
        ss >> cube.low.z;
        ss >> c >> c;
        ss >> cube.high.z;
        cube_rules.push_back(cube);
    }
    cout << "Part 1  - " << part(1) << "\n";
    cout << "Part 2  - " << part(2) << "\n";
}