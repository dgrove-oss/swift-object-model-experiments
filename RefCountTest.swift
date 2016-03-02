class Cell {
/*
  let a:Int
  let next:Cell?

  init(_ x:Int, _ n:Cell?) {
    a = x
	next = n
  }
*/
}

@warn_unused_result
@_silgen_name("_swift_make_cell")
internal func _swift_make_cell(x:Int, _ n:Cell?) -> Cell

@_silgen_name("_swift_dump_list")
internal func _swift_dump_list(l:Cell) -> Void


func makeCell(x:Int, _ n:Cell?) -> Cell {
  return _swift_make_cell(x,n)
}

func construct(n:Int) -> Cell {
  var tail:Cell = makeCell(1000, nil);
  for i in 1...n {
    tail = makeCell(i, tail)
  }
  return tail
}

func doit(n:Int) {
  print("Begin construct")
  let x = construct(n)
  print("Returned construct")
}

doit(5)
print("exiting...")
