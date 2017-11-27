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

void printBoard(vector<card> sf1,vector<card> sf2,vector<card> sf3,vector<card> sf4,vector<card> sf5,vector<card> sf6,vector<card> sf7);
void instructions();
void setTopCardVisible(vector<card> &sf1, vector<card> &sf2, vector<card> &sf3, vector<card> &sf4, vector<card> &sf5, vector<card> &sf6, vector<card> &sf7);

int main()
{
/*GAME SET UP*/

    //create vectors to contain the card objects
    vector<card> myDeck, spadesFinal, clubsFinal, heartsFinal, diamondsFinal, s1, s2, s3, s4, s5, s6, s7;

    int counter = 0;
    int deckCount = 0;
    bool gameLoop = true;
    int userChoice;
    int slotSelect;
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

    while(gameLoop){
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
        printBoard(s1,s2,s3,s4,s5,s6,s7);
        instructions();
        cin >>userChoice;

        if(userChoice == 1){
            deckCount++;
        } else if(userChoice == 2){
        //move cards


        } else if(userChoice == 3){


        } else if(userChoice == 4){
            gameLoop = false;
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
    cout << "Type the preceding number to perform the action." << endl;
    cout << "1. Next card in deck" << endl;
    cout << "2. Move single Card" << endl;
    cout << "3. Move group of Cards" << endl;
    cout << "4. Quit" << endl;
}

void printBoard(vector<card> sf1, vector<card> sf2, vector<card> sf3, vector<card> sf4, vector<card> sf5, vector<card> sf6, vector<card> sf7){
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




