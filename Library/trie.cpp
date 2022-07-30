class Trie {
	vector<vector<int>>next(1, vector<int>(26));
	vector<bool>is_terminal(1);
	const int root = 0;
	int N;
	Trie() {
		N = 0;
		next.push_back(vector<int>(26));
		is_terminal.push_back(false);
	}
	void insert(string& s) {
		int cur = root;
		for (char& c : s) {
			if (next[cur][c - 'a'] == 0) {
				next.push_back(vector<int>(26));
				is_terminal.push_back(false);
				next[cur][c - 'a'] = ++N;
			}
			cur = next[cur][c - 'a'];
		}
		is_terminal[cur] = true;
	}
}