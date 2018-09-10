#pragma once
#include "team.hpp"
#include <stack>
using namespace std;

class Instance{
	private:
		Team *_dir;
		bool **_info;
		int _assign_team[32], _pool;
		bool _assign_group[8];

	public:
		Instance(Team *dir);
		Instance(Team *dir, bool **info, int *a_team, int pool, int *a_group);
		~Instance();
		bool assign(int t, int g);
		bool checkFuture();
		bool isFullyAssigned();
		Instance getCopy();	
};

Instance::Instance(Team *dir){
	_dir = dir;

	_info = new bool*[32];
	for (int i = 0; i < 32; i++) {
		_info[i] = new bool[8];
		for (int j = 0; j < 8; j++){ 
			if (i == 0) _info[i][j] = false;
			else _info[i][j] = true;
		}
	}

	_assign_team[0] = 0; //host in group A 
	for (int i = 1; i < 32; i++) _assign_team[i] = -1;

	_assign_group[0] = true;
	for (int i = 1; i < 8; i++) _assign_group[i] = false;

	_pool = 0;

}

Instance::Instance(Team *dir, bool **info, int *a_team, int pool, bool *a_group){
	_dir = dir;
	_pool = pool;

	_info = new bool*[32];
	for (int i = 0; i < 32; i++) {
		_info[i] = new bool[8];
		for (int j = 0; j < 8; j++){ 
			_info[i][j] = info[i][j];
		}
	}

	for (int i = 0; i < 32; i++) _assign_team[i] = a_team[i];
	for (int i = 0; i < 8; i++) _assign_group[i] = a_group[i];	
}

bool Instance::assign(int t, int g){
	if (!info[t][g]) return false;
	_assign_team[t] = g;


	//propagation
	int groups[8][4] = {-1};

	for (int i = 0; i < 32; i++){
		if (_assign_team[i] != -1){
			int ipool = dir[i].getPool();
			groups[_assign_team[i]][ipool] = i;
		}
	}

	for (int i = 0; i < 32; i++){
		for (int j = 0; j < 8; j++){
			if (i == t) info[t][j] = false;
			else if (info[i][j]){ //check if I can still assign to that group

			}
		}
	}
}