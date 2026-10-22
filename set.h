/*set.h*/

/** 
 * @file set.h
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

#pragma once

#include <vector>

using namespace std;

class Set 
{
private:
  vector<int>  S;

public:
  // no constructor needed, vector will self-initialize to empty

  // returns # of elements in the set
  size_t size() const;

  // returns ith element of the set
  int operator[](int i) const;

  // surface iterator support:
  vector<int>::iterator begin();
  vector<int>::iterator end();

  // is e a member of the set?
  bool contains(int e);

  // inserts e into the set if not already a member
  void insert(int e);

  // removes e from the set if a member
  void remove(int e);


/*
 * TODO for project 01: uncomment and implement in set.cpp
 *
 
  // THIS SET = THIS set intersect S2
  void intersection(const Set& S2);

  // THIS SET = THIS SET union S2
  void merge(const Set& S2);

  // THIS SET = THIS set - S2
  void difference(const Set& S2);

  // is THIS SET disjoint from S2 (i.e. no elements in common)?
  bool disjoint(const Set& S2) const;
  
 *
 *
 */
 
};
