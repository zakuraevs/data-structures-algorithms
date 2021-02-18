// Given an array of competition results and an array of competitions,
// find the team with the most points
// O(n) time where n is the number of compatitions, O(t) space where t is the number of teams.

#include <vector>
#include <unordered_map>

std::string tournamentWinner(std::vector<std::vector<std::string>> competitions,
                        std::vector<int> results) {
  
	std::unordered_map<std::string, int> teams_scores;
	int n = competitions.size();
	
	for(int i = 0; i < n; i++) {
		teams_scores[competitions[i][1 - results[i]]] += 3;
	}
	
	std::string best_team = "";
	int best_score = -1;
	
	for(std::pair<std::string, int> team : teams_scores) {
		if(team.second > best_score) {
			best_score = team.second;
			best_team = team.first;
		}
	}
  return best_team;
}
