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
class smart_ludo_player : public QObject {
    Q_OBJECT
private:
    std::vector<int> pos_start_of_turn;
    std::vector<int> pos_end_of_turn;
    int dice_roll;
    int make_decision();
    int myColor;
    float calcSafety(int piece);
public:
    smart_ludo_player(int color);
    
signals:
    void select_piece(int);
    void turn_complete(bool);
public slots:
    void start_turn(positions_and_dice relative);
    void post_game_analysis(std::vector<int> relative_pos);
};

#endif // SMART_LUDO_PLAYER_H
