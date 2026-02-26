bool a, b, c, d;
/* ... */
if (a || b || c) NoProblem();
d = a || b || c;
if (d) AlsoNoProblem();
