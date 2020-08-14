<!-- TITLE -->
# Event Scheduler



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
  * [Input](#input)
  * [Ouput](#output)
* [Contact](#contact)


<!-- ABOUT THE PROJECT -->
## About The Project

My inspiration for this project came from talking with my girlfriend and her mom at a horse riding competition. In the world of [Eventing](https://en.wikipedia.org/wiki/Eventing), technology is relatively new and I saw a way I could put some of my knowledge on backtracking algorithms to use. At these Events, there are multiple riders riding in several divisions, many of which have the same coach. Each rider has three ride times throughout multiple days (one for each Event) and there are often conflicts between riders who have the same coach. Before each rider's ride time their coach gives some advice for the ride and if a coach has two riders both riding at the same time in different areas, the coach cannot be in two places at once. This immediately gave me the idea to solve this problem with backtracking.

Here's why:
* For each ride time there is a coach who cannot have other ride times in the last X minutes
* When deciding which rider to place into a ride time, we can backtrack and choose someone else if we see conflicts
* This process greatly reduces the amount of time spent figuring out a schedule, which is presently done by hand (for possibly hundreds of riders)

When deciding which language to use to solve this problem I immediately decided on C++ as it performs well for complex problems and algorithms.

Below in the Usage section I will specify the I/O of the program and how it works.



<!-- GETTING STARTED -->
## Getting Started

As this project is written 100% in C++, there is very little setup, however there are future plans to extend this to a web application.

### Prerequisites

The project includes a Makefile, so the only thing needed is a working version of g++.
* g++
```sh
$ sudo apt install build-essential
```
This installs g++ for Ubuntu 20.04 by installation of the development package build-essential.

### Installation

1. Clone the repo
```sh
git clone https://github.com/rheidem/Event-Scheduler.git
```


<!-- USAGE EXAMPLES -->
## Usage

To use this application, first compile:
```sh
make
```
Next, you are ready to run based on predefined input, for example:
```sh
./scheduler < test-1.txt
```
To clear executables:
```sh
make clean
```

### Input

This project contains 5 test files and the corresponding output. As you can see in each input test file, the input has a defined pattern, which I will walk through below:

```
1 coaches, 1 division, 5 riders, 8 min padding

Coaches:
Isa Parry

Divisions:
Training, 1 10:00, 1 12:00, 2 10:00

Riders:
Vannessa Stong, Isa Parry, Training
Nelly Yunker, Isa Parry, Training
Ellyn Rasor, No Coach, Training
Tamatha Clairmont, No Coach, Training
Della Coplan, No Coach, Training
```

The first line contains 4 important points of information:
* The number of coaches for this show
* The number of divisions for this show
* The number of riders for this show
* The amount of time each coach needs between their riders

Next, we have a list of all of the coaches. Following that is a list of all of the divisions. Each division has a one or two word name, then 3 day and time pairs. For example, 1 10:00 means on the first (1st) day the event is at 10:00am. Likewise, 2 16:00 would mean the event is on the second (2nd) day at 4:00pm. 

Finally, we have a list of all riders. In each row there are three things to note:
* The riders's name
* The rider's coach
* The rider's division

### Output

The output for this application is also fairly straightforward. It contains a list of each day specified in the "Divisions" section of the input followed by each corresponding ride time. Each ride time then has its rider, coach, division, and time. Below is a snippet of the test-5-output.txt file:

```
DAY 1:
-------------------------------------
Rider: Vannessa Stong
Division: Training
Coach: Isa Parry
Time: 10:00

Rider: Ellyn Rasor
Division: Training
Coach: No Coach
Time: 10:05

Rider: Nelly Yunker
Division: Training
Coach: Isa Parry
Time: 10:10
```

You'll notice at the top this section of output is for the first day of the show. Then we see three ride times. You will notice the Time for each is five minutes apart, which is because of Eventing's timing. There are usually 5 minutes between riders, which this program takes into account. We can also see the algorithm was successful because we specified 8 minutes of padding time between rider's for each coach, and our coach Isa Parry has 10 minutes between her two riders: Vannessa Stong and Nelly Yunker.


<!-- CONTACT -->
## Contact

Ryan Heidema - [@ryan-heidema](https://www.linkedin.com/in/ryan-heidema/) - rheidem@umich.edu

Project Link: [https://github.com/rheidem/Event-Scheduler](https://github.com/rheidem/Event-Scheduler)
