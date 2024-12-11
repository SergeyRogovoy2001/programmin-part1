# Lab Report: Expression Analysis and Code Debugging

## Objective
1. **Develop a data set** for testing and practice running code in a debugger.
2. **Implement expressions** for both `int` and `float` types.
3. **Analyze expressions** and create 2 data sets for each data type.
4. Execute the code using a **debugger (GDB or LLDB)**.
5. Include the **debugger output** in the report.
6. Attach the **report** and provide a link to the GitHub repository containing the source code.

---

## Code for `int` Type

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a, b, c, d, e, f;

    int expr_1 = (a * (b + c));
    int expr_2 = ((d * e * f) / (b - a + d * (c - f)));
    int expr_3 = (a * b - e);
    int expr_4 = (c + d * a - b);
    int result = expr_1 - expr_2 + expr_3 * expr_4;

    // Analyzing the expression
    // expr_1: no restrictions
    // expr_2: d != 0, c != f, b != a
    // expr_3: no restrictions
    // expr_4: no restrictions
    return 0;
}
```

## Testing in GDB
```
s@Notebook:~/programmin-part1/lab4$ gcc -g -O0 main.c -o expr
s@Notebook:~/programmin-part1/lab4$ gdb ./expr
GNU gdb (Ubuntu 15.0.50.20240403-0ubuntu1) 15.0.50.20240403-git
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./expr...
(gdb) b 5
Breakpoint 1 at 0x1138: file main.c, line 12.
(gdb)   r
Starting program: /home/s/programmin-part1/lab4/expr 

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n]) y
Debuginfod has been enabled.
To make this setting permanent, add 'set debuginfod enabled on' to .gdbinit.
Downloading separate debug info for system-supplied DSO at 0x7ffff7fc3000
[Thread debugging using libthread_db enabled]                                                                                                                  
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main (argc=1, argv=0x7fffffffdd78) at main.c:12
12          int expr_1 = (a * (b + c));
(gdb) whatis a
type = int
(gdb) p a
$1 = 0
(gdb) p b
$2 = 0
(gdb) p c
$3 = 0
(gdb) p d
$4 = 0
(gdb) p e
$5 = -134325520
(gdb) p f
$6 = 32767
(gdb) set var a=10
(gdb) set var b=15
(gdb) set var c=0
(gdb) set var d=-3
(gdb) set var e=2
(gdb) set var f=4
(gdb) next
13          int expr_2 = ((d * e * f) / (b - a + d * (c - f)));
(gdb) p expr_1
$7 = 150
(gdb) n
14          int expr_3 = (a * b - e);
(gdb) p expr_2
$8 = -1
(gdb) n
15          int expr_4 = (c + d * a - b);
(gdb) p expr_3
$9 = 148
(gdb) n
16          int result = expr_1 - expr_2 + expr_3 * expr_4;
(gdb) p expr_4
$10 = -45
(gdb) n
23          return 0;
(gdb) p result
$11 = -6509
(gdb) exit
A debugging session is active.

        Inferior 1 [process 19461] will be killed.

Quit anyway? (y or n) n
Not confirmed.
(gdb) q
A debugging session is active.

        Inferior 1 [process 19461] will be killed.

Quit anyway? (y or n) y
```

## Code for `float` Type
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;

    float expr_1 = (a * (b + c));
    float expr_2 = ((d * e * f) / (b - a + d * (c - f)));
    float expr_3 = (a * b - e);
    float expr_4 = (c + d * a - b);
    float result = expr_1 - expr_2 + expr_3 * expr_4;

    // Analyzing the expression
    // expr_1: no restrictions
    // expr_2: d != 0, c != f, b != a
    // expr_3: no restrictions
    // expr_4: no restrictions

//     (gdb) set var a=10
// (gdb) set var b=15
// (gdb) set var c=0
// (gdb) set var d=-3
// (gdb) set var e=2
// (gdb) set var f=4

    // a=10
    // b=15
    // c=0
    // d=-3
    // e=2
    // f=4
    // a * (b + c) = 10*15=150.0
    // (d * e * f) / (b - a + d * (c - f)) = (-24)/(17) = -1,41176474
    // (a * b - e) = 148,0
    // (c + d * a - b) = -45
    // expr_1 - expr_2 + expr_3 * expr_4 = 150,0 - 1,411764 - 148,0 * 45 = - 6508,58823526 / -6508.58838
    return 0;
}

```

## Testing in GDB
```
s@Notebook:~/programmin-part1/lab4$ gcc -g -O0 mainf.c -o expr
s@Notebook:~/programmin-part1/lab4$ gdb ./expr
GNU gdb (Ubuntu 15.0.50.20240403-0ubuntu1) 15.0.50.20240403-git
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./expr...
(gdb) b main
Breakpoint 1 at 0x1138: file mainf.c, line 12.
(gdb) r
Starting program: /home/s/programmin-part1/lab4/expr 

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n]) y
Debuginfod has been enabled.
To make this setting permanent, add 'set debuginfod enabled on' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main (argc=1, argv=0x7fffffffdd78) at mainf.c:12
12          float expr_1 = (a * (b + c));
(gdb) set var b=15
(gdb) set var a=10
(gdb) set var c=0
(gdb) set var d=-3
(gdb) set var e=2
(gdb) set var f=4
(gdb) n
13          float expr_2 = ((d * e * f) / (b - a + d * (c - f)));
(gdb) p expr_1
$1 = 150
(gdb) n
14          float expr_3 = (a * b - e);
(gdb) p expr_2
$2 = -1.41176474
(gdb) n
15          float expr_4 = (c + d * a - b);
(gdb) p expr_3
$3 = 148
(gdb) n
16          float result = expr_1 - expr_2 + expr_3 * expr_4;
(gdb) p expr_4
$4 = -45
(gdb) n
42          return 0;
(gdb) p result
$5 = -6508.58838
(gdb) exit
A debugging session is active.

        Inferior 1 [process 30550] will be killed.

Quit anyway? (y or n) y
```

## Report

1. Expressions were implemented for both int and float types.
2. The conditions for the expression restrictions were analyzed.
3. Debugging was performed using GDB.