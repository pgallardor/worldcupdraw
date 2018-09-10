#pragma once
using namespace std;

class Team{
	private:
		string _name;
		int _conf;
		int _pool; 

	public:
		Team(string n, int c, int p){
			_name = string(n);
			_conf = c;
			_pool = p;
		}
		string getName(){
			return _name;
		}
		int getConf(){
			return _conf;
		}
		int getPool(){
			return _pool;
		}
		Team getCopy(){
			return Team(_name, _conf, _pool);
		}
};