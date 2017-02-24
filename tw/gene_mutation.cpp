#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
using namespace std;

/*
 * Complete the function below.
 */
// int map(string gene){
// 	unordered_map<char, int> um;
// 	um['A'] = 0;
// 	um['T'] = 1;
// 	um['G'] = 2;
// 	um['C'] = 3;
// 	int ret = 0;
// 	for(int i = 0; i < gene.length(); i++)
// 		ret += (um[gene[i]] << 2*i);
// 	return ret;
// }

vector<string> getMutation(string gene, int pos){
	vector<string> mutation;
	char material[4] = {'A', 'T', 'G', 'C'};
	for(char m : material){
        if(gene[pos] == m) continue;
        string mutate = gene;
        mutate[pos] = m;
        mutation.push_back(mutate);
    }
    return mutation;
}

int findMutationDistance(string start, string end, vector < string > bank) {
	unordered_set<int> us;
	for(string gene: bank)
		us.insert(gene);
	if(us.find(end) == us.end())	return -1;
	queue<pair<string, int> > q;
	q.push(make_pair(start, 0));
	while(!q.empty()){
		pair<string, int> tmp = q.front();
		q.pop();
		for(size_t i = 0; i < q.first.length(); i++){
			vector<string> mutatoin = getMutation(tmp.first, i);
			for(string m: mutation){
				if(us.find(m) == us.end())	continue;
				if(m == end)	return p.second + 1;
				q.push(make_pair(m, p.second+1));
				us.erase(m);
			}
		}
	}
	return -1;
}

int main(){
	string gene("TTTTGGCA");
	findMutationDistance(gene, gene, vector<string>(0,""));
	return 0;
}

