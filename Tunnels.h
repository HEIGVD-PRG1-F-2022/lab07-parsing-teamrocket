//
// Created by Linus Gasser on 2023-01-09
//

#ifndef AOC_2022_16_TUNNELS_H
#define AOC_2022_16_TUNNELS_H

#include <map>
#include <string>
#include <vector>

// Une étape dans un trajet.
struct Step {
    std::string valve;
    bool open;
};

// Un tunnel représente un système de caves qui sont reliées entre elles.
// Chaque cave a une soupape qui peut laisser échapper des gaz à une pression.
// Attention, la pression peut être 0!
class Tunnels {
public:
    // Les soupapes
    std::vector<std::string> valves;
    // La pression qui peut s'échapper
    std::map<std::string, unsigned> rates;
    // Les liens entre les soupapes
    std::map<std::string, std::vector<std::string>> links;
    // Le factoriel du nombre des sorties d'une cave maximale.
    // C'est utilisé pour calculer la sortie sans biais.
    unsigned fact;

    // Créer un système de tunnels à partir d'une chaîne de caractères comme
    // définit dans le problème.
    Tunnels(const std::string &input);

    // Calculates the total rate of a given tour.
    unsigned calc_rate(const std::vector<Step> &tour, unsigned length);
};

std::ostream &operator<<(std::ostream &out, const Tunnels &t);

void test_tunnels();

#endif//AOC_2022_16_TUNNELS_H
