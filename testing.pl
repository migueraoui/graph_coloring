% Define the colors
color(red).
color(blue).
color(green).
color(yellow).
color(black).
color(gray).

% Define the graph using arcs
arc(a, b).
arc(a, c).
arc(a, e).
arc(a, f).
arc(b, a).
arc(b, c).
arc(b, d).
arc(b, f).
arc(c, b).
arc(c, a).
arc(c, d).
arc(c, e).
arc(d, c).
arc(d, b).
arc(d, e).
arc(d, f).
arc(e, d).
arc(e, c).
arc(e, a).
arc(e, f).
arc(f, d).
arc(f, e).
arc(f, a).
arc(f, b).

%Predicat to color the nodes
color_nodes([], []).
color_nodes([Node | Rest], [Node-Color | RestColoring]) :-
    color(Color),
    color_nodes(Rest, RestColoring).

% Predicate to check if adjacent nodes have different colors
valid_coloring([]).
valid_coloring([Node-NodeColor | Rest]) :-
    \+ (member(Adjacent-AdjacentColor, Rest), arc(Node, Adjacent), NodeColor = AdjacentColor),
    valid_coloring(Rest).

% Predicat to find a valid coloring
find_valid_coloring(Nodes, ValidColoring) :-
    color_nodes(Nodes, ValidColoring),
    valid_coloring(ValidColoring).

%Predicat to start the coloring from the first node
start_coloring :-
    Nodes = [a, b, c, d, e, f],
    find_valid_coloring(Nodes, ValidColoring),
    print_coloring(ValidColoring).

%Predicat to print the coloring solution
print_coloring([]).
print_coloring([Node-Color | Rest]) :-
    format('~w: ~w~n', [Node, Color]),
    print_coloring(Rest).
