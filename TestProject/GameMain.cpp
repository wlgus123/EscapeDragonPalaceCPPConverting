#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Monster.h"
#include "Crab.h"
#include "BigFish.h"
#include "SmallFish.h"
#include <json/json.h>

using namespace std;

int main()
{
	vector<Monster*> mon;
	mon.push_back(new Crab);
	mon.push_back(new BigFish);
	mon.push_back(new SmallFish);
	mon.push_back(new Crab);

	ifstream fin("MonsterData.json");
	Json::Value root;
	fin >> root;
	cout << "Jail-Crab: " << root["Jail"]["Crab"][0] << endl;

	fin.close();

	for (Monster* m : mon)
	{
		delete m;
	}
	
	return 0;
}