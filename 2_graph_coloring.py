from itertools import product

def is_valid(graph, coloring): # checks if any neighbors noeudes have the same color
    for noeude, color in coloring.items():
        for neighbor in graph[noeude]:
            if coloring.get(neighbor) == color:
                return False
    return True

def all_coloring_solutions(graph, colors):
    noeudes = list(graph.keys())
    all_solutions = []

    #Try all possible combinations of colors for the noeudes
    for coloring in product(colors, repeat=len(noeudes)):
        current_solution = dict(zip(noeudes, coloring))
        if is_valid(graph, current_solution):
            all_solutions.append(current_solution)

    return all_solutions

#Define the graph using dictionary.
graph = {
    'A': ['B', 'C', 'E', 'F'],
    'B': ['A', 'C', 'D', 'F'],
    'C': ['B', 'A', 'D', 'E'],
    'D': ['C', 'B', 'E', 'F'],
    'E': ['D', 'C', 'A', 'F'],
    'F': ['D', 'E', 'A', 'B']
}

#Define the colors.
colors = ['red', 'blue', 'green', 'yellow', 'black', 'grey']

#This to get all possible solutions
solutions = all_coloring_solutions(graph, colors)

#Print the solutions
#for i, solution in enumerate(solutions, 1):
   # print(f"Solution {i}: {solution}")

print("First Solution:", solutions[0])
