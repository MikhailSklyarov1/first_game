#pragma once
#include<vector>
#include "Tank.h"
#include "Enemy.h"
#include "Bullet.h"


class Universe {

public:
	static std::vector<Tank> MyTank;	
	static std::vector<Bullet> BulletBuf;
	static std::vector<Enemy> EnemyBuf;
	static std::vector<Bullet> EnmeyBulletBuf;
	
};




