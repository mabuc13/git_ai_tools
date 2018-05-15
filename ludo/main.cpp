#include "dialog.h"
#include <QApplication>
#include "game.h"
#include <vector>

#include "ludo_player.h"
#include "ludo_player_random.h"
#include "positions_and_dice.h"

#include "smart_ludo_player.h"
#include "geneticludoevolv.h"
Q_DECLARE_METATYPE( positions_and_dice )

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    qRegisterMetaType<positions_and_dice>();

    //instanciate the players here
    geneticLudoEvolv evolver;
    baseScores one;
   // baseScores two;
    //baseScores dummy = evolver.mergeGenes(one, two);
    bool test = true;

      /*   smart_ludo_player p1(0); //, p2(1), p3(2), p4(3);
        smart_ludo_player p2(1);
        smart_ludo_player p3(2);
        smart_ludo_player p4(3);
*/

        smart_ludo_player p1(0);
        ludo_player_random p2;
        ludo_player_random p3;
        ludo_player_random p4;
        smart_ludo_player p5(1);
        smart_ludo_player p6(2);
        smart_ludo_player p7(3);
        smart_ludo_player * p1Ptr = &p1;
        smart_ludo_player * p5Ptr = &p5;
        smart_ludo_player * p6Ptr = &p6;
        smart_ludo_player * p7Ptr = &p7;
        ludo_player_random * p2Ptr = &p2;
        ludo_player_random * p3Ptr = &p3;
        ludo_player_random * p4Ptr = &p4;

/**/

    //p1.setScores(one);
    //p2.setScores(one);
    //p3.setScores(one);
    //p4.setScores(one);

    game g;
    //g.setPlayers(p1, p2, p3, p4, evolver);
    g.setGameDelay(000); //if you want to see the game, set a delay

    // Add a GUI <-- remove the '/' to uncomment block
   // Dialog w;
    //QObject::connect(&g,SIGNAL(update_graphics(std::vector<int>)),&w,SLOT(update_graphics(std::vector<int>)));
   // QObject::connect(&g,SIGNAL(set_color(int)),                   &w,SLOT(get_color(int)));
   // QObject::connect(&g,SIGNAL(set_dice_result(int)),             &w,SLOT(get_dice_result(int)));
   // QObject::connect(&g,SIGNAL(declare_winner(int)),              &w,SLOT(get_winner()));
   // QObject::connect(&g,SIGNAL(close()),&a,SLOT(quit()));
  //  w.show();
     //Or don't add the GUI
    QObject::connect(&g,SIGNAL(close()),&a,SLOT(quit()));
    //
    std::cout << "Playing 2 training games with only smart players, then one rating game and breeding on the best performing players\n";
    //set up for each player
    /* QObject::connect(&g, SIGNAL(player1_start(positions_and_dice)),p1,SLOT(start_turn(positions_and_dice)));
    QObject::connect(p1,SIGNAL(select_piece(int)),                &g, SLOT(movePiece(int)));
    QObject::connect(&g, SIGNAL(player1_end(std::vector<int>)),    p1,SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(p1,SIGNAL(turn_complete(bool)),              &g, SLOT(turnComplete(bool)));

    QObject::connect(&g, SIGNAL(player2_start(positions_and_dice)),p2,SLOT(start_turn(positions_and_dice)));
    QObject::connect(p2,SIGNAL(select_piece(int)),                &g, SLOT(movePiece(int)));
    QObject::connect(&g, SIGNAL(player2_end(std::vector<int>)),    p2,SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(p2,SIGNAL(turn_complete(bool)),              &g, SLOT(turnComplete(bool)));

    QObject::connect(&g, SIGNAL(player3_start(positions_and_dice)),p3,SLOT(start_turn(positions_and_dice)));
    QObject::connect(p3,SIGNAL(select_piece(int)),                &g, SLOT(movePiece(int)));
    QObject::connect(&g, SIGNAL(player3_end(std::vector<int>)),    p3,SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(p3,SIGNAL(turn_complete(bool)),              &g, SLOT(turnComplete(bool)));

    QObject::connect(&g, SIGNAL(player4_start(positions_and_dice)),p4,SLOT(start_turn(positions_and_dice)));
    QObject::connect(p4,SIGNAL(select_piece(int)),                &g, SLOT(movePiece(int)));
    QObject::connect(&g, SIGNAL(player4_end(std::vector<int>)),    p4,SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(p4,SIGNAL(turn_complete(bool)),              &g, SLOT(turnComplete(bool)));
*/

    g.addPlayers(p1Ptr, p2Ptr, p3Ptr, p4Ptr, p5Ptr, p6Ptr, p7Ptr);
   /* QObject::connect(&g, SIGNAL(player1_start(positions_and_dice)),&p1,SLOT(start_turn(positions_and_dice)));
    QObject::connect(&p1,SIGNAL(select_piece(int)),                &g, SLOT(movePiece(int)));
    QObject::connect(&g, SIGNAL(player1_end(std::vector<int>)),    &p1,SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(&p1,SIGNAL(turn_complete(bool)),              &g, SLOT(turnComplete(bool)));

    QObject::connect(&g, SIGNAL(player2_start(positions_and_dice)),&p2,SLOT(start_turn(positions_and_dice)));
    QObject::connect(&p2,SIGNAL(select_piece(int)),                &g, SLOT(movePiece(int)));
    QObject::connect(&g, SIGNAL(player2_end(std::vector<int>)),    &p2,SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(&p2,SIGNAL(turn_complete(bool)),              &g, SLOT(turnComplete(bool)));

    QObject::connect(&g, SIGNAL(player3_start(positions_and_dice)),&p3,SLOT(start_turn(positions_and_dice)));
    QObject::connect(&p3,SIGNAL(select_piece(int)),                &g, SLOT(movePiece(int)));
    QObject::connect(&g, SIGNAL(player3_end(std::vector<int>)),    &p3,SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(&p3,SIGNAL(turn_complete(bool)),              &g, SLOT(turnComplete(bool)));

    QObject::connect(&g, SIGNAL(player4_start(positions_and_dice)),&p4,SLOT(start_turn(positions_and_dice)));
    QObject::connect(&p4,SIGNAL(select_piece(int)),                &g, SLOT(movePiece(int)));
    QObject::connect(&g, SIGNAL(player4_end(std::vector<int>)),    &p4,SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(&p4,SIGNAL(turn_complete(bool)),              &g, SLOT(turnComplete(bool)));*/
   // g.initTrainingGame();
    g.initTrainingGame();
    QApplication * aPtr;
    aPtr = &a;
    g.runGame(aPtr);
    g.start();
    a.exec();

   //    // std::cout << "Some insight " ;
     //   g.start();
      //  a.exec();
       // g.reset();
       // std::cout << "Where " ;
/*
           int win1Cnt = g.getW1();
            int win2Cnt = g.getW2();
            int win3Cnt = g.getW3();
            int win4Cnt = g.getW4();
            int totalWinCnt = g.getWT();
            if (totalWinCnt > 499)
            {
              //    std::cout << "Are " ;
                std::vector<int> winVector = {win1Cnt, win2Cnt, win3Cnt, win4Cnt};
                int highestWinCount = g.getW1();
                int secondHighestWinCount = g.getW2();
                for (int i = 0; i < 4; i++)
                {
                    if (winVector[i] > highestWinCount)
                    {
                        secondHighestWinCount = highestWinCount;
                        highestWinCount = winVector[i];
                    }
                }
                baseScores gene1;
                baseScores gene2;
             //     std::cout << "We " ;
                if (highestWinCount == win1Cnt)
                {
                    gene1 = p1.playerPriorities;
                }
                if (highestWinCount == win2Cnt)
                {
                    gene1 = p2.playerPriorities;
                }
                if (highestWinCount == win3Cnt)
                {
                    gene1 = p3.playerPriorities;
                }
                if (highestWinCount == win4Cnt)
                {
                    gene1 = p4.playerPriorities;
                }

          //    std::cout << "Stucked " ;
                if (secondHighestWinCount == win1Cnt)
                {
                    gene2 = p1.playerPriorities;
                }
                if (secondHighestWinCount == win2Cnt)
                {
                    gene2 = p2.playerPriorities;
                }
                if (secondHighestWinCount == win3Cnt)
                {
                    gene2 = p3.playerPriorities;
                }
                if (secondHighestWinCount == win4Cnt)
                {
                    gene2 = p4.playerPriorities;
                }
            //      std::cout << "This " ;
                baseScores child1 = evolver.mergeGenes(gene1, gene2);
                baseScores child2 = evolver.mergeGenes(gene1, gene2);
                baseScores child3 = evolver.mergeGenes(gene1, gene2);
                baseScores child4 = evolver.mergeGenes(gene1, gene2);
      //std::cout << "should " ;
                p1.setScores(child1);
                p2.setScores(child2);
                p3.setScores(child3);
                p4.setScores(child4);
               //   std::cout << "provide " ;
                g.resetCounter();
            } */


  //  }
    return 0;
}
