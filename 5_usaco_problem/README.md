# USACO Problem

Problem can be found [here](http://usaco.org/index.php?page=viewproblem2&cpid=761)

**Solution explanation (also found at top of [solution.cpp](https://github.com/LiljaKiiski/cpp-projects/blob/master/5_usaco_problem/solution.cpp))**
1. Parse file, return queue ordered from smallest to largest days
2. Loop through queue, update display using get_highest_cows() method
3. If new display is not the same as old display, increase num_changes
4. Write num_changes to file 
