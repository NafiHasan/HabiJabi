#include <bits/stdc++.h>   
using namespace std;

void PrintMatrix(vector<vector<double>>v, int r, int c){
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cout << v[i][j] << ' ';
		}
		cout << "\n";
	}
}


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

	// augmented matrix
	int R = cnt , C = vp.size(); // dimension of the matrix
	vector<vector<double>> mat(R, vector<double>(C,0));
	sort(vp.begin(), vp.end());
	for (int i=1; i<vp.size(); i++){
		if(i == 1) cout << "[";
		cout << vp[i].first;
		if(i == vp.size() - 1)cout<< "]\n";
		else cout << " "; 
	}
	for (int i=0; i<cnt; i++){
		for (int j=1; j<vp.size(); j++){
			mat[i][j - 1] = v[i][mp[vp[j].first]];
		}
		mat[i][vp.size() - 1] = v[i][mp[vp[0].first]];
	}
	// printing augmented matrix
	PrintMatrix(mat, R, C);

	//row echeleon 

	// sorting according to non zero element
	map<int,int> pos;
	vector<int> pp;
	for (int i=0; i<R; i++){
		for (int j=0; j<C; j++){
			if(mat[i][j] != 0){
				pos[i] = j + 1;
				pp.push_back(j + 1);
				break;
			}
		}
	}
	sort(pp.begin(), pp.end());
	vector<vector<double>> temp(R, vector<double>(C,0));
	ind = 0;
	for (int i=0; i<pp.size(); i++){
		for (int j=0; j<R; j++){
			if(pos[j] == pp[i]){
				temp[ind++] = mat[j];
				pos[j] = -1;
			}
		}
	}
	mat = temp;
	for (int i = 0; i < R; i++){
		double div = 0;
		int col = -1;
		for (int j = 0; j < C; j++){
			if(mat[i][j] != 0){
				if(col == -1)col = j;
				if(div == 0)div = mat[i][j];
				mat[i][j] /= div;
			}
		}
		for (int j = i + 1; j<R; j++){
			double mul = mat[j][col]; 
			for (int k = col; k < C; k++){
				mat[j][k] -= mul * mat[i][k];
			} 
		}
	}
	cout << "Row Echeleon Form:\n";
	PrintMatrix(mat, R, C);

	//Reduced Row Echeleon Form
	for (int i = 1; i < R; i++){
		double div = 0, ind = 0;
		for (int j = 0; j < C; j++){
			if(mat[i][j] == 1){
				ind = j;
				break;
			}
		}
		for (int j=0; j<i; j++){
			div = mat[j][ind];
			for (int k=0; k<C; k++){
				mat[j][k] -= div * mat[i][k];
			}
		}
	}
	cout << "Reduced row Echeleon Form:\n";
	PrintMatrix(mat, R, C);

	// solution
	map<int, char> var_map;
	vector<int> variables(C-1,0);
	vector<string> ans(C-1, "");
	string vars = "pqrstuvwxyzabcdefghijklmno";
	ind = 0;
	bool ys = 1;
	for (int i=0; i<C-1; i++){
		int cnt1 = 0;
		for (int j=0; j<R; j++){
			if(mat[j][i] == 1){
				cnt1++;
			}
		}
		if(cnt1 == 1){
			variables[i]++;
		}
		if(cnt1 == 0){
			ans[i] += vars[ind++];
		}
	}
	// check for no solution
	for (int i=0; i<R; i++){
		bool got = 0;
		for (int j=0; j<C-1; j++){
			if(mat[i][j] != 0){
				got = 1;
				break;
			}
		}
		if(!got && mat[i][C-1] != 0)ys = 0;
	}
	if(!ys){
		cout << "NO Solution\n";
		return 0;
	}
	for (int i=0; i<R; i++){
		bool get = 0;
		for (int j=0; j<C-1; j++){
			if(!get && mat[i][j]== 1 && variables[j] != 0){
				string tmp = to_string(mat[i][C-1]);
				for (int pos = tmp.size()-1 ; pos>=0; pos--){
					if(tmp[pos] != '0' && tmp[pos] != '.')break;
					tmp.pop_back();
				}
				ans[j] += tmp;
				ind = j;
				get = 1;
			}
			else if(get && mat[i][j] != 0){
				// cout << 'c' << to_string (-1 * mat[i][j]) << 'c';
				string tmp = to_string(abs(mat[i][j]));
				for (int pos = tmp.size()-1 ; pos>=0; pos--){
					if(tmp[pos] != '0' && tmp[pos] != '.')break;
					tmp.pop_back();
				}
				if(mat[i][j] > 0)ans[ind] += "-";
				else ans[ind] += "+";
				ans[ind] += tmp;
				ans[ind] += ans[j];
			}
		}
	}
	cout << "[";
	for (int i=0; i<C-1; i++){
		if(i) cout << ' ';
		cout << ans[i];
	}
	cout << "]\n";
    return 0;
}