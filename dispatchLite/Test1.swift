import DispatchLite;

func test() -> Void {
  let q = dispatch_make_queue(10,20);
  let o = dispatch_increase_data(q, 40);
  let o2 = dispatch_increase_data(q, o);
  let o3 = dispatch_increase_data(q, o2);
}

test();
