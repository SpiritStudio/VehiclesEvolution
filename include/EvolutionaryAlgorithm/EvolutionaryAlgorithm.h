//
// Created by SpiritStudio on 01.12.18.
//

#ifndef VEHICLESEVOLUTION_EVOLUTIONARYALGORITHM_H
#define VEHICLESEVOLUTION_EVOLUTIONARYALGORITHM_H


#include <vector>

#include <EvolutionaryAlgorithm/CarParameters.h>

class EvolutionaryAlgorithm {

public:
    EvolutionaryAlgorithm(const EvolutionaryAlgorithm&) = delete;
    EvolutionaryAlgorithm& operator=(const EvolutionaryAlgorithm&) = delete;
    static EvolutionaryAlgorithm& getInstance();

    std::vector<CarParameters> makeNewGeneration(std::vector<double> distances);

private:
    EvolutionaryAlgorithm() = default;

    std::vector<CarParameters> last_generation_parameters_;
    double mutation_probablity_;
    double crossover_probability_;

};


#endif //VEHICLESEVOLUTION_EVOLUTIONARYALGORITHM_H
