#include "smart_ludo_player.h"
#include <random>

smart_ludo_player::smart_ludo_player(int color):
    pos_start_of_turn(16),
    pos_end_of_turn(16),
    dice_roll(0),
    myColor(color)
{
}

void smart_ludo_player::setScores(baseScores aScore)
{
    playerPriorities = aScore;
}

int smart_ludo_player::make_decision(){ //THis is where i should modify my code, in order to make an awesome AI
                                  //Player positions should do fine for the statespace model
                                  //This statespace should be used to see if there's some special cases which is true. And these special cases
                                  //Should be the building block of the decision logic.
                                  //The priority of these cases, should be modified by evolutionary computing

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
    //The safety of a piece is calculated by the number of pieces behind said piece, a high safety score means that it is a safe move
    //The patience of a piece is basicly how close it is to the goal, a high number means that it's close to the goal


    //Methods
    //Calc_score(Piece, positions, parameters) Returns how high a score each piece has. Where the piece with the highest score should be moved. Where the case returning the highest parameter

    /*moveToStar(piece, dice) returns the score of this move
    {
       float baseScore; //The score determined by the evol algo
       float safety = calcSafety(piece)
       float patience = calcPotential(piece); // A high patience score actually means that the player is impatient :D

       totalScore =  baseScore + safety*safetyFactor + patience*patienceFactor; //

       //If these are needed, the score systems math has plenty of place for improvements or the the evol parameters is totally unreasonable...
       IF (totalScore < 0)
            TotalScore = 0;
       IF (totalScore > 1 )
            totalScore = 1;

    }
*/

    //std::cout << "MY COLOR IS: " << myColor << "\n";

    //Brute debugging:
    //std::cout << "Simple color test: " << color << "\n";

    //First we explore the possibilities for each piece
    possibilities p1P = explorePossibilities(0);
    possibilities p2P = explorePossibilities(1);
    possibilities p3P = explorePossibilities(2);
    possibilities p4P = explorePossibilities(3);
    //debugMoves(p1P);
    //debugMoves(p2P);
    //debugMoves(p3P);
   // debugMoves(p4P);
    float p1Score = calcScores(p1P);
    float p2Score = calcScores(p2P);
    float p3Score = calcScores(p3P);
    float p4Score = calcScores(p4P);
    std::vector<float> scoreVector = {p1Score, p2Score, p3Score, p4Score};
    float bestScore = -99.0;
    for (int i = 0; i < scoreVector.size(); i++)
    {
   // std::cout<< "Best score of piece " << i << " valued at: " << scoreVector[i] << "\n";
        if (scoreVector[i] > bestScore)
            bestScore = scoreVector[i];
    }

    if (bestScore == p1Score)
    {
        //std::cout<< "Best score is of piece " << 0 << " valued at: " << p1Score << "\n\n";
        return 0;

    }
    if (bestScore == p2Score)
    {
        //std::cout<< "Best score is of piece " << 1 << " valued at: " << p2Score << "\n\n";
        return 1;
    }
    if (bestScore == p3Score)
    {
       //std::cout<< "Best score is of piece " << 2 << " valued at: " << p3Score << "\n\n";
        return 2;
    }
    if (bestScore == p4Score)
    {
      // std::cout<< "Best score is of piece " << 3 << " valued at: " << p4Score << "\n\n";
        return 3;
    }
   // std::cout << "No score is the best one, wtf\n";
    return -1;


    //return -1;
}

void smart_ludo_player::debugMoves(possibilities toDebug)
{
    std::cout << "Player " << toDebug.piece << " at field " << pos_start_of_turn[toDebug.piece] << " With dice " << dice_roll << "\n";
    std::cout << "Create block: " << toDebug.createBlockB << "\n";
    std::cout << "finishPiece: " << toDebug.finishPieceB << "\n";
    std::cout << "Move forward: " << toDebug.moveForwardB << "\n";
    std::cout << "Move to globe: " << toDebug.moveGlobeB << "\n";
    std::cout << "Move in finish: " << toDebug.moveInFinishB << "\n";
    std::cout << "Move to star: " << toDebug.moveStarB << "\n";
    std::cout << "Move to star and send home: " << toDebug.moveStarSendHomeB << "\n";
    std::cout << "Move to finish: " << toDebug.moveToFinishB << "\n";
    std::cout << "Get out of home: " << toDebug.outOfHomeB << "\n";
    std::cout << "Stop blocking the field: " << toDebug.stopBlockB << "\n";
    std::cout << "Send piece home " << toDebug.sendHomeB << "\n\n" ;
    //cout << "Create block: " << toDebug. << "\n\n";
}

void smart_ludo_player::start_turn(positions_and_dice relative){
    pos_start_of_turn = relative.pos;
    dice_roll = relative.dice;
    int decision = make_decision();
    emit select_piece(decision);
}

float smart_ludo_player::calcScores(possibilities pP)
{
    float curScore;
    bool done = false;
    bool inBase = false;
    std::vector<float> scores;
    if (pos_start_of_turn[pP.piece] == 99)
        done = true;
    if (pos_start_of_turn[pP.piece] == -1)
        inBase = true;
    bool safetyOn = true;
    if (pP.sendHomeB == true && !done && !inBase)
    {
        curScore = playerPriorities.sendHomeS +calcPot(pP.piece);
        if (safetyOn)
            curScore += playerPriorities.safetyFactor*calcSafety(pos_start_of_turn[pP.piece]);

        scores.push_back(curScore);
    }

    if (pP.moveStarB == true && !done && !inBase)
    {
        curScore = playerPriorities.moveStarS +calcPot(pP.piece)*playerPriorities.potFactor;
        if (safetyOn)
            curScore += playerPriorities.safetyFactor*calcSafety(pos_start_of_turn[pP.piece]);
        scores.push_back(curScore);
    }

    if (pP.moveStarSendHomeB == true && !done && !inBase)
    {
        curScore = playerPriorities.moveStarSendHomeS +calcPot(pP.piece)*playerPriorities.potFactor;
        if (safetyOn)
            curScore += playerPriorities.safetyFactor*calcSafety(pos_start_of_turn[pP.piece]);
        scores.push_back(curScore);
    }

    if (pP.moveGlobeB == true && !done && !inBase)
    {
        curScore = playerPriorities.moveGlobeS +calcPot(pP.piece)*playerPriorities.potFactor;
        if (safetyOn)
            curScore += playerPriorities.safetyFactor*calcSafety(pos_start_of_turn[pP.piece]);
        scores.push_back(curScore);
    }

    if (pP.moveForwardB == true && !done && !inBase)
    {
        curScore = playerPriorities.moveForwardS +calcPot(pP.piece)*playerPriorities.potFactor;
        if (safetyOn)
            curScore += playerPriorities.safetyFactor*calcSafety(pos_start_of_turn[pP.piece]);
        scores.push_back(curScore);
    }

    if (pP.createBlockB == true && !done && !inBase)
    {
        curScore = playerPriorities.createBlockS +calcPot(pP.piece)*playerPriorities.potFactor;
        if (safetyOn)
            curScore += playerPriorities.safetyFactor*calcSafety(pos_start_of_turn[pP.piece]);
        scores.push_back(curScore);
    }

    if (pP.stopBlockB == true && !done && !inBase)
    {
        curScore = playerPriorities.stopBlockS + calcPot(pP.piece)*playerPriorities.potFactor;
        if (safetyOn)
            curScore += playerPriorities.safetyFactor*calcSafety(pos_start_of_turn[pP.piece]);
        scores.push_back(curScore);
    }

    if (pP.moveToFinishB == true && !done && !inBase)
    {
        curScore = playerPriorities.moveToFinishS +calcPot(pP.piece)*playerPriorities.potFactor;
        if (safetyOn)
            curScore += playerPriorities.safetyFactor*calcSafety(pos_start_of_turn[pP.piece]);
        scores.push_back(curScore);
    }

    if (pP.moveInFinishB == true && !done && !inBase)
    {
        curScore = playerPriorities.moveInFinishS +calcPot(pP.piece)*playerPriorities.potFactor;
        if (safetyOn)
            curScore += playerPriorities.safetyFactor*calcSafety(pos_start_of_turn[pP.piece]);
        scores.push_back(curScore);
    }

    if (pP.outOfHomeB && inBase)
    {
        curScore = playerPriorities.outOfHomeS +calcPot(pP.piece)*playerPriorities.potFactor;
        if (safetyOn)
        {
            if (friendsAtField(0) > 0)
                curScore += 0.25;
        }
        scores.push_back(curScore);
    }

    if (pP.finishPieceB == true)
    {
        curScore = playerPriorities.finishPieceS +calcPot(pP.piece)*playerPriorities.potFactor;
        if (safetyOn)
            curScore += playerPriorities.safetyFactor*calcSafety(pos_start_of_turn[pP.piece]);
        scores.push_back(curScore);
    }
    float seeker = -150.0;
    for (int i = 0; i < scores.size(); i++)
    {
        if (scores[i] > seeker)
            seeker = scores[i];

        if (seeker == -100.0)
            std::cout << "Seeker is bugging" << "\n";
    }
    return seeker;
}

float smart_ludo_player::calcPot(int piece)
{
    if (pos_start_of_turn[piece] > 51)
        return 0;
    return ((pos_start_of_turn[piece] + dice_roll)*0.25)/57;
}

possibilities smart_ludo_player::explorePossibilities(int piece)
{
    int pieceIndex = piece;
    int end_pos = dice_roll + pos_start_of_turn[pieceIndex];
    possibilities currentP;
    currentP.piece = piece;
    currentP.moveForwardB = moveForwardPossible(pieceIndex);
    currentP.outOfHomeB = outOfHomePossible(pieceIndex);
    currentP.sendHomeB = sendHomePossible(pieceIndex);
    if (currentP.sendHomeB == true)
    {
        currentP.moveForwardB = false;
    }
    currentP.moveStarB = moveStarPossible(pieceIndex);
    if (currentP.moveStarB == true)
    {
        currentP.moveForwardB = false;
    }
    currentP.moveStarSendHomeB = moveStarSendHomePossible(pieceIndex);
    if (currentP.moveStarSendHomeB == true)
    {
        currentP.moveForwardB = false;
    }
    currentP.moveGlobeB = moveGlobePossible(pieceIndex);
    if (currentP.moveGlobeB == true)
    {
        currentP.moveForwardB = false;
    }
    currentP.createBlockB = createBlockPossible(pieceIndex);
    if (currentP.createBlockB == true)
    {
        currentP.moveForwardB = false;
    }
    currentP.stopBlockB = stopBlockPossible(pieceIndex);
    if (currentP.stopBlockB == true)
    {
        currentP.moveForwardB = false;
    }
    currentP.moveToFinishB = moveToFinishPossible(pieceIndex);
    currentP.moveInFinishB = moveInFinishPossible(pieceIndex);
    currentP.outOfHomeB = outOfHomePossible(pieceIndex);
    currentP.finishPieceB = finishPiecePossible(pieceIndex);

    return currentP;
}

bool smart_ludo_player::sendHomePossible(int pieceindex)
{

     int end_pos = dice_roll + pos_start_of_turn[pieceindex];
     if (end_pos > 51)
         return false;
     int noEnemies = enemiesAtField(end_pos);
     if (noEnemies == 1)
         if (!(isGlobe(end_pos)))
            return true;
     return false;

}

bool smart_ludo_player::moveStarPossible(int pieceIndex)
{
    int end_pos = dice_roll + pos_start_of_turn[pieceIndex];
    if (end_pos > 51)
        return false;
    bool star = isStar(end_pos);
    //Check for block at the next star
    if (star)
        end_pos = end_pos + 13;
    if (end_pos > 51)
        return false;
    int noEnemies = enemiesAtField(end_pos);
    if (noEnemies > 0)
        return false;

    if (star)
        return true;
    return false;

}

bool smart_ludo_player::moveStarSendHomePossible(int pieceIndex)
{
    int end_pos = dice_roll + pos_start_of_turn[pieceIndex];
    if (end_pos > 51)
        return false;
    bool starKnock = false;
    bool star = isStar(end_pos);
    if (star)
        end_pos = end_pos + 13;
    if (end_pos > 51)
        return false;
    int noEnemies = enemiesAtField(end_pos);
    if (noEnemies == 1)
        starKnock = true;
    else
        return false;
    if (starKnock)
        return true;
    return false;
}

bool smart_ludo_player::moveGlobePossible(int pieceIndex)
{
    int end_pos = dice_roll + pos_start_of_turn[pieceIndex];
    if (end_pos > 51)
        return false;
    if (isGlobe(end_pos))
        return true;
    return false;
}


bool smart_ludo_player::moveForwardPossible(int pieceIndex)
{
    if (pos_start_of_turn[pieceIndex] == 99)
        return false;
    if (pos_start_of_turn[pieceIndex] == -1)
        return false;
    if (pos_start_of_turn[pieceIndex] + dice_roll > 51)
        return false;
    return true;

}

bool smart_ludo_player::createBlockPossible(int pieceIndex) //Only returns true if creates block, doesn't return false if there's allready a block, thats check safetys responsibility.
{
    int end_pos = dice_roll + pos_start_of_turn[pieceIndex];
    if (end_pos > 51)
        return false;
    int noFriends = friendsAtField(end_pos);
    if (noFriends == 1)
        return true;
    return false;

}

bool smart_ludo_player::stopBlockPossible(int pieceIndex)
{
    int end_pos = dice_roll + pos_start_of_turn[pieceIndex];
    if (end_pos > 51)
        return false;
    if (pos_start_of_turn[pieceIndex] == -1)
            return false;
    bool forward = moveForwardPossible(end_pos);
    int friendsHere = friendsAtField(pos_start_of_turn[pieceIndex]);
    if (friendsHere == 2 && forward == true)
        return true;
    return false;
}


bool smart_ludo_player::moveToFinishPossible(int pieceIndex)
{
    int end_pos = dice_roll + pos_start_of_turn[pieceIndex];
    if (pos_start_of_turn[pieceIndex] > 51)
        return false;
    if (end_pos > 51)
        return true;
    return false;
}

bool smart_ludo_player::moveInFinishPossible(int pieceIndex)
{
    if (pos_start_of_turn[pieceIndex] > 51)
    {
        if (pos_start_of_turn[pieceIndex]+dice_roll == 56 )
            return false;
        if (pos_start_of_turn[pieceIndex]+dice_roll < 56)
            return true;
    }
    return false;
}

bool smart_ludo_player::outOfHomePossible(int pieceIndex)
{
    if (pos_start_of_turn[pieceIndex] == -1 && dice_roll == 6)
        return true;
    return false;
}

bool smart_ludo_player::finishPiecePossible(int pieceIndex)
{
    if (pos_start_of_turn[pieceIndex]+dice_roll == 56)
        return true;
    return false;
}


bool smart_ludo_player::isStar(int field)
{
        if(field == 5  || field == 18 || field == 31 /*||field == 44*/)
            return true;
        return false;

}


int smart_ludo_player::enemiesAtField(int field)
{
    int counter = 0;
    bool skip = false;
    for (int i = 4; i < pos_start_of_turn.size(); i++)
    {
            if (pos_start_of_turn[i] == field)
                counter++;
    }
    return counter;
}

int smart_ludo_player::friendsAtField(int field)
{
    int counter = 0;
    for (int i = 0; i < 4; i++)
    {
        if (pos_start_of_turn[i] == field)
            counter++;
    }
    return counter;
}



bool smart_ludo_player::isGlobe(int field){
    if(field < 52){     //check only the indexes on the board, not in the home streak
        if(field == 8 || field == 8+13 || field == 8+26){            return true;
        }
    }
    return false;
}

float smart_ludo_player::calcSafety(int piece) //A high score will mean that the move is unsafe, a low score will mean that the move is safe
{
//This method will not be complete, but only consider pieces within 12 squares of itself at the ending position
    //An obvious improvement to this method would be to actually
    int end_pos = dice_roll + pos_start_of_turn[piece];
    float currentSafety;
    float moveSafety;
    bool star = isStar(end_pos);
    if (star)
        end_pos += 13;

    // movesafety - currentsafety


    int currentDanger = 0;
    for (int i = 3; i < pos_start_of_turn.size(); i++)
    {

        {
            if (pos_start_of_turn[piece] > 6)
            {
                if (((pos_start_of_turn[piece] - pos_start_of_turn[i])  < 7  ))
                {
                    if (pos_start_of_turn[i] == -1)
                    {
                    }
                    else
                    {
                        currentDanger++;
                    }


                }
            }
            else
            {
                if ((pos_start_of_turn[i] - pos_start_of_turn[piece]) > 45)
                    if (pos_start_of_turn[i] == -1)
                    {
                    }
                    else
                    {
                        currentDanger++;
                    }
            }
        }
     }



    int moveDanger = 0;
    for (int i = 3; i < pos_start_of_turn.size(); i++)
    {

        {
            if (end_pos > 6)
            {
                if (((end_pos - pos_start_of_turn[i])  < 7  ))
                {
                    if (pos_start_of_turn[i] == -1)
                    {
                    }
                    else
                    {
                        moveDanger++;
                    }

                }
            }
            else
            {
                if ((end_pos - pos_start_of_turn[piece] )> 45)
                    if (pos_start_of_turn[i] == -1)
                    {
                    }
                    else
                    {
                        moveDanger++;
                    }
            }
        }
     }
    //if (myColor == 0)
    //std::cout << "piece position: " << pos_start_of_turn[piece]+dice_roll << " danger: " << danger << "\n";
    //std::~Vector(consideredPositions);
    //Tag højde for om man er tæt på goal.
    //vector<int> nearbySquares = isOccupied[squareIndex]

    currentSafety = 0.25 - (0.25/5)*currentDanger;
    moveSafety = 0.25 - (0.25/5)*moveDanger;
    if (isGlobe(pos_start_of_turn[piece]))
        currentSafety = 0.25;
    if (friendsAtField(pos_start_of_turn[piece]) > 1)
        currentSafety = 0.25;
    if (isGlobe(end_pos))
        moveSafety = 0.25;
    if (friendsAtField(end_pos) > 1)
        moveSafety = 0.25;
    //std::cout << "Current Danger: " << currentDanger << " Move danger: " << moveDanger << "\n";
    //std::cout << "Current safety: " << currentSafety << " Move safety: " << moveSafety << "\n";
    return moveSafety - currentSafety;
}


void smart_ludo_player::post_game_analysis(std::vector<int> relative_pos){
    pos_end_of_turn = relative_pos;
    bool game_complete = true;
    for(int i = 0; i < 4; ++i){
        if(pos_end_of_turn[i] < 99){
            game_complete = false;
        }
    }
    emit turn_complete(game_complete);
}
