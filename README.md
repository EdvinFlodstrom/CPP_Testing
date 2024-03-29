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