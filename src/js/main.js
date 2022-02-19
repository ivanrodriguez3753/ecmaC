var esprima = require('esprima');
var tree2 = esprima.parseScript('   var foo = \"bar\";' +
                                '   foo[\"key1\"] = \"value1\";');
console.log(JSON.stringify(tree2));