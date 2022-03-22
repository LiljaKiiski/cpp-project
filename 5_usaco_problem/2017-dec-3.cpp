#include <iostream>
#include <map>
#include <queue>
#include <fstream>

struct Change {
	int day;
	std::string cow_name;
	int change_in_gallons;
};

//This is flipped - since we want our queue ordering from smallest to largest
bool operator<(const Change& a, const Change& b){
	return !(a.day < b.day);
}

std::priority_queue<Change> parse_file(){
	std::ifstream fint("measurement.in"); //read file
	std::priority_queue<Change> entries;

        int num_entries;
        fint >> num_entries;

	std::cout << std::to_string(num_entries) << std::endl;

	return entries;
}

void write_file(int num_changes){
	std::ofstream fout("measurement.out");
	fout << num_changes;
}

int get_solution(std::priority_queue<Change> changes){
	std::string current_cow = "blank"; //Current cow in display
	int num_changes = 0; //Number of changes in display

	std::map<std::string, int> cows; //Map of cows to gallons
	cows["bessie"] = 7;
	cows["else"] = 7;
	cows["mildred"] = 7;

	while(!changes.empty()){ //Loop through queue in order of days
		Change cow = changes.top(); //Newest cow

		cows[cow.cow_name]+=cow.change_in_gallons; //Add gallons to corresponding cow

		//If cow is NOT current cow and cow's gallons are greater than current cow
		if (cow.cow_name != current_cow && cows[cow.cow_name] >= cows[current_cow]){
			current_cow = cows[cow.cow_name];
			num_changes++;
		}

		//One other possibility is that if cow's gallons go down, now a different cow is in the lad. Check for this!

		changes.pop();
	}
	return num_changes;
}

int main() {
	parse_file();
	return 0;
}
