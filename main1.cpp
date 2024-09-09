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

auto game(vector<PlayerInfo> stronger_team, vector<PlayerInfo> weaker_team)
{
    while (true)
    {
        if(stronger_team[0].health > weaker_team[0].power)
        {
            stronger_team[0].health -= weaker_team[0].power;
            cout << weaker_team[0].name << " has attacked " << stronger_team[0].name << "\n" << stronger_team[0].name << "'s health: " << stronger_team[0].health << endl;
        }
        if(weaker_team[0].health > stronger_team[0].power)
        {
            weaker_team[0].health -= stronger_team[0].power;
            cout << stronger_team[0].name << " has attacked " << weaker_team[0].name << "\n" << weaker_team[0].name << "'s health: " << weaker_team[0].health << endl;
        }
        if(weaker_team[0].health <= stronger_team[0].power)
        {
            cout << stronger_team[0].name << " has killed " << weaker_team[0].name << "\n" << stronger_team[0].name << "'s health:" << stronger_team[0].health << endl;
            weaker_team.erase(weaker_team.begin());
        }
        if(stronger_team[0].health <= weaker_team[0].power)
        {
            cout << weaker_team[0].name << " has killed " << stronger_team[0].name << "\n" << weaker_team[0].name << "'s health: " << weaker_team[0].health << endl;
            stronger_team.erase(stronger_team.begin());
        }

        if(weaker_team.empty())
        {
            cout << "Team" << stronger_team[0].clan_id << " won!" << endl;
            break;
            return 0;
        }
    }
}

void start_game()
{
    if (team0.empty())
    {
        cout << "Team0 is empty! \nPlease add players." << endl;
    } else if (team1.empty())
    {
        cout << "Team1 is empty! \nPlease add players." << endl;
    } else {
        int team0_health = 0, team1_health = 0, team0_strength = 0, team1_strength = 0;

        for( auto el : team0)
        {
            team0_strength += el.power;
        }

        for( auto el : team1)
        {
            team1_health += el.health;
            team1_strength += el.power;
        }

        if(team1_health > team0_strength)
        {
            game(team1, team0);
        } 
        else if (team0_health > team1_strength)
        {
            game(team0, team1);
        } 
        else 
        {
            cout << "Draw!" << endl;
        }
    }
}

void player_list()
{
    if (team0.empty() == false)
    {
        cout << "Team0:" << endl;

        for(auto element : team0)
        {
            cout << element.name << endl;
        }
    } else {
        cout << "Team0 is empty" << endl;
    }

    if (team1.empty() == false)
    {
        cout << "Team1:" << endl;
        for (auto element : team1)
        {
            cout << element.name << endl;
        }
    } else {
        cout << "Team1 is empty" << endl;
    }

}


int main()
{
    while (true){
        int arg;
        cout << endl << "Menu: \n0 - add player \n1 - remove player \n2 - start game \n3 - list players" << endl;
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
        } else if (arg == 3)
        {
            player_list();
        } else {
            cout << "Error, wrong argument, enter valid argument." << endl;
        }
    }

    return 0;
}
