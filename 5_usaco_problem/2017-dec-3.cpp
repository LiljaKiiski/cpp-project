#include <string>
#include <map>
#include <queue>

struct change {
	int day;
	std::string cow_name;
	int change_in_gallons;

	//This is flipped - since we want our queue ordering from smallest to largest
	bool operator < (change b) {
        	if (day < b.day){
        	        return false;
        	}
        	return true;
	}
};

int get_solution(std::priority_queue<change> changes){
	std::string current_cow = "blank"; //Current cow in display
	int num_changes; //Number of changes in display

	//Map of cows to gallons
	std::map<std::string, int> cows;
	cows["bessie"] = 7;
	cows["else"] = 7;
	cows["mildred"] = 7;

	//Loop through queue in order of days
	while(!changes.empty()){
		change cow = changes.top(); //Newest cow

		//Add gallons to corresponding cow
		cows[cow.cow_name]+=cow.change_in_gallons;

		//If cow is NOT current cow and cow's gallons are greater than current cow
		if (cow.cow_name != current_cow && cows[cow.cow_name] >= cows[current_cow]){
			current_cow = cows[cow.cow_name];
			num_changes++;
		}
		changes.pop();
	}

	return 0;
}


int main(){


	return 0;
}
