#include <cstdio>

int light_map[6][7], result_map[5][6];

void Change(int &i) {
	if(i == 0)
		i = 1;
	else i = 0;
}

void Press(int i, int j) {
	Change(light_map[i][j]);
	Change(result_map[i-1][j-1]);
	if(i != 1) Change(light_map[i-1][j]);
	if(i != 5) Change(light_map[i+1][j]);
	if(j != 1) Change(light_map[i][j-1]);
	if(j != 6) Change(light_map[i][j+1]);
}

bool Check(int i, int j) {
	bool result = true;
	if(i == 5)  result = Check(i + 1, j - 1);
	if(light_map[i-1][j] == 0)
		return result;
	else return false;
}

void PressNext(int i, int j) {
	Press(i, j);
	if(!Check(i, j)) {
		Press(i, j);
		if(j == 1) {
			j = 6;
			--i;
		}
		else --j;
	//	PressNext(i, j);
		return;
	}
	if(i == 5 && j == 6) {
		return;
	}
	if(j == 6) {
		j = 1;
		++i;
	}
	else ++j;
	PressNext(i, j);
	
}

bool CheckLine(int i) {
	for(int j = 1; j < 7; ++j) {
		if(light_map[i][j] == 1)
			return false;
	}
	return true;
}

bool Check() {
	for(int i = 1; i < 6; ++i) {
		if(!CheckLine(i))
			return false;
	}
	return true;
}

//This function precess some useless steps...Should find some way to cut them.
void PressLFFL(int j) {
	Press(1, j);
	for(int i = 2; i < 6; ++i) {
		for(int j = 1; j < 7; ++j) {
			if(light_map[i-1][j] == 1)
				Press(i, j);
		}
	}
}

void PressFirstLine(int j) {
	//Press(1, j);
	if(j == 7)
		return;
	PressFirstLine(j + 1);
	if(!Check()) {
		PressLFFL(j);
		PressFirstLine(j + 1);
	}

}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	while(--n >= 0) {
		for(int i = 1; i < 6; ++i) {
			for(int j = 1; j < 7; ++j) {
				scanf("%d", &light_map[i][j]);
			}
		}
		//PressNext(1, 1);
		//Press(1, 1);
		PressFirstLine(2);
		if(!Check()) {
			PressLFFL(1);
			PressFirstLine(2);
		}
		printf("PUZZLE#%d\n", n + 1);
		for(int i = 0; i < 5; ++i) {
			for(int j = 0; j < 6; ++j) {
				if(j == 5) printf("%d\n", result_map[i][j]);
				else printf("%d ", result_map[i][j]);

			}
		}
	}

		
}
