#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "path.h"
#include "mazehelper.h"

char * solveMaze(Maze * m) {
    //An obvious upper bound on the size of the solution path is the number
    //of squares in the maze + 1 (to account for the '\0'). You could make
    //this a tighter bound by accounting for how many walls there are, but
    //this approach is good enough!
	char * retval = malloc(sizeof(char) * ((m->width * m->height) + 1));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	if (!depthFirstSolve(m, mp, retval, 0)) {
		fprintf(stderr, "No solution found!\n");
	} else {
		printf("Solution found: %s\n", retval);
	}
	
	return retval;
}

bool depthFirstSolve(Maze * m, MazePos curpos, char * path, int step) {

    if (atEnd(curpos, m)) {
        path[step] = '\0';
        return true;
    }
    if (!squareOK(curpos, m)) {
        return false;
    }
    m->maze[curpos.ypos][curpos.xpos].visited = true;

    char direction[4] = {'n', 's', 'e', 'w'};
    MazePos steps[4] = {{.xpos= curpos.xpos, .ypos = curpos.ypos - 1},
                        {.xpos= curpos.xpos, .ypos = curpos.ypos + 1},
                        {.xpos= curpos.xpos + 1, .ypos = curpos.ypos},
                        {.xpos= curpos.xpos - 1, .ypos = curpos.ypos}};


    int i;

    for (i = 0; i < 4; i++) {
        if (depthFirstSolve(m, steps[i], path, step + 1)) {
            path[step] = direction[i];
            return true;
        }
    }
    path[step] = '\0';
    return false;
}
