#include "game.h"
#define DEBUG 0

game::game():
    game_complete(false),
    turn_complete(true),
    game_delay(1000),
    relative(),
    dice_result(1),
    rd(),
    gen(rd()),
    color(3),
    player_positions({-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1})
{
}

void game::runGame(QApplication* oneObject)
{
    theApplication = oneObject;
    //theGame = aGame;
//    for (int ii = 0; ii < 100000; ii++){
//        // std::cout << "Some insight " ;
//        aGame.start();
//        oneObject->exec();
//        aGame.reset();
//        std::cout << ii << "\n";
//    }
}

void game::reset(){
    game_complete = false;
    turn_complete = true;
    for(auto &i : player_positions){ //without & we're changing the copy made in auto rather than the player_position
        i = -1;
    }
    color = 3;
}

void game::resetCounter()
{
    totalWinCnt = 0;
    win1Cnt = 0;
    win2Cnt = 0;
    win3Cnt = 0;
    win4Cnt = 0;
}

int game::rel_to_fixed(int relative_piece_index){
    return relative_piece_index + color * 4;
}

int game::isStar(int index){
    if(index == 5  ||
       index == 18 ||
       index == 31 ||
       index == 44){
        return 6;
    } else if(index == 11 ||
              index == 24 ||
              index == 37 ||
              index == 50){
        return 7;
    }
    return 0;
}

void game::addPlayers(smart_ludo_player *p1, ludo_player_random *p2, ludo_player_random *p3, ludo_player_random *p4, smart_ludo_player *p5, smart_ludo_player *p6, smart_ludo_player *p7)
{
    pp1 = p1;
    pp2 = p2;
    pp3 = p3;
    pp4 = p4;
    pp5 = p5;
    pp6 = p6;
    pp7 = p7;
}

void game::initRatingGame()
{
    if (firstInit)
    {
        QObject::disconnect(this,SIGNAL(player1_start(positions_and_dice)),&(*pp1), SLOT(start_turn(positions_and_dice)));
        QObject::disconnect(&(*pp1),SIGNAL(select_piece(int)),               this, SLOT(movePiece(int)));
        QObject::disconnect(this, SIGNAL(player1_end(std::vector<int>)),    &(*pp1),SLOT(post_game_analysis(std::vector<int>)));
        QObject::disconnect(&(*pp1),SIGNAL(turn_complete(bool)),                this,SLOT(turnComplete(bool)));

         QObject::disconnect(this, SIGNAL(player2_start(positions_and_dice)),&(*pp5),SLOT(start_turn(positions_and_dice)));
         QObject::disconnect(&(*pp5),SIGNAL(select_piece(int)),                 this, SLOT(movePiece(int)));
         QObject::disconnect(this, SIGNAL(player2_end(std::vector<int>)),    &(*pp5),SLOT(post_game_analysis(std::vector<int>)));
         QObject::disconnect(&(*pp5),SIGNAL(turn_complete(bool)),               this, SLOT(turnComplete(bool)));

         QObject::disconnect(this, SIGNAL(player3_start(positions_and_dice)),&(*pp6),SLOT(start_turn(positions_and_dice)));
         QObject::disconnect(&(*pp6),SIGNAL(select_piece(int)),                 this, SLOT(movePiece(int)));
         QObject::disconnect(this, SIGNAL(player3_end(std::vector<int>)),    &(*pp6),SLOT(post_game_analysis(std::vector<int>)));
         QObject::disconnect(&(*pp6),SIGNAL(turn_complete(bool)),               this, SLOT(turnComplete(bool)));

         QObject::disconnect(this, SIGNAL(player4_start(positions_and_dice)),&(*pp7),SLOT(start_turn(positions_and_dice)));
         QObject::disconnect(&(*pp7),SIGNAL(select_piece(int)),                 this, SLOT(movePiece(int)));
         QObject::disconnect(this, SIGNAL(player4_end(std::vector<int>)),    &(*pp7),SLOT(post_game_analysis(std::vector<int>)));
         QObject::disconnect(&(*pp7),SIGNAL(turn_complete(bool)),              this, SLOT(turnComplete(bool)));
      //  std::cout << "I disconnected \n";
    }
    QObject::connect(this,SIGNAL(player1_start(positions_and_dice)),&(*pp1), SLOT(start_turn(positions_and_dice)));
    QObject::connect(&(*pp1),SIGNAL(select_piece(int)),               this, SLOT(movePiece(int)));
    QObject::connect(this, SIGNAL(player1_end(std::vector<int>)),    &(*pp1),SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(&(*pp1),SIGNAL(turn_complete(bool)),                this,SLOT(turnComplete(bool)));
    //QObject::connect(this,SIGNAL(close()),&(*theApplication),SLOT(quit()));
    QObject::connect(this, SIGNAL(player2_start(positions_and_dice)),&(*pp2),SLOT(start_turn(positions_and_dice)));
    QObject::connect(&(*pp2),SIGNAL(select_piece(int)),                 this, SLOT(movePiece(int)));
    QObject::connect(this, SIGNAL(player2_end(std::vector<int>)),    &(*pp2),SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(&(*pp2),SIGNAL(turn_complete(bool)),               this, SLOT(turnComplete(bool)));

    QObject::connect(this, SIGNAL(player3_start(positions_and_dice)),&(*pp3),SLOT(start_turn(positions_and_dice)));
    QObject::connect(&(*pp3),SIGNAL(select_piece(int)),                 this, SLOT(movePiece(int)));
    QObject::connect(this, SIGNAL(player3_end(std::vector<int>)),    &(*pp3),SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(&(*pp3),SIGNAL(turn_complete(bool)),               this, SLOT(turnComplete(bool)));

    QObject::connect(this, SIGNAL(player4_start(positions_and_dice)),&(*pp4),SLOT(start_turn(positions_and_dice)));
    QObject::connect(&(*pp4),SIGNAL(select_piece(int)),                 this, SLOT(movePiece(int)));
    QObject::connect(this, SIGNAL(player4_end(std::vector<int>)),    &(*pp4),SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(&(*pp4),SIGNAL(turn_complete(bool)),              this, SLOT(turnComplete(bool)));

}

void game::initTrainingGame()
{

    if (firstInit)
    {
        QObject::disconnect(this,SIGNAL(player1_start(positions_and_dice)),&(*pp1), SLOT(start_turn(positions_and_dice)));
        QObject::disconnect(&(*pp1),SIGNAL(select_piece(int)),               this, SLOT(movePiece(int)));
        QObject::disconnect(this, SIGNAL(player1_end(std::vector<int>)),    &(*pp1),SLOT(post_game_analysis(std::vector<int>)));
        QObject::disconnect(&(*pp1),SIGNAL(turn_complete(bool)),                this,SLOT(turnComplete(bool)));
        //QObject::connect(this,SIGNAL(close()),&(*theApplication),SLOT(quit()));
        QObject::disconnect(this, SIGNAL(player2_start(positions_and_dice)),&(*pp2),SLOT(start_turn(positions_and_dice)));
        QObject::disconnect(&(*pp2),SIGNAL(select_piece(int)),                 this, SLOT(movePiece(int)));
        QObject::disconnect(this, SIGNAL(player2_end(std::vector<int>)),    &(*pp2),SLOT(post_game_analysis(std::vector<int>)));
        QObject::disconnect(&(*pp2),SIGNAL(turn_complete(bool)),               this, SLOT(turnComplete(bool)));

        QObject::disconnect(this, SIGNAL(player3_start(positions_and_dice)),&(*pp3),SLOT(start_turn(positions_and_dice)));
        QObject::disconnect(&(*pp3),SIGNAL(select_piece(int)),                 this, SLOT(movePiece(int)));
        QObject::disconnect(this, SIGNAL(player3_end(std::vector<int>)),    &(*pp3),SLOT(post_game_analysis(std::vector<int>)));
        QObject::disconnect(&(*pp3),SIGNAL(turn_complete(bool)),               this, SLOT(turnComplete(bool)));

        QObject::disconnect(this, SIGNAL(player4_start(positions_and_dice)),&(*pp4),SLOT(start_turn(positions_and_dice)));
        QObject::disconnect(&(*pp4),SIGNAL(select_piece(int)),                 this, SLOT(movePiece(int)));
        QObject::disconnect(this, SIGNAL(player4_end(std::vector<int>)),    &(*pp4),SLOT(post_game_analysis(std::vector<int>)));
        QObject::disconnect(&(*pp4),SIGNAL(turn_complete(bool)),              this, SLOT(turnComplete(bool)));
    }
    // QObject::connect(this,SIGNAL(close()),&(*theApplication),SLOT(quit()));
   QObject::connect(this,SIGNAL(player1_start(positions_and_dice)),&(*pp1), SLOT(start_turn(positions_and_dice)));
   QObject::connect(&(*pp1),SIGNAL(select_piece(int)),               this, SLOT(movePiece(int)));
   QObject::connect(this, SIGNAL(player1_end(std::vector<int>)),    &(*pp1),SLOT(post_game_analysis(std::vector<int>)));
   QObject::connect(&(*pp1),SIGNAL(turn_complete(bool)),                this,SLOT(turnComplete(bool)));

    QObject::connect(this, SIGNAL(player2_start(positions_and_dice)),&(*pp5),SLOT(start_turn(positions_and_dice)));
    QObject::connect(&(*pp5),SIGNAL(select_piece(int)),                 this, SLOT(movePiece(int)));
    QObject::connect(this, SIGNAL(player2_end(std::vector<int>)),    &(*pp5),SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(&(*pp5),SIGNAL(turn_complete(bool)),               this, SLOT(turnComplete(bool)));

    QObject::connect(this, SIGNAL(player3_start(positions_and_dice)),&(*pp6),SLOT(start_turn(positions_and_dice)));
    QObject::connect(&(*pp6),SIGNAL(select_piece(int)),                 this, SLOT(movePiece(int)));
    QObject::connect(this, SIGNAL(player3_end(std::vector<int>)),    &(*pp6),SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(&(*pp6),SIGNAL(turn_complete(bool)),               this, SLOT(turnComplete(bool)));

    QObject::connect(this, SIGNAL(player4_start(positions_and_dice)),&(*pp7),SLOT(start_turn(positions_and_dice)));
    QObject::connect(&(*pp7),SIGNAL(select_piece(int)),                 this, SLOT(movePiece(int)));
    QObject::connect(this, SIGNAL(player4_end(std::vector<int>)),    &(*pp7),SLOT(post_game_analysis(std::vector<int>)));
    QObject::connect(&(*pp7),SIGNAL(turn_complete(bool)),              this, SLOT(turnComplete(bool)));
    if (!firstInit)
        firstInit = true;
}

int game::isOccupied(int index){ //returns number of people of another color
    int number_of_people = 0;

    if(index != 99){
        for(size_t i = 0; i < player_positions.size(); ++i){
            if(i < static_cast<size_t>(color)*4 || i >= static_cast<size_t>(color)*4 + 4){        //Disregard own players
                if(player_positions[i] == index){
                    ++number_of_people;
                }
            }
        }
    }
    return number_of_people;
}

bool game::isGlobe(int index){
    if(index < 52){     //check only the indexes on the board, not in the home streak
        if(index % 13 == 0 || (index - 8) % 13 == 0 || isOccupied(index) > 1){  //if more people of the same team stand on the same spot it counts as globe
            return true;
        }
    }
    return false;
}

void game::send_them_home(int index){
    for(size_t i = 0; i < player_positions.size(); ++i){
        if(i < static_cast<size_t>(color)*4 || i >= static_cast<size_t>(color)*4 + 4){        //this way we don't skip one player position
            if(player_positions[i] == index){
                player_positions[i] = -1;
            }
        }
    }
}

void game::move_start(int fixed_piece){
    if(dice_result == 6 && player_positions[fixed_piece] < 0){
        player_positions[fixed_piece] = color*13; //move me to start
        send_them_home(color*13); //send pieces home if they are on our start
    }
}

int game::next_turn(unsigned int delay = 0){
    if(game_complete){
        return 0;
    }
    switch(color){
        case 0:
        case 1:
        case 2:
            ++color;
            break;
        case 3:
        default:
            color = 0;
            break;
    }
    // global_color = color;
    rollDice();
    relative.dice = getDiceRoll();
    relative.pos = relativePosition();
    emit set_color(color);
    emit set_dice_result(dice_result);

    msleep(delay);
    switch(color){
        case 0:
            emit player1_start(relative);
            break;
        case 1:
            emit player2_start(relative);
            break;
        case 2:
            emit player3_start(relative);
            break;
        case 3:
            emit player4_start(relative);
        default:
            break;
    }

    return 0;
}

void game::movePiece(int relative_piece){
    int fixed_piece = rel_to_fixed(relative_piece);     //index of the piece in player_positions
    int modifier = color * 13;
   // if (ratingSwitcer > 1)
    //    std::cout << "Color: " << color << "\n";
    int relative_pos = player_positions[fixed_piece];
    int target_pos = 0;
    if(player_positions[fixed_piece] == -1){        //if the selected piece is in the safe house, try to move it to start
        move_start(fixed_piece);
    } else {
        //convert to relative position
        if(relative_pos == 99){
            //std::cout << "I tought this would be it ";
        } else if(relative_pos == 51){ //if people land on 51, they shouldn't be sent to goal stretch
            switch(color){
            case 0 : relative_pos = 51; break;
            case 1 : relative_pos = 38; break;
            case 2 : relative_pos = 25; break;
            case 3 : relative_pos = 12; break;
            }
        } else if( relative_pos > 50) {
            relative_pos = relative_pos - color * 5 - 1;
        } else if(relative_pos < modifier) {
            relative_pos = relative_pos + 52 - modifier;
        } else if( relative_pos > 50) {
            relative_pos = relative_pos - color * 5 - 1;
        } else {//if(relative >= modifier)
            relative_pos = relative_pos - modifier;
        }

        if(DEBUG) std::cout << "color: " << color << " pos: " << relative_pos << " + " << dice_result << " = " << relative_pos + dice_result;
        //add dice roll
        relative_pos += dice_result;    //this is relative position of the selected token + the dice number

        int jump = isStar(relative_pos); //return 0 | 6 | 7
        if(jump){
            if(jump + relative_pos == 57){
                relative_pos = 56;
            } else {
                relative_pos += jump;
            }
        }
        //special case checks
        if(relative_pos > 56 && relative_pos < 72){ // go back
            target_pos = 56-(relative_pos-56) + color * 5 + 1; //If the player moves over the goal, it should move backwards
        }else if(relative_pos == 56 || relative_pos >= 99){
            target_pos = 99;
        }else if(relative_pos > 50){ // goal stretch
            target_pos = relative_pos + color * 5 + 1;
        } else {
            int new_pos = relative_pos + modifier;
            if(new_pos < 52){
                target_pos = new_pos;
            } else { //wrap around
                target_pos = new_pos - 52;  //this is the global position wrap around at the green entry point
            }
        }
        //check for game stuff

        if(isOccupied(target_pos)){
            if(isGlobe(target_pos)){
                target_pos = -1; //send me home
            } else {
                send_them_home(target_pos);
            }
        }
        if(DEBUG) std::cout << " => " << target_pos << std::endl;
        player_positions[fixed_piece] = target_pos;
    }
    std::vector<int> new_relative = relativePosition();
    switch(color){
        case 0:
            emit player1_end(new_relative);
            break;
        case 1:
            emit player2_end(new_relative);
            break;
        case 2:
            emit player3_end(new_relative);
            break;
        case 3:
            emit player4_end(new_relative);
        default:
            break;
    }
    emit update_graphics(player_positions);
}

std::vector<int> game::relativePosition(){
    std::vector<int> relative_positions;
    int modifier = color * 13;

    //from start id to end
    for(int i = color*4; i < static_cast<int>(player_positions.size()); ++i){
        relative_positions.push_back(player_positions[i]);
    }
    //from 0 to start id
    for(int i = 0; i < color*4; ++i){
        relative_positions.push_back(player_positions[i]);
    }


    for(size_t i = 0; i < relative_positions.size(); ++i){
        if(relative_positions[i] == 99 || relative_positions[i] == -1){
            relative_positions[i] = (relative_positions[i]);
        } else if(relative_positions[i] < modifier) {
            relative_positions[i] = (relative_positions[i]+52-modifier);
        } else if(relative_positions[i] > 50) {
            relative_positions[i] = (relative_positions[i]-color*5-1);
        } else if(relative_positions[i] >= modifier) {
            relative_positions[i] = (relative_positions[i]-modifier);
        }
    }
    return std::move(relative_positions);
}

void game::turnComplete(bool win){
    game_complete = win;
    turn_complete = true;
    if(game_complete){
       // std::cout << "player: " << color << " won" << std::endl;
        totalWinCnt++;
        //std::cout << "TotalwinCOunt: " << totalWinCnt << "\n";
        if (color == 0)
        {
            win1Cnt++;
        }

        if (color == 1)
        {
            win2Cnt++;
        }

        if (color == 2)
        {
            win3Cnt++;
        }

        if (color == 3)
        {
            win4Cnt++;
        }

        if (totalWinCnt == 1500 && ratingGame)
        {
            std::cout << "Player 1 has won: " << win1Cnt << " times with a winrate of: " << (float)win1Cnt/(float)totalWinCnt << "\n";
            std::cout << "Player 2 has won: " << win2Cnt << " times with a winrate of: " << (float)win2Cnt/(float)totalWinCnt << "\n";
            std::cout << "Player 3 has won: " << win3Cnt << " times with a winrate of: " << (float)win3Cnt/(float)totalWinCnt << "\n";
            std::cout << "Player 4 has won: " << win4Cnt << " times with a winrate of: " << (float)win4Cnt/(float)totalWinCnt << "\n";
            //std::cout << "Color: " << color << " has won \n" ;
            std::cout << "Total games: " << totalWinCnt << "\n\n";
        }

        emit declare_winner(color);
    }
}

int game::getW1()
{
    return win1Cnt;
}

int game::getW2()
{
    return win2Cnt;
}

int game::getW3()
{
    return win3Cnt;
}

int game::getW4()
{
    return win4Cnt;
}

int game::getWT()
{
    return totalWinCnt;
}

void game::run() {
    std::cout << "Entered run \n" ;
    if(DEBUG) std::cout << "color:     relative pos => fixed\n";
    for (int ii = 0; ii < 100000000; ii++){
        start();
       // std::cout<< "Started game\n" ;
    while(!game_complete){
        //std::cout << "Running...\n";
        if(turn_complete){
            turn_complete = false;
            msleep(game_delay/4);
            next_turn(game_delay - game_delay/4);
        }
    }
        // std::cout << "Some insight " ;
        //if (ii != 0 )
        //    theApplication->exec();
     //std::cout << ii << "\n";
     if (totalWinCnt > 1500)
     {
         if (trainingCounter < 2)
         {
         //First train 10 generations
         std::vector<int> winVector = {win1Cnt, win2Cnt, win3Cnt, win4Cnt};
         int highestWinCount = win1Cnt;
         int secondHighestWinCount = win2Cnt;
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
             gene1 = (*pp1).playerPriorities;
         }
         if (highestWinCount == win2Cnt)
         {
             gene1 = (*pp5).playerPriorities;
         }
         if (highestWinCount == win3Cnt)
         {
             gene1 = (*pp6).playerPriorities;
         }
         if (highestWinCount == win4Cnt)
         {
             gene1 = (*pp7).playerPriorities;
         }

   //    std::cout << "Stucked " ;
         if (secondHighestWinCount == win1Cnt)
         {
             gene2 = (*pp1).playerPriorities;
         }
         if (secondHighestWinCount == win2Cnt)
         {
             gene2 = (*pp5).playerPriorities;
         }
         if (secondHighestWinCount == win3Cnt)
         {
             gene2 = (*pp6).playerPriorities;
         }
         if (secondHighestWinCount == win4Cnt)
         {
             gene2 = (*pp7).playerPriorities;
         }

     //      std::cout << "This " ;
         baseScores child1 = evolver.mergeGenes(gene1, gene2);
         baseScores child2 = evolver.mergeGenes(gene1, gene2);
         baseScores child3 = evolver.mergeGenes(gene1, gene2);
         baseScores child4 = evolver.mergeGenes(gene1, gene2);
//std::cout << "should " ;
         (*pp1).setScores(child1);
         (*pp5).setScores(child2);
         (*pp6).setScores(gene1);
         (*pp7).setScores(gene2);
        //   std::cout << "provide " ;
         resetCounter();
         trainingCounter++;
        // std::cout << "Training counter: " << trainingCounter << "\n";

         }
         else
         {
             switch (ratingSwitcer)
             {
             case 1:
                 //std::cout << "Where ";
                 initRatingGame();
                 ratingGame = true;
                 resetCounter();
                 ratingSwitcer++;
                 break;
             case 2:
                // std::cout << "is ";
                 p1Rating = win1Cnt;
                 geneBank = (*pp1).playerPriorities;
                 (*pp1).playerPriorities = (*pp5).playerPriorities;
                 resetCounter();
                 ratingSwitcer++;
                 break;
             case 3:
              //   std::cout << "the ";
                 p2Rating = win1Cnt;
                 (*pp1).playerPriorities = (*pp6).playerPriorities;
                 resetCounter();
                 ratingSwitcer++;
                 break;
             case 4:
                 p3Rating = win1Cnt;
                 (*pp1).playerPriorities = (*pp7).playerPriorities;
                 resetCounter();
                 ratingSwitcer++;
                 break;
             case 5:
                 p4Rating = win1Cnt;
                 (*pp1).playerPriorities = geneBank;
                 resetCounter();
                 ratingSwitcer = 1;
                // trainingCounter = 0;
                 initTrainingGame();
                 ratingGame = false;
                 std::vector<int> winVector2 = {p1Rating, p2Rating, p3Rating, p4Rating};
                 int highestWinCount2 = p1Rating;
                 int secondHighestWinCount2 = p2Rating;
                 baseScores gene1;
                 baseScores gene2;
                 for (int i = 0; i < 4; i++)
                 {
                     if (winVector2[i] > highestWinCount2)
                     {
                         secondHighestWinCount2 = highestWinCount2;
                         highestWinCount2 = winVector2[i];
                     }
                 }
                 if (highestWinCount2 == p1Rating)
                 {
                     gene1 = (*pp1).playerPriorities;
                 }
                 if (highestWinCount2 == p2Rating)
                 {
                     gene1 = (*pp5).playerPriorities;
                 }
                 if (highestWinCount2 == p3Rating)
                 {
                     gene1 = (*pp6).playerPriorities;
                 }
                 if (highestWinCount2 == p4Rating)
                 {
                     gene1 = (*pp7).playerPriorities;
                 }

           //    std::cout << "Stucked " ;
                 if (secondHighestWinCount2 == p1Rating)
                 {
                     gene2 = (*pp1).playerPriorities;
                 }
                 if (secondHighestWinCount2 == p2Rating)
                 {
                     gene2 = (*pp5).playerPriorities;
                 }
                 if (secondHighestWinCount2 == p3Rating)
                 {
                     gene2 = (*pp6).playerPriorities;
                 }
                 if (secondHighestWinCount2 == p4Rating)
                 {
                     gene2 = (*pp7).playerPriorities;
                 }

             //      std::cout << "This " ;
                 std::cout << "The best performing parent gene: \n";
                 evolver.printGene(gene1);
                 std::cout << "The second best performing parent 1 gene: \n";
                 evolver.printGene(gene2);
                 baseScores child1 = evolver.mergeGenes(gene1, gene2);
                 baseScores child2 = evolver.mergeGenes(gene1, gene2);
                 baseScores child3 = evolver.mergeGenes(gene1, gene2);
                 baseScores child4 = evolver.mergeGenes(gene1, gene2);
        //std::cout << "should " ;
                 (*pp1).setScores(child1);
                 (*pp5).setScores(child2);
                 (*pp6).setScores(gene1);
                 (*pp7).setScores(gene2);

                 //Make four new children with the highest winning players
             }
             //std::cout << "Switching counter: " << ratingSwitcer << "\n";
         }
     }
        reset();

        //std::cout << ii << "\n";
    }
    emit close();
    QThread::exit();
}
