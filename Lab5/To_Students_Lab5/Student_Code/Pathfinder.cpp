//
//  Pathfinder.cpp
//  Lab5
//
//  Created by Brandon Derbidge on 10/31/16.
//  Copyright © 2016 Brandon Derbidge. All rights reserved.
//

#include "Pathfinder.h"

Pathfinder::Pathfinder(){ srand(time(0));}
Pathfinder::~Pathfinder(){}

//Part 1-----------------------------------------------------------------------------------
/*
 * getMaze
 *
 * Returns a string representation of the current maze. Returns a maze of all 1s if no maze
 * has yet been generated or imported. XXXX
 *
 * A valid string representation of a maze consists only of 125 1s and 0s (each separated
 * by spaces) arranged in five 5x5 grids (each separated by newlines). A valid maze must
 * also have 1s in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).
 *
 * Cell (0, 0, 0) is represented by the first number in the string representation of the
 * maze. Increasing in x means moving toward the east, meaning cell (1, 0, 0) is the second
 * number. Increasing in y means moving toward the south, meaning cell (0, 1, 0) is the
 * sixth number. Increasing in z means moving downward to a new grid, meaning cell
 * (0, 0, 1) is the twenty-sixth number. Cell (4, 4, 4) is represented by the last number.
 *
 * Returns:		string
 *				A single string representing the current maze
 */

string Pathfinder::getMaze(){
    
    stringstream ss;
    
    string badmaze = "1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1";
    
    if(nummaze[0][0][0] != 1 || nummaze[4][4][4] != 1)
    {
        return badmaze;
    }
    else{
        
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                for(int k = 0; k < 5; k++)
                {
                   if(nummaze[i][j][k] > 1 || nummaze[i][j][k] < 0)
                   {
                       return badmaze;
                   }
                   else{
                       if(k == 4)
                       {
                           ss << nummaze[i][j][k];
                       }
                       else{
                           ss << nummaze[i][j][k] << " " ;
                       }
                   }
                       
                }
                ss << "\n";
            }
            ss << "\n";
        }
        currentMaze = ss.str();
    }
    return currentMaze;
}

void Pathfinder::createRandomMaze(){
    
    int numOne = 0;
    int numZero = 0;
    
    for(int i = 0 ; i < HEIGHT; i++)
    {
        for(int j = 0 ; j < ROW; j++)
        {
            for(int k = 0 ; k < COLUMN; k++)
            {
                if((i == 0 && j == 0 && k == 0 ) ||(i == 4 && j == 4 && k == 4 ))
                {
                    nummaze[i][j][k] = 1;
                     maze[i][j][k] = BACKGROUND;
                    
                }
                else if(numOne > numZero +1)
                {
                    nummaze[i][j][k] = 0;
                    numZero++;
                    maze[i][j][k] = ABNORMAL;
                    
                }
                else if(numZero > numOne +1)
                {
                    nummaze[i][j][k] = 1;
                    numOne++;
                    maze[i][j][k] = BACKGROUND;
                }
                else{
                    
                    int random = rand() % 2;
                    
                    nummaze[i][j][k] = random;
                    
                    if(random == 1)
                    {
                        numOne++;
                        maze[i][j][k] = BACKGROUND;
                    }
                    else if(random == 0)
                    {
                        numZero++;
                         maze[i][j][k] = ABNORMAL;
                    }
                    
                }
                /*cout << nummaze[i][j][k] << " ";*/
            }
            /*cout << endl;*/
        }
       /* cout << endl << endl;*/
    }
}
//Part 2-----------------------------------------------------------------------------------
/*
 * importMaze
 *
 * Reads in a maze from a file with the given file name and stores it as the current maze.
 * Does nothing if the file does not exist or if the file's data does not represent a valid
 * maze.
 *
 * The file's contents must be of the format described above to be considered valid.
 *
 * Parameter:	file_name
 *				The name of the file containing a maze
 * Returns:		bool
 *				True if the maze is imported correctly; false otherwise
 */

bool Pathfinder::importMaze(string file_name)
{
   
    int temp[5][5][5];
    ifstream myfile;
    char n;
    int m = 0;
    myfile.open(file_name.c_str());
   
    for(int i = 0 ; i < ROW; i++)
    {
        for(int j = 0 ; j < COLUMN; j++)
        {
            for(int k = 0 ; k < HEIGHT; k++)
            {
                if(myfile >> n)
                {
                    if( isdigit(n))
                    {
                        m = atoi(&n);
                        temp[i][j][k] = m;
                        if(m > 1)
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                    
                }
                else if(myfile.fail())
                {
                    myfile.clear();
                   
                    return false;
                }
                else
                {
                    break;
                }
            }
            
        }
        
    }
    if(temp[4][4][4] == 0)
    {

        return false;
    }
    else if( myfile >> n)
    {

        return false;
    }
    
    
    for(int i = 0 ; i < ROW; i++)
    {
        for(int j = 0 ; j < COLUMN; j++)
        {
            for(int k = 0 ; k < HEIGHT; k++)
            {
                
                        nummaze[i][j][k] = temp[i][j][k];
                
                        if(temp[i][j][k]  == 1)
                        {
                            maze[i][j][k] = BACKGROUND;
                        }
                        else if(temp[i][j][k]  == 0)
                        {
                            maze[i][j][k] = ABNORMAL;
                            
                        }
            }
           
        }
        
    }
    
    
    
  
    
    
    if (myfile.is_open())
    {
        myfile.close();
     
        return true;
        
    }
    else
    {

        return false;
    }
  
}

//Part 3-----------------------------------------------------------------------------------
/*
 * solveMaze
 *
 * Attempts to solve the current maze and returns a solution if one is found.
 *
 * A solution to a maze is a list of coordinates for the path from the entrance to the exit
 * (or an empty vector if no solution is found). This list cannot contain duplicates, and
 * any two consecutive coordinates in the list can only differ by 1 for only one
 * coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
 * in the solution. Each string in the solution vector must be of the format "(x, y, z)",
 * where x, y, and z are the integer coordinates of a cell.
 *
 * Understand that most mazes will contain multiple solutions
 *
 * Returns:		vector<string>
 *				A solution to the current maze, or an empty vector if none exists
 */

bool Pathfinder::find_maze_path(int h, int r, int c)
{
    stringstream ss;
    string mymaze;
    
    if(r < 0 || c < 0 || h < 0 || r>= ROW || c>= COLUMN || h>= HEIGHT )
    {
        
        return false;
    }
    else if(maze[h][r][c] != BACKGROUND)
    {
        return false;
    }
    else if(r == 4 && c == 4 && h == 4){
        ss << "( " << c << ", " << r << ", " << h << " )";
        mymaze = ss.str();
       /* cout << mymaze << endl;*/
        mazePath.push_back(mymaze);
        mymaze.clear();
        ss.str("");

        maze[h][r][c] = PATH;
        return true;
    }
    else
    {
        ss << "( " << c << ", " << r << ", " << h << " )";
        mymaze = ss.str();
        mazePath.push_back(mymaze);
        mymaze.clear();
        ss.str("");
        maze[h][r][c] = PATH;
        if(find_maze_path( h-1, r, c)
           || find_maze_path( h+1, r, c)
           || find_maze_path( h, r-1, c)
           || find_maze_path( h, r+1, c)
           || find_maze_path( h, r, c-1)
           || find_maze_path( h, r, c+1) )
        {
            
            return true;
        }
    
        else
        {
            mazePath.pop_back();
            maze[h][r][c] = TEMPORARY;
            return false;
        }
        
    }
}
//Part 3-----------------------------------------------------------------------------------
/*
 * solveMaze
 *
 * Attempts to solve the current maze and returns a solution if one is found.
 *
 * A solution to a maze is a list of coordinates for the path from the entrance to the exit
 * (or an empty vector if no solution is found). This list cannot contain duplicates, and
 * any two consecutive coordinates in the list can only differ by 1 for only one
 * coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
 * in the solution. Each string in the solution vector must be of the format "(x, y, z)",
 * where x, y, and z are the integer coordinates of a cell.
 *
 * Understand that most mazes will contain multiple solutions
 *
 * Returns:		vector<string>
 *				A solution to the current maze, or an empty vector if none exists
 */
 vector<string> Pathfinder::solveMaze(){
 
     mazePath.clear();
         bool clear = find_maze_path( 0, 0, 0);
     
    if( clear == true)
    {
                return mazePath;
    }
     mazePath.clear();
    return mazePath;
}






