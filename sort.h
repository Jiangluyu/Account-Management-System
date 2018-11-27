#pragma once
//here use the Strategy Pattern
class sort
{
public:
	virtual void sortList(List_stock list_stock) = 0;
};

class bubbleSort :public sort
{
public:
	void sortList(List_stock list_stock);
};

class selectSort :public sort
{
public:
	void sortList(List_stock list_stock);
};

class insertSort :public sort
{
public:
	void sortList(List_stock list_stock);
};