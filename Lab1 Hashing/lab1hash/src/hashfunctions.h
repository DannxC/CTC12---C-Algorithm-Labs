#ifndef LAB1_HASH_FUNCS_H
#define LAB1_HASH_FUNCS_H

#include <string>
#include <iostream>

/**
 * \brief hashing by division
 * \param str the string to be hashed
 * \param m size of hash table. Auxiliary functions are used to fix the value. This implementation works for any size.
 * \return the hash value of the input string
 */
int hashdiv(std::string str, int m );

int hashdiv29(std::string str);



#endif
