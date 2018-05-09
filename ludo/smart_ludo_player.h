#ifndef SMART_LUDO_PLAYER_H
#define SMART_LUDO_PLAYER_H
#include <QObject>
#include <iostream>
#include "positions_and_dice.h"
#include "game.h"
/*
 * This is a modified version of the ludo_player class. Where evolutionary computing has been used to improve the decision making logic of the player.
 * All modifications has been developed by Mark Buch.
 */

struct baseScores{
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
int piece;
float safetyFactor = 1.0;
float potFactor = 1.0;
};


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
