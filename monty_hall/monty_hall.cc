
#include <random>
#include <iostream>

int main(){

    int reps;
    std::cout << "Enter the number of simulation runs:" << std::endl;
    std::cin >> reps;

    // rng setup
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> door3_dist(0,2); // distribution representing picking one of three doors
    std::uniform_int_distribution<std::mt19937::result_type> door2_dist(0,1); // distribtution representing picking one of two doors

    int stay_wins = 0;
    int switch_wins = 0;
    for(int i = 0; i < reps; i++){
        int doors[3] = {0, 0, 0};
        int car_pos = door3_dist(rng);

        int player_choice = 0; // the players' initial choice of door is fixed, doesnt need to be randomized if the cars position is random.

        // Monty picks a door to reveal. He only ever reveals doors with goats behind them.
        int reveal_door = door2_dist(rng) + 1;
        while (reveal_door == car_pos){
            reveal_door = door2_dist(rng) + 1;
        }

        if (player_choice == car_pos){
            stay_wins++;   // If the player doesnt switch doors
        } else {
            switch_wins++; // If the player chooses to switch doors. This is the same as if the players initial choice had a goat.
        }
    }

    float stay_prob = ( (float) stay_wins / reps) * 100;
    float switch_prob = ( (float) switch_wins / reps) * 100;

    std::cout << "Stay won " << stay_wins << "/" << reps;
    std::cout << " (" << stay_prob << "% win chance)" << std::endl;

    std::cout << "Switch won " << switch_wins << "/" << reps;
    std::cout << " (" << switch_prob << "% win chance)" << std::endl;

}