#include <vector>
#include <string> 
#include <iostream>

using namespace std;

struct LinkedList
{
	int key;
	int val;
	LinkedList* next;
	LinkedList(int x):	val(x), next(NULL) {}
};

class my_map{
public:
	my_map(int x): size(x), list(vector<LinkedList*>(x, NULL)) {}

	void put(int x){
		size_t idx = hash<int>{}(x) % size;
		LinkedList* slot = list[idx];
		if(!slot){
			slot = new LinkedList(x);
		}
		else{
			LinkedList* tmp = slot;
			while(tmp->next){
				if(tmp->val == x)	break;
				tmp = tmp->next;
			}
			tmp->next = new LinkedList(x);
		}
		list[idx] = slot;
	}

	int get(int x){
		size_t idx = hash<int>{}(x) % size;
		LinkedList* tmp = list[idx];
		while(tmp){
			if(tmp->val == x)	return x;
			tmp = tmp->next;
		}
		return -1;
	}


private:
	vector<LinkedList*> list;
	int size;
};

int main(){
	my_map mmap(10);
	return 0;
}