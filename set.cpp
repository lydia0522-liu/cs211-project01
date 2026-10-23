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
  // vector<int>::iterator iter = std::find(this->S.begin(), this->S.end(), e);

  // return (iter != this->S.end());
  auto iter = lower_bound(S.begin(), S.end(), e);
  return(iter != S.end() && *iter ==e);
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
  //vector<int>::iterator iter = std::find(this->S.begin(), this->S.end(), e);
  //if (iter != this->S.end()) // yes, so remove:
  //{
  //  this->S.erase(iter);
  //}
    auto iter = lower_bound(S.begin(), S.end(), e);

    if (iter != S.end() && *iter == e)
    {
        S.erase(iter);
    }
}

// merge two sets together, eliminating duplicates
void Set::merge(const Set& S2)
{
  vector<int> result;
  size_t i = 0;
  size_t j = 0;
  while (i < this->S.size() && j < S2.S.size())
  {
    if (this->S[i] < S2.S[j])
    {
      result.push_back(this->S[i]);
      i++;
    }
    else if (this->S[i] > S2.S[j])
    {
      result.push_back(S2.S[j]);
      j++;
    }
    else
    {
      result.push_back(this->S[i]);
      i++;
      j++;
    }
  }

  while (i < this->S.size())
    {
      result.push_back(this->S[i]);
      i++;
    }
    while (j< S2.S.size())
    {
      result.push_back(S2.S[j]);
      j++;
    }

  this->S = result;
}

void Set::difference(const Set& other)
{
    Set result;

    size_t i = 0;
    size_t j = 0;

    while (i < S.size() && j < other.S.size())
    {
        if (S[i] < other.S[j])
        {
            result.S.push_back(S[i]);
            i++;
        }
        else if (S[i] > other.S[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    while (i < S.size())
    {
        result.S.push_back(S[i]);
        i++;
    }

    S = result.S;
}


//common ele in both sets
void Set::intersection(const Set& S2)
{
    vector<int> result;
    size_t i = 0;
    size_t j = 0;
    while (i < S.size() && j < S2.S.size())
    {
        if (S[i] < S2.S[j])
        {
            i++;
        }
        else if (S[i] > S2.S[j])
        {
            j++;
        }
        else
        {
            result.push_back(S[i]);
            i++;
            j++;
        }
    }
    S = result;
}

// if 2 sets have common ele
bool Set::disjoint(const Set& S2) const
{
    size_t i = 0;
    size_t j = 0;
    while (i < S.size() && j < S2.S.size())
    {
        if (S[i] == S2.S[j])
        {
            return false;
        }
        else if (S[i] < S2.S[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return true;
}