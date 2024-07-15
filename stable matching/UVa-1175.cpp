// 2024_07_14 kerong
// stable marriage problem
// Gale-Shapely algorithm

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> girl(n, vector<int>(n, 0));
		vector<vector<int>> boy(n, vector<int>(n, 0));
		vector<int> boyMatch(n, -1);
		vector<int> girlMatch(n, -1);
		vector<int> nextProposal(n, 0);
		for (auto& y : boy) {
			for (auto& x : y) {
				cin >> x;
			}
		}

		for (auto& y : girl) {
			for (auto& x : y) {
				cin >> x;
			}
		}


		bool freeMan = true;
		int m = 0;
		while (freeMan) {
			freeMan = false;
			int w = boy[m][nextProposal[m]] - 1;
            nextProposal[m]++;
			if (girlMatch[w] == -1) {
				// w is free engage(m, w)
				girlMatch[w] = m;
				boyMatch[m] = w;
			}
			else {
				// w is engaged
				bool haveBetterProposal = false;
				for (int x = 0; x < n; ++x) {
					if (girl[w][x] == girlMatch[w] + 1) {
						haveBetterProposal = false;
						break;
					}
					if (girl[w][x] == m + 1) {
						haveBetterProposal = true;
						break;
					}
				}

				if (haveBetterProposal) {
					boyMatch[girlMatch[w]] = -1;

					girlMatch[w] = m;
					boyMatch[m] = w;
				}
			}

			for (int x = 0; x < n; ++x) {
				if (boyMatch[x] == -1) {
					m = x;
					freeMan = true;
					break;
				}
			}
		}

		for (int x = 0; x < n; ++x) {
            cout << boyMatch[x] + 1 << "\n";
		}
        if (T != 0) {
		    cout << "\n";
        }
	}


	return 0;
}
