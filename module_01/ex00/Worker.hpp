#ifndef WORKER_HPP

#define WORKER_HPP

#include <string>

#include "Position.hpp"
#include "Shovel.hpp"
#include "Statistic.hpp"

class Worker
{
  public:
	Worker(std::string name, Position coords, Statistic stats);
	~Worker(void);
	std::string getName();
	Position getPosition();
	Statistic getStatistic();
	void setPosition(Position coords);
	void setStatistic(Statistic stats);
	void giveShovel(Shovel *shovel);
	Shovel *takeShovel();
	bool hasShovel();
	void display();

  private:
	std::string _name;
	Position _coords;
	Statistic _stats;
	Shovel *_shovel;
};

#endif // WORKER_HPP
