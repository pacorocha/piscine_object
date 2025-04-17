#ifndef WORKER_HPP

#define WORKER_HPP

#include <algorithm>
#include <string>
#include <vector>

#include "ATool.hpp"
#include "Hammer.hpp"
#include "Position.hpp"
#include "Shovel.hpp"
#include "Statistic.hpp"
#include "Workshop.hpp"

class Workshop;

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

	void giveTool(Tool *tool);
	void removeTool(Tool *tool);
	void useTool(Tool *tool);
	void display();

	void registerToWorkshop(Workshop *workshop);
	void unregisterFromWorkshop(Workshop *workshop);
	void work(Workshop *workshop);
	bool isRegisteredAt(Workshop *workshop) const;

	template <typename ToolType>
	ToolType *getTool()
	{
		for (std::vector<Tool *>::iterator it = _tools.begin();
			 it != _tools.end(); ++it)
		{
			if (ToolType *tool = dynamic_cast<ToolType *>(*it))
			{
				return tool;
			}
		}
		return NULL;
	}

  private:
	std::string _name;
	Position _coords;
	Statistic _stats;
	std::vector<Tool *> _tools;
	std::vector<Workshop *> _workshops;
};

#endif
