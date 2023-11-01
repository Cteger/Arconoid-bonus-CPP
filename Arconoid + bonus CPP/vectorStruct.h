#pragma once
struct iVector
{
	int x, y;
};

struct dVector
{
	double x, y;
};

template <typename T>
class CustomVec {
public:
	T x, y;
};