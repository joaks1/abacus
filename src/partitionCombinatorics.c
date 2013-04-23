/**
 * \file partitionCombinatorics.c
 * \brief A collection of functions for partition combinatorics.
 *
 *
 */
#include "partitionCombinatorics.h"

int integerPartitionCumulativeSpectrum(int n, int arr[]) {
    int i, j;
    int table[n+1][n+1];
    // initialize table with base cases
    for (i = 0; i <= n; i++)
        table[i][0] = 0;
    for (i = 1; i <= n; i++)
        table[0][i] = 1;
    // populate table
    for (i = 1 ; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i - j < 0){
                table[i][j] = table[i][j-1];
                continue;
            }
            table[i][j] = table[i][j-1] + table[i-j][j];
        }
    }
    for (i = 0; i < n; i++) {
        arr[i] = table[n][i+1];
    }
    return table[n][n];
}

int integerPartitionSpectrum(int n, int arr[]) {
    int i;
    int a[n];
    int ip = integerPartitionCumulativeSpectrum(n, a);
    arr[0] = 1;
    for (i = 1; i < n; i++) {
        arr[i] = a[i] - a[i-1];
    }
    return ip;
}
    
double integerPartitionCumulativeProbs(int n, double arr[]) {
    int i;
    int a[n];
    int ip = integerPartitionCumulativeSpectrum(n, a);
    for (i = 0; i < n; i++) {
        arr[i] = a[i] / ((double) ip);
    }
    return arr[n-1];
}

double integerPartitionProbs(int n, double arr[]) {
    int i;
    int a[n];
    int ip = integerPartitionSpectrum(n, a);
    double sum = 0.0;
    for (i = 0; i < n; i++) {
        arr[i] = a[i] / ((double) ip);
        sum += arr[i];
    }
    return sum;
}

int integerPartition(int n) {
    int arr[n];
    int ip = integerPartitionCumulativeSpectrum(n, arr);
    return ip;
}

int drawIntegerPartitionCategory(const gsl_rng * rng, int n) {
    double cumulativeProbs[n];
    double totalProb = integerPartitionCumulativeProbs(n, cumulativeProbs);
    double r = gsl_rng_uniform(rng);
    int i;
    for (i = 0; i < n; i++) {
        if (r < cumulativeProbs[i]) {
            return (i+1);
        }
    }
    return -1;
}

/** 
 * A function for generating a random draw from a Dirichlet process.
 *
 * The function will generate one random mapping of `n` elements to subset
 * indices via a Dirichlet process.
 *
 * @param rng is a Gnu Scientific Library (http://www.gnu.org/software/gsl/)
 * instance of a random number generator (for compatibility with the msBayes
 * package).
 * @param n is the number of elements.
 * @param alpha is the concentration parameter of the Dirichlet process.
 * @param elements is an array of length n in which to store the subset
 * indices generated by the process.
 */
int dirichletProcessDraw(const gsl_rng * rng, int n, double alpha, int elements[]) {
    elements[0] = 0;
    int subSetCounts[n];
    subSetCounts[0] = 1;
    int numSubSets = 1;
    double subSetProb, newSubSetProb, u;
    int i, j;
    for (i = 1; i < n; i++) {
        newSubSetProb = (alpha / (alpha + (double)i));
        u = gsl_rng_uniform(rng);
        u -= newSubSetProb;
        if (u < 0.0) {
            elements[i] = numSubSets;
            subSetCounts[numSubSets] = 1;
            numSubSets += 1;
            continue;
        }
        for (j = 0; j < numSubSets; j++) {
            subSetProb = ((double)subSetCounts[j] / (alpha + (double)i));
            u -= subSetProb;
            if (u < 0.0) {
                elements[i] = j;
                subSetCounts[j] += 1;
                break;
            }
        }
        if (u > 0.0) {
            elements[i] = numSubSets-1;
            subSetCounts[numSubSets-1] += 1;
        }
    }
    return numSubSets;
}

/** 
 * A function for generating all partitions of an integer.
 *
 * This function generates all of the integer partitions of an integer in
 * anti-lexicographic order. The code is based on Algorithm ZS1 from:
 *
 * Zoghbi, A., and I. Stojmenovic. 1998. Fast algorithms for generating
 *     generating integer partitions. Intern. J. Computer Math.
 *     70:319--332.
 *
 * @param n is the integer to partition.
 * @param ip is the integer partition of n, or the total number of was
 * to partition n when order is irrelevant.
 * @see integerPartition()
 * @param partitions is an ip x n multidimensional array where the
 * generated partitions will be stored.
 */ 
void generateIntegerPartitions(int n, int ip, int **partitions) {
    /* memset(partitions, 0, sizeof(partitions[0][0]) * ip * n); */
    int i, j;
    for (i = 0; i < ip; i++) {
        for (j = 0; j < n; j++) {
            partitions[i][j] = 0;
        }
    }
    int x[n];
    for (i = 0; i < n; i++) {
        x[i] = 1;
    }
    x[0] = n;
    int m = 0;
    int h = 0;
    int r, t, sum;
    partitions[0][0] = x[0];
    int part_index = 0;
    while (x[0] != 1) {
        part_index += 1;
        if (x[h] == 2) {
            m += 1;
            x[h] = 1;
            h -= 1;
        }
        else {
            r = x[h] - 1;
            t = m - h + 1;
            x[h] = r;
            while (t >= r) {
                h += 1;
                x[h] = r;
                t -= r;
            }
            if (t == 0) {
                m = h;
            }
            else {
                m = h + 1;
                if (t > 1) {
                    h += 1;
                    x[h] = t;
                }
            }
        }
        sum = 0;
        for (i = 0; i < n; i++) {
            partitions[part_index][i] = x[i];
            sum += x[i];
            if (sum >= n) {
                break;
            }
        }
    }
}

