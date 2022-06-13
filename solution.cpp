#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol238;
using namespace std;

/*takeaways
  - use DP to achieve O(n)
  - the space complexity is O(n)
  - scan the array from left to right to build
    a left product array
    [1,2,3,4] => [1,1,1x2,1x2x3]
  - we then produce the right product array
    [1,2,3,4] => [2x3x4,3x4,4,1]
  - scan the array one more time to prodcue
    the final product
    [2x3x4,1x3x4,1x2x4,1x2x3]

*/
vector<int> Solution::product(vector<int> &nums)
{
  int n = nums.size();
  /* lp[i] will store nums[0]*...*nums[i-1] */
  auto lp = vector<int>(n, 1);
  /* rp[i] will store nums[i+1]*...*nums[n-1] */
  auto rp = vector<int>(n, 1);

  auto result = vector<int>(n, 1);

  for (auto i = 1; i < n; i++)
    lp[i] = lp[i - 1] * nums[i - 1];

  for (auto i = n - 2; i >= 0; i--)
    rp[i] = rp[i + 1] * nums[i + 1];

  for (auto i = 0; i < n; i++)
    result[i] = lp[i] * rp[i];

  return result;
}

/*takeaways
  - each element will be visited twice in a single loop
    - the first half of the nums will collect the product
      of its left subarray (first visit) and then the right
      (second visit)
      - for example, the nums[0] will pick up its left,
        which is 1, and later 2x3x4, which is its right

  - space complexity is a constant (the result is not
    counted per the question)
*/

vector<int> Solution::product2(vector<int> &nums)
{
  int n = nums.size(), l = 1, r = 1;
  auto result = vector<int>(n, 1);

  /*two pointers
    - i and n-1-i
  */
  for (auto i = 0; i < n; i++)
  {
    /* start from the beginning
       - pick up the left
    */
    result[i] *= l;
    /* start from the end
       - pick up the right
    */
    result[n - 1 - i] *= r;
    /* grow left and right  */
    l *= nums[i];
    r *= nums[n - 1 - i];
  }

  return result;
}