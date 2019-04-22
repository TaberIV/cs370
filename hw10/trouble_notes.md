# Known Issues

Our algorithm finds the best solutions it can then makes incremental changes, but apparently
this approach does not work for all cases.

We went over a few different things to try and improve our solution.

We initially thought that our solution failed when the correct solution was below the target resistance, as we use an approach that goes from largest-to-smallest resistors.
This was incorrect though, as shown in test case 17 we find a solution slightly below the target.

Then we also noticed that it seemed like we failed to find solutions or the correct solution when the solution matched the target, but we couldn't find a consistent issue as to why we wouldn't find this solution.

We determined that in order to find the best solution every time we needed to somehow encase our algorithm in an additional loop and remove options in order to find all possible solutions and then compare them later.

We couldn't figure out how to implement this though, as we thought that perhaps removing the largest value resistor and looping until we had no more unique resistor values remaining would work. After doing a short trace though, we saw that it wouldn't help us get closer to a solution for test case 20.

It seems like we are missing a step to handle cases where the first "best" solution we find isn't actually the correct one, as we seek to make incremental changes in order to eventually reach a possible solution.