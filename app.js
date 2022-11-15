const addon = require('bindings')('native')

console.log(addon.hello())
console.log(addon.addNumber(123, 1))
