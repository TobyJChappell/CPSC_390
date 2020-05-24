# CRASH + ERROR + REBOOT = HACKER

import constraint

problem = constraint.Problem()

problem.addVariables("CERH", range(1, 10))
problem.addVariables("ASOBTK", range(10))

def sum_constraint(c,r,a,s,h,e,o,b,t,k):
    if c*10000 + r*1000 + a*100 + s*10 + h + e*10000 + r*1000 + r*100 + o*10 + r + r*100000 + e*10000 + b*1000 + o*100 + o*10 + t == h*100000 + a*10000 + c*1000 + k*100 + e*10 + r:
        return True

problem.addConstraint(sum_constraint, "CRASHEOBTK")

problem.addConstraint(constraint.AllDifferentConstraint())

solutions = problem.getSolutions()
print("Number of solutions found: {}\n".format(len(solutions)))

for s in solutions:
    print("C = {}, R = {}, A = {}, S = {}, H = {}, E = {}, O = {}, B = {}, T = {}, K = {}"
        .format(s['C'], s['R'], s['A'], s['S'], s['H'], s['E'], s['O'], s['B'], s['T'], s['K']))
