import Dispatch

func test() -> Void {
  let q = dispatch_make_queue(10,20)
  let o = dispatch_increase_data(q, 40)
  let o2 = dispatch_increase_data(q, o)
  let o3 = dispatch_increase_data(q, o2)
  dispatch_suspend(q)
  dispatch_suspend_q(q)
  dispatch_increase_data(q, o3)
}

func test2() -> Void {
   let q = dispatch_make_queue(100,200)
   dispatch_async(q) { print("Hello World!") }
}


print("BEGIN")
test()
print("INTERMISSION")
test2()
print("FINI")
