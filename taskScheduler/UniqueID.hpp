#pragma once

using namespace std;

class UniqueID {
private:
	static int id ;

public:
	int static generateID();
	int static getLastID();
};

