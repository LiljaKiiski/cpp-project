#include <iostream>
#include <map>
#include <queue>
#include <fstream>
#include <vector>
#include <algorithm>

struct Entry {
	int day;
	std::string cow_name;
	int change_in_gallons;
};

bool operator<(const Entry& a, const Entry& b){ //Flipped since queue is ordered from smallest day to largest
	return !(a.day < b.day);
}

std::priority_queue<Entry> parse_file(){
	std::ifstream fint("measurement.in");
	std::priority_queue<Entry> entries;

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

void write_file(int num_changes){
	std::ofstream fout("measurement.out");
	fout << num_changes;
}

std::vector<std::string> highest_cows(std::map<std::string, int> cows){
	std::map<std::string, int>::iterator it; //Iterate through cow map
	std::vector<std::string> highest_cows; //Cows with highest gallon production rate
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

int get_solution(std::priority_queue<Entry> entries){
	int num_changes = 0; //Number of changes in display
	std::vector<std::string> display;
	std::vector<std::string> old_display;

	std::map<std::string, int> cows; //Map of cows to gallons
	cows["Bessie"] = 7;
	cows["Elsie"] = 7;
	cows["Mildred"] = 7;

	while(!entries.empty()){ //Loop through queue in order of days
		Entry entry = entries.top(); //Newest cow
		
		old_display = highest_cows(cows);

		cows[entry.cow_name]+=entry.change_in_gallons; //Add gallons to corresponding cow

		display = highest_cows(cows);

		//Display has been changed
		if (old_display != display){
			num_changes++;
		}

		//If cow is current cow and drops down, so that another cow takes place...
		entries.pop();
	}

	return num_changes;
}

int main() {
	write_file(get_solution(parse_file()));
	return 0;
}
