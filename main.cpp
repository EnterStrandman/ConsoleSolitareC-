#include <iostream>
#include <array>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <iterator>
#include <list>
#include <ostream>


using namespace std;

class card{
    public:
        //CONSTRCUTORS
        card();
        card(int cardFace, int cardSuit);

        //getters
        int getFaceVal(){
            return face;
        }

        int getSuit(){
            return suit;
        }

        //setters
        int setFaceVal(int faceVal){
            this->face = faceVal;
        }

        int setSuitVal(int suitVal){
            this->suit = suitVal;
        }

    private:
        int face;
        int suit;
};

void showCards(list<card> myList1,list<card> myList2,list<card> myList3,list<card> myList4,list<card> myList5,list<card> myList6,list<card> myList7);

int main()
{
/*GAME SET UP*/

    //create deck to be used in solitaire
    card myDeck[52];
    //Slots that need completed to win
    list <card> spadesFinal;
    list <card> clubsFinal;
    list <card> heartsFinal;
    list <card> diamondsFinal;
    //Slots for board
    list <card> s1;
    list <card> s2;
    list <card> s3;
    list <card> s4;
    list <card> s5;
    list <card> s6;
    list <card> s7;

    int counter = 0;

    //Create the deck
    for(int i=1; i<=13; i++){
        for(int j=0; j<4; j++){
            myDeck[counter] = card(i,j);
            counter++;
        }
    }

    //shuffle the cards
    random_shuffle(&myDeck[0], &myDeck[51]);

    //deal the deck
    int pos = 0;
    while(pos < 28){
        if(s1.size() < 1){
            s1.push_front(myDeck[pos]);
            pos++;
        }
        if(s2.size() < 2){
            s2.push_front(myDeck[pos]);
            pos++;
        }
        if(s3.size() < 3){
            s3.push_front(myDeck[pos]);
            pos++;
        }
        if(s4.size() < 4){
            s4.push_front(myDeck[pos]);
            pos++;
        }
        if(s5.size() < 5){
            s5.push_front(myDeck[pos]);
            pos++;
        }
        if(s6.size() < 6){
            s6.push_front(myDeck[pos]);
            pos++;
        }
        if(s7.size() < 7){
            s7.push_front(myDeck[pos]);
            pos++;
        }
    }

    //print the beginning board
    cout << "Slot1  Slot2   Slot3   Slot4   Slot5   Slot6   Slot7";

    showCards(s1,s2,s3,s4,s5,s6,s7);


    return 0;
}

card::card(){
    face = 0;
    suit = 0;
}

card::card(int cardFace, int cardSuit){
    this->face = cardFace;
    this->suit = cardSuit;
}

void instructions(){
    cout << "Type instructions here";
}

void showCards(list<card> myList1,list<card> myList2,list<card> myList3,list<card> myList4,list<card> myList5,list<card> myList6,list<card> myList7){
    int totalCards =  myList1.size() + myList2.size() + myList3.size() + myList4.size() + myList5.size() + myList6.size() + myList7.size();
    int printed = 0;
    int largestList;


}







