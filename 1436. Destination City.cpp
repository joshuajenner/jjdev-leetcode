#include <vector>
using namespace std;

// You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. 
// Return the destination city, that is, the city without any path outgoing to another city.

// It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

string destCity(vector<vector<string>>& paths);

string destCity(vector<vector<string>>& paths)
{
	unordered_map<string, bool> cityIsBeginning;
	unordered_map<string, bool> cityIsDestination;

	for (int index = 0; index < paths.size(); index++) 
	{
		cityIsBeginning[paths[index][0]] = true;
		cityIsDestination[paths[index][1]] = true;
	}

	for (auto checkCity : cityIsDestination)
	{
		if (cityIsBeginning.find(checkCity.first) == cityIsBeginning.end())
		{
			return checkCity.first;
		}
	}
	return "";
}