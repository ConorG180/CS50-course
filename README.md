# CS50-course

Contains solutions to all problems presented in Harvard's CS50 course

## Week 1

### Problem set 1 - Mario

ward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.

screenshot of Mario jumping over adjacent pyramids

Let’s recreate those pyramids in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramids themselves will also be taller than they are wide.

        #  #
       ##  ##
      ###  ###
     ####  ####
The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here’s how the program might work if the user inputs 8 when prompted:

            #  #
           ##  ##
          ###  ###
         ####  ####
        #####  #####
       ######  ######
      #######  #######
     ########  ########

Here’s how the program might work if the user inputs 4 when prompted:

        #  #
       ##  ##
      ###  ###
     ####  ####
Here’s how the program might work if the user inputs 2 when prompted:

        #  #
       ##  ##
And here’s how the program might work if the user inputs 1 when prompted:

        #  #
If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate.

Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.
Open your mario.c file to implement this problem as described!
