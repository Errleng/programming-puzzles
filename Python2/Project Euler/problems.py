import math
import time

#2 Sum of even Fibonacci sequence terms
#Fibonacci: tn = tn-1 + tn-2
def fibonacciRecursion(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacciRecursion(n-1) + fibonacciRecursion(n-2)

def fibonacciIteration(n):
    a, b = 0, 1
    terms = [a, b]
    for i in range(n):
        terms.append(terms[-1] + terms[-2])
    return terms[-1]

def fibonacciIterationEvenSum():
    evenSum = 0
    terms = [1, 2]
    while terms[-1] < 4 * 1000000:
        nextTerm = (terms[-1] + terms[-2])
        if nextTerm % 2 == 0:
            evenSum += nextTerm
        terms.append(nextTerm)
    print terms
    return evenSum

#Recursion vs Iteration
#fibonacciTerm = 30
#print "For term %s in the Fibonacci Sequence" % fibonacciTerm
#recursionStartTime = time.time()
#recursionResult = fibonacciRecursion(fibonacciTerm)
#recursionEndTime = time.time()
#recursionTime = recursionEndTime - recursionStartTime
#print "Recursion took %s seconds" % recursionTime
#
#iterationStartTime = time.time()
#iterationResult = fibonacciIteration(fibonacciTerm)
#iterationEndTime = time.time()
#iterationTime = iterationEndTime - iterationStartTime
#print "Iteration took %s seconds" % iterationTime
#
#evenSum = fibonacciIterationEvenSum()
#print "Sum of evens:", evenSum

#3 Largest Prime Factor

def primeChecker(n):
    if n <= 1:
        return False
    elif n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    a = 5
    while a * a <= n:
        if n % a == 0 or n % (a+2) == 0:
            return False
        a += 6
    return True

def bruteGeneratePrimes(n):
    primes = [2]
    for number in range(2, n+1):
        isPrime = True
        for prime in primes:
            if number % prime == 0:
                isPrime = False
                break
        if isPrime:
            if len(primes) > 10000:
                break
            primes.append(number)
    return primes

def sieveEratosthenes(n):
    primes = []
    isPrime = [True for i in range(n+1)]
    a = 2
    while a * a <= n:
        if isPrime[a]:
            for i in range(a*a, n+1, a):
                isPrime[i] = False
        a += 1
    for i in range(2, n):
        if isPrime[i]:
            primes.append(i)
    return primes

def sieve_loop(n):
    not_prime = [True for i in range(n+1)]
    prime = []
    for i in range(2, n+1):
        if not_prime[i]:
            prime.append(i)
            for j in range(i*i, n+1, i):
                not_prime[j] = False
    return prime

def findPrimeFactors(n, primes):
    primeFactors = []
    for prime in primes:
        if n % prime == 0:
            if len(primeFactors) > 10000:
                break
            primeFactors.append(prime)
    return primeFactors

#factoredNumber = 600851475143
#primeLimit = int(math.floor(factoredNumber**0.5))
#primeStartTime = time.time()
##primeList = bruteGeneratePrimes(primeLimit)
##primeList = sieveEratosthenes(primeLimit)
#primeList = sieve_loop(primeLimit)
#primeEndTime = time.time()
#primeTime = primeEndTime - primeStartTime
#print "Finding primes to %s took %s seconds" % (primeLimit, primeTime)
#print "There are %s primes in %s" % (len(primeList), primeLimit)
##print primeList
#primeFactorsList = findPrimeFactors(factoredNumber, primeList)
#print factoredNumber, "has %s prime factors" % len(primeFactorsList)
#print primeFactorsList


#4 Largest palindrome number from product of two 3 digit numbers
#def bruteFindPalindrome(start, end):
#    palindromes = []
#    for i in range(start, end):
#        for j in range(start, end):
#            product = i*j
#            strProduct = str(product)
#            reverseProduct = ""
#            for k in range(len(strProduct)-1, -1, -1):
#                reverseProduct += strProduct[k]
#            if strProduct == reverseProduct:
#                palindromes.append(product)
#    return palindromes
#startingNum, endingNum = 100, 1000
#palindromeStartTime = time.time()
#palindromeList = bruteFindPalindrome(startingNum, endingNum)
#palindromeEndtime = time.time()
#palindromeTime = palindromeEndtime - palindromeStartTime
#print "Finding palindrome from %s to %s took %s seconds" % (startingNum, endingNum, palindromeTime)
##print "Palindrome list:", palindromeList
#print "Largest palindrome is", max(palindromeList)

#5 Smallest multiple of range of numbers
def bruteSmallestMultiple(startNum, endNum):
    primes = []
    for i in range(startNum, endNum+1):
        if primeChecker(i):
            primes.append(i)
    primeMultiple = 1
    for prime in primes:
        primeMultiple *= prime
    number = primeMultiple
    smallestMultiple = 0
    while smallestMultiple == 0:
        success = True
        for j in range(startNum, endNum + 1):
            if number % j != 0:
                success = False
                break
        if success:
            smallestMultiple = number
        number += primeMultiple
    return smallestMultiple
startNum, endNum = 1, 3
smallestMultipleStartTime = time.time()
smallestMultiple = bruteSmallestMultiple(startNum, endNum)
smallestMultipleEndTime = time.time()
smallestMultipleTime = smallestMultipleEndTime - smallestMultipleStartTime
print "Smallest multiple is", smallestMultiple
print "Finding smallest multiple from %s to %s took %s seconds" % (startNum, endNum, smallestMultipleTime)
