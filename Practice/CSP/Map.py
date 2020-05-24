import constraint

problem = constraint.Problem()

problem.addVariable('WA', "rgb")
problem.addVariable('NT', "rgb")
problem.addVariable('Q', "rgb")
problem.addVariable('SA', "rgb")
problem.addVariable('NSW', "rgb")
problem.addVariable('V', "rgb")
problem.addVariable('T', "rgb")

def constraint(WA,NT,Q,SA,NSW,V,T):
    if WA!=NT and WA!=SA and NT!=SA and NT!=Q and SA!=Q and SA!=NSW and SA!=V and Q!=NSW and NSW!=V:
        return True

problem.addConstraint(constraint, ['WA','NT','Q','SA','NSW','V','T'])

solutions = problem.getSolutions()

length = len(solutions)
print("Number of Solutions: ", length)
print("(WA,NT,Q,SA,NSW,V,T) ∈ {", end="")
for index, solution in enumerate(solutions):
    if index == length - 1:
        print("({},{},{},{},{},{},{})".format(solution['WA'], solution['NT'], solution['Q'], solution['SA'], solution['NSW'], solution['V'], solution['T']), end="")
    else:
        print("({},{},{},{},{},{},{}), ".format(solution['WA'], solution['NT'], solution['Q'], solution['SA'], solution['NSW'], solution['V'], solution['T']), end="")
print("}")
