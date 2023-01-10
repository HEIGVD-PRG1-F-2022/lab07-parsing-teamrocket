//
// Created by Linus Gasser on 2023-01-09
//

#include "TwoPersons.h"
#include <set>

using namespace std;

Step add_step(Tunnels &base, set<string> &opened, string &valve, unsigned step){
    auto valves = base.links[valve];
    valve = valves.at(step % valves.size());
    bool open = step >= base.fact && opened.insert(valve).second;
    return Step{valve, open};
}

unsigned TwoPersons::calc_fitness(NumericVector route) {
    set<string> opened;
    string valve1 = "AA";
    string valve2 = "AA";
    vector<Step> tour1{Step{valve1, false}};
    vector<Step> tour2{Step{valve2, false}};
    bool path1 = true;
    for (auto const &step: route.get_values()) {
        if (path1) {
            tour1.push_back(add_step(base, opened, valve1, step));
        } else {
            tour2.push_back(add_step(base, opened, valve2, step));
        }
        path1 = !path1;
    }
    return base.calc_rate(tour1, max_length / 2) + base.calc_rate(tour2, max_length / 2);
}
