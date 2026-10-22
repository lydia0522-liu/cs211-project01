/*main.cpp*/

/** 
 * @file main.cpp
 * @brief main program to test Set
 *
 * @author Prof Joe Hummel, Northwestern University
 * @author ?
 * @author ?
 * @author ?
 */
#include <iostream>
#include <chrono>
#include <random>
#include <limits>

#include "set.h"

using namespace std;


int main()
{
  Set s;

  cout << endl;

  // Setup to generate random integers from 1..MAX_INT:
  std::random_device rd; 
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<> distr(1, std::numeric_limits<int>::max()); 

  // Insert N random integers to our set:
  int N = 20000;
  cout << "Inserting " << N << " random elements..." << endl;
  auto start = chrono::high_resolution_clock::now();

  for (int i = 0; i < N; ++i) {
      s.insert(distr(gen));
  }

  // make sure duplicates are not inserted:
  s.insert(s[0]);  // re-insert first 3 elements...
  s.insert(s[1]);
  s.insert(s[2]);
  s.insert(s[s.size()-3]);  // re-insert last 3 elements...
  s.insert(s[s.size()-2]);
  s.insert(s[s.size()-1]);

  auto stop = chrono::high_resolution_clock::now();
	auto diff = stop - start;
	auto duration = chrono::duration_cast<chrono::milliseconds>(diff);
  cout << "Time: " << duration.count() / 1000.0 << " secs" << endl;

  cout << endl;
  cout << "# of elements: " << s.size() << endl;

  cout << "First 3 elements: "
       << s[0] << ", "
       << s[1] << ", "
       << s[2] << endl;
  
  cout << "Last 3 elements:  "
      << s[s.size()-3] << ", "
      << s[s.size()-2] << ", "
      << s[s.size()-1] << endl;

  // remove first and last elements:
  cout << endl;
  cout << "Removing first and last elements..." << endl;
  s.remove(s[0]);
  s.remove(s[s.size()-1]);

  cout << endl;
  cout << "# of elements: " << s.size() << endl;
  cout << "First 3 elements: "
       << s[0] << ", "
       << s[1] << ", "
       << s[2] << endl;
  
  cout << "Last 3 elements:  "
      << s[s.size()-3] << ", "
      << s[s.size()-2] << ", "
      << s[s.size()-1] << endl;

  //
  // check contains():
  //
  if (s.contains(-1))
    cout << "ERROR: set does not contain -1" << endl;
  if (s.contains(0))
    cout << "ERROR: set does not contain 0" << endl;

  if (!s.contains(s[0]))
    cout << "ERROR: set does contains " << s[0] << "?!" << endl;  
  if (!s.contains(s[s.size()-1]))
    cout << "ERROR: set does contains " << s[s.size()-1] << "?!" << endl; 

  //
  // for each first 10 elements:
  //
  int count = 0;

  cout << endl;
  cout << "First 10 elements using foreach:" << endl;

  for (int e : s) {
    cout << e << endl;

    count++;
    if (count == 10)
      break;
  }

  //
  // last 10 elements using iterators:
  //
  cout << endl;
  cout << "Last 10 elements using iterators:" << endl;

  auto iter = s.end() - 10;
  while (iter != s.end()) {
    cout << *iter << endl;
    iter++;
  }

  //
  // done:
  //
  cout << endl;

  return 0;
}
