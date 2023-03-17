#include <bits/stdc++.h>   
using namespace std;
 
int main()
{
	map<string, int> mp; // to check if any variable came before 
	vector<pair<string, int>> vp; // to store variables and index
	vector<vector<double>> v(1000, vector<double>(1000,0)); // 2d vector to store the coefficients
	int ind = 1; // column
	int cnt = 0; // row
	while(1){
		string s;
		getline(cin, s);
		if(s.empty())break;
		string tmp = "", num = ""; // tmp is for variable checking and num is for coefficient
		int mul = 1; // to check the sign
		bool tak_num = 1;
		for (int i=0; i<s.size(); i++){
			if(s[i] == ' '){
				if(!num.empty() && tak_num){
					tak_num = 0;
				}
				continue;
			}
			if(s[i] == '+' || s[i] == '-' || s[i] == '='){
				tak_num = 1;
				// store the variable index and coefficient
				if(!tmp.empty()){
					if(mp[tmp] == 0){
						// mp[tmp] == 0 means the variable is new
						vp.push_back({tmp, ind});
						if(num == "") num = "1"; // if the coefficient is 1
						v[cnt][ind] = mul * stod(num);
						mp[tmp] = ind; // storing the index of the string/variable
						ind++;
					}
					else{
						//if the variable came before then store it according to map
						if(num == "") num = "1";
						v[cnt][vp[mp[tmp] - 1].second] = mul * stod(num); 
					}
				}
				if(s[i] == '-')mul = -1;// checking sign
				else mul = 1;
				tmp = "", num = ""; // clearing strings for variable and coefficient
			}
			else if(tak_num && ((s[i] >= '0' && s[i] <= '9') || (s[i] == '.'))) num += s[i];
			else {
				tmp += s[i];
				tak_num = 0;
			}

			// storing the constant
			if(s[i] == '='){
				tmp = "=";
				num = "";
				for (int j=i+1; j<s.size(); j++){
					if((s[j] >= '0' && s[j] <= '9') || s[j] == '.')num += s[j];
					else if(s[j] == '-')mul = -1;
				}
				if(mp[tmp] == 0){
					if(num == "") {
						num = "1";
					}
					vp.push_back({tmp, ind});
					v[cnt][ind] = mul * stod(num);
					mp[tmp] = ind++;
				}
				else{
					if(num == ""){
						num = "1";
					}
					v[cnt][vp[mp[tmp] - 1].second] =mul * stod(num);
				}
				break;
			}
		}
		cnt++;
	}
	sort(vp.begin(), vp.end());
	for (int i=1; i<vp.size(); i++){
		if(i == 1) cout << "[";
		cout << vp[i].first;
		if(i == vp.size() - 1)cout<< "]\n";
		else cout << " "; 
	}
	for (int i=0; i<cnt; i++){
		for (int j=1; j<vp.size(); j++){
			cout << v[i][mp[vp[j].first]] << ' ';
		}
		cout << v[i][mp[vp[0].first]]<< '\n';
	}
    return 0;
}