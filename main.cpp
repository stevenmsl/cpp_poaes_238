#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol238;

/*
Input:  [1,2,3,4]
Output: [24,12,8,6]
*/

tuple<vector<int>, vector<int>>
testFixture1()
{
  auto input = vector<int>{1, 2, 3, 4};
  auto output = vector<int>{24, 12, 8, 6};
  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.product(get<0>(f))) << endl;
}

void test2()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.product2(get<0>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}