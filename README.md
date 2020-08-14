<!-- TITLE -->
# Event Scheduler



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
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

### Built With
This section should list any major frameworks that you built your project using. Leave any add-ons/plugins for the acknowledgements section. Here are a few examples.
* [Bootstrap](https://getbootstrap.com)
* [JQuery](https://jquery.com)
* [Laravel](https://laravel.com)



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

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_



<!-- CONTACT -->
## Contact

Ryan Heidema - [@ryan-heidema](https://www.linkedin.com/in/ryan-heidema/) - rheidem@umich.edu

Project Link: [https://github.com/rheidem/Event-Scheduler](https://github.com/rheidem/Event-Scheduler)
