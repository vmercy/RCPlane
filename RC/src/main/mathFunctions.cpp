/**
 * @file mathFunctions.cpp
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Definition of a set of mathematical functions
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

template<typename T>
T sum(T dataArray_p[], uint8_t size_p)
{
  T sum = 0;
  for(uint8_t i = 0; i<size_p; i++)
    sum+=dataArray_p[i];
  return sum;
}

template<typename T, typename K>
K mean(T dataArray_p[], uint8_t size_p)
{
  return (K)sum<T>(dataArray_p,size_p)/size_p;
}

#endif