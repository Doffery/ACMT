#include<cstdio>

int board[8][8] = {0};
int solution[92][8];
int solution_index = 0;

void PutQueen(int l, int r) {
	
	for(int i = 1; i <= r; ++i) {
		if(l - i >= 0)
			board[l - i][r - i] += 1;
		board[l][r - i] += 1;
		if(l + i < 8)
			board[l + i][r - i] += 1;
	}
	for(int i = 0; i < 8; ++i)
		board[i][r] += 1;
	board[l][r] += 10;
	for(int i = r; i < 8; ++i) {
		if(l + i - r < 8)
			board[l + i - r][i] += 1;
		board[l][i] += 1;
		if(l - i + r >= 0)
			board[l - i + r][i] += 1;
	}
}

void TakeQueen(int l, int r) {
	
	for(int i = 1; i <= r; ++i) {
		if(l - i >= 0)
			board[l - i][r - i] -= 1;
		board[l][r - i] -= 1;
		if(l + i < 8)
			board[l + i][r - i] -= 1;
	}
	for(int i = 0; i < 8; ++i)
		board[i][r] -= 1;
	board[l][r] -= 10;
	for(int i = r; i < 8; ++i) {
		if(l + i - r < 8)
			board[l + i - r][i] -= 1;
		board[l][i] -= 1;
		if(l - i + r >= 0)
			board[l - i + r][i] -= 1;
	}
}

void RecordThis() {
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j) {
			if(board[i][j] >= 10) {
				solution[solution_index][i] = j + 1;
				break;
			}
		}
	++solution_index;
}

void Game(int l) {
	if(l == 8) {
		RecordThis();
		return;
	}
	for(int i = 0; i < 8; ++i) {
		if(board[l][i] == 0) {
			PutQueen(l, i);
			Game(l + 1);
			TakeQueen(l, i);
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	Game(0);
	while(--n >= 0) {
		int num;
		scanf("%d", &num);

		for(int i = 0; i < 8; ++i) {
			printf("%d", solution[num - 1][i]);
		}
		printf("\n");

	}
}
