#include "geneticludoevolv.h"
geneticLudoEvolv::geneticLudoEvolv()
{
}

float geneticLudoEvolv::randomize(float gene, float amount)
{


    randomAmount();
    return gene + randomFloat;
}

baseScores geneticLudoEvolv::mergeGenes(baseScores parentOne, baseScores parentTwo)
{
    baseScores child;

    randomSelector();
    int parentOneCounter = 0;
    int switchCounter = selector;

    for (int i = 0; i < 13; i++)
    {
        //std::cout << "Switching ";

        genRandSelector();

        switch (switchCounter)
        {

         case 1:
               if (parentOneCounter < 8)
               {
                    if (randSelector < 8)
                    {

                        child.sendHomeS = randomize(parentOne.sendHomeS, 0.2);
                        parentOneCounter++;
                    }
                    else
                        child.sendHomeS = parentOne.sendHomeS;
               }
               else
               {
                   if (randSelector < 8)
                   {
                       child.sendHomeS = randomize(parentTwo.sendHomeS, 0.2);
                       parentOneCounter++;
                   }
                   else
                       child.sendHomeS = parentTwo.sendHomeS;
               }
       //     switchCounter++;
            break;
        case 2:
            if (parentOneCounter < 8)
            {
                 if (randSelector < 8)
                 {
                     child.moveStarS = randomize(parentOne.moveStarS, 0.2);
                     parentOneCounter++;
                 }
                 else
                     child.moveStarS = parentOne.moveStarS;
            }
            else
            {
                if (randSelector < 8)
                {
                    child.moveStarS = randomize(parentTwo.moveStarS, 0.2);
                    parentOneCounter++;
                }
                else
                    child.moveStarS = parentTwo.moveStarS;
            }
      //   switchCounter++;
            break;
        case 3:
            if (parentOneCounter < 8)
            {
                 if (randSelector < 8)
                 {
                     child.moveStarSendHomeS = randomize(parentOne.moveStarSendHomeS, 0.2);
                     parentOneCounter++;
                 }
                 else
                     child.moveStarSendHomeS = parentOne.moveStarSendHomeS;
            }
            else
            {
                if (randSelector < 8)
                {
                    child.moveStarSendHomeS = randomize(parentTwo.moveStarSendHomeS, 0.2);
                    parentOneCounter++;
                }
                else
                    child.moveStarSendHomeS = parentTwo.moveStarSendHomeS;
            }
        // switchCounter++;
            break;
        case 4:
            if (parentOneCounter < 8)
            {
                 if (randSelector < 8)
                 {
                     child.moveGlobeS = randomize(parentOne.moveGlobeS, 0.2);
                     parentOneCounter++;
                 }
                 else
                     child.moveGlobeS = parentOne.moveGlobeS;
            }
            else
            {
                if (randSelector < 8)
                {
                    child.moveGlobeS = randomize(parentTwo.moveGlobeS, 0.2);
                    parentOneCounter++;
                }
                else
                    child.moveGlobeS = parentTwo.moveGlobeS;
            }
       //  switchCounter++;
            break;
        case 5:
            if (parentOneCounter < 8)
            {
                 if (randSelector < 8)
                 {
                     child.moveForwardS = randomize(parentOne.moveForwardS, 0.2);
                     parentOneCounter++;
                 }
                 else
                     child.moveForwardS = parentOne.moveForwardS;
            }
            else
            {
                if (randSelector < 8)
                {
                    child.moveForwardS = randomize(parentTwo.moveForwardS, 0.2);
                    parentOneCounter++;
                }
                else
                    child.moveForwardS = parentTwo.moveForwardS;
            }
       //  switchCounter++;
            break;
        case 6:
            if (parentOneCounter < 8)
            {
                 if (randSelector < 8)
                 {
                     child.createBlockS = randomize(parentOne.createBlockS, 0.2);
                     parentOneCounter++;
                 }
                 else
                     child.createBlockS = parentOne.createBlockS;
            }
            else
            {
                if (randSelector < 8)
                {
                    child.createBlockS = randomize(parentTwo.createBlockS, 0.2);
                    parentOneCounter++;
                }
                else
                    child.createBlockS = parentTwo.createBlockS;
            }
       //  switchCounter++;
            break;
        case 7:
            if (parentOneCounter < 8)
            {
                 if (randSelector < 8)
                 {
                     child.stopBlockS = randomize(parentOne.stopBlockS, 0.2);
                     parentOneCounter++;
                 }
                 else
                     child.stopBlockS = parentOne.stopBlockS;
            }
            else
            {
                if (randSelector < 8)
                {
                    child.stopBlockS = randomize(parentTwo.stopBlockS, 0.2);
                    parentOneCounter++;
                }
                else
                    child.stopBlockS = parentTwo.stopBlockS;
            }
       //  switchCounter++;
            break;
        case 8:
            if (parentOneCounter < 8)
            {
                 if (randSelector < 8)
                 {
                     child.moveToFinishS = randomize(parentOne.moveToFinishS, 0.2);
                     parentOneCounter++;
                 }
                 else
                     child.moveToFinishS = parentOne.moveToFinishS;
            }
            else
            {
                if (randSelector < 8)
                {
                    child.moveToFinishS = randomize(parentTwo.moveToFinishS, 0.2);
                    parentOneCounter++;
                }
                else
                    child.moveToFinishS = parentTwo.moveToFinishS;
            }
       //  switchCounter++;
            break;
        case 9:
            if (parentOneCounter < 8)
            {
                 if (randSelector < 8)
                 {
                     child.moveInFinishS = randomize(parentOne.moveInFinishS, 0.2);
                     parentOneCounter++;
                 }
                 else
                     child.moveInFinishS = parentOne.moveInFinishS;
            }
            else
            {
                if (randSelector < 8)
                {
                    child.moveInFinishS = randomize(parentTwo.moveInFinishS, 0.2);
                    parentOneCounter++;
                }
                else
                    child.moveInFinishS = parentTwo.moveInFinishS;
            }
      //   switchCounter++;
            break;
        case 10:
            if (parentOneCounter < 8)
            {
                 if (randSelector < 8)
                 {
                     child.outOfHomeS = randomize(parentOne.outOfHomeS, 0.2);
                     parentOneCounter++;
                 }
                 else
                     child.outOfHomeS = parentOne.outOfHomeS;
            }
            else
            {
                if (randSelector < 8)
                {
                    child.outOfHomeS = randomize(parentTwo.outOfHomeS, 0.2);
                    parentOneCounter++;
                }
                else
                    child.outOfHomeS = parentTwo.outOfHomeS;
            }
     //    switchCounter++;
            break;
        case 11:
            if (parentOneCounter < 8)
            {
                 if (randSelector < 8)
                 {
                     child.finishPieceS = randomize(parentOne.finishPieceS, 0.2);
                     parentOneCounter++;
                 }
                 else
                     child.finishPieceS = parentOne.finishPieceS;
            }
            else
            {
                if (randSelector < 8)
                {
                    child.finishPieceS = randomize(parentTwo.finishPieceS, 0.2);
                    parentOneCounter++;
                }
                else
                    child.finishPieceS = parentTwo.finishPieceS;
            }
      //   switchCounter++;
            break;
        case 12:
            if (parentOneCounter < 8)
            {
                 if (randSelector < 8)
                 {
                     child.safetyFactor = randomize(parentOne.safetyFactor, 0.2);
                     parentOneCounter++;
                 }
                 else
                     child.safetyFactor = parentOne.safetyFactor;
            }
            else
            {
                if (randSelector < 8)
                {
                    child.safetyFactor = randomize(parentTwo.safetyFactor, 0.2);
                    parentOneCounter++;
                    if (child.safetyFactor < 0)
                        child.safetyFactor = 0;
                }
                else
                    child.safetyFactor = parentTwo.safetyFactor;
                    if (child.safetyFactor < 0)
                        child.safetyFactor = 0;
            }
       //  switchCounter++;
            break;
        case 13:
            if (parentOneCounter < 8)
            {
                 if (randSelector < 8)
                 {
                     child.potFactor = randomize(parentOne.potFactor, 0.2);
                     parentOneCounter++;
                 }
                 else
                     child.potFactor = parentOne.potFactor;
            }
            else
            {
                if (randSelector < 8)
                {
                    child.potFactor = randomize(parentTwo.potFactor, 0.2);
                    parentOneCounter++;
                }
                else
                    child.potFactor = parentTwo.potFactor;
            }

            break;
        default:
            break;
        }
      //  std::cout <<  "switchCounter " << switchCounter << "\n";
        switchCounter++;
        if (switchCounter > 13)
            switchCounter = 1;

    }
  //  std::cout << "Created a child with parent one gene: \n";
    //printGene(parentOne);
   // std::cout <<"And parent two gene: \n";
    //printGene(parentTwo);
    //std::cout << "Which resulted in following child gene: \n";
    //printGene(child);
    return child;
}
void geneticLudoEvolv::printGene(baseScores gene)
{

    std::cout << "Create block: " << gene.createBlockS << "\n";
    std::cout << "finishPiece: " << gene.finishPieceS << "\n";
    std::cout << "Move forward: " << gene.moveForwardS << "\n";
    std::cout << "Move to globe: " << gene.moveGlobeS << "\n";
    std::cout << "Move in finish: " << gene.moveInFinishS << "\n";
    std::cout << "Move to star: " << gene.moveStarS << "\n";
    std::cout << "Move to star and send home: " << gene.moveStarSendHomeS << "\n";
    std::cout << "Move to finish: " << gene.moveToFinishS << "\n";
    std::cout << "Get out of home: " << gene.outOfHomeS << "\n";
    std::cout << "Stop blocking the field: " << gene.stopBlockS << "\n";
    std::cout << "Send piece home " << gene.sendHomeS << "\n" ;
    std::cout << "safetyFactor " << gene.safetyFactor << "\n" ;
    std::cout << "Potfactor " << gene.potFactor << "\n\n" ;
}

/*Sample code to read files
 * void SokabanLoader::loadMap(string location)
{
    string line; //The input we're iterating over
    cout << location.c_str() << endl;
    ifstream txtMap(location.c_str()); //CHANGE ASAP
    bool firstLine = true;
    int heightIterator = 0;
    if (txtMap.is_open())
    {
        while (getline (txtMap, line))
        {
            if (firstLine == true)
            {
                width = ((int)line[0]-48)*10 + (int)line[1]-48; //-48 is the offset between ascii table start index and ints start index
                cout << "line: " << line << endl;
                height = (int)(line[3]-48)*10 + (int)(line[4]-48);
                noDiamonds = (int)line[6]*10 +(int)line[7];
                firstLine = false;
                charMap = initMap(width, height);
                cout << "width: " << width << " height: " << height << endl;
            }
            else
            {
                for(int i = 0; i< line.size(); i++)
                {
                    charMap[i][heightIterator] = line[i];
                   // cout << line[i] << " ";
                }
                heightIterator++;
            }
        }
        txtMap.close();
        printMap();
    }
    else
        cout << "Could not open file..." << endl;
}
 *
 *
 **/
