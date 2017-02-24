#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

template<class T>
class MyIterator{
public:
	MyIterator(vector<T> v){
		push_all(v);
	}

	bool hasNext(){
		return !s_.empty();
	}

	T next(){
		T tmp = s_.front();
		s_.pop();
		return tmp;
	}

	T operator*(MyIterator<T> it){
		return it.front();
	}


private:
	queue<T> s_;
	void push_all(vector<T> v){
		for(int i = 0; i < v.size(); i++){
			s_.push(v[i]);
		}
	}
};

int main(){
	int b[5] = {1,2,3,4,5};
	vector<int> a(b, b+5);
	MyIterator<int> it(a);
	while(it.hasNext()){
		cout << it.next() << endl;
	}
	for(auto i = a.begin(); i != a.end(); ++i)
		cout << *i << endl;
	return 0;
}