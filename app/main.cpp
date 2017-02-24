#include <vector>
#include <string> 
#include <iostream>
#include <queue>

using namespace std;

struct cmp{
	bool operator() (int x, int y){
		return x < y;
	}
};
int main(){
	priority_queue<int, vector<int>, cmp> pq;
	pq.push(1);
	pq.push(100);
	while(!pq.empty()){
		cout << pq.top() << endl;
		pq.pop();
	}
	return 1;
}