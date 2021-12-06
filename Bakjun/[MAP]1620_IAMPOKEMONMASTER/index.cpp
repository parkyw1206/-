#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
bool checkInt(string pokemon){
    for (int i = 0; i < pokemon.size(); i++) {
		if (!(pokemon[i] >= '0' && pokemon[i] <= '9')) return false;
	}
	return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int N,M;
    string pokemon;
    map<string,int> pokemonList;
    vector<string> pokemonNameList;
    
    cin >> M >> N;
    cin.ignore();
    
    pokemonNameList.push_back("");
    for(int i = 0 ; i < M ; i++){
        getline(cin,pokemon);
        pokemonList[pokemon] = i+1;
        pokemonNameList.push_back(pokemon);
    }
    
    for(int i = 0 ; i < N ; i++){
        getline(cin, pokemon);
        if(checkInt(pokemon)){
            printf("%s \n",pokemonNameList[stoi(pokemon)].c_str());
        }
        else{
            printf("%d \n",pokemonList[pokemon]);
        }
    }
    return 0;
}
