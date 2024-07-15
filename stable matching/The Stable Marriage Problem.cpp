#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T = 0;
	cin >> T;
	while (T--) {
		int n = 0;
		cin >> n;
		cin.ignore();
		string s;
		getline(cin, s);
		vector<vector<int>> female(n, vector<int>(n, 0));
		vector<vector<int>> male(n, vector<int>(n, 0));
		vector<int> femaleMatch(n, -1);
		vector<int> maleMatch(n, -1);
		vector<int> nextProposal(n, 0);
        cout << s << "\n";
		for (int y = 0; y < n; ++y) {
			getline(cin, s);
			for (int x = 2; x < s.size(); ++x) {
				male[s[0] - 'a'][x - 2] = s[x] - 'A';
			}
		}
		for (int y = 0; y < n; ++y) {
			getline(cin, s);
			for (int x = 2; x < s.size(); ++x) {
				female[s[0] - 'A'][x - 2] = s[x] - 'a';
			}
		}

        bool freeMale = true;
        int m = 0;
        while(freeMale) {
            freeMale = false;
            int f = male[m][nextProposal[m]];
            nextProposal[m]++;
            if (femaleMatch[f] == -1) {
                femaleMatch[f] = m;
                maleMatch[m] = f;
//                cout << m << "," << f << "\n";
            }
            else {
                bool haveBetterProposal = false;
                for (int x = 0; x < n; ++x) {
                    if (female[f][x] == femaleMatch[f]) {
                        haveBetterProposal = false;
                        break;
                    }
                    if (female[f][x] == m) {
                        haveBetterProposal = true;
                        break;
                    }
                }

                if (haveBetterProposal) {
                    maleMatch[femaleMatch[f]] = -1;
                    femaleMatch[f] = m;
                    maleMatch[m] = f;
//                    cout <<"@\n";
//                    cout << "@" << m << "," << f << "\n";
                }
            }
            for (int x = 0; x < n; ++x) {
				if (maleMatch[x] == -1) {
					m = x;
					freeMale = true;
					break;
				}
			}
        }
        for (int x =0 ; x < n; ++x) {
            cout << char(maleMatch[x] + 'a') << " " << char(femaleMatch[x] + 'A') << "\n";
        }

		if (T != 0) {
			cout << "\n";
		}
	}


	return 0;
}
/*
2
3
abcA B C
a:BAC
b:BAC
c:ACB
A:acb
B:bac
C:cab
3
a b c A B C
a:ABC
b:ABC
c:BCA
A:bac
B:acb
C:abc

*/
