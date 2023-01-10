//
// Created by Linus Gasser on 2023-01-09
//

#include "NumericVector.h"
#include "OnePerson.h"
#include "Solve.h"
#include "Tunnels.h"
#include "TwoPersons.h"
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    testNumeric();
    test_tunnels();

    // For OnePlayer, the solutions are:
    // - 'sample-input.txt': 1651
    // - 'input.txt': 1940

    // For TwoPlayers, the solutions are:
    // - `sample-input.txt`: 1707
    // - `input.txt`: unknown :(

    Tunnels t("../input.txt");
    cout << t << endl;
    OnePerson input(t);
    Solve solver_annealing(input);
    Solve solver_genetic(input);
    unsigned rounds = 50;
    for (unsigned i = 0; i < rounds; i++) {
        double mutate = pow(1 - i / (rounds - 1.), 10.);
        cout << "Round " << i;
        cout << " - annealing: " << solver_annealing.run_annealing(1000, mutate);
        cout << " - genetics: " << solver_genetic.run_genetic(1000, 100, 10, 0.01) << endl;
    }
    return 0;
}
