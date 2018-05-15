#ifndef SMART_LUDO_PLAYER_H
#define SMART_LUDO_PLAYER_H
#include <QObject>
#include <iostream>
#include "positions_and_dice.h"
//#include "game.h"
//#include "geneticludoevolv.h"
/*
 * This is a modified version of the ludo_player class. Where evolutionary computing has been used to improve the decision making logic of the player.
 * All modifications has been developed by Mark Buch.
 */

struct baseScores{
    float createBlockS = 0.1;
       float finishPieceS = 0.1;
       float moveForwardS = 0.1;
       float moveGlobeS = 0.1;
       float moveInFinishS =  0.1;
       float moveStarS = 0.1;
       float moveStarSendHomeS = 0.1;
       float moveToFinishS = 0.1;
       float outOfHomeS =0.1;
       float stopBlockS = 0.1;
       float sendHomeS = 0.1;

       float safetyFactor = 0.1;
       float potFactor = 0.1;

};

/*
 *
Create block:
finishPiece:
Move forward:
Move to globe:
Move in finish:
Move to star:
Move to star and send home:
Move to finish:
Get out of home:
Stop blocking the field:
Send piece home
safetyFactor
Potfactor
 *
 *
 *
    float createBlockS = -0.254;
       float finishPieceS = 1.344;
       float moveForwardS =-0.4;
       float moveGlobeS = -0.354;
       float moveInFinishS =  -2.674;
       float moveStarS =  1.866;
       float moveStarSendHomeS = -1.13;
       float moveToFinishS = 3.154;
       float outOfHomeS = 0.776;
       float stopBlockS = -1.578;
       float sendHomeS =0.26;

       float safetyFactor =0.0759999;
       float potFactor = 0.748; // 55 - 60 % winrate, with the upgraded framework
Create block: 0.35
finishPiece: 0.786
Move forward: -0.66
Move to globe: 0.982
Move in finish: -1.86
Move to star: -0.576
Move to star and send home: -2.568
Move to finish:
Get out of home:
Stop blocking the field:
Send piece home
safetyFactor
Potfactor

    float createBlockS = -0.484;
       float finishPieceS = 0.902;
       float moveForwardS =-0.402;
       float moveGlobeS = 0.082;
       float moveInFinishS =  -0.694;
       float moveStarS = -0.426;
       float moveStarSendHomeS = -1.974;
       float moveToFinishS = 1.732;
       float outOfHomeS =0.292;
       float stopBlockS = -1.998;
       float sendHomeS = 0.472;

       float safetyFactor = 0.38;
       float potFactor = 0.884; //This AI have around 60-65 % winrate, but it seems to be more stable than the other one with the same amount

    float createBlockS = -0.262;
       float finishPieceS = 0.264;
       float moveForwardS =-0.238;
       float moveGlobeS = 0.894;
       float moveInFinishS =  -0.00399999;
       float moveStarS = -0.176;
       float moveStarSendHomeS = -1.582;
       float moveToFinishS = 1.272;
       float outOfHomeS =0.526;
       float stopBlockS = -1.974;
       float sendHomeS = 0.12;

       float safetyFactor = -0.016;
       float potFactor = 1.472; //CA 60-65 % winrate

    float createBlockS = -0.402;
    float finishPieceS = 1.222;
    float moveForwardS =-0.218;
    float moveGlobeS = 1.364;
    float moveInFinishS = -0.96;
    float moveStarS = 0.12;
    float moveStarSendHomeS = -0.216;
    float moveToFinishS = 1.942;
    float outOfHomeS = 0.138;
    float stopBlockS = -0.814;
    float sendHomeS = 0.252;

    float safetyFactor = -0.456;
    float potFactor = 1.932;
    int piece; NOT THIS ONE

 *   float createBlockS = 0.2;
    float finishPieceS = 0.62;
    float moveForwardS =0.286;
    float moveGlobeS = 0.59;
    float moveInFinishS =  0.194;
    float moveStarS = -0.082;
    float moveStarSendHomeS = -1.042;
    float moveToFinishS = 1.018;
    float outOfHomeS = 0.784;
    float stopBlockS = -1.288;
    float sendHomeS = 0.634;

    float safetyFactor = 0.006;
    float potFactor = 1.212; Ca. 60% winrate against random
 *
 *    float sendHomeS = 0.3;
    float moveStarS = 0.35;
    float moveStarSendHomeS = 0.4;
    float moveGlobeS = 0.3;
    float moveForwardS = 0.1;
    float createBlockS = 0.3;
    float stopBlockS = 0.05;
    float moveToFinishS = 0.5;
    float moveInFinishS = 0.3;
    float outOfHomeS = 0.4;
    float finishPieceS = 0.4;

    float safetyFactor = 1.0;
    float potFactor = 1.0;
    int piece; NOT THIS ONE
 *
    float sendHomeS = -0.172;
    float moveStarS = -3.91;
    float moveStarSendHomeS =-2.13;
    float moveGlobeS = -1.222;
    float moveForwardS = 2.066;
    float createBlockS = 1.188;
    float stopBlockS = -1.896;
    float moveToFinishS =  2.614;
    float moveInFinishS = -4.96;
    float outOfHomeS =  3.158;
    float finishPieceS = 4.678;

    float safetyFactor = 0.188;
    float potFactor = 1.39; NOT THIS ONE
    int piece;

 *
 *Create block: 0.3
finishPiece: 0.646
Move forward: 0.19
Move to globe: 0.102
Move in finish: 0.63
Move to star: -0.258
Move to star and send home: -0.76
Move to finish: 0.59
Get out of home: 0.966
Stop blocking the field: -0.138
Send piece home 0.514
safetyFactor 0.802
Potfactor 0.884
 *
 *   float sendHomeS = 0.514;
    float moveStarS = -0.258;
    float moveStarSendHomeS = -0.76;
    float moveGlobeS = 0.102;
    float moveForwardS = 0.19;
    float createBlockS = 0.3;
    float stopBlockS = -0.138;
    float moveToFinishS = 0.59;
    float moveInFinishS = 0.63;
    float outOfHomeS = 0.966;
    float finishPieceS = 0.646;

    float safetyFactor = 0.802;
    float potFactor = 0.884;
    int piece;
 *
 * struct baseScores{
float sendHomeS = 0.3;
float moveStarS = 0.35;
float moveStarSendHomeS = 0.4;
float moveGlobeS = 0.3;
float moveForwardS = 0.1;
float createBlockS = 0.3;
float stopBlockS = 0.05;
float moveToFinishS = 0.5;
float moveInFinishS = 0.3;
float outOfHomeS = 0.4;
float finishPieceS = 0.4;

float safetyFactor = 1.0;
float potFactor = 1.0;
int piece;
}; */


struct possibilities{
    bool sendHomeB;
    bool moveStarB;
    bool moveStarSendHomeB;
    bool moveGlobeB;
    bool moveForwardB;
    bool createBlockB;
    bool stopBlockB;
    bool moveToFinishB;
    bool moveInFinishB;
    bool outOfHomeB;
    bool finishPieceB;
    int piece;
};
//Cases: All cases will be modified by how safely a player plays.
//Safety (This is a constant which determines how much the player prioritises safety should also be modified by the evolutionary algorithm)
//Patience (This is a constant which determines how much a player weights sending pieces quickly to home)
//send home (The int is a modifier of the priority, relative to how safe it is to send the piece home
//Move to star
//Move to star AND send home
//Move to globe
//Move forward
//Create block
//Disassemble block !!IF TRUE move forward is disabled!
//Move from globe
//Move to finish
//Move in finish



class smart_ludo_player : public QObject {
    Q_OBJECT
private:
    std::vector<int> pos_start_of_turn;
    std::vector<int> pos_end_of_turn;
    int dice_roll;
    int make_decision();
    int myColor;

    possibilities explorePossibilities(int piece);
    /*
    float sendHome(int pieceIndex);
    float moveStar(int pieceIndex);
    float moveStarSendHome(int pieceIndex);
    float moveGlobe(int pieceIndex);
    float moveForward(int pieceIndex);
    float createBlock(int pieceIndex);
    float stopBlock(int pieceIndex);
    float moveToFinish(int pieceIndex);
    float moveInFinish(int pieceIndex);
    float finishPiece(int pieceIndex);
    */
    bool sendHomePossible(int pieceIndex);
    bool moveStarPossible(int pieceIndex);
    bool moveStarSendHomePossible(int pieceIndex);
    bool moveGlobePossible(int pieceIndex);
    bool moveForwardPossible(int pieceIndex);
    bool createBlockPossible(int pieceIndex);
    bool stopBlockPossible(int pieceIndex);
    bool moveToFinishPossible(int pieceIndex);
    bool moveInFinishPossible(int pieceIndex);
    bool finishPiecePossible(int pieceIndex);
    bool outOfHomePossible(int pieceIndex);

    bool isGlobe(int field);
    bool isStar(int field);
    int enemiesAtField(int field);
    int friendsAtField(int field);

    void debugMoves(possibilities toDebug);

    float calcScores(possibilities playerP);
    float calcPot(int piece);
    float calcSafety(int piece);
    //scores calcScores(possibilities &pPossibilities);
   // int bestOption(scores p1S, possibilities p1P, scores p2S, possibilities p2P, scores p3S, possibilities p3P, scores p4S, possibilities p4P);
public:
    baseScores playerPriorities;
    smart_ludo_player(int color);
    void setScores(baseScores aScore);
    float potFactor;
    float safetyFactor;
signals:
    void select_piece(int);
    void turn_complete(bool);
public slots:
    void start_turn(positions_and_dice relative);
    void post_game_analysis(std::vector<int> relative_pos);
};

#endif // SMART_LUDO_PLAYER_H
