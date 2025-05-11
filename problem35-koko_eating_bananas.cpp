/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30
*/

/*
Solution approach: 
The idea is to solve the problem by applying binary search on answer.


Lower limit of speed is 1 banana/hr as Koko must eat at least one banana per hour, and Upper limit is the maximum bananas among all piles.
Apply binary search on the possible answer range to get minimum speed to eat all bananas within k hours. 
If the current speed (mid) is enough to eat all bananas within given k hours then update the minimum eating time and continue the search in lower half of the range to check for slower eating speeds.
Else search in upper half of the range as we need to increase the eating speed.

The ceil function (short for ceiling) returns the smallest integer greater than or equal to a given number.
ceil(3.2) = 4
ceil(5.0) = 5
ceil(6.9) = 7
It’s used when you want to round up to the nearest whole number — even if the number is already very close to the next integer.

Below, we used a math to avoid using floating point due to: 
-> Floating-point numbers can introduce rounding errors because they can't represent all decimal numbers exactly. This is especially dangerous in problems requiring exact comparisons or boundaries like binary search.
-> Integer operations are faster than floating-point operations on most CPUs. In large-scale or time-critical problems, this small difference can add up.
-> If you use floating-point division, the midpoint might not be exactly halfway due to floating rounding, leading to infinite loops or incorrect results.
-> Using integer math avoids the need for cmath functions like ceil(), making the code simpler, safer, and more portable in constrained environments like online judges.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //Minimum possible eating speed. Koko must eat at least 1 banana per hour.
        int start = 1;
        //Start by assuming the largest pile is the first one.
        int end = piles[0];
        //Find the maximum pile size to set the maximum possible speed. Because Koko doesn’t need to eat faster than the largest pile.
        for(int i = 1; i < piles.size(); i++){
            end = max(end, piles[i]);
        }
        //This holds the best answer so far. Initialized with the max speed.
        int ans = end;

        while(start <= end){
            int mid = (start + end) / 2;
            //Call countHours() to check how many hours Koko would need to finish eating at speed mid
            if(countHours(piles, mid) > (long) h) {
                //If it takes more hours than allowed (> h), it means speed is too slow, so search on the right
                start = mid + 1;
            } else {
                //If it's within allowed time, it means this speed is valid, but we want to try for a lower speed, so update ans and search left.
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }

    //This function calculates the total number of hours Koko needs to eat all bananas at the given speed.
    long countHours(vector<int>& piles, int speed){
        //Start with 0 total hours
        long number_hours = 0;
        for(int i = 0; i < piles.size(); i++){
            //For each pile, calculate the number of hours it takes to eat it using ceiling division
            number_hours += findCeil(piles[i], speed);
        }
        return number_hours;
    }
    //Custom function to perform ceiling division without using floating point math.
    long findCeil(int a, int b){
        //If a is perfectly divisible by b, just return the result
        if(a % b == 0){
            return a / b;
        } else { //If not, return the integer division plus one — which is how ceiling works.
            return(a/b) + 1;
        }
    }
};

int main() {
    Solution sol;

    // Example input: piles of bananas and total hours Koko has
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    // Call the function and print the result
    int result = sol.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;

    return 0;
}
