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
/*
 * Complete the function below.
 */
bool checkV4(string ip){
  int left = 0, right = 0, count = 0;
  while(right < ip.length()){
    int lead_zero = 0;
    int sum = 0;
    while(right < ip.length() and isdigit(ip[right])){
      if(sum == 0 and ip[right] == '0') ++lead_zero;
      sum = sum*10 + (ip[right]-'0');
      if(lead_zero >= 2 or (right-left+1 >= 4) or (sum > 255) or (lead_zero > 0 and sum != 0)){
        return false;
      }
      ++right;
    }
    if(left == right){
      return false;
    }
    ++count;
    if (count <= 3){
      if (right >= ip.length() or ip[right] != '.'){
        return false;
      }
      left = ++right;
    }
    else
      if(right != ip.length()){
        return false;
      }
  }
  if(count == 4)  return true;
  return false;
}

bool checkV6(string ip){
  int left = 0, right = 0, count = 0;
  while(right < ip.length()){
    while(right < ip.length() and isalnum(ip[right])){
      if((right-left+1)>4 or (ip[right]>'F' and ip[right]<='Z') or (ip[right]>'f' and ip[right] <= 'z'))
        return false;
      ++right;
    }
    if(left == right)  return false;
    ++count;
    if(count <= 7){
      if(right >= ip.length() or ip[right] != ':') return false;
        left = ++right;
    }
    else
      if(right != ip.length())  return false;
  }
  if(count == 8)  return true;
  return false;
}

vector < string > checkIP(vector < string > ips) {
  vector<string> ans;
  for(string ip: ips){
    if(checkV4(ip)) ans.push_back("IPv4");
    else if(checkV6(ip)) ans.push_back("IPv6");
    else  ans.push_back("Neither");
  }
  for(string a : ans)
    cout << a << endl;
  return ans;
}

int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
  vector<string> ips;
  string ip;
  getline(cin, ip);
  ips.push_back(ip);
  checkIP(ips);
}