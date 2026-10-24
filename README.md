_This project has been created as part of the 42 curriculum by alkonsta_
# ft_printf
## Description
## Instructions
## Resources
- [Beej's Guide: Variadic Functions](https://beej.us/guide/bgc/html/split/variadic-functions.html#variadic-functions)
## Algorithm
## Notes
- Trailing `%`
```c
ft_printf("Hello%");
```
The output is not defined and is system implementation dependent. Options considered:
1. Print it as a literal character
2. Return error