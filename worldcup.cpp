#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "team.hpp"
#include "instance.hpp"
#define EU 1
using namespace std;

Team list[4][8];

void copy_table(bool **src, bool **arr){
	for (int i = 0; i < 32; i++){
		for (int j = 0; j < 8; j++){
			arr[i][j] = src[i][j];
		}
	}
}

bool **init(){
	bool **ret = new bool*[32];
	for (int i = 0; i < 32; i++){
		ret[i] = new bool[8];
	}
	return ret;
}

bool canAssignToGroup(int group_info[], int assigned[32], Team t){
	int c_cnt = 0;
	for (int i = 0; i < 4; i++){
		int pool = group_info[i] / 8, idx = group_info[i] % 8;
		if (t.getPool() == list[pool][idx].getPool()) return false;
		if (t.getConf() == list[pool][idx].getConf()) c_cnt++
	}

	if (t.getConf() == EU && c_cnt < 2) return true;
	if (t.getConf() != EU && c_cnt < 1) return true;
	return false;
}

bool recursive(int T, int assigned[32], bool **info, int groups[8][4], bool ag[], int pool){
	if (T == 32)
		return true;



}

void solve(){

}

//show possible groups
int main(){
	int opt;

	do{
		scanf("World Cup Final Group Solver!\nSelect an option:");
		scanf("1. Automatic draw.\n2. Manual draw.\n3. Exit\n");
		
		do {
			cin >> opt;
			if (opt < 1 || opt > 3) printf("Invalid option.\n");	
		}while(opt < 1 || opt > 3);
		if (opt == 3) break;

		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 8; j++){
				string name;
				int c;
				cin >> name >> c;
				list[i][j] = Team(name, c, i+1);
			}
		}

		if (opt == 1){

		}

		else if (opt == 2){

		}

	}while(true);
}