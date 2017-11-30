#include <iostream>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <iterator>
#include <ostream>
#include <vector>

using namespace std;

class card{
    public:
        //CONSTRCUTORS
        card();
        card(int cardFace, int cardSuit, bool visible);

        //getters
        int getFaceVal(){
            return face;
        }

        int getSuit(){
            return suit;
        }

        bool getVisible(){
            return visible;
        }
        //setters
        void setFaceVal(int faceVal){
            this->face = faceVal;
        }

        void setSuitVal(int suitVal){
            this->suit = suitVal;
        }

        void setVisible(){
            this->visible = true;
        }

    private:
        int face;
        int suit;
        bool visible;
};

void printBoard(vector<card> sf1,vector<card> sf2,vector<card> sf3,vector<card> sf4,vector<card> sf5,vector<card> sf6,vector<card> sf7,vector<card> spadesFinal, vector<card> clubsFinal,vector<card> heartsFinal, vector<card> diamondsFinal);
void instructions();
void setTopCardVisible(vector<card> &sf1, vector<card> &sf2, vector<card> &sf3, vector<card> &sf4, vector<card> &sf5, vector<card> &sf6, vector<card> &sf7);
int cardFinder(vector<card> sf1, int topCardFind);
int suitFinder(vector<card> sf1, int topCardFind);
bool cardFinderHelper(vector<card> sf1, int topCardFind);
void cardMover(vector<card> &sf1, vector<card> &sf2, int topCard, int deckCount);

int main()
{
/*GAME SET UP*/

    //create vectors to contain the card objects
    vector<card> myDeck, spadesFinal, clubsFinal, heartsFinal, diamondsFinal, s1, s2, s3, s4, s5, s6, s7;

    int counter = 0;
    int deckCount = 0;
    bool gameLoop = true;
    int userChoice;
    int slotSelectFrom;
    int slotSelectTo;
    int topCard;
    int cardLocation;

    //Create the deck
    for(int i=1; i<=13; i++){
        for(int j=0; j<4; j++){
            myDeck.push_back(card(i,j, false));
            counter++;
        }
    }
    //shuffle the cards
    random_shuffle(myDeck.begin(), myDeck.end());

    //deal the deck
    int pos = 0;
    while(pos < 28){
        if(s1.size() < 1){
            s1.push_back(myDeck.back());
            myDeck.pop_back();
            pos++;
        }
        if(s2.size() < 2){
            s2.push_back(myDeck.back());
            myDeck.pop_back();
            pos++;
        }
        if(s3.size() < 3){
            s3.push_back(myDeck.back());
            myDeck.pop_back();
            pos++;
        }
        if(s4.size() < 4){
            s4.push_back(myDeck.back());
            myDeck.pop_back();
            pos++;
        }
        if(s5.size() < 5){
            s5.push_back(myDeck.back());
            myDeck.pop_back();
            pos++;
        }
        if(s6.size() < 6){
            s6.push_back(myDeck.back());
            myDeck.pop_back();
            pos++;
        }
        if(s7.size() < 7){
            s7.push_back(myDeck.back());
            myDeck.pop_back();
            pos++;
        }
    }
    //LOOP TO PLAY THE GAME
    while(gameLoop){
        while(spadesFinal.size()!= 13 && clubsFinal.size()!=13 && heartsFinal.size()!=13 && diamondsFinal.size()!=13){
            //display deck and allow to loop through
            if(deckCount == 0){
                cout << "Deck Card: " << endl;
            } else{
                cout << "Deck Card: ";
                cout << myDeck[deckCount].getFaceVal();
                cout << " ";
                cout << myDeck[deckCount].getSuit() << endl;
            }
            //print board, display instructions, allow user to choose what move to make
            setTopCardVisible(s1,s2,s3,s4,s5,s6,s7);
            printBoard(s1,s2,s3,s4,s5,s6,s7,spadesFinal,clubsFinal,heartsFinal,diamondsFinal);
            instructions();
            cin >>userChoice;


            if(userChoice == 1){
                //CYCLE THROUGH THE DECK
                deckCount++;
            } else if(userChoice == 2){
            //move cards
                cout << "Type the slot you would like to move from(0-7 where 0 is the deck): ";
                cin >> slotSelectFrom;
                cout << "Type the highest value of the cards you wish to move: ";
                cin >> topCard;
                cout << "Type the slot you would like to move them to(0-7 where 0 is the deck): ";
                cin >> slotSelectTo;

                if(slotSelectFrom == 0){
                    if(slotSelectTo == 1){
                        cardMover(myDeck, s1, topCard, deckCount);
                    } else if(slotSelectTo == 2){
                        cardMover(myDeck, s2, topCard, deckCount);
                    } else if(slotSelectTo == 3){
                        cardMover(myDeck, s3, topCard, deckCount);
                    } else if(slotSelectTo == 4){
                        cardMover(myDeck, s4, topCard, deckCount);
                    } else if(slotSelectTo == 5){
                        cardMover(myDeck, s5, topCard, deckCount);
                    } else if(slotSelectTo == 6){
                        cardMover(myDeck, s6, topCard, deckCount);
                    } else if(slotSelectTo == 7){
                        cardMover(myDeck, s7, topCard, deckCount);
                    } else if(slotSelectTo == 8){
                        cardMover(myDeck, heartsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 9){
                        cardMover(myDeck, diamondsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 10){
                        cardMover(myDeck, clubsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 11){
                        cardMover(myDeck, spadesFinal, topCard, deckCount);
                    }

                } else if(slotSelectFrom == 1){
                    if(slotSelectTo == 1){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 2){
                        cardMover(s1, s2, topCard, deckCount);
                    } else if(slotSelectTo == 3){
                        cardMover(s1, s3, topCard, deckCount);
                    } else if(slotSelectTo == 4){
                        cardMover(s1, s4, topCard, deckCount);
                    } else if(slotSelectTo == 5){
                        cardMover(s1, s5, topCard, deckCount);
                    } else if(slotSelectTo == 6){
                        cardMover(s1, s6, topCard, deckCount);
                    } else if(slotSelectTo == 7){
                        cardMover(s1, s7, topCard, deckCount);
                    } else if(slotSelectTo == 8){
                        cardMover(s1, heartsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 9){
                        cardMover(s1, diamondsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 10){
                        cardMover(s1, clubsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 11){
                        cardMover(s1, spadesFinal, topCard, deckCount);
                    }
                } else if(slotSelectFrom == 2){
                    if(slotSelectTo == 1){
                        cardMover(s2, s1, topCard, deckCount);
                    } else if(slotSelectTo == 2){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 3){
                        cardMover(s2, s3, topCard, deckCount);
                    } else if(slotSelectTo == 4){
                        cardMover(s2, s4, topCard, deckCount);
                    } else if(slotSelectTo == 5){
                        cardMover(s2, s5, topCard, deckCount);
                    } else if(slotSelectTo == 6){
                        cardMover(s2, s6, topCard, deckCount);
                    } else if(slotSelectTo == 7){
                        cardMover(s2, s7, topCard, deckCount);
                    } else if(slotSelectTo == 8){
                        cardMover(s2, heartsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 9){
                        cardMover(s2, diamondsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 10){
                        cardMover(s2, clubsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 11){
                        cardMover(s2, spadesFinal, topCard, deckCount);
                    }
                } else if(slotSelectFrom == 3){
                    if(slotSelectTo == 1){
                        cardMover(s3, s1, topCard, deckCount);
                    } else if(slotSelectTo == 2){
                        cardMover(s3, s2, topCard, deckCount);
                    } else if(slotSelectTo == 3){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 4){
                        cardMover(s3, s4, topCard, deckCount);
                    } else if(slotSelectTo == 5){
                        cardMover(s3, s5, topCard, deckCount);
                    } else if(slotSelectTo == 6){
                        cardMover(s3, s6, topCard, deckCount);
                    } else if(slotSelectTo == 7){
                        cardMover(s3, s7, topCard, deckCount);
                    } else if(slotSelectTo == 8){
                        cardMover(s3, heartsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 9){
                        cardMover(s3, diamondsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 10){
                        cardMover(s3, clubsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 11){
                        cardMover(s3, spadesFinal, topCard, deckCount);
                    }
                } else if(slotSelectFrom == 4){
                    if(slotSelectTo == 1){
                        cardMover(s4, s1, topCard, deckCount);
                    } else if(slotSelectTo == 2){
                        cardMover(s4, s2, topCard, deckCount);
                    } else if(slotSelectTo == 3){
                        cardMover(s4, s3, topCard, deckCount);
                    } else if(slotSelectTo == 4){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 5){
                        cardMover(s4, s5, topCard, deckCount);
                    } else if(slotSelectTo == 6){
                        cardMover(s4, s6, topCard, deckCount);
                    } else if(slotSelectTo == 7){
                        cardMover(s4, s7, topCard, deckCount);
                    } else if(slotSelectTo == 8){
                        cardMover(s4, heartsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 9){
                        cardMover(s4, diamondsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 10){
                        cardMover(s4, clubsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 11){
                        cardMover(s4, spadesFinal, topCard, deckCount);
                    }
                } else if(slotSelectFrom == 5){
                    if(slotSelectTo == 1){
                        cardMover(s5, s1, topCard, deckCount);
                    } else if(slotSelectTo == 2){
                        cardMover(s5, s2, topCard, deckCount);
                    } else if(slotSelectTo == 3){
                        cardMover(s5, s3, topCard, deckCount);
                    } else if(slotSelectTo == 4){
                        cardMover(s5, s4, topCard, deckCount);
                    } else if(slotSelectTo == 5){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 6){
                        cardMover(s5, s6, topCard, deckCount);
                    } else if(slotSelectTo == 7){
                        cardMover(s5, s7, topCard, deckCount);
                    } else if(slotSelectTo == 8){
                        cardMover(s5, heartsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 9){
                        cardMover(s5, diamondsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 10){
                        cardMover(s5, clubsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 11){
                        cardMover(s5, spadesFinal, topCard, deckCount);
                    }
                } else if(slotSelectFrom == 6){
                    if(slotSelectTo == 1){
                        cardMover(s6, s1, topCard, deckCount);
                    } else if(slotSelectTo == 2){
                        cardMover(s6, s2, topCard, deckCount);
                    } else if(slotSelectTo == 3){
                        cardMover(s6, s3, topCard, deckCount);
                    } else if(slotSelectTo == 4){
                        cardMover(s6, s4, topCard, deckCount);
                    } else if(slotSelectTo == 5){
                        cardMover(s6, s5, topCard, deckCount);
                    } else if(slotSelectTo == 6){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 7){
                        cardMover(s6, s7, topCard, deckCount);
                    } else if(slotSelectTo == 8){
                        cardMover(s6, heartsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 9){
                        cardMover(s6, diamondsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 10){
                        cardMover(s6, clubsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 11){
                        cardMover(s6, spadesFinal, topCard, deckCount);
                    }
                } else if(slotSelectFrom == 7){
                    if(slotSelectTo == 1){
                        cardMover(s7, s1, topCard, deckCount);
                    } else if(slotSelectTo == 2){
                        cardMover(s7, s2, topCard, deckCount);
                    } else if(slotSelectTo == 3){
                        cardMover(s7, s3, topCard, deckCount);
                    } else if(slotSelectTo == 4){
                        cardMover(s7, s4, topCard, deckCount);
                    } else if(slotSelectTo == 5){
                        cardMover(s7, s5, topCard, deckCount);
                    } else if(slotSelectTo == 6){
                        cardMover(s7, s6, topCard, deckCount);
                    } else if(slotSelectTo == 7){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 8){
                        cardMover(s7, heartsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 9){
                        cardMover(s7, diamondsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 10){
                        cardMover(s7, clubsFinal, topCard, deckCount);
                    } else if(slotSelectTo == 11){
                        cardMover(s7, spadesFinal, topCard, deckCount);
                    }
                } else if(slotSelectFrom == 8){
                    if(slotSelectTo == 1){
                        cardMover(heartsFinal, s1, topCard, deckCount);
                    } else if(slotSelectTo == 2){
                        cardMover(heartsFinal, s2, topCard, deckCount);
                    } else if(slotSelectTo == 3){
                        cardMover(heartsFinal, s3, topCard, deckCount);
                    } else if(slotSelectTo == 4){
                        cardMover(heartsFinal, s4, topCard, deckCount);
                    } else if(slotSelectTo == 5){
                        cardMover(heartsFinal, s5, topCard, deckCount);
                    } else if(slotSelectTo == 6){
                        cardMover(heartsFinal, s6, topCard, deckCount);
                    } else if(slotSelectTo == 7){
                        cardMover(heartsFinal, s7, topCard, deckCount);
                    } else if(slotSelectTo == 8){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 9){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 10){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 11){
                        cout << "The move is not valid. Try Again." << endl;
                    }
                } else if(slotSelectFrom == 9){
                    if(slotSelectTo == 1){
                        cardMover(diamondsFinal, s1, topCard, deckCount);
                    } else if(slotSelectTo == 2){
                        cardMover(diamondsFinal, s2, topCard, deckCount);
                    } else if(slotSelectTo == 3){
                        cardMover(diamondsFinal, s3, topCard, deckCount);
                    } else if(slotSelectTo == 4){
                        cardMover(diamondsFinal, s4, topCard, deckCount);
                    } else if(slotSelectTo == 5){
                        cardMover(diamondsFinal, s5, topCard, deckCount);
                    } else if(slotSelectTo == 6){
                        cardMover(diamondsFinal, s6, topCard, deckCount);
                    } else if(slotSelectTo == 7){
                        cardMover(diamondsFinal, s7, topCard, deckCount);
                    } else if(slotSelectTo == 8){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 9){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 10){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 11){
                        cout << "The move is not valid. Try Again." << endl;
                    }
                } else if(slotSelectFrom == 10){
                    if(slotSelectTo == 1){
                        cardMover(clubsFinal, s1, topCard, deckCount);
                    } else if(slotSelectTo == 2){
                        cardMover(clubsFinal, s2, topCard, deckCount);
                    } else if(slotSelectTo == 3){
                        cardMover(clubsFinal, s3, topCard, deckCount);
                    } else if(slotSelectTo == 4){
                        cardMover(clubsFinal, s4, topCard, deckCount);
                    } else if(slotSelectTo == 5){
                        cardMover(clubsFinal, s5, topCard, deckCount);
                    } else if(slotSelectTo == 6){
                        cardMover(clubsFinal, s6, topCard, deckCount);
                    } else if(slotSelectTo == 7){
                        cardMover(clubsFinal, s7, topCard, deckCount);
                    } else if(slotSelectTo == 8){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 9){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 10){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 11){
                        cout << "The move is not valid. Try Again." << endl;
                    }
                } else if(slotSelectFrom == 11){
                    if(slotSelectTo == 1){
                        cardMover(spadesFinal, s1, topCard, deckCount);
                    } else if(slotSelectTo == 2){
                        cardMover(spadesFinal, s2, topCard, deckCount);
                    } else if(slotSelectTo == 3){
                        cardMover(spadesFinal, s3, topCard, deckCount);
                    } else if(slotSelectTo == 4){
                        cardMover(spadesFinal, s4, topCard, deckCount);
                    } else if(slotSelectTo == 5){
                        cardMover(spadesFinal, s5, topCard, deckCount);
                    } else if(slotSelectTo == 6){
                        cardMover(spadesFinal, s6, topCard, deckCount);
                    } else if(slotSelectTo == 7){
                        cardMover(spadesFinal, s7, topCard, deckCount);
                    } else if(slotSelectTo == 8){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 9){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 10){
                        cout << "The move is not valid. Try Again." << endl;
                    } else if(slotSelectTo == 11){
                        cout << "The move is not valid. Try Again." << endl;
                    }
                }
            } else if(userChoice == 3){
                gameLoop = false;

            } else {
                cout << "Try Again.Improper input, type a number 1,2, or 3." << endl;
            }

        }
    }

    return 0;
}

card::card(){
    face = 0;
    suit = 0;
    visible = true;
}

card::card(int cardFace, int cardSuit, bool visible){
    this->face = cardFace;
    this->suit = cardSuit;
    this->visible = visible;
}

void instructions(){
    cout << "The cards are represented by numbers, 1-13 are the face values, and 0-3 are the suits." << endl;
    cout << "Face Values:(1=ace, 11=jack, 12=queen, 13=king)" << endl;
    cout << "Suits: the suits are (0=hearts, 1=diamonds, 2=clubs, 3=spades)." << endl;
    cout << "The slots to put Ace-King in for each suit are... 8=hearts, 9=diamonds, 10=clubs, 11=spades " << endl;
    cout << "Type the preceding number to perform the action." << endl;
    cout << "1. Next card in deck(located above slot 1 text)" << endl;
    cout << "2. Move Cards" << endl;
    cout << "3. Quit" << endl;

}

void printBoard(vector<card> sf1, vector<card> sf2, vector<card> sf3, vector<card> sf4, vector<card> sf5, vector<card> sf6, vector<card> sf7,vector<card> spadesFinal, vector<card> clubsFinal,vector<card> heartsFinal, vector<card> diamondsFinal){
    if(heartsFinal.size() > 0){
        cout << "Hearts(0): ";
        cout << heartsFinal.back().getFaceVal();
    } else {
        cout << "Hearts(0):     ";
    }
    if(diamondsFinal.size() > 0){
        cout << "Diamonds(1): ";
        cout << diamondsFinal.back().getFaceVal();
    } else {
        cout << "Diamonds(1):     ";
    }
    if(clubsFinal.size() > 0){
        cout << "Clubs(2): ";
        cout << clubsFinal.back().getFaceVal();
    } else {
        cout << "Clubs(2):     ";
    }
    if(spadesFinal.size() > 0){
        cout << "Spades(3): ";
        cout << clubsFinal.back().getFaceVal() << endl;
    } else {
        cout << "Spades(3):     " << endl;
    }

	cout << "Slot1       Slot2       Slot3       Slot4       Slot5       Slot6       Slot7" << endl;
    cout << "------      ------      ------      ------      ------      ------      ------" << endl;
	/*
		Find the biggest slot. You only have to loop that many times.
	*/
	int max = sf1.size();
	if(sf2.size() > max){
		max = sf2.size();
	}
	if(sf3.size() > max){
		max = sf3.size();
	}
	if(sf4.size() > max){
		max = sf4.size();
	}
	if(sf5.size() > max){
		max = sf5.size();
	}
	if(sf6.size() > max){
		max = sf6.size();
	}
	if(sf7.size() > max){
		max = sf7.size();
	}


    for(int i = 0; i < max; i++){
		if(i < sf1.size()){
            if(sf1[i].getVisible() == true){
                cout << sf1[i].getFaceVal();
                cout << " ";
                cout << sf1[i].getSuit();
                cout << "  ";

            }
            else if (sf1[i].getVisible() == false){
                cout << "*****";
            }


			if(sf1[i].getFaceVal() > 9){
            	cout << "      ";
			}
			else{
				cout << "       ";
			}
		}
		else{
			cout << "            ";
		}

		if(i < sf2.size()){
            if(sf2[i].getVisible() == true){
                cout << sf2[i].getFaceVal();
                cout << " ";
                cout << sf2[i].getSuit();
                cout << "  ";

            }
            else if(sf2[i].getVisible() == false){
                cout << "*****";
            }

			if(sf2[i].getFaceVal() > 9){
            	cout << "      ";
			}
			else{
				cout << "       ";
			}
		}
		else{
			cout << "            ";
		}
		if(i < sf3.size()){
            if(sf3[i].getVisible() == true){
                cout << sf3[i].getFaceVal();
                cout << " ";
                cout << sf3[i].getSuit();
                cout << " ";

            }
			else if(sf3[i].getVisible() == false){
                cout << "*****";
            }

			if(sf3[i].getFaceVal() > 9){
            	cout << "       ";
			}
			else{
				cout << "       ";
			}
		}
		else{
			cout << "            ";
		}
		if(i < sf4.size()){
            if(sf4[i].getVisible() == true){
                cout << sf4[i].getFaceVal();
                cout << " ";
                cout << sf4[i].getSuit();
                cout << "  ";
            }
            else if(sf4[i].getVisible() == false){
                cout << "*****";
            }


			if(sf4[i].getFaceVal() > 9){
            	cout << "      ";
			}
			else{
				cout << "       ";
			}
		}
		else{
			cout << "            ";
		}
		if(i < sf5.size()){
            if(sf5[i].getVisible() == true){
                cout << sf5[i].getFaceVal();
                cout << " ";
                cout << sf5[i].getSuit();
                cout << "  ";
            }
            else if(sf5[i].getVisible() == false){
                cout << "*****";
            }

			if(sf5[i].getFaceVal() > 9){
            	cout << "       ";
			}
			else{
				cout << "       ";
			}
		}
		else{
			cout << "            ";
		}
		if(i < sf6.size()){
            if(sf6[i].getVisible() == true){
                cout << sf6[i].getFaceVal();
                cout << " ";
                cout << sf6[i].getSuit();
                cout << "  ";
            }
			else if(sf6[i].getVisible() == false){
                cout << "*****";
            }
			if(sf6[i].getFaceVal() > 9){
            	cout << "       ";
			}
			else{
				cout << "       ";
			}
		}
		else{
			cout << "            ";
		}
		if(i < sf7.size()){
            if(sf7[i].getVisible() == true){
                cout << sf7[i].getFaceVal();
                cout << " ";
                cout << sf7[i].getSuit();
                cout << "  ";
            }
            else if(sf7[i].getVisible() == false){
                cout << "*****";
            }


			if(sf7[i].getFaceVal() > 9){
            	cout << "       ";
			}
			else{
				cout << "       ";
			}
		}
		else{
			cout << "            ";
		}
		cout << endl;
	}

}

void setTopCardVisible(vector<card> &sf1, vector<card> &sf2, vector<card> &sf3, vector<card> &sf4, vector<card> &sf5, vector<card> &sf6, vector<card> &sf7){
    if(sf1.back().getVisible() == false){
        sf1.back().setVisible();
    }
    if(sf2.back().getVisible() == false){
        sf2.back().setVisible();
    }
    if(sf3.back().getVisible() == false){
        sf3.back().setVisible();
    }
    if(sf4.back().getVisible() == false){
        sf4.back().setVisible();
    }
    if(sf5.back().getVisible() == false){
        sf5.back().setVisible();
    }
    if(sf6.back().getVisible() == false){
        sf6.back().setVisible();
    }
    if(sf7.back().getVisible() == false){
        sf7.back().setVisible();
    }
}

int cardFinder(vector<card> sf1, int topCardFind){
    //return the position the card is in
    for(int i=sf1.size(); i>0; i--){
        if(sf1[i].getFaceVal() == topCardFind){
            return i;
        }
    }
}

int suitFinder(vector<card> sf1, int topCardFind){
    for(int i=sf1.size(); i>0; i--){
        if(sf1[i].getFaceVal() == topCardFind){
            return sf1[i].getSuit();
        }
    }
}

bool cardFinderHelper(vector<card> sf1, int topCardFind){
    //logic to make sure the move is valid and that the card exists in the slot
    for(int i=sf1.size(); i > 0; i--){
        if(sf1[i].getFaceVal() < sf1[i-1].getFaceVal()){
            cout << i;
            cout << ": IF WAS ENTERED"<< endl;
            if(sf1[i].getFaceVal() == topCardFind){
                cout << "true should be returned" << endl;
                return true;
            }
        }
    }
    return false;
}

void cardMover(vector<card> &sf1, vector<card> &sf2, int topCard, int deckCount){
    int cardLocation = cardFinder(sf1, topCard);
    int secondBack = sf2.back().getFaceVal()-1;
    //secondBack is used to check that the moved topCard is 1 less than the destination value
    //topCard is the highest value from the deck being moved from
    //checks the cards exist

    //check the cards exist
    cout << "helper on sf2: ";
    cout << sf2.back().getFaceVal();
    cout << cardFinderHelper(sf2, topCard+1) << endl;
    if(cardFinderHelper(sf1, topCard) == true && cardFinderHelper(sf2, topCard+1) == true){
        //check the face value is appropriate
        cout << "card helper returned true";
        if(topCard == secondBack){
            //check the suit compatibility
            cout << sf2.back().getSuit();
            cout << "faceval good";
            if(suitFinder(sf1,topCard) == 0 && sf2.back().getSuit() == 0){
                cout << "The move is not valid. Try Again." << endl;
            } else if(suitFinder(sf1,topCard) == 0 && sf2.back().getSuit() == 1){
                cout << "The move is not valid. Try Again." << endl;
            } else if(suitFinder(sf1,topCard) == 0 && sf2.back().getSuit() == 2){
                for(int i = sf1.size(); i > cardLocation; i--){
                        sf2.push_back(sf1[i]);
                }
            } else if(suitFinder(sf1,topCard) == 0 && sf2.back().getSuit() == 3){
                for(int i = sf1.size(); i > cardLocation; i--){
                        sf2.push_back(sf1[i]);
                }
            } else if(suitFinder(sf1,topCard) == 1 && sf2.back().getSuit() == 0){
                cout << "The move is not valid. Try Again." << endl;
            } else if(suitFinder(sf1,topCard) == 1 && sf2.back().getSuit() == 1){
                cout << "The move is not valid. Try Again." << endl;
            } else if(suitFinder(sf1,topCard) == 1 && sf2.back().getSuit() == 2){
                for(int i = sf1.size(); i > cardLocation; i--){
                        sf2.push_back(sf1[i]);
                }
            } else if(suitFinder(sf1,topCard) == 1 && sf2.back().getSuit() == 3){
                for(int i = sf1.size(); i > cardLocation; i--){
                        sf2.push_back(sf1[i]);
                }
            } else if(suitFinder(sf1,topCard) == 2 && sf2.back().getSuit() == 0){
                for(int i = sf1.size(); i > cardLocation; i--){
                        sf2.push_back(sf1[i]);
                }
            } else if(suitFinder(sf1,topCard) == 2 && sf2.back().getSuit() == 1){
                for(int i = sf1.size(); i > cardLocation; i--){
                        sf2.push_back(sf1[i]);
                }
            } else if(suitFinder(sf1,topCard) == 2 && sf2.back().getSuit() == 2){
                cout << "The move is not valid. Try Again." << endl;
            } else if(suitFinder(sf1,topCard) == 2 && sf2.back().getSuit() == 3){
                cout << "The move is not valid. Try Again." << endl;
            } else if(suitFinder(sf1,topCard) == 3 && sf2.back().getSuit() == 0){
                for(int i = sf1.size(); i > cardLocation; i--){
                        sf2.push_back(sf1[i]);
                }
            } else if(suitFinder(sf1,topCard) == 3 && sf2.back().getSuit() == 1){
                for(int i = sf1.size(); i > cardLocation; i--){
                        sf2.push_back(sf1[i]);
                }
            } else if(suitFinder(sf1,topCard) == 3 && sf2.back().getSuit() == 2){
                cout << "The move is not valid. Try Again." << endl;
            } else if(suitFinder(sf1,topCard) == 3 && sf2.back().getSuit() == 3){
                cout << "The move is not valid. Try Again." << endl;
            }

        }else{
            cout << "The move is not valid. Try Again." << endl;
        }
    }
    else{
        cout << "The move is not valid. Try Again." << endl;
    }

}

