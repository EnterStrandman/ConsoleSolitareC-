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

        void setVisible(bool vis){
            this->visible = true;
        }

    private:
        int face;
        int suit;
        bool visible;
};

void printBoard();
void instructions();

int main()
{
/*GAME SET UP*/

    //create deck to be used in solitaire
    vector<card> myDeck;
    //Slots that need completed to win
    vector<card> spadesFinal;
    vector<card> clubsFinal;
    vector<card> heartsFinal;
    vector<card> diamondsFinal;
    //Slots for board
    vector<card> s1;
    vector<card> s2;
    vector<card> s3;
    vector<card> s4;
    vector<card> s5;
    vector<card> s6;
    vector<card> s7;

    int counter = 0;

    //Create the deck
    for(int i=1; i<=13; i++){
        for(int j=0; j<4; j++){
            myDeck.push_back(card(i,j, false));
            counter++;
        }
    }

    //shuffle the cards
    random_shuffle(&myDeck[0], &myDeck[51]);
    cout << "the deck has been shuffled" << endl;
    //deal the deck
    int pos = 0;
    int iterations = 0;
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

    //print the beginning board
    cout << "Slot1  Slot2   Slot3   Slot4   Slot5   Slot6   Slot7";




    return 0;
}

card::card(){
    face = 0;
    suit = 0;
    visible = false;
}

card::card(int cardFace, int cardSuit, bool visible){
    this->face = cardFace;
    this->suit = cardSuit;
    this->visible = visible;
}

void instructions(){
    cout << "Type instructions here";
}

void printBoard(){

}







