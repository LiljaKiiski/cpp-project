#include <iostream>
#include <string>
#include <map>
#include <queue>

struct Change {
	int day;
	std::string cow_name;
	int change_in_gallons;
};

//This is flipped - since we want our queue ordering from smallest to largest
bool operator<(const Change& a, const Change& b){
	return !(a.day < b.day);
}

int get_solution(std::priority_queue<Change> changes){
	std::string current_cow = "blank"; //Current cow in display
	int num_changes; //Number of changes in display

	std::cout << std::to_string(num_changes) << std::endl;

	//Map of cows to gallons
	std::map<std::string, int> cows;
	cows["bessie"] = 7;
	cows["else"] = 7;
	cows["mildred"] = 7;

	//Loop through queue in order of days
	while(!changes.empty()){
		Change cow = changes.top(); //Newest cow

		//Add gallons to corresponding cow
		cows[cow.cow_name]+=cow.change_in_gallons;

		//If cow is NOT current cow and cow's gallons are greater than current cow
		if (cow.cow_name != current_cow && cows[cow.cow_name] >= cows[current_cow]){
			current_cow = cows[cow.cow_name];
			num_changes++;
		}
		changes.pop();
	}
	return num_changes;
}

int main(){
	Change c1;
	c1.day = 7; c1.cow_name = "mildred"; c1.change_in_gallons = +3;

	Change c2;
        c2.day = 4; c2.cow_name = "elsie"; c2.change_in_gallons = -1;

	Change c3;
        c3.day = 9; c3.cow_name = "mildred"; c3.change_in_gallons = -1;

	Change c4;
        c4.day = 1; c4.cow_name = "bessie"; c4.change_in_gallons = +2;

	std::priority_queue<Change> changes;
	changes.push(c1);
	changes.push(c2);
	changes.push(c3);
	changes.push(c4);

	std::cout << std::to_string(get_solution(changes)) << std::endl;

	return 0;
}
