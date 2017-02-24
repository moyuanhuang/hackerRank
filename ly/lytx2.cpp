/*
 * Complete the function below.
 */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int minMoves(vector < int > avg) {
	// move zero to the end
	size_t len = avg.size();
	size_t idx_one = 0;
	size_t idx_zero = 0;
	vector<int> cpy = avg;
	int ans1 = 0;
	while(idx_zero < len){
		if(cpy[idx_zero] == 0){
			idx_one = idx_zero + 1;
			while(idx_one < len and cpy[idx_one] != 1)	++idx_one;
			if(idx_one == len)	break;
			swap(cpy[idx_one], cpy[idx_zero]);
			ans1 += idx_one - idx_zero;
		}
		++idx_zero;
	}
	// move one to the end
	idx_one = 0;
	idx_zero = 0;
	int ans2 = 0;
	while(idx_one < len){
		if(avg[idx_one] == 1){
			idx_zero = idx_one + 1;
			while(idx_zero < len and avg[idx_zero] != 0)	++idx_zero;
			if(idx_zero == len)	break;
			if(avg[idx_zero] == 0){
				swap(avg[idx_one], avg[idx_zero]);
				ans2 += idx_zero - idx_one;
			}
		}
		++idx_one;
	}
	return min(ans1, ans2);

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    
    int _avg_size = 0;
    cin >> _avg_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _avg;
    int _avg_item;
    for(int _avg_i=0; _avg_i<_avg_size; _avg_i++) {
        cin >> _avg_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _avg.push_back(_avg_item);
    }
    
    res = minMoves(_avg);
    fout << res << endl;
    
    fout.close();
    return 0;
}

