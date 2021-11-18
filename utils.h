/**
 * @file utils.h
 * @brief Contains a few utility functions
 */

#include "colormapper.h"

/**
 * @brief returns min of 3 parameters
 * @return min value of three arguments
 */
template<typename t>
t min_3(const t &a, const t &b, const t&c);

/**
 * @brief returns max of 3 parameters
 * @return max value of three arguments
 */
template<typename t>
t max_3(const t &a, const t &b, const t&c);

/**
 * @brief Used to check equality of doubles upto a threshold of 1e-6
 * @return true if equal, false if not equal
 */
bool isEquals(const double& a, const double &b);

bool compareLuminosity(ColorRGB a, ColorRGB b);

