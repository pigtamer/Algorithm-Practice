#include <cmath>
#include <deque>
#include <iostream>
#include <string>

using namespace std;

template <typename T> std::deque<T> merge(deque<T> lhs, deque<T> rhs) {
	deque<T> mergedList;
	while ((!lhs.empty()) && (!rhs.empty())) {
		if (lhs[0] <= rhs[0]) {
			mergedList.push_back(lhs.front());
			lhs.pop_front();
		}
		else {
			mergedList.push_back(rhs.front());
			rhs.pop_front();
		}
	}
	if (!lhs.empty())
		mergedList.insert(mergedList.end(), lhs.begin(), lhs.end());
	else if (!rhs.empty())
		mergedList.insert(mergedList.end(), rhs.begin(), rhs.end());
	else
		;
	return mergedList;
}

template <typename T>
std::deque<T> slicer(deque<T> DequeToSlice, int startIdx, int endIdx) {
	deque<T> sliced;
	if (!(startIdx >= 0 && endIdx <= DequeToSlice.size() && startIdx <= endIdx)) {
		cout << "Index Error" << endl;
		exit(0);
	}
	for (int i = startIdx; i < endIdx; i++) {
		sliced.push_back(DequeToSlice[i]);
	}
	return sliced;
}

template <typename T> std::deque<T> mergeSortter(std::deque<T>& InputDeque) {
	if (InputDeque.size() <= 1)
		return InputDeque;
	int MID_POSITION = int(InputDeque.size()) / 2;
	deque<T> lhs = mergeSortter(slicer(InputDeque, 0, MID_POSITION));
	deque<T> rhs =
		mergeSortter(slicer(InputDeque, MID_POSITION, InputDeque.size()));
    
	return merge(lhs, rhs);
}

int main(int argc, char **argv) {
	int a[10]{ 3, 1, 10, 6, 2, 8, 7, 4, 9, 5 };
	deque<int> aDq;
	for (int i = 0; i < 10; i++)
		aDq.push_back(a[i]);
	aDq = mergeSortter(aDq);
	for (int i = 0; i < 10; i++)
		cout << aDq[i] << " ";
	cout << endl;
	return 0;
}
