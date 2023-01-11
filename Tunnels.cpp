//
// Created by Linus Gasser on 2023-01-09
//

#include "Tunnels.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

Tunnels::Tunnels(const string &file) {
    string line;
    ifstream infile(file);
    while (getline(infile, line)) {
        if (line.empty()) {
            break;
        }

        // Valve name
        string valveName = line.substr(6, 2);
        this->valves.push_back(valveName);

        // Valve rate
        short ratePosOffset = 1;
        size_t rateStartPos = line.find('=') + ratePosOffset;
        size_t rateEndPos = line.find(';') - rateStartPos;
        unsigned rate = stoi(line.substr(rateStartPos, rateEndPos));
        this->rates[valveName] = rate;

        // Valve links
        short linksPosOffset = 3;
        string linksStrPart = line.substr(line.find("to valve"), line.length());
        size_t linksStartPos = linksStrPart.find(" ", 4);
        size_t linksEndPos = linksStrPart.length() - linksStartPos;

        vector<string> linksTunnel;
        istringstream split(linksStrPart.substr(linksStartPos, linksEndPos));
        for (string link; getline(split, link, ','); linksTunnel.push_back(link.substr(1, link.length())));

        this->links[valveName] = linksTunnel;
    }
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

std::ostream &operator<<(std::ostream &out, const Tunnels &t){
    (void)t;
    return out;
}

void test_tunnels() {
    Tunnels sample("../sample-input.txt");
    unsigned rate = sample.calc_rate(
            str_to_tour(
                    "AA DD_ CC BB_ AA II JJ_ II AA DD EE FF GG HH_ GG FF EE_ DD CC_"),
            30);
    assert(rate == 1651);
}