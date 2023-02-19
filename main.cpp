#include <list>
#include <stack>
#include <iostream>
#include <string>
#include <ostream>
#include <stdio.h>
#include <queue>
#include <bits/stdc++.h>

using namespace std;


class player{
public:
    string Name;
    int Score;

    player(string name, int score){
        Name = name;
        Score = score;
    }

};


void dateDisplay(list<int>);
void topThree(list<player>);
string dateFormatter(int date);


/*You are to write a c++ program using the following business requirements. In doing so your code must use a pointer at some point and your choice of  a list, or a stack, or a que

1. You are to enter 10 players, their name and their high score and the date they got it.

2. In your code you must sort the date in descending order, using a pointer display the list.

3. In addition to displaying the list, you must then display the top three scorers.

4. The highest player will be displayed last.

5. On a separate document you must give an example of que, stack, list and when to use them. This part must be technical.*/

//Used to gather user info and then place the lists into the functions that will sort and print them. (We make the date into a number using stoi)
int main(){
    list<player> players;
    list<int> dates;
    string name;
    int score;
    int dateNum;
    string date;
    string reformattedDate;
    for (int playerCounter = 0; playerCounter < 1; playerCounter++) {
        printf("Please enter player %ds name:\n", playerCounter + 1);
        cin >> name;
        printf("Please enter player %ds high score:\n", playerCounter + 1);
        cin >> score;
        printf("Please enter the date player %d got the score (Use this format: (DD/MM/YYYY):\n", playerCounter + 1);
        cin >> date;
        reformattedDate = date.substr(6,4) + date.substr(3,2) + date.substr(0,2);
        dateNum = stoi(reformattedDate);
        players.emplace_back(name, score);
        dates.push_front(dateNum);
    }

    dateDisplay(dates);
    topThree(players);
}




//Sorts the date then displays the date
void dateDisplay(list<int> dates) {
    dates.sort();
    dates.reverse();
    list<int>::iterator dateIt;
    for (dateIt = dates.begin(); dateIt != dates.end(); dateIt++) {
        int date = *dateIt;
        cout << dateFormatter(date) << '\n';
    }

}

//Sorts player list comparing scores
bool scoreSort(const player &firstPlayer, const player &secondPlayer){
    return firstPlayer.Score < secondPlayer.Score;
}

//Top three with first placed displayed last.
void topThree(list<player> players){
        players.sort(scoreSort);
        for(int popper = 0; popper < 2; popper++){
        players.pop_front();
        }
        list<player>::iterator playerIt;
        for(playerIt = players.begin(); playerIt != players.end(); *playerIt++) {
            cout << (*playerIt).Name  << " " << (*playerIt).Score  << '\n';
        }
}

//refactors the dates back into original format
string dateFormatter(int date){
    string dateString = to_string(date);


    string correctFormat = dateString.substr(6, 2)+ "/" + dateString.substr(4,2) + "/" + dateString.substr(0,4);

    return correctFormat;
}
