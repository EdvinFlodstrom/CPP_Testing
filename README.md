Journal
========

This right here, it's a journal. And it's where I'll be documenting my progress on learning the basics of C++. Why? Because I want to try something new, and learning C++ seems like it could deepen my understanding of not only programming in general, but how programming languages function and control systems and such. And because I no longer know what a holiday is. So this is going to be a painful, but also fun (I hope) journey.

2024-03-29
-----------
C++. Confusion. Not as much as I thought, though. I'm still merely learning the basics, but I've made more progress than I thought I would. In like an hour and a half, maybe two, I've now made a program that successfully converts Fahrenheit to Celsius and vice versa. Sure, it can definetely be improved, but I've implemented many a techniques that are new to me. I interacted with the STL (Standard Library) for the first time, used lambda expressions and ternary operators, this `std::ostringstream`, wrote to and from the terminal, and defined functions. All in all, good progress, I should think.

I've continued for a few hours now, making some progress. I think it's been fun so far. All I can hope is that I'm doing it all right.

Several hours later, I've now worked even more on learning C++. For the past couple of hours, I've focused more on instructional videos on C++ on YouTube, so I've written hardly any code. Still, it's definetely been a fruitsome day, I should think. I believe I've spent around 8 hours total, learning C++. For exactly how long, I do not know for certain, but I believe this is time well invested. I am having a bit of trouble with the following code, though:
```cpp
std::cin.ignore(std::numeric_limits<std::streamsize>::max()).get();
```
The code above is for pausing the program until the user clicks enter. The `ignore` part is so that the `get` part doesn't retrieve what's stored in the terminal buffer, or something like that. Excluding `ignore` means that the program exits immediately regardless of the `std::cin.get();` And the whole `std::numeric_limits<std::streamsize>::max()` is to get the maximum value attainable, and supply it as a parameter to `ignore`. The problem I'm having is that supplying such a large value to `ignore` means that the program will ignore the next very many values that are input through the terminal. Which is a problem, because then the user can't close the application the way I want them to be able to. I'll see what I can do about it, and then round off for the day. I've been working basically non-stop since 08:00, and the time of writing is 18:10.

Got it working, just a few minutes later. Now, this is what the code looks like instead:
```cpp
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n').get();
```
All that I needed to do was slap on a '\n' so that the program knows what to listen for. I assume that it currently ignores everything until a '\n' (a new line - when enter is pressed), at which point it stops ignoring the terminal inputs. Which gives me the desired effect of the program pausing until enter is pressed. As explained by a certain AI: '...the program will pause and discard all characters from the input buffer until it encounters a newline character (i.e., until the user presses enter)'. Nice.

2024-03-30
-----------
I've worked a tad more with C++ so far today, and I added a buffer for the logging to make the logging more efficient. Better to log several messages at once than multiple messages individually. I also implemented a simple multiplication function to test using lists and pairs as arguments to functions. I also slapped on a lambda expression to do the actual multiplication. It's far from perfect of course, so maybe I'll improve it later. I'd like to learn more about memory management first, though.

I also moved some code around, specifically the logging functions. They are better fit in 'Log.h' and 'Log.cpp', so that I can reuse them later should I require logging from new files.

2024-03-31
-----------
I've kept working even more with C++ now. I started out by watching more videos on the topic, I've been following a series made by 'The Cherno', on YouTube. So, I learned some about classes in C++. I'm already very much familiar with classes from C#, so I've got the basic idea of them already. I did want to practice some, though, so I wrote a simple function in my main file that uses a class from another file. This class 'DiceHolder' is split into a .cpp and a .h file. Nothing too fancy, but it worked. After a while, anyway. I had some linking errors and such, which I do not fully understand yet, so I hope I'll get better at it eventually. Anyway when the player calls the function (in the main .CPP file) to create a few dices, they send the amount of dices as an argument. Then, through the console, they may choose the number of sides on each dice (dice or die? I don't know...). Then, that amount of instances of 'DiceHolder' are created, and added to a vector. Then, the amount of dices created are logged (saved in a buffer to be logged later, but same thing), and finally, the simulated dice throws are logged. Relatively simple, but it was interesting nontheless. Also, after committing the changes I noticed that I wanted to move some code. Just one line, when I created the vector. Since I hadn't yet pushed the commit, I thought to fix that little mistake. So I ran `git rebase -i HEAD~1` and moved it. I think it worked well, but perhaps it was a tad overkill. I may have been able to do the same thing with only `git commit --amend`, but eh. It worked. I think.

2024-04-01
-----------
As today is the last day of my short holiday, I shall not spend as much time studying. So, today was a short one and a half hours (aproximately, anyway) of C++. I learned some more about inheritance and pure virtual functions (interfaces). I also implemented a 'MainClass' and a 'SubClass', where 'SubClass' implements 'MainClass', which contains a pure virtual function (method? Since it's part of a class?). Nothing too fancy, but it works. Since my schedule's going to be back on track by tomorrow, I won't be spending as much time learning C++ from now on. Maybe on the weekends. It's been a fun little journey, these fours days of something new. My main goal with all this was to learn more about the C-family in general, which I probably have. At least a little. I think I definetely learned some more about memory management and more technological subjects related to programming. As such, I will likely keep studying C++ somewhat on-and-off, when I have some spare time.

2024-04-06
-----------
Recently, I've gotten more interested in using C++ to interact with hardware a tad more than I have before. So, I wanted to try something along those lines today. I wrote a small program that, each time you enter a key on the keyboard, the position of the cursor is logged to the console. So it'll look something like `The position of the cursor is: X: 0, Y: 0` if your cursor is at the very top left of the screen. Nothing major, but a small little project that was different from what I've done before.

2024-04-07
-----------
I was messing around today, a bit too much perhaps? I got some really dumb ideas yesterday, that I wanted to try implementing today. So I wrote two new functions, one for saving the current position of the cursor and then moving it there later, and one for simulating left click, x amount of times. So, when one runs the program, one can hover their cursor above a position, press any key, move the cursor away, and then press that same key. What happens is that the cursor will instantly move back to that position, and a left click will be simulated. As of right now, I've mostly used it do set the cursor's position above the 'X' to close the application, and then close the application by pressing 'E' at the bottom left edge of the screen. Nothing too fancy, but a fun little project, I think.