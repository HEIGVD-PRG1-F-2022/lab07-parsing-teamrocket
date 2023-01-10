//
// Created by Home on 01.01.23.
//

#ifndef AOC_2022_16_NUMERICVECTOR_H
#define AOC_2022_16_NUMERICVECTOR_H

#include "Tunnels.h"
#include <random>
#include <utility>
#include <vector>

// La méthode de test, appelé par main
void testNumeric();

// La classe NumericVector représente une solution du problème de la 16ième journée
// de Advent of Code.
// Pour chaque étape à travers les tunnels, NumericVector contient une valeur entre 0..value_max-1.
// Ces valeurs sont interprétées par OnePerson et TwoPersons pour calculer les points récoltés par ce
// chemin à travers les tunnels.
class NumericVector {
    // La longueur maximale de ce vecteur
    unsigned length;
    // Les valeurs de chaque étape
    std::vector<unsigned> values;
    // La valeur maximale, non-inclusive.
    unsigned value_max;
    // Une fois calculée, la "fitness" va être gardé ici pour éviter de la recalculer chaque fois.
    unsigned fitness = std::numeric_limits<unsigned>::max();

    // Crée un vecteur aléatoire.
    void randomize();

    // Cette méthode a le droit d'utiliser les variables privées.
    friend void testNumeric();

public:
    // Construit et initialise aléatoirement un NumericVector, sauf si un vecteur de valeurs et donnée
    // en argument.
    NumericVector(unsigned length, unsigned value_max, std::vector<unsigned> values = std::vector<unsigned>()) : length(
                                                                                                                         length),
                                                                                                                 values(std::move(values)), value_max(value_max) {
        randomize();
    }

    // Change un seul élément du vecteur aléatoirement.
    NumericVector mutate();

    // Mélange ce vecteur avec un deuxième vecteur et retourne le nouveau vecteur.
    // Le vecteur actuel n'est pas modifié.
    NumericVector crossover(const NumericVector &other) const;

    // Enregistre la "fitness" de ce vecteur.
    void set_fitness(unsigned fit);
    // Retourne la "fitnesse" de ce vecteur.
    unsigned get_fitness() const;

    // Retourne une copie des valeurs de ce vecteur.
    std::vector<unsigned> get_values();
};

#endif//AOC_2022_16_NUMERICVECTOR_H
