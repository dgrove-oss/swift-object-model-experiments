class Cell {
  let a:Int
  let next:Cell?

  init(_ x:Int, _ n:Cell?) {
    a = x
	next = n
  }

  deinit {
    print("Deinit call on Cell with value \(a)")
  }
}

@warn_unused_result
@_silgen_name("_swift_make_cell")
internal func _swift_make_cell(x:Int, _ n:Cell?) -> Cell


func makeCell(x:Int, _ n:Cell?) -> Cell {
  print("About to call native make_cell")
  return _swift_make_cell(x,n)
}

func construct(n:Int) -> Cell? {
  var tail:Cell? = nil
  for i in 1...n {
    tail = makeCell(i, tail)
  }
  return tail
}

func doit(n:Int) {
  print("Begin construct")
  let x = construct(n)
  print("Returned construct")
  if (x == nil) { print("No elements constructed") }
}

doit(5)
print("exiting...")
