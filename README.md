Not a real readme thusfar but a place for our notes so far.

We're going off the 2022 ECMAScript Spec, currently found at: https://tc39.es/ecma262/

We are generating, at runtime, a script that calls esprima.parseScript. This way, the executable does not have any working directory dependencies. The script we generate will handle reading the user input provided at the command line.
    