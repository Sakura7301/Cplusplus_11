#pragma once

template<class node>
class queue {
public:
	node front()
	{
		return this->queue[left];
	}
	void ne(int &x) { ++x; if (x == N) x = 1; }
	void push(node x) { ne(r); qu[r] = x; ++cnt; }
	void pop() { ne(l); --cnt; }
	bool empty() { return !cnt; }
	void size() { return cnt; }
	void clear() { r = cnt = 0, l = 1; }
private:
	int left;
	int right;
	int count;
	node *queue;
};

