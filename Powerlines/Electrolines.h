#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Vector2.h"

struct ForceLines
{
	std::vector<Vector2> positive;
	std::vector<Vector2> negative;
};

struct Charge
{
	float value;
	Vector2 position;
};

struct ElectricField
{
	bool flag;
	std::vector<int> kucha;
	std::vector<Charge> charges;
	std::vector<Vector2> lines;
	Vector2 FindForce(const Charge& c) const;
};

//counts summary force that impacted on a particullar electric charge 
Vector2 ElectricField::FindForce(const Charge& q) const 
{
	Vector2 R(0, 0);	//Value that contains summ of forces
	Vector2 r(0, 0);	
	for (int i = 0; i < charges.size(); ++i) {
		r = q.position - charges[i].position;
		float b = r.length();
		R += r * (q.value * charges[i].value /(b*b*b)); // F = r * (q*qi/ r^3)
	}
	return R;
}
