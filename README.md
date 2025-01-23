# PS3: Static and Dynamic N-Body Simulation
## Contact
Name: Daniel Dsouza
Section: 201
Time to Complete: About 7-8 hours

## Description
Currently This project simulates the gravitational interactions between celestial bodies in a two-dimensional plane using Newton's laws of motion and gravitation. The simulation reads data from an input file (such as planets.txt) and animates the movement of planets according to the forces exerted on them. The user can specify the total simulation time and the time step between updates through command-line arguments. The program then draws the celestial bodies on the screen in their new correct positions and does so for every step until the time limit is reached.

### Features
I made a change where the Universe class be a friend class in the CelestialBody class, this allowed me to have two private helper functions in the CelestialBody class that were used to update the position and the velocity of the celestial bodies which are private to the CelestialBody class.The simulation uses the SFML library to render and animate celestial bodies based on their calculated positions and velocities.

### Memory
I used a vector of smart pointers to save the celestial bodies in the universe to ensure that the program will run smoothly in case of a large number of celestial bodies. It also allows me to pass the smart pointers to the draw function which will draw the celestial bodies on the screen then. All celestial bodies are stored in a vector, and their lifetimes are tied to the lifetime of the Universe object.

### Issues
I did not run into any issues that I was not able to solve in a reasonable time. I encountered some difficulties with the initial setup of smart pointers and handling texture loading for celestial body sprites. I could not write the tests for broken leapfrog and inverted implementations.

### Extra Credit
Anything special you did.  This is required to earn bonus points.
If you created your own universe file.  Describe it here and explain why it is interesting.

## Acknowledgements
blackboard and stackoverflow.com
