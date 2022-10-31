#include <string>
#include <map>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

/* USACO 2017 December Contest, Bronze
 * Problem 3. Milk Measurement
 *
 * Solution explanation
 * 1. Parse file, return queue ordered from smallest to largest days
 * 2. Loop through queue, update display using get_highest_cows() method
 * 3. If new display is not the same as old display, increase num_changes
 * 4. Write num_changes to file
 */

struct Entry {
	int day;
	string cow_name;
	int change_in_gallons;
};

bool operator<(const Entry& a, const Entry& b){
	return !(a.day < b.day);
}

//Parse file and return queue of cow entries in order from smallest to largest day
priority_queue<Entry> parse_file(){
	ifstream fint("measurement.in");
	priority_queue<Entry> entries;

        int num_entries;
        fint >> num_entries;

	for (int x = 0; x < num_entries; x++){ //Collect all entries
		Entry entry;

		fint >> entry.day;
		fint >> entry.cow_name;
		fint >> entry.change_in_gallons;
		entries.push(entry);
	}

	return entries;
}

//Write answer to file
void write_file(int num_changes){
	ofstream fout("measurement.out");
	fout << num_changes;
}

//Return vector of cows with highest milk production rate
vector<string> get_highest_cows(map<string, int> cows){
	map<string, int>::iterator it; //Iterate through cow map
	vector<string> highest_cows;
	int highest = 0;

	for (it = cows.begin(); it != cows.end(); it++) {
		if (cows[it->first] > highest){
			highest = cows[it->first]; //Highest is updated
			highest_cows.clear();
			highest_cows.push_back(it->first);

		} else if (cows[it->first] == highest){
			highest_cows.push_back(it->first);
		}
	}
	return highest_cows;
}

//Return number of changes to display
int get_solution(priority_queue<Entry> entries){
	int num_changes = 0; //Number of changes in display
	vector<string> display;

	map<string, int> cows; //Map of cows to gallons
	cows["Bessie"] = 7;
	cows["Elsie"] = 7;
	cows["Mildred"] = 7;

	while(!entries.empty()){ //Loop through queue in order of days

		Entry entry = entries.top(); //Newest cow entry
		vector<string> old_display = get_highest_cows(cows); //Old display (before updating)
		cows[entry.cow_name]+=entry.change_in_gallons; //Add gallons to corresponding cow
		display = get_highest_cows(cows); //Latest display

		//Display has been changed
		if (old_display != display){
			num_changes++;
		}
		entries.pop(); 
	}
	return num_changes;
}

int main() {
	write_file(get_solution(parse_file()));
	return 0;
}
