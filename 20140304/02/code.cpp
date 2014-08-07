#include<cstdio>
#include<cstring>

struct OrderNote {
	int note_move;
	OrderNote *next;
};

int data[9];
const char moves[9][10] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
int exacute_times[9];
int command_order[27];

bool Check() {
	for(int i = 0; i < 9; ++i) {
		if(data[i] != 12)
			return false;
	}
	return true;
}

void Move(int i) {
	data[i] += 3;
	if(data[i] == 15)
		data[i] = 3;
}

void MoveBack(int i) {
	data[i] -= 3;
	if(data[i] == 0)
		data[i] = 12;
}

bool ExacuteCommand(int i) {
	if(exacute_times[i] == 3)
		return false;
	else ++exacute_times[i];
	int l = strlen(moves[i]);
	for(int j = 0; j < l; ++j) {
		Move(moves[i][j]- 'A');
	}

	return true;
}

void CancelCommand(int i) {
	int l = strlen(moves[i]);
	for(int j = 0; j < l; ++j) {
		MoveBack(moves[i][j] - 'A');
	}
	--exacute_times[i];
}

void Game(int s) {

	if(Check()) {
		for(int i = 0; i < 9; ++i)
			printf("%d ", exacute_times[i]);
		printf("\n");
	}
	if(s == 9)
		return;
	for(int i = 0; i < 3; ++i) {
		Game(s + 1);
		ExacuteCommand(s);
		//Game(s + 1);
	}
	Game(s + 1);
	for(int i = 0; i < 3; ++i)
		CancelCommand(s);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	while(--n >= 0) {
		for(int i = 0; i < 9; ++i) {
			scanf("%d", &data[i]);
			exacute_times[i] = 0;
		}
		//for(int i = 0; !Check() && i < 9; ++i) {
			Game(0);
		//}
	}

}
