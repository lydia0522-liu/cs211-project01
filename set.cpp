/*set.cpp*/

/** 
 * @file set.cpp
 * @brief Set class
 *
 * Implements the notion of a mathematical set of
 * integers: no duplicates, in ascending order.
 * Provides set operations intersection, union, and
 * difference.
 *
 * @author Prof Joe Hummel, Northwestern University
 * @author ?
 * @author ?
 * @author ?
*/

#include <algorithm>

#include "set.h"

using namespace std;

/** 
 * @brief returns # of elements in the set
 *
 * @return # of elements 
 */
size_t Set::size() const
{
  return this->S.size();
}

/** 
 * @brief returns ith element in the set (0-based)
 *
 * @return ith element in the set 
 */
int Set::operator[](int i) const
{
  return this->S[i];
}

/** 
 * @brief returns iterator to start of iteration space
 *
 * @return iterator to start of iteration space
 */
vector<int>::iterator Set::begin()
{
  return this->S.begin();
}

/** 
 * @brief returns iterator to end of iteration space
 *
 * @return iterator to end of iteration space
 */
vector<int>::iterator Set::end()
{
  return this->S.end();
}

/** 
 * @brief searches if e is element of set
 *
 * @return true if e is an element, false if not
 */
bool Set::contains(int e)
{
  vector<int>::iterator iter = std::find(this->S.begin(), this->S.end(), e);

  return (iter != this->S.end());
}

/** 
 * @brief inserts e into set if not already a member
 *
 * @return void
 */
void Set::insert(int e)
{
  // Binary search: O(log N)
    auto iter = lower_bound(S.begin(), S.end(), e);

    // Iterator comparison: O(1) Element comparison: O(1)
    if (iter != S.end() && *iter == e)            // O(1)
        return;                                   // O(1)

    // Vector insertion: O(N) worst case
    // Elements may need to be shifted to the right
    S.insert(iter, e);  

}

/** 
 * @brief removes e from set if a member
 *
 * @return void
 */
void Set::remove(int e)
{
  // is e in the set?
  vector<int>::iterator iter = std::find(this->S.begin(), this->S.end(), e);
  if (iter != this->S.end()) // yes, so remove:
  {
    this->S.erase(iter);
  }
}
