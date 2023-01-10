//
// Created by Linus Gasser on 2023-01-09
//

#include "Tunnels.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

Tunnels::Tunnels(const string &file) {
    // TODO
}

unsigned Tunnels::calc_rate(const vector<Step> &tour, unsigned length) {
    // TODO
    return 0;
}

vector<Step> str_to_tour(string s) {
    vector<Step> ret;
    auto pos = s.begin();
    do {
        auto next = find(pos, s.end(), ' ');
        string step(pos, next);
        ret.emplace_back(Step{string(step, 0, 2), step.size() > 2});
        pos = next + 1;
    } while (pos < s.end());
    return ret;
}

void test_tunnels() {
    Tunnels sample("../sample-input.txt");
    unsigned rate = sample.calc_rate(
            str_to_tour(
                    "AA DD_ CC BB_ AA II JJ_ II AA DD EE FF GG HH_ GG FF EE_ DD CC_"),
            30);
    assert(rate == 1651);
}