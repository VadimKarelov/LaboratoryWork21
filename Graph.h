#pragma once
#include <vector>
using namespace std;

class Graph
{
protected:
	// adjacency matrix
	vector<vector<int>> _mat;

	// for search
	vector<int> _minRoad;
	vector<bool> _checkedList;

	bool IsAllChecked();

public:
	Graph();

	Graph(vector<vector<int>> source);

	// departure and arrival, start with 1
	int RoadLength(int dep, int arr);

	int MinLength(int dep, int arr);

    int Size();
};
