#ifndef GENETICLUDOEVOLV_H
#define GENETICLUDOEVOLV_H
#include <random>

#include <string>
#include <vector>
#include <iostream>
#include "smart_ludo_player.h"
#include <QObject>
#include <iostream>
#include "positions_and_dice.h"

//smart_ludo_player::baseScores dummy;
class geneticLudoEvolv
{
public:

    int selector = 0;
    float randomFloat = 0.0;
    int randomInt = 0;
    int randSelector = 0;
    std::mt19937 gen1;
    std::mt19937 gen2;
    std::mt19937 gen3;
    int raandom;
    geneticLudoEvolv();
    void randomSelector(){
            std::uniform_int_distribution<> dis1(1, 13);
            selector = dis1(gen1);
        }
    void randomAmount(){
            std::uniform_int_distribution<> dis2(-100, 100);
            randomInt = dis2(gen2);
            randomFloat = float(randomInt)/500;
        }
    void genRandSelector(){
            std::uniform_int_distribution<> dis3(1, 10);
            randSelector = dis3(gen3);
        }
    float randomize(float gene, float amount);
    baseScores mergeGenes(baseScores parentOne, baseScores parentTwo);
    void printGene(baseScores gene);
    int evovleCounter;
    std::string Filename;
    std::string geneName;
private:

};

#endif // GENETICLUDOEVOLV_H
