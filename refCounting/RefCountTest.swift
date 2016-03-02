class Cell {
  let a:Int
  let next:Cell?

  init(_ x:Int, _ n:Cell?) {
    a = x
	next = n
  }

  deinit {
    print("Swift-level deinit called with data \(a)")
  }
}

@warn_unused_result
@_silgen_name("_swift_make_cell")
internal func native_make_cell(x:Int, _ n:Cell?) -> Cell

@_silgen_name("_swift_dump_list")
internal func native_dump_list(l:Cell) -> Void

func construct(n:Int, inSwift:Bool) -> Cell {
  var tail:Cell = inSwift ? Cell(1000, nil) : native_make_cell(1000, nil)
  for i in 1...n {
    if (inSwift) {
	    tail = Cell(i, tail)
	} else {
        tail = native_make_cell(i, tail)
	}
  }
  native_dump_list(tail);
  return tail
}

func doit(n:Int, inSwift:Bool) {
  print("Begin list construction")
  let x = construct(n, inSwift:inSwift)
  print("Returning from doit")
}

doit(5, inSwift:true)
doit(5, inSwift:false)
print("exiting...")
