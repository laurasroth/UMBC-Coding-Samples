""" A subclass of a constraint problem to solve an n-queens problem of
    a given size with a given solver """

from constraint import *

class NQ(Problem):

    def __init__(self, n=8, solver=None):

        """N is the size of the board, solver is the CSP solver
           that will be used to sove the problem """

        # call the base class init method
        super(NQ, self).__init__(solver=solver)

        # set any NQ instance variables needed
        # define CSP variables with their domains
        # add CSP constraint

        # number of queens
        queens = range(n)

        # domain of queens
        domain = range(n)

        # adds the queens and their respection domains
        self.addVariables(queens, domain)

        # for a queen
        for v1 in queens:

            # go through each subsequent queen
            for v2 in queens:

                # if the current queen is less than the queen it is being compare to
                # it is ignored. The highest numeric queen will have constrants for
                # every queen, whereas the smallest queen has done
                if v1 < v2:
                    # each queen is inherently in its own column, this checks if
                    # it is in the same row or diagnol     
                    F = lambda r1, r2, c1=v1, c2=v2: \
                    r1 != r2 and abs(r1 - r2) != abs(c1 - c2)

                    self.addConstraint(F, (v1, v2))
        
