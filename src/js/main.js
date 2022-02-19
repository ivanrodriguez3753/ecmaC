function helloFromFunc() {
    console.log("hello from js's helloFromFunc()");
}

console.log("hello from js global space");
helloFromFunc();

var esprima = require('esprima');
var tree = esprima.parseScript('answer = 42');
console.log(tree);
var tree2 = esprima.parseScript('   var foo = \"bar\";' +
                                '   foo[\"key1\"] = \"value1\";');
console.log(tree2);