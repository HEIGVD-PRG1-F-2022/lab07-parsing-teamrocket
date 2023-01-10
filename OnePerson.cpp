//
// Created by Linus Gasser on 2023-01-09
//

#include "OnePerson.h"
#include <set>
#include <string>

using namespace std;

unsigned OnePerson::calc_fitness(NumericVector route) {
    set<string> opened;
    string valve = "AA";
    vector<Step> tour{Step{valve, false}};
    for (auto const &step: route.get_values()) {
        auto valves = base.links[valve];
        valve = valves.at(step % valves.size());
        bool open = base.rates[valve] > 0 && step >= base.fact && opened.insert(valve).second;
        tour.emplace_back(Step{valve, open});
    }
    return base.calc_rate(tour, max_length);
}

void test_oneperson() {}