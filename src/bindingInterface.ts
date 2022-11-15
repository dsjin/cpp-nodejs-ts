export interface NativeAddOn {
  hello: () => string
  addNumber: (a: number, b: number) => number
  welcome: (msg: string, cb: (result: string) => void) => void
}
