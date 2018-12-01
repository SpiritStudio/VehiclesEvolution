//
// Created by SpiritStudio on 01.12.18.
//

#include "include/EvolutionaryAlgorithm/EvolutionaryAlgorithm.h"

EvolutionaryAlgorithm& EvolutionaryAlgorithm::getInstance() {
    static EvolutionaryAlgorithm evolutionaryAlgorithmInstance;
    return evolutionaryAlgorithmInstance;
}

std::vector<CarParameters> EvolutionaryAlgorithm::makeNewGeneration(std::vector<double> distances) {

}