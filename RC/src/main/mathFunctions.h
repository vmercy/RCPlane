/**
 * @file mathFunctions.h
 * @author Valentin Mercy (https://github.com/vmercy)
 * @brief Declaration of a set of mathematical functions
 * @version 0.1
 * @date 2020-11-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include <Arduino.h>

/**
 * @brief computes a sum
 * @tparam T type of return
 * @tparam K type of input data
 * @param dataArray_p array containing all values
 * @param size_p size of arrayData_p
 * @return T 
 */
template<typename T, typename K>
T sum(K dataArray_p[], uint8_t size_p)
{
  T sum = 0;
  for(uint8_t i = 0; i<size_p; i++)
    sum+=dataArray_p[i];
  return sum;
}

/**
 * @brief computes a mean value
 * @tparam T type of input data
 * @tparam K type of return
 * @tparam U type of sum (optional) 
 * @note set U to avoid overflow situations when calculating sum
 * @param dataArray_p array containing all values
 * @param size_p size of arrayData_p
 * @return T 
 */
template<typename T, typename K, typename U = K>
T mean(K dataArray_p[], uint8_t size_p)
{
  return (T)(sum<U,K>(dataArray_p,size_p)/size_p);
}

#endif