/*
https://leetcode.com/problems/find-median-from-data-stream/
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 
Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 
Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
*/

/*
Solution approach:
https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/#expected-approach-usingheaps

If the array is odd, we only grab the middle value

If the array is even, we divide the array into minimums and maximums by the half. 
For instance: 
[5,7,9, 10,15,16,23,28]

This is one part: 
5,7,9,10 -> the median value here is 10, which we can access by using a max heap
15,16,23,28 -> the median value is 15, which we can access by using a max heap


*/

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class MedianFinder {
private:
    /*
    left: a max-heap (default in C++) that stores the smaller half of the numbers.
    right: a min-heap using greater<int> comparator that stores the larger half of the numbers.
    Why two heaps?
    They help efficiently keep track of the middle of a dynamic stream of numbers.
    The left heap ensures the largest of the smaller half is quickly accessible.
    The right heap ensures the smallest of the larger half is quickly accessible.
    */
    std::priority_queue<int> left; // max-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> right; // min-heap

public:
    MedianFinder() {}
    //Adds a new number num into the data structure.
    void addNum(int num) {
        /*
        If left is empty or num is smaller than or equal to the largest in left, put it in left.
        Else, it's bigger, so it goes to right.
        This keeps left and right split around the median.
        We intentionally keep the left heap (max-heap) slightly larger when the number of elements is odd.
        */
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Balance the heaps: max difference in size is 1
        /*
        Ensures the heaps stay balanced, so their sizes differ by at most 1.
        If left is too big, move the top to right.
        If right is bigger, move its top to left
        */
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        /*
        If both heaps are the same size (even number of elements), median is average of left.top() and right.top().
        If odd number of elements, left will always have the extra one, so return left.top() as the median.
        */
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        } else {
            return left.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    std::cout << mf.findMedian() << std::endl; // 1.5
    mf.addNum(3);
    std::cout << mf.findMedian() << std::endl; // 2.0
    return 0;
}