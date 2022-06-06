# Team-Manager
## Based on GOOGLE HASHCODE 2022 Problem
https://codingcompetitions.withgoogle.com/hashcode/round/00000000008caae7/000000000098afc8

Although, includes some changes-
1. Projects should be given in a manner that all are completed at the end, i.e. the while loop terminates in the main function of source code. Otherwise, it can be an infinite loop.
2. The appearnce of Contributer's names for each project in the Output file is not as expected in the HashCode question. The order is different and it includes the name to roles assigned.

## About
This is a Team manager app where Contributers are assigned to Projects based on their skill levels.

A contributor can be assigned to a project for a specific role (at most one role in a single project), if they either:
1. have the skill at the required level or higher; or
2. have the skill below the required level, only if another contributor on the same project (assigned to another role), has this skill at the required level or higher. In this case, the contributor will be mentored by their colleague.

One contributor can mentor multiple people at once, including for the same skill. A contributor can mentor and be mentored by other contributors at the same time.
Not possessing a skill is equivalent to possessing a skill at level 0. So a contributor can work on a project and be assigned to a role with requirement C++ level 1 if they don’t know any C++, provided that somebody else on the team knows C++ at level 1 or higher.

Completing a project is a learning opportunity, especially for the contributors working on the edge of their existing abilities! When each project is completed:
1. contributors working in roles where the required skill level was equal or higher than their current level improve their skill level by one level
2. other contributors keep their skill level
3. mentoring someone doesn’t increase the level of the skill for the mentor.

## Input File Format
Each input data set is provided in a plain text file. The file contains only ASCII characters with lines ending with a single '\n' character (also called “UNIX-style” line endings). When multiple strings and numbers are given in one line, they are separated by a single space between each two elements.

The first line of the data set contains:
  1. an integer C (1 ≤ C≤ 105) – the number of contributors,
  2. integer P (1 ≤ P ≤ 105) – the number of projects.

This is followed by C sections describing individual contributors. Each contributor is described by the following lines:

The first line contains:
  1. the contributor's name (ASCII string of at most 20 characters, all of which are lowercase or uppercase English alphabet letters a-z and A-Z, or numbers 0-9),
  2. an integer N (1≤ N ≤ 100) - the number of skills of the contributor.
  3. the next N lines describe individual skills of the contributor. Each such line contains:
      1. the name of the skill (ASCII string of at most 20 characters, all of which are lowercase or uppercase English alphabet letters a-z and A-Z, numbers 0-9, dashes '-' or pluses '+'),
      2. an integer Li (1≤ Li ≤ 10) - skill level.

This is followed by P sections describing individual projects. Each project is described by the following lines:

The first line contains:
   1. the name of the project (ASCII string of at most 20 characters, all of which are lowercase or uppercase English alphabet letters a-z and A-Z or numbers 0-9),
   2. an integer Di (1 ≤Di ≤ 105) – the number of days it takes to complete the project,
   3. an integer Si (1 ≤ Si ≤ 105) – the score awarded for project’s completion,
   4. an integer Bi (1 ≤ Bi ≤ 105) – the “best before” day for the project,
   5. an integer Ri (1 ≤ Ri ≤ 100) – the number of roles in the project.
   6. the next Ri lines describe the skills in the project:
        1. a string Xk – the name of the skill (ASCII string of at most 20 characters, all of which are lowercase or uppercase English alphabet letters a-z and A-Z, numbers 0-9, dashes '-' or pluses '+'),
        2. an integer Lk (1≤Lk≤100) – the required skill level.

## Output File Format
Output file describes which projects each contributor is going to work on and in which role.

The first line should contain the integer E (0≤E≤P) – the number of executed projects.

This should be followed by E sections each describing one completed project. Each project should be described by two lines:
1. A single line containing the name of the project (as it appears in the input file). Each project can be mentioned at most once in the submission file.
2. A single line containing the names of the contributors assigned to each of the project roles with name of those roles, separated by semicolons.

## Working
The source code will easily run in any IDE (I used VS code).

It takes input files's name as the input and creates an output file.

Two example files are provieded in this repository, one can also make others of their own.
