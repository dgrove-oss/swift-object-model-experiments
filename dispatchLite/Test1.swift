import DispatchLite;

func test() -> Void {
  let q = dispatch_make_queue(10,20);
  let o = dispatch_increase_data(q, 40);
  print("Data was \(o)");
}

test();
