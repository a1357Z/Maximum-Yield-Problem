# Vitamin E Mixing problem

## Problem statement:
Consider the following 1 indexed arrays of length n:
    stock, percentE, percentAlpha, percentDelta

stock[i] represents the weight of the ith stock
percentE[i] represents the percent of vitamin E in the ith stock

vitamin E is made of some variants which include alpha and delta variants.

percentAlpha[i] represents the percent of the alpha variant in the vitamin E obtained from the ith stock

weight of vitamin E in ith stock (WE[i]) = stock[i]*(percentE[i]/100)
weight of alpha variant in ith stock (WAlpha[i]) = WE[i]*(percentAlpha[i]/100)
weight of delta variant in ith stock (WDelta[i]) = WE[i]*(percentDelta[i]/100)

We are given 3 variables: x, y, z

We want to pick a combination of the n stocks and  mix some fraction of those stocks such that following holds true:
    x --> minimum percent of vitamin E in the final mixture
    y --> maximum percent of alpha variant in the final mixture
    z --> maximum percent of delta variant in the final mixture

## Approach 1:
consider an array fraction of length n:
    fraction[i] represents the fraction of the ith stock we are taking in the mixture

weight of mixture (weight) = ∑ (stock[i] * fraction[i])

weight of vitamin E in the mixture (vitaminEWeight) = ∑ (stock[i] * fraction[i] * percentE[i])/100

percent of vitamin E in the mixture (percentVitaminE) = (∑ (stock[i] * fraction[i] * percentE[i])) / (∑ (stock[i] * fraction[i]))

use backtracking to build the solution iteratively

Input format:

n: number of stocks
stock: stocks array
percentE: percent of vitamin E array
percentAlpha: percent of alpha array
percentDelta: percent of delta array
x, y, x

E.g. Test cases:

5
171 310 95 16 94
41 70 49 24 25
50 12 4 3 4
12 24 42 59 54
60 25 45

5
131.4 351 55.8 104.5 171.6
3 2 25 35 41
51 55 42 38 25
16 9 5 8 12
60 25 45

--------------

5
131.4 351 55.8 104.5 171.6
3 2 25 35 41
51 55 42 38 25
16 9 5 8 12
38 25 45

--------------
not working:

10
131.4 351 55.8 104.5 171.6 310.5 94.9 16.3 94.2 243
3 2 25 35 41 55 49 24 25 21
51 55 42 38 25 12 4 3 4 3
16 9 5 8 12 24 49 59 54 53
38 25 45

-------------------------

7
131.4 351 55.8 104.5 171.6 310.5 94.9
3 2 25 35 41 55 49
51 55 42 38 25 12 4
16 9 5 8 12 24 49
38 25 45

------------------------
takes: around 3-4 minutes:

8
131.4 351 55.8 104.5 171.6 310.5 94.9 16.3
3 2 25 35 41 55 49 24
51 55 42 38 25 12 4 3
16 9 5 8 12 24 49 59
38 25 45

-------------------------
takes around 1 minute for step of 0.05
6
131.4 351 55.8 104.5 171.6 310.5
3 2 25 35 41 55
51 55 42 38 25 12
16 9 5 8 12 24
38 25 45


