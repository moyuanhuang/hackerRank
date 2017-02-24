/*
 * Complete the function below.
 */

int search(vector<int> &nums, int key){
	int left = 0, right = nums.size()-1;
	while(left < right - 1){
		mid = left + (right-left)/2;
		if(nums[mid] <= key)
			left = mid;
		else
			right = mid;
	}
	if(nums[right] <= key) return right;
	if(nums[left] <= key)	return left;
	return -1;
}

vector < int > counts(vector < int > nums, vector < int > maxes){
	vector<int> ans;
	sort(nums.begin(), nums.end());
	for(int m : maxes)
		ans.push_back(search(nums, m));
	return ans;
}
