""" A subclass of a constraint problem to find a magic square for a
    nxn grid and sum n*(n*n+1)/2. """

# Laura Roth
# rolaur1@umbc.edu
# CMSC471
# Homework 3 - Problem 2

from constraint import *

class MS(Problem):

    def __init__(self, n=3, solver=None):

        """N is the size of the magic square, solver is the CSP solver
           that will be used to sove the problem """

        # call the base class init method
        super(MS, self).__init__(solver=solver)

        # set any MS instance variables needed
        # define CSP variables with their domains
        # add CSP constraints

        self.addVariables(range(n**2), range(1, n**2 + 1))

        magicsum = n*(n**2 + 1)/2                         # stores the calculated magic sum values

        diag1 = list()                                    # stores the indeces of the left diagnol
        diag2 = list()                                    # stores the indeces of the right diagnol

        j = 1                                             # used to iterate for the right diagnol

        for i in range(0, n):
            diag1.append(i * (n + 1))

        for i in range(0, n):
            diag2.append(j * (n - 1))
            j = j + 1

        self.addConstraint(AllDifferentConstraint(), range(n**2))
        self.addConstraint(ExactSumConstraint(magicsum), diag1)
        self.addConstraint(ExactSumConstraint(magicsum), diag2)

        for row in range(n):
            self.addConstraint(ExactSumConstraint(magicsum), [row*n + i for i in range(n)])

        for col in range(n):
            self.addConstraint(ExactSumConstraint(magicsum), [col + n*i for i in range(n)])
        

