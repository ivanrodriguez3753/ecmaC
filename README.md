Not a real readme thusfar but a place for our notes so far.

We're going off the 2021 ECMAScript Spec, currently found at: https://www.ecma-international.org/wp-content/uploads/ECMA-262_12th_edition_june_2021.pdf

We are generating, at runtime, a script that calls esprima.parseScript. This way, the executable does not have any working directory dependencies. The script we generate will handle reading the user input provided at the command line.
    
