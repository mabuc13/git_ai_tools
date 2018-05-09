#include "smart_ludo_player.h"
#include <random>

smart_ludo_player::smart_ludo_player(int color):
    pos_start_of_turn(16),
    pos_end_of_turn(16),
    dice_roll(0),
    myColor(color)
{
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

    std::cout << "MY COLOR IS: " << myColor << "\n";

    //Brute debugging:
    //std::cout << "Simple color test: " << color << "\n";
    if(dice_roll == 6){ //Do we move the brick from start?
        for(int i = 0; i < 4; ++i){
            if(pos_start_of_turn[i]<0){
                return i;
            }
        }
        for(int i = 0; i < 4; ++i){
            if(pos_start_of_turn[i]>=0 && pos_start_of_turn[i] != 99){
                return i;
            }
        }
    } else { //The pieces with a low index, will be moved first.
        for(int i = 0; i < 4; ++i){
            //BRUTE DEBUGGING
            if(pos_start_of_turn[i]>=0 && pos_start_of_turn[i] != 99){
                float dummy;
                dummy = calcSafety(i);
                return i;
            }
        }
        for(int i = 0; i < 4; ++i){ //maybe they are all locked in
            if(pos_start_of_turn[i]<0){
                return i;
            }
        }
    }

    return -1;
}

void smart_ludo_player::start_turn(positions_and_dice relative){
    pos_start_of_turn = relative.pos;
    dice_roll = relative.dice;
    int decision = make_decision();
    emit select_piece(decision);
}

float smart_ludo_player::calcSafety(int piece) //A high score will mean that the move is unsafe, a low score will mean that the move is safe
{
//This method will not be complete, but only consider pieces within 12 squares of itself at the ending position
    int pieceIndex = myColor*piece + piece;
    int end_pos = dice_roll + pos_start_of_turn[pieceIndex];
    if (end_pos > 51)
        end_pos = end_pos-51;


    std::vector<int> consideredPositions;
    bool skip;
    int danger = 0;
    for (int i = 0; i < pos_start_of_turn.size(); i++)
    {
        if (pos_start_of_turn[i] == -1)
            skip = true;
        if (i == myColor*4 )
        {
            skip = true;
            i += 3;

        }
        for (int ii = 0; i < consideredPositions.size(); ii++)
            {
                if (consideredPositions[ii] == pos_start_of_turn[i])
                    skip = true;
            }
        if (!skip)
        {
            //Next line is known to have a bug, where the first of the for loop probably fixes it! But there may still be a bug
        if (((end_pos - pos_start_of_turn[i]  < 7  ) && (end_pos - pos_start_of_turn[i]  > 0)) ||( (end_pos -pos_start_of_turn[i]> 51-7)&&(end_pos < 6)) )
            {
                  std::cout << "The piece at " << end_pos << " Will be threatened by piece at " << pos_start_of_turn[i] << "\n";
                  danger++;
                  consideredPositions.push_back(pos_start_of_turn[i]);
                }
        }

        skip = false;
        //std::cout << "Piece index " << i << "piece position" << pos_start_of_turn[i+myColor*4] << "\n";
        //std::cout <<" Considered positions " << consideredPositions[0] << "Index " << i << "\n"; //THis will return error if my syntax is off
    }
    //if (myColor == 0)
    std::cout << "piece position: " << pos_start_of_turn[pieceIndex] << " danger: " << danger << "\n";
    //std::~Vector(consideredPositions);
    //Tag højde for om man er tæt på goal.
    //vector<int> nearbySquares = isOccupied[squareIndex]
    0.25 - (0.25/6)*danger;
    return 0.0;
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
