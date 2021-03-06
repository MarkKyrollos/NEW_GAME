#ifndef A_STAR_H
#define A_STAR_H
#include <QPair>
#include <QVector>
#include <QStack>
#include <cfloat>
#include "character.h"
#include "player.h"
typedef QPair<int, int> Pair;
class A_star
{
public:
    A_star();
    // A structure to hold the necessary parameters
    struct cell {
        // Row and Column index of its parent
        int parent_i, parent_j;
        int data;
        // f = g + h
        double f, g, h;
    };

    // A Utility Function to check whether given cell (row, col)
    // is a valid cell or not.
    bool isValid(int row, int col, QVector<QVector<int>> map)
    {
        // Returns true if row number and column number
        // is in range and not a wall
        return (row >= 0) && (row < 30) && (col >= 0)
               && (col < 30) && (map[row][col]!=-4) ;
    }

    // A Utility Function to check whether the given cell is
    // blocked or not
    /*
    bool isUnBlocked(int map[][30], int row, int col)
    {
        // Returns true if the cell is not blocked else false
        if (map[row][col] != 4)
            return (true);
        else
            return (false);
    }
     */
    // A Utility Function to check whether destination cell has
    // been reached or not
    bool isDestination(int row, int col, player* player)
    {
        if (row == player->row && col == player->col)
            return (true);
        else
            return (false);
    }

    // A Utility Function to calculate the 'h' heuristics.
    double calculateHValue(int row, int col, player* player)
    {
        // Return using the distance formula
        return ((double)sqrt(
            (row - player->row) * (row - player->row)
            + (col - player->col) * (col - player->col)));
    }

    // A Utility Function to trace the path from the source
    // to destination
    void tracePath(cell cellDetails[30][30], player* player) //take note of this
    {
        //printf("\nThe Path is ");
        int row = player->row;
        int col = player->col;

        QStack<Pair> Path;

        while (!(cellDetails[row][col].parent_i == row
                 && cellDetails[row][col].parent_j == col)) {
            Path.push(make_pair(row, col));
            int temp_row = cellDetails[row][col].parent_i;
            int temp_col = cellDetails[row][col].parent_j;
            row = temp_row;
            col = temp_col;
        }

        Path.push(make_pair(row, col));
        while (!Path.empty()) {
            QPair<int, int> p = Path.top();
            //TODO: put boss movement here
            Path.pop();
            //printf("-> (%d,%d) ", p.first, p.second);
        }

        return;
    }

    // A Function to find the shortest path between
    // a given source cell to a destination cell according
    // to A* Search Algorithm
    void aStarSearch(int grid[30][30], Pair src, Pair dest)
    {
        // If the source is out of range
        if (isValid(src.first, src.second, map) == false) {
            return;
        }

        // If the destination is out of range
        if (isValid(dest.first, dest.second, map) == false) {
            return;
        }

        // Either the source or the destination is blocked
        /*
        if (isUnBlocked(grid, src.first, src.second) == false
            || isUnBlocked(grid, dest.first, dest.second)
                   == false) {
            printf("Source or the destination is blocked\n");
            return;
        }
        */
        // If the destination cell is the same as source cell
        if (isDestination(src.first, src.second, player)
            == true) {
            return;
        }

        // Create a closed list and initialise it to false which
        // means that no cell has been included yet This closed
        // list is implemented as a boolean 2D array
        bool closedList[30][30];
        memset(closedList, false, sizeof(closedList));

        // Declare a 2D array of structure to hold the details
        // of that cell
        cell cellDetails[30][30];

        int i, j;

        for (i = 0; i < 30; i++) {
            for (j = 0; j < 30; j++) {
                cellDetails[i][j].f = FLT_MAX;
                cellDetails[i][j].g = FLT_MAX;
                cellDetails[i][j].h = FLT_MAX;
                cellDetails[i][j].parent_i = -1;
                cellDetails[i][j].parent_j = -1;
                cellDetails[i][j].data= map[i][j];
            }
        }

        // Initialising the parameters of the starting node
        i = src.first, j = src.second;
        cellDetails[i][j].f = 0.0;
        cellDetails[i][j].g = 0.0;
        cellDetails[i][j].h = 0.0;
        cellDetails[i][j].parent_i = i;
        cellDetails[i][j].parent_j = j;
        cellDetails[i][j].data=map[i][j];
        /*
         Create an open list having information as-
         <f, <i, j>>
         where f = g + h,
         and i, j are the row and column index of that cell
         Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
         This open list is implemented as a set of pair of
         pair.*/
        set<pPair> openList;

        // Put the starting cell on the open list and set its
        // 'f' as 0
        openList.insert(make_pair(0.0, make_pair(i, j)));

        // We set this boolean value as false as initially
        // the destination is not reached.
        bool foundDest = false;

        while (!openList.empty()) {
            pPair p = *openList.begin();

            // Remove this vertex from the open list
            openList.erase(openList.begin());

            // Add this vertex to the closed list
            i = p.second.first;
            j = p.second.second;
            closedList[i][j] = true;

            /*
             Generating all the 8 successor of this cell

                        N
                        |
                        |
                 W----Cell----E
                        |
                        |
                        S

             Cell-->Popped Cell (i, j)
             N -->  North       (i-1, j)
             S -->  South       (i+1, j)
             E -->  East        (i, j+1)
             W -->  West        (i, j-1)

            */
            // To store the 'g', 'h' and 'f' of the 8 successors
            double gNew, hNew, fNew;

            //----------- 1st Successor (North) ------------

            // Only process this cell if this is a valid one
            if (isValid(i - 1, j, map) == true) {
                // If the destination cell is the same as the
                // current successor
                if (isDestination(i - 1, j, dest) == true) {
                    // Set the Parent of the destination cell
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                    tracePath(cellDetails, dest);
                    foundDest = true;
                    return;
                }
                // If the successor is already on the closed
                // list or if it is blocked, then ignore it.
                // Else do the following
                else if (closedList[i - 1][j] == false)
                {
                    gNew = cellDetails[i][j].g + 1.0;
                    hNew = calculateHValue(i - 1, j, dest);
                    fNew = gNew + hNew;

                    // If it isn???t on the open list, add it to
                    // the open list. Make the current square
                    // the parent of this square. Record the
                    // f, g, and h costs of the square cell
                    //                OR
                    // If it is on the open list already, check
                    // to see if this path to that square is
                    // better, using 'f' cost as the measure.
                    if (cellDetails[i - 1][j].f == FLT_MAX
                        || cellDetails[i - 1][j].f > fNew) {
                        openList.insert(make_pair(
                            fNew, make_pair(i - 1, j)));

                        // Update the details of this cell
                        cellDetails[i - 1][j].f = fNew;
                        cellDetails[i - 1][j].g = gNew;
                        cellDetails[i - 1][j].h = hNew;
                        cellDetails[i - 1][j].parent_i = i;
                        cellDetails[i - 1][j].parent_j = j;
                    }
                }
            }

            //----------- 2nd Successor (South) ------------

            // Only process this cell if this is a valid one
            if (isValid(i + 1, j, map) == true) {
                // If the destination cell is the same as the
                // current successor
                if (isDestination(i + 1, j, player) == true) {
                    // Set the Parent of the destination cell
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                    tracePath(cellDetails, player);
                    foundDest = true;
                    return;
                }
                // If the successor is already on the closed
                // list or if it is blocked, then ignore it.
                // Else do the following
                else if (closedList[i + 1][j] == false) {
                    gNew = cellDetails[i][j].g + 1.0;
                    hNew = calculateHValue(i + 1, j, player);
                    fNew = gNew + hNew;

                    // If it isn???t on the open list, add it to
                    // the open list. Make the current square
                    // the parent of this square. Record the
                    // f, g, and h costs of the square cell
                    //                OR
                    // If it is on the open list already, check
                    // to see if this path to that square is
                    // better, using 'f' cost as the measure.
                    if (cellDetails[i + 1][j].f == FLT_MAX
                        || cellDetails[i + 1][j].f > fNew) {
                        openList.insert(make_pair(
                            fNew, make_pair(i + 1, j)));
                        // Update the details of this cell
                        cellDetails[i + 1][j].f = fNew;
                        cellDetails[i + 1][j].g = gNew;
                        cellDetails[i + 1][j].h = hNew;
                        cellDetails[i + 1][j].parent_i = i;
                        cellDetails[i + 1][j].parent_j = j;
                    }
                }
            }

            //----------- 3rd Successor (East) ------------

            // Only process this cell if this is a valid one
            if (isValid(i, j + 1, map) == true) {
                // If the destination cell is the same as the
                // current successor
                if (isDestination(i, j + 1, dest) == true) {
                    // Set the Parent of the destination cell
                    cellDetails[i][j + 1].parent_i = i;
                    cellDetails[i][j + 1].parent_j = j;
                    printf("The destination cell is found\n");
                    tracePath(cellDetails, dest);
                    foundDest = true;
                    return;
                }

                // If the successor is already on the closed
                // list or if it is blocked, then ignore it.
                // Else do the following
                else if (closedList[i][j + 1] == false) {
                    gNew = cellDetails[i][j].g + 1.0;
                    hNew = calculateHValue(i, j + 1, player);
                    fNew = gNew + hNew;

                    // If it isn???t on the open list, add it to
                    // the open list. Make the current square
                    // the parent of this square. Record the
                    // f, g, and h costs of the square cell
                    //                OR
                    // If it is on the open list already, check
                    // to see if this path to that square is
                    // better, using 'f' cost as the measure.
                    if (cellDetails[i][j + 1].f == FLT_MAX
                        || cellDetails[i][j + 1].f > fNew) {
                        openList.insert(make_pair(
                            fNew, make_pair(i, j + 1)));

                        // Update the details of this cell
                        cellDetails[i][j + 1].f = fNew;
                        cellDetails[i][j + 1].g = gNew;
                        cellDetails[i][j + 1].h = hNew;
                        cellDetails[i][j + 1].parent_i = i;
                        cellDetails[i][j + 1].parent_j = j;
                    }
                }
            }

            //----------- 4th Successor (West) ------------

            // Only process this cell if this is a valid one
            if (isValid(i, j - 1, map) == true) {
                // If the destination cell is the same as the
                // current successor
                if (isDestination(i, j - 1, player) == true) {
                    // Set the Parent of the destination cell
                    cellDetails[i][j - 1].parent_i = i;
                    cellDetails[i][j - 1].parent_j = j;
                    printf("The destination cell is found\n");
                    tracePath(cellDetails, player);
                    foundDest = true;
                    return;
                }

                // If the successor is already on the closed
                // list or if it is blocked, then ignore it.
                // Else do the following
                else if (closedList[i][j - 1] == false) {
                    gNew = cellDetails[i][j].g + 1.0;
                    hNew = calculateHValue(i, j - 1, player);
                    fNew = gNew + hNew;

                    // If it isn???t on the open list, add it to
                    // the open list. Make the current square
                    // the parent of this square. Record the
                    // f, g, and h costs of the square cell
                    //                OR
                    // If it is on the open list already, check
                    // to see if this path to that square is
                    // better, using 'f' cost as the measure.
                    if (cellDetails[i][j - 1].f == FLT_MAX
                        || cellDetails[i][j - 1].f > fNew) {
                        openList.insert(make_pair(
                            fNew, make_pair(i, j - 1)));

                        // Update the details of this cell
                        cellDetails[i][j - 1].f = fNew;
                        cellDetails[i][j - 1].g = gNew;
                        cellDetails[i][j - 1].h = hNew;
                        cellDetails[i][j - 1].parent_i = i;
                        cellDetails[i][j - 1].parent_j = j;
                    }
                }
            }



        // When the destination cell is not found and the open
        // list is empty, then we conclude that we failed to
        // reach the destination cell. This may happen when the
        // there is no way to destination cell (due to
        // blockages)
        if (foundDest == false)
            printf("Failed to find the Destination Cell\n");

        return;
    }
}
};

#endif // A_STAR_H
