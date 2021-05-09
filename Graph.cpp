#include "Graph.h"

Graph::Graph()
{
	_mat = { {0, 0, 13, 15, 0, 0},
			 {28, 0, 0, 20, 0, 0},
			 {0, 0, 0, 0, 30, 0},
			 {0, 0, 0, 0, 39, 31},
			 {0, 21, 0, 39, 0, 0},
			 {18, 0, 0, 0, 0, 0} };
}

Graph::Graph(vector<vector<int>> source)
{
	if (source.size() > 0 && source.size() == source[0].size())
	_mat = source;
}

int Graph::RoadLength(int dep, int arr)
{
	dep--;
	arr--;
	if (arr >= 0 && arr < _mat.size() && dep >= 0 && dep < _mat.size())
	{
		return _mat[dep][arr];
	}
	else
	{
		return 0;
	}
}

int Graph::MinLength(int dep, int arr)
{
	if (dep == arr) return 0;	

	dep--;
	arr--;

	// preparing
	_minRoad.clear();
	_checkedList.clear();
	for (int i = 0; i < _mat.size(); i++)
	{
		_minRoad.push_back(10000);
		_checkedList.push_back(false);
	}

	// starting from departure node
	// road from dep to dep will be infinity
	for (int i = 0; i < _mat.size(); i++)
	{
		if (RoadLength(dep + 1, i + 1) > 0)
		{			
			_minRoad[i] = min(_minRoad[i], RoadLength(dep + 1, i + 1));
		}
	}
	_checkedList[dep] = true;

	// for avoid looping
	int k = _mat.size() * 2;
	// now check other elements
	while (!IsAllChecked() && k > 0)
	{
		k--;
		for (int i = 0; i < _mat.size(); i++)
		{
			if (!_checkedList[i])
			{
				for (int j = 0; j < _mat.size(); j++)
				{
					if (RoadLength(i + 1, j + 1) > 0)
					{
						_minRoad[j] = min(_minRoad[j], _minRoad[i] + RoadLength(i + 1, j + 1));
					}
				}
				_checkedList[i] = true;
			}
		}
	}

	return _minRoad[arr];
}

bool Graph::IsAllChecked()
{
	for (int i = 0; i < _checkedList.size(); i++)
	{
		if (!_checkedList[i]) return false;
	}
	return true;
}

int Graph::Size()
{
    return _mat.size();
}
