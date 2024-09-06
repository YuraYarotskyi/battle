#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



struct PlayerInfo
{
    string name;
    int clan_id;
    int health;
    int power;
};


vector<PlayerInfo> team0;
vector<PlayerInfo> team1;

void add_player()
{
    cout << "Add player" << endl;


    string name;
    int clan_id, health, strength;

    cout << "Enter player name:" << endl;
    cin >> name;

    cout << "Enter clan id:" << endl;
    cin >> clan_id;

    cout << "Enter player health:" << endl;
    cin >> health;

    cout << "Enter player strength" << endl;
    cin >> strength;

    if(clan_id == 0)
    {
        for (auto el : team0)
        {
            if(el.name == name)
            {
                cout << "Player already exists" << endl;
                break;
            }
        }

        team0.push_back({ name , clan_id , health , strength});

    } else {

        for (auto el : team1)
        {
            if(el.name == name)
            {
                cout << "Player already exists" << endl;
                break;
            }
        }

        team1.push_back({ name , clan_id , health , strength});
    }

}

void remove_player()
{
    int team_id;
    string name;

    cout << "Enter player name:" << endl;
    cin >> name;

    cout << "Enter player team id:" << endl;
    cin >> team_id;

    if(team_id == 0)
    {
        for(auto el : team0)
        {
            if (el.name == name)
            {
                team0.erase(std::remove_if(team0.begin(), team0.end(), [&](const PlayerInfo& el) { return el.name == name; }), team0.end());
                break;
            }
        }
        cout << "Wrong data provided!" << endl;

    } else if(team_id == 1) 
    {
        for(auto el : team1)
        {
            if (el.name == name)
            {
                team1.erase(std::remove_if(team1.begin(), team1.end(), [&](const PlayerInfo& el) { return el.name == name; }), team1.end());
                break;
            }
        }

        cout << "Wrong data provided!" << endl;
    } else {
        cout << "Wrong team id!" << endl;
    }


}

void start_game()
{
    cout << "Start game" << endl;

    int team0_health = 0, team1_health = 0, team0_strength = 0, team1_strength = 0;

    cout << "Team0:" << endl; 

    for( auto el : team0)
    {
        cout << el.name << endl;
        team0_health += el.health;
        team0_strength += el.power;
    }

    cout << "Team0 health: " << team0_health << "\nTeam0 power: " << team0_strength << endl;


    cout << "Team1:" << endl; 

    for( auto el : team1)
    {
        cout << el.name << endl;
        team1_health += el.health;
        team1_strength += el.power;
    }

    cout << "Team1 health: " << team1_health << "\nTeam1 power: " << team1_strength << endl;
}


int main()
{


    while (true){
        int arg;
        cout << "Menu: \n0 - add player \n1 - remove player \n2 - start game" << endl;
        cin >> arg;


        if (arg == 0)
        {
            add_player();
        } else if (arg == 1)
        {
            remove_player();
        } else if (arg == 2)
        {
            start_game();
        } else {
            cout << "Error, wrong argument, enter valid argument." << endl;
        }

    }

    return 0;
}
