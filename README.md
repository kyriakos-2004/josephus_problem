# Calculate the surviving position in the Josephus problem
This program calculates the surviving position in the Josephus problem with two ways. The first one by using observational mathematics and patterns, while the second one using bit shifting.

## What is the Josephus problem?
A bit of history. Flavius Josephus was a Jewish historian living in the 1st century. When the Yodfat was under siege by the Romans, he and 40 soldiers were trapped in a cave. Instead of surrendering to the Romans, they chose suicide instead. The way to do this was that they all stand in a circle and starting on the top, each person will kill the one next to them. The remaining alive soldiers will form a smaller circle and the one who was next, will kill the one standing next to them. This will go on and on until only one man remains. This was a trick, as Josephus did not want to commit suicide and he would rather surrender himself. He thought that either by luck or the hand of God, he might be spared in the circle and surrender.

In case the number of soldiers in the circle is a power of two, then the Josephus position (or the last man standing position) is always the starting position. The most interesting part of this problem is that if you write the number of soldiers in binary and then take the most significant bit (the one in the far left) and bring it to the end to become the least significant bit, then the number that occurs in binary is the Josephus position. This is the example:

Number of soldiers: 41

41 in binary: 101001

Move the most significant bit to the end: 010011

The answer is : 19

The reason the bit shifting is true is due to the fact that the whole problem can be written as an equation that depends only on the number of soldiers. 2<sup>m</sup> is described as the largest power of two that is less or equal to the number of soldiers. This is an algorithmic description, however. Taken from mathematics, m in this case is the integer part of the logarithm with base 2 of n. Programmatically, this can be written as floor(log<sub>2</sub> n). Through this, we can see that if we combine the two previous equations:

n = 2<sup>m</sup> + k

w = 2k + 1

we will get:

w = 2(n – 2<sup>m</sup>) + 1

and if we apply what we have just found out:

w = 2(n – 2<sup>floor(log<sub>2</sub>(n))</sup>) + 1

## Inspiration and further reading
The following video from the channel Numberphile and Professor Elman, was the inspiration behind this code.
[Numberphile Video - The Josephus Problem](https://youtu.be/uCsD3ZGzMgE)

The below page explains thoroughly why the shifting the most significant bit to least significant bit always works.
[The Josephus Problem - Binary analysis](https://www.exploringbinary.com/powers-of-two-in-the-josephus-problem/)
 
## License
This project is licensed under the MIT license.
 