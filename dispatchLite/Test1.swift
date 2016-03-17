import Dispatch

func test() -> Void {
  let q = dispatch_queue_create(10,20)
  let o = dispatch_increase_data(q, 40)
  let o2 = dispatch_increase_data(q, o)
  let o3 = dispatch_increase_data(q, o2)
  dispatch_suspend(q)
  dispatch_suspend_q(q)
  dispatch_increase_data(q, o3)
  dispatch_semaphore_create()
}

func test2() -> Void {
   let q = dispatch_queue_create(100,200)
   dispatch_async(q) { print("Hello World!") }
}

func test3() -> Void {
  let s = dispatch_source_create(10)
  dispatch_suspend(s)
}


print("BEGIN")
test()
print("INTERMISSION")
test2()
print("INTERMISSION REDUX")
test3()
print("FINI")
