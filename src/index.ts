import bindings from 'bindings'
import { NativeAddOn } from './bindingInterface'
const addon: NativeAddOn = bindings('native') as NativeAddOn

console.log(addon.hello())
console.log(addon.addNumber(123, 1))
addon.welcome('Bob', (result: string) => {
  console.log(result)
})