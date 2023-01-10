//
// Created by Linus Gasser on 2023-01-09
//

#ifndef AOC_2022_16_TWOPERSONS_H
#define AOC_2022_16_TWOPERSONS_H

#include <utility>

#include "NumericVector.h"
#include "Tunnels.h"

// Cette classe peut calculer la pression enlevée si deux personnes (ou une personne et
// un éléphant) percourent les tunnels et enlèvent de la vapeur.
class TwoPersons {
    Tunnels base;

public:
    // La longeur maximale des deux trajets
    static const unsigned max_length = 52;
    // La valeur maximale pour chacune des étapes.
    const unsigned max_values;

    // Initialise avec un système de tunnels donné.
    explicit TwoPersons(Tunnels base) : base(std::move(base)), max_values(2 * base.fact) {}

    // Calculer la "fitness" de cette solution, qui est la pression totale partie pendant le trajet.
    // La première valeur du vecteur est utilisée pour le premier trajet, la deuxième valeur pour le
    // deuxième trajet, puis de nouveau pour le premier trajet, et ainsi de suite.
    // Il faut faire attention qu'il n'y a pas une soupape qui est ouverte dans les deux trajets!
    unsigned calc_fitness(NumericVector route);
};

#endif//AOC_2022_16_TWOPERSONS_H
