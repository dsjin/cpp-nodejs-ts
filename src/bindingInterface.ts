export type HelloFuntion = () => string

export interface NativeAddOn {
  hello: HelloFuntion
  addNumber: (a: number, b: number) => number
  welcome: (msg: string, cb: (result: string) => void) => void
  createObject: (msg: string) => {
    msg: string
  }
  createHelloFunction: () => HelloFuntion
}
