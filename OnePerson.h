//
// Created by Linus Gasser on 2023-01-09
//

#ifndef AOC_2022_16_ONEPERSON_H
#define AOC_2022_16_ONEPERSON_H


#include <utility>

#include "NumericVector.h"
#include "Tunnels.h"

// Calcule la "fitness" d'un NumericVecteur étant donné une seule personne.
class OnePerson {
    Tunnels base;

public:
    // La durée maximale d'un trajet.
    static const unsigned max_length = 30;
    // La valeur maximale utilisée dans un trajet, non inclusive.
    const unsigned max_values;

    // Initialise avec un système de tunnels donné.
    explicit OnePerson(Tunnels base) : base(std::move(base)), max_values(base.fact * 2) {}

    // Calculer la "fitness" de cette solution, qui est la pression totale partie pendant le trajet.
    unsigned calc_fitness(NumericVector route);
};


#endif//AOC_2022_16_ONEPERSON_H
