//Salma El Gohary 09/27/2024
//this code represents a soccer game simulation, choosing a random number of events and dividing it between two halves/rounds, keeping track of the scores of the different teams and determining the winner based on the final scores

// Debug: Make program output the number of events it randomly chooses to run
// After the simulation runs, count the number of rounds it produced to make sure it produced the same number it said it would produce
// There was an error in the number of rounds the code was producing, so I debugged my code and found that my random events generator was producing a number between 0-30 instead of 1-30, and that would cause random errors in the number of outputted rounds in my code.
// I fixed my code by making it generate a random number from 1-30 by adding a 1, and it worked!

#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

int team_b_score = 0, b_shots_on_goal = 0, b_shots_off_goal = 0, b_blocked_shots = 0, b_yellow_cards = 0, b_red_cards = 0;
int team_a_score = 0, a_shots_on_goal = 0, a_shots_off_goal = 0, a_blocked_shots = 0, a_yellow_cards = 0, a_red_cards = 0;

int delay(int milliseconds){
     clock_t goal = milliseconds + clock();
     while(goal>clock());
     return 1;
    }

void a_shooting(int internal_event);
// Purpose: Determine the status of Team A's attempt to shoot a goal
// Input: Randomly generated integer internal event by the main function
// Output: Status of Team A's attempt to score a goal + either increments Team A's score, shots on goal, shots off goal or blocked shots depending on the random internal event generated

void b_shooting(int internal_event);
// Purpose: Determine the status of Team B's attempt to shoot a goal
// Input: Randomly generated integer "internal event" by the main function
// Output: Status of Team B's attempt to score a goal + either increments Team B's score, shots on goal, shots off goal or blocked shots depending on the random internal event generated

void a_foul(int penalty_card);
// Purpose: Determine the status of Team A's foul (if yellow/red card or no penalty given)
// Input: Randomly generated integer "penalty card" by the main function
// Output: Status of Team A's foul, either increments Team A's number of yellow cards, number of red cards or nothing if no penalty was given depending on the random penalty card value generated

void b_foul(int penalty_card);
// Purpose: Determine the status of Team B's foul (if yellow/red card or no penalty given)
// Input: Randomly generated integer "penalty card" by the main function
// Output: Status of Team B's foul, either increments Team B's number of yellow cards, number of red cards or nothing if no penalty was given depending on the random penalty card value generated

void a_foul_close_to_goal(int penalty_card);
// Purpose: Determine what happens when Team A commits a foul close to goal (again if yellow/red card or no penalty given)
// Input: Randomly generated integer "penalty card" by the main function
// Output: What happens to Team A regarding their foul close to goal, either increments Team A's number of yellow cards, number of red cards or nothing if no penalty was given depending on the random penalty card value generated

void b_foul_close_to_goal(int penalty_card);
// Purpose: Determine what happens when Team B commits a foul close to goal (again if yellow/red card or no penalty given)
// Input: Randomly generated integer "penalty card" by the main function
// Output: What happens to Team B regarding their foul close to goal, either increments Team B's number of yellow cards, number of red cards or nothing if no penalty was given depending on the random penalty card value generated

int main(){
    srand(time(0));

    int number_of_events = rand() % 5 + 1;
    int first_half = number_of_events / 2;
    int second_half = number_of_events - first_half;
    
    cout << "Welcome to the ultimate soccer showdown between Team A and Team B! There will be " << number_of_events << " events in this game!\n";
    delay (1*1000);
    cout << "\nThe first half will have: " << first_half << " rounds.";
    cout << "\nThe second half will have: " << second_half << " rounds.\n";
    delay (1*1000);
    cout << "\nLooks like they have started playing!\n";
    
    for (int n = 0; n < first_half ; ++n){
        int random_event = rand() % 6 + 1; //generate random number to choose between the 6 possible events
        int internal_event = rand() % 3; //generate random number to input to the functions to choose which internal event will occur within the functions
        int penalty_card = rand() % 2; //generate random number to determine what penalty each team recieves for fouls

        if (random_event == 1){ //team a shooting target
            a_shooting(internal_event);
            }
        else if (random_event == 2){ //team b shooting target
            b_shooting(internal_event);
            }
        else if (random_event == 3){ //Team b committing a foul, team A getting their free kick
            b_foul(penalty_card);
            a_shooting(internal_event);
            }
        else if (random_event == 4){ // Team A committing a foul, team B getting their free kick
            a_foul(penalty_card);
            b_shooting(internal_event);
            }
        else if (random_event == 5){ //team B committing foul close to goal, team A getting their penalty shot
            b_foul_close_to_goal(penalty_card);
            a_shooting(internal_event);
            }
        else if (random_event == 6){ //team A committing foul close to goal, team B getting their penalty shot
            a_foul_close_to_goal(penalty_card);
            b_shooting(internal_event);
            }
        }

    cout << "\nWe have reached half time! Lets give the players a break and review the scores...\n";    
    delay (3*1000);

    cout << "\n                " << "Scores" << "          " << "Blocked Shots" << "          " << "Shots On Goal" << "          " << "Shots Off Goal" << "          " << "Yellow Cards" << "          " << "Red Cards" << endl;
    cout << "Team A" << "             " << team_a_score << "                  " << a_blocked_shots << "                      " << a_shots_on_goal << "                       " << a_shots_off_goal << "                     " << a_yellow_cards << "                    " << a_red_cards << endl;
    cout << "Team B" << "             " << team_b_score << "                  " << b_blocked_shots << "                      " << b_shots_on_goal << "                       " << b_shots_off_goal << "                     " << b_yellow_cards << "                    " << b_red_cards << endl;

    if (team_a_score > team_b_score){
        cout << "\nTeam B has to catch up! Good work Team A!\n";
        }
    else if (team_b_score > team_a_score){
        cout << "\nTeam A has to catch up! Good work Team B!\n";
        }

    delay (1*1000);

    cout << "\nHalf time is over! Lets get back for the second half of the game...\n";

    delay (2*1000);

    //second half of game
    srand(time(0));

    for (int m = 0; m < second_half ; ++m){
        int random_event = rand() % 6 + 1;
        int internal_event = rand() % 3;
        int penalty_card = rand() % 2;

        if (random_event == 1){ //team a shooting target
            a_shooting(internal_event);
            }
        else if (random_event == 2){ //team b shooting target
            b_shooting(internal_event);
            }
        else if (random_event == 3){ //Team b committing a foul, team A getting their free kick
            b_foul(penalty_card);
            a_shooting(internal_event);
            }
        else if (random_event == 4){ // Team A committing a foul, team B getting their free kick
            a_foul(penalty_card);
            b_shooting(internal_event);
            }
        else if (random_event == 5){ //team B committing foul close to goal, team A getting their penalty shot
            b_foul_close_to_goal(penalty_card);
            a_shooting(internal_event);
            }
        else if (random_event == 6){ //team A committing foul close to goal, team B getting their penalty shot
            a_foul_close_to_goal(penalty_card);
            b_shooting(internal_event);
            }
    }

    cout << "\nDING DING DING, it is the end of this soccer match! Lets review the scores and see who the winner is...\n";    
    
    delay (3*1000);

    cout << "\n                " << "Scores" << "          " << "Blocked Shots" << "          " << "Shots On Goal" << "          " << "Shots Off Goal" << "          " << "Yellow Cards" << "          " << "Red Cards" << endl;
    cout << "Team A" << "             " << team_a_score << "                  " << a_blocked_shots << "                      " << a_shots_on_goal << "                       " << a_shots_off_goal << "                     " << a_yellow_cards << "                    " << a_red_cards << endl;
    cout << "Team B" << "             " << team_b_score << "                  " << b_blocked_shots << "                      " << b_shots_on_goal << "                       " << b_shots_off_goal << "                     " << b_yellow_cards << "                    " << b_red_cards << endl;
    
    delay (2*1000);
        
    if (team_a_score > team_b_score){
        cout << "\nCongratulations Team A!!! Their hard work has paid off and they have won this soccer match!";
        }
    else if (team_b_score > team_a_score){
        cout << "\nCongratulations Team B!!! Their hard work has paid off and they have won this soccer match!";
        }
    else if (team_b_score == team_a_score){
        cout << "\nIt's a tie! Good job to both teams!";
        }
    }

//function to execute if team A tries to shoot
void a_shooting(int internal_event){ 
    cout << "\nLooks like Team A has tried to shoot at the target..what is their outcome?\n";

    delay (2*1000); 

    if (internal_event == 0){ 
        cout << "Team A has scored a goal! INCREDIBLE shot!\n";
        team_a_score++;
        a_shots_on_goal++;
        }
    else if (internal_event == 1){
        cout << "SO CLOSE! Team A tried to score a goal, but was saved by the goal keeper or last defender!\n";
        a_shots_on_goal++;
        a_blocked_shots++;
        }
    else if (internal_event == 2){
        cout << "OH NO! Team A tried to score a goal, but the shot was made off goal!\n";
        a_shots_off_goal++;
        }        
    else if (internal_event == 3){
        cout << "BLOCKED! Team A tried to score a goal, but the shot was blocked by a player who is not the last defender!\n";
        a_blocked_shots++;
        a_shots_off_goal++;
        }
    }

//function to execute if team B tries to shoot
void b_shooting(int internal_event){ 
    cout << "\nTeam B has tried to shoot at the target..what is their outcome?\n";

    delay (2*1000); 

    if (internal_event == 0){ 
        cout << "Team B has scored a goal! INCREDIBLE shot!\n";
        team_b_score++;
        b_shots_on_goal++;
        }
    else if (internal_event == 1){
        cout << "SO CLOSE! Team B tried to score a goal, but was saved by the goal keeper or last defender!\n";
        b_shots_on_goal++;
        b_blocked_shots++;
        }
    else if (internal_event == 2){
        cout << "OH NO! Team B tried to score a goal, but the shot was made off goal!\n";
        b_shots_off_goal++;
        }        
    else if (internal_event == 3){
        cout << "BLOCKED! Team B tried to score a goal, but the shot was blocked by a player who is not the last defender!\n";
        b_blocked_shots++;
        b_shots_off_goal++;
        }
    }

//function to execute if team A commits a foul
void b_foul(int penalty_card){
    cout << "\nLooks like Team B has committed a foul...did they get a penalty? ";

    delay (2*1000); 

    //if card was given for foul
    if (penalty_card == 0){
        cout << "Awesome! No penalty card was given to Team B!\n";
        }
    else if (penalty_card == 1){
        cout << "Oh no! A yellow card was given to Team B.\n";
        b_yellow_cards++;
        }
    else if (penalty_card == 2){
        cout << "Oh no! A red card was given to Team B.\n";
        b_red_cards++;
        }

    //team A's free kick
    delay (2*1000);
    cout << "Team A was awarded a free kick, GO TEAM A! ";
}

//function to execute if team B commits a foul
void a_foul(int penalty_card){
//Team A committing a foul
    cout << "\nLooks like Team A has committed a foul...did they get a penalty? ";

    delay (2*1000); 

    //if card was given for foul
    if (penalty_card == 0){
        cout << "Awesome! No penalty card was given to Team A!\n";
        }
    else if (penalty_card == 1){
        cout << "Oh no! A yellow card was given to Team A.\n";
        a_yellow_cards++;
        }
    else if (penalty_card == 2){
        cout << "Oh no! A red card was given to Team A.\n";
        a_red_cards++;
        }
            
    delay (2*1000);
    //team B's free kick
    cout << "Team B was awarded a free kick, GO TEAM B! ";
}   

//function to execute if team A gets a foul close to goal
void b_foul_close_to_goal(int penalty_card){
    cout << "\nTeam B has committed a foul close to the goal...did they get a penalty? ";

    delay (2*1000); 

    //if card was given for foul
    if (penalty_card == 0){
        cout << "Awesome! No penalty card was given to Team B!\n";
        }
    else if (penalty_card == 1){
        cout << "Oh no! A yellow card was given to Team B.\n";
        b_yellow_cards++;
        }
    else if (penalty_card == 2){
        cout << "Oh no! A red card was given to Team B.\n";
        b_red_cards++;
        }

    //team A's penalty shot
    delay (2*1000);
    cout << "Team A was awarded a penalty shot, GO TEAM A! ";
}

//function to execute if team B gets a foul close to goal
void a_foul_close_to_goal(int penalty_card){
    cout << "\nLooks like Team A has committed a foul close to the goal...did they get a penalty? ";

    delay (2*1000); 

    //if card was given for foul
    if (penalty_card == 0){
        cout << "Awesome! No penalty card was given to Team A!\n";
        }
    else if (penalty_card == 1){
        cout << "Oh no! A yellow card was given to Team A.\n";
        a_yellow_cards++;
        }
    else if (penalty_card == 2){
        cout << "Oh no! A red card was given to Team A.\n";
        a_red_cards++;
        }

    //team B's penalty shot
    delay (2*1000);
    cout << "Team B was awarded a penalty shot, GO TEAM B! ";
}