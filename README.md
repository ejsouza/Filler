# Filler

`Filler` is an algorithmic game which consists in filling a grid of a known size in advance
with pieces of random size and shapes, without the pieces being stacked more than one
square above each other and without them exceeding the grid. If one of these conditions
is not met, the game stops.

Each successfully placed piece yields a number of points, and has only one player, the
goal of the game could be to get the best score possible. However, it is with two players
that the filler takes all his interest. Each player has for the purpose of placing as many
pieces as possible while attempting to prevent his opponent from doing the same. At the
end of the game, the one with the most points wins the match...

Writing a Filler player is a very interesting **algorithmic challenge**. Each turn, the active
player receives the grid status and must maximize his points while trying to minimize
those of the opponent by eliminating it as quickly as possible.

## How the game rolls
Here is an example on how a game will roll out. <br />
$>./filler_vm -p1 user1 -p2 user2 -v -f samples/w1.flr <br />
$$$ exec p1 : [user1] <br />
$$$ exec p2 : [user2] <br />
Plateau 14 30: <br />
`012345678901234567890123456789` <br />
`000 ..............................` <br />
`001 ..............................` <br />
`002 ..............................` <br />
`003 ..............................` <br />
`004 ......X.......................` <br />
`005 ..............................` <br />
`006 ..............................` <br />
`007 ..........................O...` <br />
`008 ..............................` <br />
`009 ..............................` <br />
`010 ..............................` <br />
`011 ..............................` <br />
`012 ..............................` <br />
`013 ..............................` <br />
Piece 3 6: <br />
`.****.` <br />
`**....` <br />
`*.....` <br />
<got (O) : [7 24] (7,24) <br />
Plateau 14 30: <br />
`012345678901234567890123456789` <br />
`000 ..............................` <br />
`001 ..............................` <br />
`002 ..............................` <br />
`003 ..............................` <br />
`004 ......X.......................` <br />
`005 ..............................` <br />
`006 ..............................` <br />
`007 .........................oooo.` <br />
`008 ........................oo....` <br />
`009 ........................o.....` <br />
`010 ..............................` <br />
`011 ..............................` <br />
`012 ..............................` <br />
`013 ..............................` <br />
Piece 3 8: <br />
`......*.` <br />
`......**` <br />
`.......*` <br />
<got (X) : [4 0] (4,0) <br />
Plateau 14 30: <br />
`012345678901234567890123456789` <br />
`000 ..............................` <br />
`001 ..............................` <br />
`002 ..............................` <br />
`003 ..............................` <br />
`004 ......x.......................` <br />
`005 ......xx......................` <br />
`006 .......x......................` <br />
`007 .........................OOOO.` <br />
`008 ........................OO....` <br />
`009 ........................O.....` <br />
`010 ..............................` <br />
`011 ..............................` <br />
`012 ..............................` <br />
`013 ..............................` <br />
[...] <br />
== X fin : 175 <br />
== O fin : 168 <br />
