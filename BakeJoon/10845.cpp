#include <iostream>

using namespace std;

class Queue
{
public:

	Queue() 
	{

	}
	~Queue()
	{

	}
	void push(const int data)
	{
		_top++;
		_data[_top] = data;
		_size++;
	}
	int pop()
	{
		if (empty())
			return _top;
		else
		{
			int temp = _data[0];
			for (int i = 0; i < _size; i++)
			{
				_data[i] = _data[i + 1];
			}
			_top--;
			_size--;
			return temp;
		}
	}
	
	int empty()
	{
		if (_top == -1)
			return 1;
		else
			return 0;
	}
	int front()
	{
		if (empty())
			return _top;
		else
			return _data[0];
	}
	int back()
	{
		if (empty())
		{
			return _top;
		}
		else
		{
			return _data[_top];
		}
	}


public:
	int _size = 0;
	int _top = -1;
	int _data[10001] = {};
};

int main()
{

	Queue a;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int data;
			cin >> data;
			a.push(data);
			
		}
		else if (str == "front")
		{
			cout<<a.front()<<"\n";
		}
		else if (str == "back")
		{
			cout << a.back() << "\n";
		}
		else if (str == "pop")
		{
			cout << a.pop() << "\n";
		}
		else if (str == "empty")
		{
			cout << a.empty() << "\n";
		}
		else if (str == "size")
		{
			cout << a._size<<"\n";
		}
	}
	return 0;
}