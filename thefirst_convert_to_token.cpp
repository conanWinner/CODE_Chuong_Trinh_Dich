#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> idx_opr;
vector<pair<char, int>> idx_format;

void index_operator(string s){
	int tmp = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '(' || s[i] == ')') {
			idx_opr.push_back({s[i], i + tmp});
			tmp++;
		}
	}	
}

// get index '/'
void index_format(string s) {
	int tmp = 0;
	for(int i = 0; i < s.length(); i++){
		 if (s[i] == '\\') {
			idx_format.push_back({s[i], i + tmp});
			tmp += 2;
		}
	}
}

int check_opr(char c) {
	if(c == ')') return 0;
//	else if(c == '(') return 0;
	return 1;
}

//check number
bool check_number(string s){
	if(s == " ") return false;
	for(char x: s){
		if(x != '4' && x != '5' && x != '6') return false;
	}
	return true;
}

string ans_token(string s){
	string tmp = "";
	if(s == "if" || s == "then" || s == "else") tmp = "keyword";
	else if(s == " " || s == "\\t" || s == "\\n") tmp = "whitespace";
	else if(check_number(s)) tmp = "number";
	else if(s == "=" || s == ">" || s == "<") tmp = "operator";
	else if(s == "(" || s == ")" || s == "+") tmp = "punctuator";
	else tmp = "identifier"; 
	string ans = "<" + tmp + "," + "\'" + s + "\'>";
	return ans;
}

int main(){
	string tmp = "\\tif (sum < 65) then\\n\\t\\tc8 = e9 + 4\\n\\telse if (a > 4) then\\n\\t\\tc8 = 564";
	index_operator(tmp);
	for(auto it: idx_opr) {
		tmp.insert(it.second + check_opr(it.first), " ");
	}          
	index_format(tmp);       
	for(auto it: idx_format) {
		tmp.insert(it.second, " ");
		tmp.insert(it.second + 3, " ");
	}                                
		
	cout << '\n' << tmp << '\n';
	string word;
	stringstream ss(tmp);
	//getline(ss, word, ' ')
	while(ss >> word) {
		cout << word << '\t' << ans_token(word) << '\n';
	}
	
}